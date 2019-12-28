#pragma once
#ifndef _Aft_Core_Base_Header
#define _Aft_Core_Base_Header

#include <Adt_AvlTree.hxx>
#include <Mesh_GlobalData.hxx>
#include <Mesh_AftTypeTraits.hxx>
#include <Aft_FrontInfo.hxx>
#include <Aft_MetricPrcsr.hxx>
#include <Geom_Sort.hxx>

#include <memory>
#include <vector>

//#include "Aft2d_OptNodeAnIso_Calculator.hxx"
//#include "Aft2d_FrontAnIsoGlobalData.hxx"
//#include "Aft2d_FrontAnIsoInfo.hxx"

namespace AutLib
{

	struct Aft_Core_Base_Info
	{

		static const Standard_Real SIZE_TO_HIGHT_ELEMENT_COEFF;
		static const Standard_Integer RESERVED_SORT_SIZE;
	};

	template<class OptNodeAlg, class FrontInfo, class FrontData, class SizeFun, class MetricFun>
	class Aft_Core_Base
		: public Mesh_GlobalData<typename FrontInfo::elementType>
		, public FrontInfo
		, public FrontData
		, public Aft_Core_Base_Info
	{

	public:

		typedef typename FrontInfo::nodeType nodeType;
		typedef typename FrontInfo::frontType frontType;
		typedef typename FrontInfo::elementType elementType;

		typedef typename nodeType::ptType Point;

		typedef Mesh_GlobalData<typename FrontInfo::elementType> globalData;
		typedef FrontInfo frontInfo;
		typedef FrontData frontData;

		typedef Aft_MetricPrcsr<frontType, SizeFun, MetricFun> metricMap;

	private:

		template< bool cond, typename U >
		using resolvedType = typename std::enable_if< cond, U >::type;

		/*Private Data*/

		std::shared_ptr<OptNodeAlg> theNodeCalculator_;
		std::shared_ptr<metricMap> theMetricMap_;

	public:

		const std::shared_ptr<OptNodeAlg>& NodeCalculator() const
		{
			return theNodeCalculator_;
		}

		const std::shared_ptr<metricMap>& MetricMap() const
		{
			return theMetricMap_;
		}

	protected:

		struct mySort
		{

			Stl_Vector<Standard_Real> Quality_;
			Stl_Vector<Standard_Integer> Indices_;

			Standard_Integer Size_;

			void Import
			(
				const Stl_Vector<std::shared_ptr<nodeType>>& theNodes,
				const Point& theCentre,
				const metricMap& theSizeMap
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
						theSizeMap.CalcSquareDistance(theCentre, node->Coord());
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
		)
		{
			if (P.X() > Pmax.X()) Pmax.X() = P.X();
			if (P.X() < Pmin.X()) Pmin.X() = P.X();

			if (P.Y() > Pmax.Y()) Pmax.Y() = P.Y();
			if (P.Y() < Pmin.Y()) Pmin.Y() = P.Y();

			if (P.Z() > Pmax.Z()) Pmax.Z() = P.Z();
			if (P.Z() < Pmin.Z()) Pmin.Z() = P.Z();
		}

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

			auto zmax = MAX(Q0.Z(), Q1.Z());
			if (zmax < Pmin.Z()) return Standard_False;

			auto zmin = MIN(Q0.Z(), Q1.Z());
			if (zmin > Pmax.Z()) return Standard_False;

			return Standard_True;
		}

		void RemoveEntitiesFromGeometry();

		Standard_Boolean IsOnLevel
		(
			const frontType& theFront
		) const;

		Standard_Boolean GetFrontEntity();

		Standard_Boolean IsBelongToFront() const;

		Standard_Boolean ChackDistCriteria
		(
			const std::vector<std::shared_ptr<frontType>>& theFronts
		) const;

		Standard_Boolean IsSameLevelFueled();

		Standard_Boolean IsNextLevelFueled();

		Standard_Boolean IsCavityRemoverFueled();

		Standard_Boolean IsNewPointCandidate
		(
			const std::vector<std::shared_ptr<frontType>>& theEffectives
		) const;

		void CalcOptimumCoord();

		void CalcElementSize();

		void CalcLocalFrontRadius();

		void SetDepthSearching();

		void AddOptimumNodeTo(std::vector<std::shared_ptr<nodeType>>& theNodes);

		void SortNodes
		(
			std::vector<std::shared_ptr<nodeType>>& theNodes
		) const;

		void RemoveCurrentFromFront() const;

		void RetrieveEffectiveFronts
		(
			const std::vector<std::shared_ptr<frontType>>& theEntities,
			std::vector<std::shared_ptr<frontType>>& theEffectives
		) const;

		void RetrieveEarlyNodes
		(
			std::vector<std::shared_ptr<nodeType>>& theNodes
		) const;

		void RejectCurrent
		(
			const std::shared_ptr<frontType>& theEntity
		);

		void RegisterElement();

		template<class U = void>
		resolvedType<is_two_dimension<(int)Point::dim>::value, U> RetrieveLocalFrontEntities
		(
			const std::vector<std::shared_ptr<nodeType>>& theNodes,
			std::vector<std::shared_ptr<frontType>>& theEntities
		) const
		{
			Adt_AvlTree<std::shared_ptr<frontType>> compact;
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
			const std::vector<std::shared_ptr<nodeType>>& theNodes,
			std::vector<std::shared_ptr<frontType>>& theEntities
		) const;


		void NodesInRadius
		(
			const Standard_Real theRadius,
			const Point& theCoord,
			const std::vector<std::shared_ptr<nodeType>>& theNodes,
			std::vector<std::shared_ptr<nodeType>>& theInners
		) const;

		Aft_Core_Base()
		{}

		Aft_Core_Base
		(
			const std::shared_ptr<metricMap>& theMetricMap, 
			const std::shared_ptr<OptNodeAlg>& theNodeAlg
		)
			: theMetricMap_(theMetricMap)
			, theNodeCalculator_(theNodeAlg)
		{}

	public:

		Standard_Boolean IsMetricMapLoaded() const
		{
			return (Standard_Boolean)theMetricMap_;
		}

		Standard_Boolean IsNodeCalculatorLoaded() const
		{
			return (Standard_Boolean)theNodeCalculator_;
		}

		void LoadNodeCalculator(const std::shared_ptr<OptNodeAlg>& theAlg)
		{
			theNodeCalculator_ = theAlg;
		}

		void LoadMetricMap(const std::shared_ptr<metricMap>& theMetricMap)
		{
			theMetricMap_ = theMetricMap;
		}
	};
}

#include <Aft_Core_BaseI.hxx>

#endif // !_Aft_Core_Base_Header
