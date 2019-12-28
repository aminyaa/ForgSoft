#pragma once
#ifndef _Aft3d_Element_Header
#define _Aft3d_Element_Header

#include <Aft_Element.hxx>
#include <Aft3d_ElementTraits.hxx>

namespace AutLib
{

	typedef Aft_Element
		<
		Aft3d_ElementTraits, 
		Mesh_ElementType_Tetrahedron
		> Aft3d_Element;
}

#endif // !_Aft3d_Element_Header