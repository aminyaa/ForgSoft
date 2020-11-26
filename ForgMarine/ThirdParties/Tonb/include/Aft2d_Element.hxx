#pragma once
#ifndef _Aft2d_Element_Header
#define _Aft2d_Element_Header

#include <Aft_Element.hxx>
#include <Aft2d_ElementTraits.hxx>

namespace tnbLib
{

	typedef Aft_Element
		<
		Aft2d_ElementTraits,
		Mesh_ElementType_Triangle2D
		> Aft2d_Element;
}

#endif // !_Aft2d_Element_Header