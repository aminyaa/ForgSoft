#pragma once
#ifndef _Mesh_Facet_Header
#define _Mesh_Facet_Header

#include <Mesh_Element.hxx>

namespace AutLib
{

	template<class FacetTraits>
	using Mesh_Facet = Mesh_Element<FacetTraits, Mesh_ElementType_Triangle3D>;
}

#endif // !_Mesh_Facet_Header