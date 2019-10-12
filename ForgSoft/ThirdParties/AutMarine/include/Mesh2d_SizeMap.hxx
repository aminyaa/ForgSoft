#pragma once
#ifndef _Mesh2d_SizeMap_Header
#define _Mesh2d_SizeMap_Header

#include <Mesh_SizeMap.hxx>
#include <Entity2d_Box.hxx>
#include <Aft2d_EdgeFwd.hxx>

namespace AutLib
{

	struct Mesh2d_SizeMapShield
	{};

	template<>
	struct remove_shield<Mesh2d_SizeMapShield> { typedef Aft2d_Edge type; };

	template<>
	class Mesh_SizeMap<Aft2d_Edge>
		: public Mesh_SizeMap<Mesh2d_SizeMapShield>
		, public std::enable_shared_from_this<Mesh_SizeMap<Aft2d_Edge>>
	{

		/*Private Data*/

	public:

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

	};

	typedef Mesh_SizeMap<Aft2d_Edge> Mesh2d_SizeMap;
}

#endif // !_Mesh2d_SizeMap_Header