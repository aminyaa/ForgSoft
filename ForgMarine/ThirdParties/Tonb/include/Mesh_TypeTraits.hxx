#pragma once
#ifndef _Mesh_TypeTraits_Header
#define _Mesh_TypeTraits_Header

#include <Traits.hxx>
#include <Mesh2d_NodeFwd.hxx>
#include <Mesh2d_EdgeFwd.hxx>
#include <Mesh2d_ElementFwd.hxx>
#include <Mesh3d_NodeFwd.hxx>
#include <Mesh3d_EdgeFwd.hxx>
#include <Mesh3d_FacetFwd.hxx>
#include <Mesh3d_ElementFwd.hxx>


namespace tnbLib
{

	template<class T, int Rank> struct sub_type {};

	template<> struct sub_type<Mesh2d_Element, 0> { typedef Mesh2d_Node type; };
	template<> struct sub_type<Mesh2d_Element, 1> { typedef Mesh2d_Edge type; };
	template<> struct sub_type<Mesh2d_Element, 2> { typedef Mesh2d_Element type; };

	template<> struct sub_type<Mesh3d_Element, 0> { typedef Mesh3d_Node type; };
	template<> struct sub_type<Mesh3d_Element, 1> { typedef Mesh3d_Edge type; };
	template<> struct sub_type<Mesh3d_Element, 2> { typedef Mesh3d_Facet type; };
	template<> struct sub_type<Mesh3d_Element, 3> { typedef Mesh3d_Element type; };

	template<> struct sub_type<Mesh3d_Facet, 0> { typedef Mesh3d_Node type; };
	template<> struct sub_type<Mesh3d_Facet, 1> { typedef Mesh3d_Edge type; };
	template<> struct sub_type<Mesh3d_Facet, 2> { typedef Mesh3d_Facet type; };
}

#endif // !_Mesh_TypeTraits_Header