#pragma once
#ifndef _Aft2d_ElementAnIso_Header
#define _Aft2d_ElementAnIso_Header

#include <Aft_Element.hxx>
#include <Aft2d_ElementAnIsoTraits.hxx>

namespace AutLib
{

	typedef Aft_Element
		<
		Aft2d_ElementAnIsoTraits, 
		Mesh_ElementType_Triangle2D
		> Aft2d_ElementAnIso;
}

#endif // !_Aft2d_ElementAnIso_Header