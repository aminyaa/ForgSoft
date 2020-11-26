#pragma once
#ifndef _Aft2d_ElementFwd_Header
#define _Aft2d_ElementFwd_Header

#include <Aft_ElementFwd.hxx>

namespace tnbLib
{

	// Forward Declarations

	struct Aft2d_ElementTraits;

	typedef Aft_Element
		<
		Aft2d_ElementTraits,
		Mesh_ElementType_Triangle2D
		>
		Aft2d_Element;
}

#endif // !_Aft2d_ElementFwd_Header