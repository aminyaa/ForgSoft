#pragma once
#ifndef _Mesh_SizeMap_Header
#define _Mesh_SizeMap_Header

#include <Global_Done.hxx>
#include <Entity_Box.hxx>
#include <Mesh_SizeMapTraits.hxx>

#include <memory>

namespace AutLib
{

	template<class FrontType>
	class Mesh_SizeMap
		: public Global_Done
	{

		/*Private Data*/

	public:

		typedef typename remove_shield<FrontType>::type frontType;
		typedef typename size_map_traits<frontType>::ptType Point;
		typedef typename size_map_traits<frontType>::vtType Vector;

		typedef Point ptType;

		Mesh_SizeMap()
		{}

		virtual const Entity_Box<Point>& BoundingBox() const = 0;

		virtual Standard_Real DimSize() const = 0;

		virtual Standard_Real BaseElementSize() const = 0;

		virtual Standard_Real CalcElementSize
		(
			const Point&
		) const = 0;

		virtual Standard_Real CalcElementSize
		(
			const frontType&
		) const = 0;

		virtual Standard_Real Oriented
		(
			const Point&,
			const frontType&
		) const = 0;

		virtual Standard_Real CalcDistance
		(
			const Point&,
			const Point&
		) const = 0;

		virtual Standard_Real CalcSquareDistance
		(
			const Point&,
			const Point&
		) const = 0;

		virtual Standard_Real CalcDistance
		(
			const Point&,
			const frontType&
		) const = 0;

		virtual Standard_Real CalcSquareDistance
		(
			const Point&,
			const frontType&
		) const = 0;

		virtual Standard_Real CalcUnitDistance
		(
			const Point&,
			const Point&
		) const = 0;

		virtual Point CalcOptimumCoord
		(
			const Standard_Real theSize,
			const frontType&
		) const = 0;

		/*virtual Point CalcCentreOf
		(
			const frontType&
		) const = 0;

		virtual Entity_Box<Point> CalcSearchRegion
		(
			const Standard_Real theRadius,
			const Point& theCentre
		) const = 0;

		virtual Entity_Box<Point> CalcSearchRegion
		(
			const Standard_Real theRadius,
			const Point& theCentre,
			const frontType&
		) const = 0;*/

		virtual void Make() = 0;

		virtual Standard_Real Integrand
		(
			const Point& thePoint,
			const Point& theVector
		) const = 0;

		virtual Standard_Real Integrand
		(
			const Point& thePoint,
			const Vector& theVector
		) const = 0;

		virtual Standard_Real IntegrandPerSize
		(
			const Point& thePoint,
			const Point& theVector
		) const = 0;

		virtual Standard_Real IntegrandPerSize
		(
			const Point& thePoint,
			const Vector& theVector
		) const = 0;
	};
}

#endif // !_Mesh_SizeMap_Header
