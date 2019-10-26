#pragma once
#ifndef _Mesh_AftMetricPrcsrIso_Header
#define _Mesh_AftMetricPrcsrIso_Header

#include <Mesh_AftMetricPrcsr.hxx>

namespace AutLib
{

	template<class SizeFun, class FrontType>
	class Mesh_AftMetricPrcsrIso_Base
		: public Geo_MetricPrcsr<SizeFun, void>
	{

		/*Private Data*/

	public:

		typedef Geo_MetricPrcsr<SizeFun, void> base;
		typedef FrontType frontType;
		typedef typename SizeFun::ptType Point;

		typedef Entity_Box<Point> box;


		using base::CalcElementSize;
		using base::CalcDistance;
		using base::CalcSquareDistance;

		Mesh_AftMetricPrcsrIso_Base
		(
			const std::shared_ptr<SizeFun>& theSizeFunction
		)
			: Geo_MetricPrcsr<SizeFun, void>(theSizeFunction)
		{}

		Mesh_AftMetricPrcsrIso_Base
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

		Point CalcCentreOf(const frontType& theFront) const;

		box CalcSearchRegion(const Standard_Real theRadius, const Point& theCentre) const;

		box CalcSearchRegion(const Standard_Real theRadius, const Point& theCentre, const frontType& theFront) const;

		box CalcSearchRegion(const Standard_Real theRadius, const frontType& theFront) const;

		box CalcEffectiveFront(const Standard_Real theRadius, const Point& theCentre, const frontType& theFront) const;
	};
}

#include <Mesh_AftMetricPrcsrIsoI.hxx>

#endif // !_Mesh_AftMetricPrcsrIso_Header
