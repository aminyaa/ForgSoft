#pragma once
#ifndef _Aft3d_ElementAnIso_Header
#define _Aft3d_ElementAnIso_Header

#include <Aft_Element.hxx>
#include <Aft3d_ElementAnIsoTraits.hxx>

namespace AutLib
{

	typedef Aft_Element
		<
		Aft3d_ElementAnIsoTraits,
		Mesh_ElementType_Tetrahedron
		> Aft3d_ElementAnIso;
}

#endif // !_Aft3d_ElementAnIso_Header