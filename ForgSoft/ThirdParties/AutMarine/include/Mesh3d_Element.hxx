#pragma once
#ifndef _Mesh3d_Element_Header
#define _Mesh3d_Element_Header

#include <Mesh_Element.hxx>
#include <Mesh3d_ElementTraits.hxx>

namespace AutLib
{

	typedef Mesh_Element<Mesh3d_ElementTraits, Mesh_ElementType_Tetrahedron> Mesh3d_Element;
}

#endif // !_Mesh3d_Element_Header
