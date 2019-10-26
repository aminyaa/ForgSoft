#pragma once
#ifndef _Aft2d_ElementAnIsoFwd_Header
#define _Aft2d_ElementAnIsoFwd_Header

#include <Aft_ElementFwd.hxx>

namespace AutLib
{

	// Forward Declarations

	struct Aft2d_ElementAnIsoTraits;

	typedef Aft_Element<Aft2d_ElementAnIsoTraits, Mesh_ElementType_Triangle2D>
		Aft2d_ElementAnIso;
}

#endif // !_Aft2d_ElementAnIsoFwd_Header
