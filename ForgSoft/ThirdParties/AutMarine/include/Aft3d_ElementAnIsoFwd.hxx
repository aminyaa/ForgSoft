#pragma once
#ifndef _Aft3d_ElementAnIsoFwd_Header
#define _Aft3d_ElementAnIsoFwd_Header

#include <Aft_ElementFwd.hxx>

namespace AutLib
{

	// Forward Declarations

	struct Aft3d_ElementAnIsoTraits;

	typedef Aft_Element<Aft3d_ElementAnIsoTraits, Mesh_ElementType_Tetrahedron>
		Aft3d_ElementAnIso;
}

#endif // !_Aft3d_ElementAnIsoFwd_Header