#pragma once
#ifndef _Mesh2d_SizeMapAnIso_Header
#define _Mesh2d_SizeMapAnIso_Header

#include <Mesh_SizeMap.hxx>
#include <Entity2d_Box.hxx>
#include <Entity2d_Metric1.hxx>
#include <Aft2d_EdgeAnIsoFwd.hxx>

namespace AutLib
{

	struct Mesh2d_SizeMapAnIsoShield
	{};

	template<>
	struct remove_shield<Mesh2d_SizeMapAnIsoShield> { typedef Aft2d_EdgeAnIso type; };

	template<>
	class Mesh_SizeMap<Aft2d_EdgeAnIso>
		: public std::enable_shared_from_this<Mesh_SizeMap<Aft2d_EdgeAnIso>>
		, public Mesh_SizeMap<Mesh2d_SizeMapAnIsoShield>
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
	};

	typedef Mesh_SizeMap<Aft2d_EdgeAnIso> Mesh2d_SizeMapAnIso;
}

#endif // !_Mesh2d_SizeMapAnIso_Header