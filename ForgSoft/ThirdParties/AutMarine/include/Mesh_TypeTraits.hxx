#pragma once
#ifndef _Mesh_TypeTraits_Header
#define _Mesh_TypeTraits_Header

#include <Traits.hxx>
#include <Aft2d_NodeFwd.hxx>
#include <Aft2d_EdgeFwd.hxx>
#include <Aft2d_ElementFwd.hxx>
#include <Aft2d_NodeAnIsoFwd.hxx>
#include <Aft2d_EdgeAnIsoFwd.hxx>
#include <Aft2d_ElementAnIsoFwd.hxx>
#include <Aft2d_NodeSurfaceFwd.hxx>
#include <Aft2d_EdgeSurfaceFwd.hxx>
#include <Aft2d_ElementSurfaceFwd.hxx>
#include <Aft3d_FacetFwd.hxx>
#include <Aft3d_EdgeFwd.hxx>
#include <Aft3d_NodeFwd.hxx>

#include <Mesh2d_ElementFwd.hxx>


namespace AutLib
{

	// Forward Declarations
	/*template<class FacetTraits, class FacetAdaptor>
	class Mesh_Facet;*/

	struct Aft2d_ElementAnIsoTraits;
	class Aft2d_ElementAnIsoAdaptor;

	struct Aft2d_ElementSurfaceTraits;
	class Aft2d_ElementSurfaceAdaptor;

	class Aft2d_PoleNode;
	class Aft2d_LineNode;
	class Mesh2d_Edge;
	class Mesh2d_Node;

	template<class T, int Rank, int Dim> struct is_validType : std::false_type {};


	template<> struct is_validType<Aft2d_Node, 0, 2> : std::true_type {};
	template<> struct is_validType<Aft2d_Edge, 1, 2> : std::true_type {};
	template<> struct is_validType<Aft2d_Element, 2, 2> : std::true_type {};

	template<class T, int Rank> struct sub_type {};
	template<> struct sub_type<Aft2d_Node, 0> { typedef Aft2d_Node type; };
	template<> struct sub_type<Aft2d_Edge, 0> { typedef Aft2d_Node type; };
	template<> struct sub_type<Aft2d_Edge, 1> { typedef Aft2d_Edge type; };
	template<> struct sub_type<Aft2d_Element, 0> { typedef Aft2d_Node type; };
	template<> struct sub_type<Aft2d_Element, 1> { typedef Aft2d_Edge type; };
	template<> struct sub_type<Aft2d_Element, 2> { typedef Aft2d_Element type; };

	template<> struct sub_type<Mesh2d_Element, 0> { typedef Mesh2d_Node type; };
	template<> struct sub_type<Mesh2d_Element, 1> { typedef Mesh2d_Edge type; };
	template<> struct sub_type<Mesh2d_Element, 2> { typedef Mesh2d_Element type; };

	template<> struct sub_type<Aft3d_Facet, 0> { typedef Aft3d_Node type; };
	template<> struct sub_type<Aft3d_Facet, 1> { typedef Aft3d_Edge type; };
	template<> struct sub_type<Aft3d_Facet, 2> { typedef Aft3d_Facet type; };

	template<> struct sub_type<Aft2d_NodeAnIso, 0> { typedef Aft2d_NodeAnIso type; };
	template<> struct sub_type<Aft2d_EdgeAnIso, 0> { typedef Aft2d_NodeAnIso type; };
	template<> struct sub_type<Aft2d_EdgeAnIso, 1> { typedef Aft2d_EdgeAnIso type; };
	template<> struct sub_type<Aft2d_ElementAnIso, 0> { typedef Aft2d_NodeAnIso type; };
	template<> struct sub_type<Aft2d_ElementAnIso, 1> { typedef Aft2d_EdgeAnIso type; };
	template<> struct sub_type<Aft2d_ElementAnIso, 2> { typedef Aft2d_ElementAnIso type; };

	template<> struct sub_type<Aft2d_NodeSurface, 0> { typedef Aft2d_NodeSurface type; };
	template<> struct sub_type<Aft2d_EdgeSurface, 0> { typedef Aft2d_NodeSurface type; };
	template<> struct sub_type<Aft2d_EdgeSurface, 1> { typedef Aft2d_EdgeSurface type; };
	template<> struct sub_type<Aft2d_ElementSurface, 0> { typedef Aft2d_NodeSurface type; };
	template<> struct sub_type<Aft2d_ElementSurface, 1> { typedef Aft2d_EdgeSurface type; };
	template<> struct sub_type<Aft2d_ElementSurface, 2> { typedef Aft2d_ElementSurface type; };

	/*template<> struct sub_type<Mesh_Facet<Aft2d_ElementAnIsoTraits, Aft2d_ElementAnIsoAdaptor>, 0> { typedef Aft2d_NodeAnIso type; };
	template<> struct sub_type<Mesh_Facet<Aft2d_ElementAnIsoTraits, Aft2d_ElementAnIsoAdaptor>, 1> { typedef Aft2d_EdgeAnIso type; };

	template<> struct sub_type<Mesh_Facet<Aft2d_ElementSurfaceTraits, Aft2d_ElementSurfaceAdaptor>, 0> { typedef Aft2d_NodeSurface type; };
	template<> struct sub_type<Mesh_Facet<Aft2d_ElementSurfaceTraits, Aft2d_ElementSurfaceAdaptor>, 1> { typedef Aft2d_EdgeSurface type; };*/

	template<class T, int Rank> struct has_subType : std::false_type {};

	template<> struct has_subType<Aft2d_Node, 0> : std::true_type {};
	template<> struct has_subType<Aft2d_Edge, 0> : std::true_type {};
	template<> struct has_subType<Aft2d_Edge, 1> : std::true_type {};
	template<> struct has_subType<Aft2d_Element, 0> : std::true_type {};
	template<> struct has_subType<Aft2d_Element, 1> : std::true_type {};
	template<> struct has_subType<Aft2d_Element, 2> : std::true_type {};

	template<class T1, class T2> struct same_type : std::false_type {};

	template<> struct same_type<Aft2d_PoleNode, Aft2d_PoleNode> : std::true_type {};
	template<> struct same_type<Aft2d_LineNode, Aft2d_LineNode> : std::true_type {};

	template<class T> struct is_isoType : std::false_type {};
	template<> struct is_isoType<Aft2d_Node> : std::true_type {};
	template<> struct is_isoType<Aft2d_Edge> : std::true_type {};
	template<> struct is_isoType<Aft2d_Element> : std::true_type {};

	template<class T> struct is_anisoType : std::false_type {};
	template<> struct is_anisoType<Aft2d_NodeAnIso> : std::true_type {};
	template<> struct is_anisoType<Aft2d_EdgeAnIso> : std::true_type {};
	template<> struct is_anisoType<Aft2d_ElementAnIso> : std::true_type {};
	template<> struct is_anisoType<Aft2d_NodeSurface> : std::true_type {};
	template<> struct is_anisoType<Aft2d_EdgeSurface> : std::true_type {};
	template<> struct is_anisoType<Aft2d_ElementSurface> : std::true_type {};

	template<bool COND> struct is_true : std::false_type {};
	template<> struct is_true<true> : std::true_type {};

	template<bool COND> struct is_false : std::false_type {};
	template<> struct is_false<false> : std::true_type {};

}

#endif // !_Mesh_TypeTraits_Header