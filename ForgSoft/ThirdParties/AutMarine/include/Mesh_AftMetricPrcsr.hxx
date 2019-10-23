#pragma once
#ifndef _Mesh_AftMetricPrcsr_Header
#define _Mesh_AftMetricPrcsr_Header

#include <Geo_MetricPrcsr.hxx>
#include <Entity_Box.hxx>
#include <Aft2d_EdgeFwd.hxx>
#include <Aft2d_EdgeAnIsoFwd.hxx>
#include <Aft2d_EdgeSurfaceFwd.hxx>
#include <Aft3d_FacetFwd.hxx>
#include <Aft3d_FacetAnIsoFwd.hxx>

namespace AutLib
{

	template<class SizeFun, class MetricFun, class FrontType>
	class Mesh_AftMetricPrcsr
	{

		/*Private Data*/


	};


	template<class SizeFun>
	class Mesh_AftMetricPrcsr<SizeFun, void, Aft2d_Edge>
		: public Geo_MetricPrcsr<SizeFun, void>
	{

		/*Private Data*/

	public:

		typedef Geo_MetricPrcsr<SizeFun, void> base;
		typedef Aft2d_Edge frontType;
		typedef typename SizeFun::ptType Point;

		typedef Entity_Box<Point> box;

		Mesh_AftMetricPrcsr
		(
			const std::shared_ptr<SizeFun>& theSizeFunction
		)
			: Geo_MetricPrcsr<SizeFun, void>(theSizeFunction)
		{}

		Mesh_AftMetricPrcsr
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<SizeFun>& theSizeFunction
		)
			: Geo_MetricPrcsr<SizeFun, void>(theIndex, theName, theSizeFunction)
		{}


		Standard_Real CalcElementSize(const frontType& theFront) const;

		Standard_Real Oriented(const Point& thePt, const frontType& theFront) const;

		Standard_Real CalcDistance(const Point& thePt, const frontType& theFront) const;

		Standard_Real CalcSquareDistance(const Point& thePt, const frontType& theFront) const;

		Point CalcOptimumCoord(const Standard_Real theSize, const frontType& theFront) const;

		Point CalcCentreOf(const frontType& theFront) const;

		box CalcSearchRegion(const Standard_Real theRadius, const Point& theCentre) const;

		box CalcSearchRegion(const Standard_Real theRadius, const Point& theCentre, const frontType& theFront) const;

		box CalcSearchRegion(const Standard_Real theRadius, const frontType& theFront) const;

		box CalcEffectiveFront(const Standard_Real theRadius, const Point& theCentre, const frontType& theFront) const;

	};

	template<class SizeFun, class MetricFun>
	class Mesh_AftMetricPrcsr<SizeFun, MetricFun, Aft2d_EdgeAnIso>
	{

		/*Private Data*/

	public:

		typedef Geo_MetricPrcsr<SizeFun, MetricFun> base;
		typedef Aft2d_Edge frontType;
		typedef typename SizeFun::ptType Point;

		Mesh_AftMetricPrcsr
		(
			const std::shared_ptr<SizeFun>& theSizeFunction,
			const std::shared_ptr<MetricFun>& theMetricFunction
		)
			: Geo_MetricPrcsr<SizeFun, MetricFun>(theSizeFunction, theMetricFunction)
		{}

		Mesh_AftMetricPrcsr
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<SizeFun>& theSizeFunction,
			const std::shared_ptr<MetricFun>& theMetricFunction
		)
			: Geo_MetricPrcsr<SizeFun, MetricFun>(theIndex, theName, theSizeFunction, theMetricFunction)
		{}

		Standard_Real CalcElementSize(const frontType& theFront) const;

		Standard_Real Oriented(const Point& thePt, const frontType& theFront) const;

		Standard_Real CalcDistance(const Point& thePt, const frontType& theFront) const;

		Standard_Real CalcSquareDistance(const Point& thePt, const frontType& theFront) const;

		Point CalcOptimumCoord(const Standard_Real theSize, const frontType& theFront) const;
	};


	template<class SizeFun, class MetricFun>
	class Mesh_AftMetricPrcsr<SizeFun, MetricFun, Aft2d_EdgeSurface>
	{

		/*Private Data*/

	public:

		typedef Geo_MetricPrcsr<SizeFun, MetricFun> base;
		typedef Aft2d_Edge frontType;
		typedef typename SizeFun::ptType Point;

		Mesh_AftMetricPrcsr
		(
			const std::shared_ptr<SizeFun>& theSizeFunction,
			const std::shared_ptr<MetricFun>& theMetricFunction
		)
			: Geo_MetricPrcsr<SizeFun, MetricFun>(theSizeFunction, theMetricFunction)
		{}

		Mesh_AftMetricPrcsr
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<SizeFun>& theSizeFunction,
			const std::shared_ptr<MetricFun>& theMetricFunction
		)
			: Geo_MetricPrcsr<SizeFun, MetricFun>(theIndex, theName, theSizeFunction, theMetricFunction)
		{}

		Standard_Real CalcElementSize(const frontType& theFront) const;

		Standard_Real Oriented(const Point& thePt, const frontType& theFront) const;

		Standard_Real CalcDistance(const Point& thePt, const frontType& theFront) const;

		Standard_Real CalcSquareDistance(const Point& thePt, const frontType& theFront) const;

		Point CalcOptimumCoord(const Standard_Real theSize, const frontType& theFront) const;
	};
}

#include <Mesh_AftMetricPrcsrI.hxx>

#endif // !_Mesh_AftMetricPrcsr_Header
