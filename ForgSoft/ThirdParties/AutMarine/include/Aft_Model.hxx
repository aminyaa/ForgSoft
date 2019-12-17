#pragma once
#ifndef _Aft_Model_Header
#define _Aft_Model_Header

#include <Entity_Connectivity.hxx>
#include <Entity_StaticData.hxx>
#include <Aft_MetricPrcsr.hxx>
#include <Aft_Core.hxx>
#include <Aft_Model_Traits.hxx>
#include <Aft_Model_Cache.hxx>
#include <Aft_Model_Constants.hxx>

//#include "Aft2d_Core.hxx"
//#include "Aft2d_Element.hxx"
//#include "Geo2d_SizeFunction.hxx"
//#include "Aft2d_Edge.hxx"

namespace AutLib
{

	template<class ModelType, class SizeFun, class MetricFun = void>
	class Aft_Model
		: public Aft_Core
		<
		typename aft_model_traits<ModelType, SizeFun, MetricFun>::nodeCalculator,
		SizeFun,
		typename aft_model_traits<ModelType, SizeFun, MetricFun>::frontInfo,
		typename aft_model_traits<ModelType, SizeFun, MetricFun>::globalData,
		MetricFun
		>
		, public aft_model_traits<ModelType, SizeFun, MetricFun>::cacheType
		, public Aft_Model_Constants
	{

	public:

		typedef Aft_Core
			<
			typename aft_model_traits<ModelType, SizeFun, MetricFun>::nodeCalculator,
			SizeFun,
			typename aft_model_traits<ModelType, SizeFun, MetricFun>::frontInfo,
			typename aft_model_traits<ModelType, SizeFun, MetricFun>::globalData,
			MetricFun
			> base;

		typedef typename aft_model_traits<ModelType, SizeFun, MetricFun>::frontType frontType;
		typedef typename aft_model_traits<ModelType, SizeFun, MetricFun>::elementType elementType;
		typedef typename aft_model_traits<ModelType, SizeFun, MetricFun>::nodeCalculator nodeCalculator;
		typedef typename aft_model_traits<ModelType, SizeFun, MetricFun>::frontInfo frontInfo;
		typedef typename aft_model_traits<ModelType, SizeFun, MetricFun>::globalData frontData;
		typedef typename aft_model_traits<ModelType, SizeFun, MetricFun>::cacheType cache;

		//typedef typename frontInfo::frontType frontType;
		typedef typename frontInfo::nodeType nodeType;
		typedef typename nodeType::ptType Point;

		typedef Entity_StaticData<Point, typename elementType::connectType>
			staticMesh;

		typedef Aft_MetricPrcsr<frontType, SizeFun, MetricFun> metricPrcsr;

	private:

		/*Private Data*/

		//- Boundary size map which may be different with the domain's size map
		std::shared_ptr<metricPrcsr> theBoundaryMap_;

		std::vector<std::shared_ptr<frontType>> theBoundaryEdges_;


		std::shared_ptr<staticMesh> theTriangulation_;


		//- functions and operators

		void Import
		(
			const std::vector<std::shared_ptr<frontType>>& theBoundary,
			const std::shared_ptr<metricPrcsr>& theBoundaryMap
		);

		//- static functions and operators

		static Entity_Box<Point> 
			RetrieveBoundingBox
			(
				const std::vector<std::shared_ptr<nodeType>>& theNodes
			);

		static void CheckBoundary
		(
			const std::vector<std::shared_ptr<frontType>>& theFronts
		);

	protected:

		std::vector<std::shared_ptr<frontType>>& ChangeBoundary()
		{
			return theBoundaryEdges_;
		}

		Standard_Integer Meshing();

		Standard_Boolean CheckAngle
		(
			const frontType& theFront,
			const nodeType& theNode,
			const Standard_Real CosAngle
		) const;

		void MeshingOneLevel();

		void FindValidNode
		(
			const std::vector<std::shared_ptr<nodeType>>& theCandidates,
			const std::vector<std::shared_ptr<frontType>>& theEffectives
		);

		void Update();

		void InsertNewEdgesToLevels();

	public:

		Aft_Model()
		{}

		Standard_Boolean IsBoundaryLoaded() const
		{
			return (Standard_Boolean)theBoundaryEdges_.size();
		}

		Standard_Boolean IsBoundaryMapLoaded() const
		{
			return (Standard_Boolean)theBoundaryMap_;
		}

		Standard_Boolean IsLoaded() const
		{
			if (NOT base::IsMetricMapLoaded()) return Standard_False;
			if (NOT IsBoundaryLoaded()) return Standard_False;
			if (NOT IsBoundaryMapLoaded()) return Standard_False;
			return Standard_True;
		}

		const std::vector<std::shared_ptr<frontType>>& BoundaryEdges() const
		{
			return theBoundaryEdges_;
		}

		const std::shared_ptr<staticMesh>& StaticMesh() const
		{
			return theTriangulation_;
		}

		const std::shared_ptr<metricPrcsr>& BoundaryMap() const
		{
			return theBoundaryMap_;
		}

		void Perform();

		void CreateStaticMesh();

		void CompactNumbering
		(
			const std::vector<std::shared_ptr<elementType>>& theElements
		) const;

		void LoadBoundaryEdges
		(
			const std::vector<std::shared_ptr<frontType>>& theBoundaryEdges
		)
		{
			theBoundaryEdges_ = theBoundaryEdges;
		}

		void LoadBoundaryMetricMap
		(
			const std::shared_ptr<metricPrcsr>& theSizeMap
		)
		{
			theBoundaryMap_ = theSizeMap;
		}

		//- static functions and operators

		static void ActiveFront
		(
			const std::vector<std::shared_ptr<frontType>>& theEdges
		);

		static std::vector<std::shared_ptr<nodeType>>
			RetrieveNodesFrom
			(
				const std::vector<std::shared_ptr<frontType>>& theFronts
			);

		static std::vector<std::shared_ptr<nodeType>> 
			RetrieveNodesFrom
			(
				const std::vector<std::shared_ptr<elementType>>& theElements
			);

		static std::vector<std::shared_ptr<frontType>> 
			RetrieveEdgesFrom
		(
			const std::vector<std::shared_ptr<elementType>>& theElements
		);

		static std::vector<Pnt2d> 
			RetrieveGeometryFrom
			(
				const std::vector<std::shared_ptr<nodeType>>& theNodes
			);

		static std::vector<connectivity::triple> 
			RetrieveGeometryFrom
			(
				const std::vector<std::shared_ptr<elementType>>& theElements, 
				std::map<unsigned, unsigned>& theNodesIndices
			);
	};
}

#include <Aft_ModelI.hxx>

#endif // !_Aft_Model_Header
