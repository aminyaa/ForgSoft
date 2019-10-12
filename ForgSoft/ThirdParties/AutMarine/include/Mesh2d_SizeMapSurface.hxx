#pragma once
#ifndef _Mesh2d_SizeMapSurface_Header
#define _Mesh2d_SizeMapSurface_Header

#include <Pnt3d.hxx>
#include <Mesh2d_SizeMap.hxx>
#include <Entity2d_Box.hxx>
#include <Entity2d_Metric1.hxx>
#include <Aft2d_EdgeSurfaceFwd.hxx>

namespace AutLib
{

	struct Mesh2d_SizeMapSurfaceShield
	{};

	template<>
	struct remove_shield<Mesh2d_SizeMapSurfaceShield> { typedef Aft2d_EdgeSurface type; };

	template<>
	class Mesh_SizeMap<Aft2d_EdgeSurface>
		: public std::enable_shared_from_this<Mesh_SizeMap<Aft2d_EdgeSurface>>
		, public Mesh_SizeMap<Mesh2d_SizeMapSurfaceShield>
	{

		/*Private Data*/

	public:

		typedef Entity2d_Metric1 metric;
		typedef Entity2d_Box box;

		Mesh_SizeMap()
		{}

		virtual Point CalcCentreOf
		(
			const Point&,
			const Point&
		) const = 0;

		virtual Point CalcCentreOf
		(
			const frontType&
		) const = 0;

		virtual box CalcSearchRegion
		(
			const Standard_Real theRadius,
			const metric& theMetric,
			const Point& theCentre
		) const = 0;

		virtual box CalcSearchRegion
		(
			const Standard_Real theRadius,
			const Point& theCentre,
			const frontType&
		) const = 0;

		virtual box CalcSearchRegion
		(
			const Standard_Real theRadius,
			const frontType&
		) const = 0;

		virtual box CalcEffectiveRegion
		(
			const Standard_Real theRadius,
			const Point& theCentre,
			const frontType&
		) const = 0;

		virtual metric CalcEffectiveMetric
		(
			const Pnt2d& theP0,
			const Pnt2d& theP1
		) const = 0;

		virtual Pnt3d CalcCoord3D
		(
			const Pnt2d& theCoord
		) const = 0;

		virtual Standard_Real CalcLength3D
		(
			const frontType& theEdge
		) const = 0;

		virtual Standard_Real CalcLength3D
		(
			const Pnt2d& P0,
			const Pnt2d& P1
		) const = 0;

		virtual Standard_Real CalcLength3D
		(
			const Pnt3d& P0,
			const Pnt3d& P1
		) const = 0;
	};

	typedef Mesh_SizeMap<Aft2d_EdgeSurface> Mesh2d_SizeMapSurface;
}

#endif // !_Mesh2d_SizeMapSurface_Header