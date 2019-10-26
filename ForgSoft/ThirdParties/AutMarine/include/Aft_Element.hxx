#pragma once
#ifndef _Aft_Element_Header
#define _Aft_Element_Header

#include <Mesh_Element.hxx>

namespace AutLib
{

	template<class ElementTraits, Mesh_ElementType ElmType = Mesh_ElementType_Tetrahedron>
	using Aft_Element = Mesh_Element<ElementTraits, ElmType>;
}

#endif // !_Aft_Element_Header
