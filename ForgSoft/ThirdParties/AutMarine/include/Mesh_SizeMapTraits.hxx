#pragma once
#ifndef _Mesh_SizeMapTraits_Header
#define _Mesh_SizeMapTraits_Header

#include <Pnt2d.hxx>
#include <Pnt3d.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Vec.hxx>
#include <Aft2d_EdgeFwd.hxx>
#include <Aft2d_EdgeAnIsoFwd.hxx>
#include <Aft2d_EdgeSurfaceFwd.hxx>
#include <Aft3d_FacetFwd.hxx>
#include <Aft3d_FacetAnIsoFwd.hxx>

namespace AutLib
{

	template<class T>
	struct remove_shield { typedef T type; };

	template<class FrontType>
	struct size_map_traits {};

	template<>
	struct size_map_traits<Aft2d_Edge>
	{
		typedef Pnt2d ptType;
		typedef gp_Vec2d vtType;
	};

	template<>
	struct size_map_traits<Aft2d_EdgeAnIso>
	{
		typedef Pnt2d ptType;
		typedef gp_Vec2d vtType;
	};

	template<>
	struct size_map_traits<Aft2d_EdgeSurface>
	{
		typedef Pnt2d ptType;
		typedef gp_Vec2d vtType;
	};

	template<>
	struct size_map_traits<Aft3d_Facet>
	{
		typedef Pnt3d ptType;
		typedef gp_Vec vtType;
	};

	template<>
	struct size_map_traits<Aft3d_FacetAnIso>
	{
		typedef Pnt3d ptType;
		typedef gp_Vec vtType;
	};
}

#endif // !_Mesh_SizeMapTraits_Header