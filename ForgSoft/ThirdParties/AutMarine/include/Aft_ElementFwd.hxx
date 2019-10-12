#pragma once
#ifndef _Aft_ElementFwd_Header
#define _Aft_ElementFwd_Header

#include <Mesh_ElementType.hxx>

namespace AutLib
{

	// Forward Declarations

	template<class ElementTraits, Mesh_ElementType ElmType>
	class Mesh_Element;

	template<class ElementTraits, Mesh_ElementType ElmType = Mesh_ElementType_Tetrahedron>
	using Aft_Element = Mesh_Element<ElementTraits, ElmType>;
}

#endif // !_Aft_ElementFwd_Header
