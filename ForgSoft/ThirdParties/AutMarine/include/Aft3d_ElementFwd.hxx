#pragma once
#ifndef _Aft3d_ElementFwd_Header
#define _Aft3d_ElementFwd_Header

#include <Aft_ElementFwd.hxx>

namespace AutLib
{

	// Forward Declarations

	struct Aft3d_ElementTraits;

	typedef Aft_Element<Aft3d_ElementTraits, Mesh_ElementType_Tetrahedron>
		Aft3d_Element;
}

#endif // !_Aft3d_ElementFwd_Header