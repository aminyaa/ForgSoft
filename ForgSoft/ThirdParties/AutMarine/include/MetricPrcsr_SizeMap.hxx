#pragma once
#ifndef _MetricPrcsr_SizeMap_Header
#define _MetricPrcsr_SizeMap_Header

#include <MetricPrcsr_SizeMapBase.hxx>
#include <Cad_CascadeTraits.hxx>
#include <Entity2d_Box.hxx>
#include <Entity3d_Box.hxx>

namespace AutLib
{

	template<class Point>
	class MetricPrcsr_SizeMap
		: public Global_Indexed
		, public Global_Named
		, public Global_Done
	{

		/*Private Data*/

		Entity_Box<Point> theBoundingBox_;

	protected:

		MetricPrcsr_SizeMap()
		{}

		MetricPrcsr_SizeMap(const Entity_Box<Point>& theBox)
			: theBoundingBox_(theBox)
		{}

		Entity_Box<Point>& ChangeBoundingBox()
		{
			return theBoundingBox_;
		}

	public:

		typedef Entity_Box<Point> boxType;
		typedef Point ptType;
		typedef typename cascadeLib::vec_type_from_point<Point>::vcType vcType;

		const Entity_Box<Point>& BoundingBox() const
		{
			return theBoundingBox_;
		}

		Standard_Real DimSize() const
		{
			return theBoundingBox_.Diameter();
		}

		virtual Standard_Real CalcElementSize(const Point& thePoint) const = 0;

		virtual Standard_Real CalcDistance(const Point& theP0, const Point& theP1) const = 0;

		virtual Standard_Real CalcSquareDistance(const Point& theP0, const Point& theP1) const = 0;

		virtual Standard_Real CalcUnitDistance(const Point& theP0, const Point& theP1) const = 0;

		virtual Standard_Real Integrand(const Point& thePoint, const Point& theVector) const = 0;

		virtual Standard_Real Integrand(const point& thePoint, const vcType& theVcetor) const = 0;

		virtual Standard_Real IntegrandPerSize(const Point& thePoint, const Point& theVector) const = 0;

		virtual Standard_Real IntegrandPerSize(const point& thePoint, const vcType& theVcetor) const = 0;

		virtual void Make() const = 0;
	};
}

#endif // !_MetricPrcsr_SizeMap_Header
