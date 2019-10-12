#pragma once
#pragma once
#ifndef _Aft_Core_Header
#define _Aft_Core_Header

#include <Adt_AvlTree.hxx>
#include <Mesh_TypeTraits.hxx>
#include <Geom_Sort.hxx>
#include <Mesh_GlobalData.hxx>
#include <Aft_FrontInfo.hxx>

#include <memory>

//#include "Mesh2d_SizeMapSurface.hxx"
//#include "Aft2d_FrontSurfaceGlobalData.hxx"
//#include "Aft2d_FrontSurfaceInfo.hxx"

namespace AutLib
{

	struct Aft_CoreInfo
	{
		static const Standard_Real SIZE_TO_HIGHT_ELEMENT_COEFF;
		static const Standard_Integer RESERVED_SORT_SIZE;
	};

	template<class SizeMap, class FrontInfo, class FrontData>
	class Aft_Core
		: public Mesh_GlobalData<typename FrontInfo::elementType>
		, public FrontInfo
		, public FrontData
		, public Aft_CoreInfo
	{

		template< bool cond, typename U >
		using resolvedType = typename std::enable_if< cond, U >::type;

		/*Private Data*/

	public:

		typedef typename FrontInfo::nodeType nodeType;
		typedef typename FrontInfo::edgeType edgeType;
		typedef typename FrontInfo::edgeType frontType;
		typedef typename FrontInfo::elementType elementType;

		typedef typename nodeType::ptType Point;

		typedef FrontData frontData;
		typedef Mesh_GlobalData<typename FrontInfo::elementType> globalData;
		typedef FrontInfo frontInfo;

		typedef std::shared_ptr<SizeMap> sizeMap_ptr;
		typedef std::shared_ptr<frontType> front_ptr;
		typedef std::shared_ptr<nodeType> node_ptr;

		typedef FrontInfo frontInfo;
		typedef FrontData frontData;


	protected:

		std::shared_ptr<SizeMap> theSizeMap_;

		struct mySort
		{

			Stl_Vector<Standard_Real> Quality_;
			Stl_Vector<Standard_Integer> Indices_;

			Standard_Integer Size_;

			void Import
			(
				const Stl_Vector<node_ptr>& theNodes,
				const Point& theCentre,
				const SizeMap& sizeMap
			)
			{
#if MESH_DEBUG
				if (theNodes.Size() > mySort::RESERVED_SORT_SIZE)
				{
					FatalErrorIn(FunctionSIG)
						<< "Too large front size to sorting"
						<< abort(FatalError);
				}
#endif

				if (theNodes.size() > mySort::Quality_.size())
				{
					mySort::Quality_.resize(theNodes.size() * 2);
					mySort::Indices_.resize(theNodes.size() * 2);
				}

				Standard_Integer k = 0;
				for (const auto& node : theNodes)
				{
					Debug_Null_Pointer(node);
					mySort::Quality_[k] =
						sizeMap.CalcSquareDistance(theCentre, node->Coord());
					mySort::Indices_[k] =
						k;
					++k;
				}

				Size_ = (Standard_Integer)theNodes.size();
			}

			void Perform
			(
				const Standard_Integer theSize
			)
			{
				Geom_Sort::Sort
					<
					Standard_Real,
					Stl_Vector
					>
					(Quality_, Indices_, theSize);
			}
		};

		static mySort Sort;

		template<class U = void>
		static resolvedType<is_two_dimension<(int)Point::dim>::value, U> Update_Pmin_Pmax
		(
			const Point& P,
			Point& Pmin,
			Point& Pmax
		)
		{
			if (P.X() > Pmax.X()) Pmax.X() = P.X();
			if (P.X() < Pmin.X()) Pmin.X() = P.X();

			if (P.Y() > Pmax.Y()) Pmax.Y() = P.Y();
			if (P.Y() < Pmin.Y()) Pmin.Y() = P.Y();
		}

		template<class U = void>
		static resolvedType<is_three_dimension<(int)Point::dim>::value, U> Update_Pmin_Pmax
		(
			const Point& P,
			Point& Pmin,
			Point& Pmax
		);

		template<class U = Standard_Boolean>
		static resolvedType<is_two_dimension<(int)Point::dim>::value, U>  IsIntersect
		(
			const Point& Q0,
			const Point& Q1,
			const Point& Pmin,
			const Point& Pmax
		)
		{
			auto xmax = MAX(Q0.X(), Q1.X());
			if (xmax < Pmin.X()) return Standard_False;

			auto xmin = MIN(Q0.X(), Q1.X());
			if (xmin > Pmax.X()) return Standard_False;

			auto ymax = MAX(Q0.Y(), Q1.Y());
			if (ymax < Pmin.Y()) return Standard_False;

			auto ymin = MIN(Q0.Y(), Q1.Y());
			if (ymin > Pmax.Y()) return Standard_False;

			return Standard_True;
		}

		template<class U = Standard_Boolean>
		static resolvedType<is_three_dimension<(int)Point::dim>::value, U>  IsIntersect
		(
			const Point& Q0,
			const Point& Q1,
			const Point& Pmin,
			const Point& Pmax
		);

	protected:

		void RemoveEntitiesFromGeometry();

		Standard_Boolean IsOnLevel(const frontType& theEdge) const;

		Standard_Boolean GetFrontEntity();

		Standard_Boolean IsBelongToFront() const;

		Standard_Boolean ChackDistCriteria(const Stl_Vector<front_ptr>& theFronts) const;

		Standard_Boolean IsSameLevelFueled();

		Standard_Boolean IsNextLevelFueled();

		Standard_Boolean IsCavityRemoverFueled();

		Standard_Boolean IsNewPointCandidate(const Stl_Vector<front_ptr>& theEffectives) const;

		void CalcElementSize();

		void CalcOptimumCoord();

		void CalcLocalFrontRadius();

		void SetDepthSearching();

		void AddOptimumNodeTo(Stl_Vector<node_ptr>& theNodes);

		void SortNodes
		(
			Stl_Vector<node_ptr>& theNodes
		) const;

		void RemoveCurrentFromFront() const;

		void RetrieveEffectiveFronts
		(
			const Stl_Vector<front_ptr>& theEntities,
			Stl_Vector<front_ptr>& theEffectives
		) const;

		void RetrieveEarlyNodes(Stl_Vector<node_ptr>& theNodes) const;

		/*void RetrieveLocalFrontNodes
		(
			Stl_Vector<node_ptr>& theLocals,
			Stl_Vector<node_ptr>& theSearching
		) const;*/

		template<class U = void>
		resolvedType<is_isoType<typename SizeMap::frontType>::value, U> RetrieveLocalFrontNodes
		(
			Stl_Vector<node_ptr>& theLocals,
			Stl_Vector<node_ptr>& theSearching
		) const
		{
			Stl_Vector<node_ptr> Locals;
			Debug_Null_Pointer(theSizeMap_);
			Debug_Null_Pointer(frontInfo::CurrentFront());
			const auto& sizeMap = *theSizeMap_;
			const auto& current = *frontInfo::CurrentFront();

			Entity_Box<Point> box;
			if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Generation)
			{
				box = sizeMap.CalcSearchRegion
				(
					frontInfo::LocFrontRadius(),
					frontInfo::Coord(),
					current
				);
			}
			else
			{
				box = sizeMap.CalcSearchRegion
				(
					frontInfo::LocFrontRadius(),
					current
				);
			}

			frontData::GeometrySearch
			(
				box,
				Locals
			);

			Debug_If_Condition_Message
			(
				frontInfo::SquareSearchRadius() <= 0,
				"Invalid Searching Radius"
			);
			const auto squareSearchingRadius =
				frontInfo::SquareSearchRadius();

			Debug_If_Condition_Message
			(
				frontInfo::SquareLocFrontRadius() <= 0,
				"Invalid Local Radius"
			);
			const auto squareLocalRadius =
				frontInfo::SquareLocFrontRadius();

			const auto& coord = frontInfo::Coord();

			std::vector<Point> Pts;
			Pts.reserve(Locals.size());
			for (const auto& node : Locals)
			{
				Standard_Boolean cond = Standard_False;
				forThose(Index, 0, frontType::nbNodes - 1)
				{
					if (node IS_EQUAL current.Node(Index))
					{
						cond = Standard_True;
						break;
					}
				}
				if (cond)
				{
					continue;
				}

				auto radius2 =
					sizeMap.CalcSquareDistance(coord, node->Coord());

				if (radius2 <= squareSearchingRadius)
				{
					theSearching.push_back
					(
						node
					);
					Pts.push_back(node->Coord());
				}
				if (radius2 <= squareLocalRadius)
					theLocals.push_back
					(
						node
					);
			}

			if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Generation)
			{
				frontInfo::SetCandidateSize((Standard_Integer)Pts.size());

				if (Pts.size()) frontInfo::SetBoundingBox(Entity_Box<Point>::BoundingBoxOf(Pts));
			}
		}

		template<class U = void>
		resolvedType<is_anisoType<typename SizeMap::frontType>::value, U> RetrieveLocalFrontNodes
		(
			Stl_Vector<node_ptr>& theLocals,
			Stl_Vector<node_ptr>& theSearching
		) const
		{
			//Stl_Vector<node_ptr> Locals;

			Debug_Null_Pointer(theSizeMap_);
			Debug_Null_Pointer(frontInfo::CurrentFront());
			const auto& sizeMap = *theSizeMap_;
			const auto& current = *frontInfo::CurrentFront();

			Entity_Box<Point> box;
			if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Generation)
			{
				box = sizeMap.CalcSearchRegion
				(
					frontInfo::LocFrontRadius(),
					frontInfo::Coord(),
					current
				);
			}
			else
			{
				box = sizeMap.CalcSearchRegion
				(
					frontInfo::LocFrontRadius(),
					current
				);
			}


			/*frontData::GeometrySearch
			(
				box,
				Locals
			);*/

			frontData::GeometrySearch
			(
				box,
				theLocals
			);

			Debug_If_Condition_Message
			(
				frontInfo::SquareSearchRadius() <= 0,
				"Invalid Searching Radius"
			);
			const auto squareSearchingRadius =
				frontInfo::SquareSearchRadius();

			Debug_If_Condition_Message
			(
				frontInfo::SquareLocFrontRadius() <= 0,
				"Invalid Local Radius"
			);
			const auto squareLocalRadius =
				frontInfo::SquareLocFrontRadius();

			const auto& coord = frontInfo::Coord();
			//cout << "lr = " << sqrt(squareLocalRadius) << " , sr = " << sqrt(squareSearchingRadius) << std::endl;
			std::vector<Point> Pts;
			//Pts.reserve(Locals.size());
			Pts.reserve(theLocals.size());
			//for (const auto& node : Locals)
			for (const auto& node : theLocals)
			{
				Standard_Boolean cond = Standard_False;
				forThose(Index, 0, frontType::nbNodes - 1)
				{
					if (node IS_EQUAL current.Node(Index))
					{
						cond = Standard_True;
						break;
					}
				}
				if (cond)
				{
					continue;
				}

				auto radius2 =
					sizeMap.CalcSquareDistance(coord, node->Coord());

				if (radius2 <= squareSearchingRadius)
				{
					theSearching.push_back
					(
						node
					);

					Pts.push_back(node->Coord());
				}

				/*if (radius2 <= squareLocalRadius)
					theLocals.push_back
					(
						node
					);*/
			}
			//cout << "lr size = " << theLocals.size() << ", sr size = " << theSearching.size() << std::endl;
			if (frontInfo::AlgCondition() IS_EQUAL Aft_AlgCondition_Generation)
			{
				frontInfo::SetCandidateSize((Standard_Integer)Pts.size());

				if (Pts.size()) frontInfo::SetBoundingBox(Entity_Box<Point>::BoundingBoxOf(Pts));
			}
		}

		template<class U = void>
		resolvedType<is_two_dimension<(int)Point::dim>::value, U> RetrieveLocalFrontEntities
		(
			const Stl_Vector<node_ptr>& theNodes,
			Stl_Vector<front_ptr>& theEntities
		) const
		{
			Adt_AvlTree<front_ptr> compact;
			compact.SetComparableFunction(&frontType::IsLess);

			for (const auto& node : theNodes)
			{
				Debug_Null_Pointer(node);

				auto entities = node->RetrieveFrontEdges();
				for (const auto& entity : entities)
				{
					Debug_Null_Pointer(entity.second.lock());

					compact.InsertIgnoreDup
					(
						entity.second.lock()
					);
				}
			}
			compact.RetrieveTo(theEntities);
		}

		template<class U = void>
		resolvedType<is_three_dimension<(int)Point::dim>::value, U> RetrieveLocalFrontEntities
		(
			const Stl_Vector<node_ptr>& theNodes,
			Stl_Vector<front_ptr>& theEntities
		) const;

		void NodesInRadius
		(
			const Standard_Real theRadius,
			const Point& theCoord,
			const Stl_Vector<node_ptr>& theNodes,
			Stl_Vector<node_ptr>& theInners
		) const;


		template<class U = void>
		resolvedType<is_isoType<typename SizeMap::frontType>::value, U> ModifyLocalFront
		(
			const Standard_Real theFactor
		)
		{
			if (theFactor < (Standard_Real)1.0)
			{
				FatalErrorIn(FunctionSIG)
					<< "Invalid Factor"
					<< abort(FatalError);
			}

			if (frontData::IsGeometryEmpty())
			{
				return;
			}

			Debug_Null_Pointer(theSizeMap_);
			const auto& sizeMap = *theSizeMap_;

			Stl_Vector<node_ptr> nodes;
			frontData::RetrieveFromGeometryTo(nodes);

			for (auto& ptr : nodes)
			{
				Debug_Null_Pointer(ptr);
				auto& node = *ptr;
				const auto& pt = node.Coord();

				auto fronts = node.RetrieveFrontEdges();
				Debug_If_Condition(NOT fronts.size());

				//- Retrieve max_length attached to the current node
				Standard_Real maxLength = (Standard_Real)0.;
				for (auto& w_entity : fronts)
				{
					Debug_Null_Pointer(w_entity.second.lock());
					auto entity = w_entity.second.lock();

					if (entity->CharLength() > maxLength)
						maxLength = entity->CharLength();
				}

				maxLength *= theFactor;
				Debug_If_Condition_Message
				(
					maxLength <= (Standard_Real)0.,
					" Invalid MaxLength Value"
				);

				//- save the max_length
				node.SetRadius
				(
					MAX(node.Radius(), maxLength)
				);

				Stl_Vector<node_ptr> locals;
				frontData::GeometrySearch
				(
					sizeMap.CalcSearchRegion(maxLength, node.Coord()),
					locals
				);

				Stl_Vector<node_ptr> inners;
				NodesInRadius
				(
					maxLength,
					node.Coord(),
					locals,
					inners
				);

				for (auto& innerNode : inners)
					innerNode->SetRadius
					(
						MAX(innerNode->Radius(), maxLength)
					);
			}
		}

		template<class U = void>
		resolvedType<is_anisoType<typename SizeMap::frontType>::value, U> ModifyLocalFront
		(
			const Standard_Real theFactor
		)
		{
			if (theFactor < (Standard_Real)1.0)
			{
				FatalErrorIn(FunctionSIG)
					<< "Invalid Factor"
					<< abort(FatalError);
			}

			if (frontData::IsGeometryEmpty())
			{
				return;
			}

			Debug_Null_Pointer(theSizeMap_);
			const auto& sizeMap = *theSizeMap_;

			Stl_Vector<node_ptr> nodes;
			frontData::RetrieveFromGeometryTo(nodes);

			for (auto& ptr : nodes)
			{
				Debug_Null_Pointer(ptr);
				auto& node = *ptr;
				const auto& pt = node.Coord();

				auto fronts = node.RetrieveFrontEdges();
				Debug_If_Condition(NOT fronts.size());

				//- Retrieve max_length attached to the current node
				Standard_Real maxLength = (Standard_Real)0.;
				for (auto& w_entity : fronts)
				{
					Debug_Null_Pointer(w_entity.second.lock());
					auto entity = w_entity.second.lock();

					if (entity->CharLength() > maxLength)
						maxLength = entity->CharLength();
				}

				//- Retrieve worst metric attached to the current node
				auto Iter = fronts.begin();
				auto M = Iter->second.lock()->EffectiveMetric();
				Iter++;

				while (Iter NOT_EQUAL fronts.end())
				{
					const auto& Mi = Iter->second.lock()->EffectiveMetric();
					if (M.Determinant() < Mi.Determinant())
					{
						M = Entity2d_Metric1::UnionSR(M, Mi);
					}
					else
					{
						M = Entity2d_Metric1::UnionSR(Mi, M);
					}
					Iter++;
				}

				maxLength *= theFactor;
				Debug_If_Condition_Message
				(
					maxLength <= (Standard_Real)0.,
					" Invalid MaxLength Value"
				);

				//- save the max_length
				node.SetRadius
				(
					MAX(node.Radius(), maxLength)
				);

				auto detM = M.Determinant();
				//- save worst metric
				if (node.Metric().Determinant() < detM)
				{
					node.SetMetric(Entity2d_Metric1::UnionSR(node.Metric(), M));
				}
				else
				{
					node.SetMetric(Entity2d_Metric1::UnionSR(M, node.Metric()));
				}

				//auto h = sizeMap.CalcElementSize(node.Coord());

				Stl_Vector<node_ptr> locals;
				frontData::GeometrySearch
				(
					sizeMap.CalcSearchRegion(MAX(maxLength, sizeMap.CalcElementSize(node.Coord())), M, node.Coord()),
					locals
				);

				Stl_Vector<node_ptr> inners;
				NodesInRadius
				(
					maxLength,
					node.Coord(),
					locals,
					inners
				);

				for (auto& innerNode : inners)
				{
					innerNode->SetRadius
					(
						MAX(innerNode->Radius(), maxLength)
					);

					if (innerNode->Metric().Determinant() < detM)
					{
						innerNode->SetMetric(Entity2d_Metric1::UnionSR(innerNode->Metric(), M));
					}
					else
					{
						innerNode->SetMetric(Entity2d_Metric1::UnionSR(M, innerNode->Metric()));
					}
				}
			}
		}

		void RejectCurrent
		(
			const front_ptr& theEntity
		);

		void RegisterElement();

		template<class U = void>
		resolvedType<is_isoType<typename SizeMap::frontType>::value, U> UpdateFront()
		{
			Debug_Null_Pointer(frontInfo::ValidNode());
			const auto& node = *frontInfo::ValidNode();

			frontInfo::PointCondition() = Aft_PointCondition_PickedUp;

			// check for updating the nodes tree
			if (node.Index() IS_EQUAL frontInfo::NodeCounter() + 1)
			{
				frontInfo::NodeCounter()++;

				frontInfo::PointCondition() = Aft_PointCondition_NewPoint;

				// insert the new node into the NODES TREE
				frontData::InsertToGeometry(frontInfo::ValidNode());
			}

			frontInfo::SetPaires();

			frontInfo::UpdatePaires(*theSizeMap_);

			frontInfo::CreateElement();

			frontInfo::UpdateElement();

			RemoveEntitiesFromGeometry();

			RegisterElement();
		}

		template<class U = void>
		resolvedType<is_anisoType<typename SizeMap::frontType>::value, U> UpdateFront()
		{
			Debug_Null_Pointer(frontInfo::ValidNode());
			const auto& node = frontInfo::ValidNode();

			const auto& current = frontInfo::CurrentFront();

			frontInfo::PointCondition() = Aft_PointCondition_PickedUp;

			// check for updating the nodes tree
			if (node->Index() IS_EQUAL frontInfo::NodeCounter() + 1)
			{
				frontInfo::NodeCounter()++;

				const auto effect = theSizeMap_->CalcEffectiveMetric(node->Coord(), current->Centre());
				node->SetMetric(effect);

				frontInfo::PointCondition() = Aft_PointCondition_NewPoint;

				// insert the new node into the NODES TREE
				frontData::InsertToGeometry(frontInfo::ValidNode());
			}

			frontInfo::SetPaires();

			frontInfo::UpdatePaires(*theSizeMap_);

			frontInfo::CreateElement();

			frontInfo::UpdateElement();

			RemoveEntitiesFromGeometry();

			RegisterElement();
		}

		//void UpdateFront();

	public:

		Aft_Core()
		{}

		Aft_Core(const std::shared_ptr<SizeMap>& theSizeMap)
			: theSizeMap_(theSizeMap)
		{}

		Standard_Boolean IsSizeMapLoaded() const
		{
			return (Standard_Boolean)theSizeMap_;
		}

		const std::shared_ptr<SizeMap>& Map() const
		{
			return theSizeMap_;
		}

		void LoadSizeMap(const std::shared_ptr<SizeMap>& theSizeMap)
		{
			theSizeMap_ = theSizeMap;
		}


	};
}

#include <Aft_CoreI.hxx>

#endif // !_Aft_Core_Header