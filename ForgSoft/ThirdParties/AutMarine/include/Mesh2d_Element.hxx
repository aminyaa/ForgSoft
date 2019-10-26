#pragma once
#ifndef _Mesh2d_Element_Header
#define _Mesh2d_Element_Header

#include <Mesh_Element.hxx>
#include <Mesh2d_ElementTraits.hxx>

namespace AutLib
{

	typedef Mesh_Element<Mesh2d_ElementTraits, Mesh_ElementType_Triangle2D> Mesh2d_Element;
}

#endif // !_Mesh2d_Element_Header
