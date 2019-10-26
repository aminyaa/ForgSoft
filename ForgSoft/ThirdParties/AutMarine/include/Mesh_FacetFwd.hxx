#pragma once
#ifndef _Mesh_FacetFwd_Header
#define _Mesh_FacetFwd_Header

#include <Mesh_ElementType.hxx>

namespace AutLib
{

	// Forward Declarations

	template<class ElementTraits, Mesh_ElementType ElmType>
	class Mesh_Element;

	template<class FacetTraits>
	using Mesh_Facet = Mesh_Element<FacetTraits, Mesh_ElementType_Triangle3D>;
}

#endif // !_Mesh_FacetFwd_Header
