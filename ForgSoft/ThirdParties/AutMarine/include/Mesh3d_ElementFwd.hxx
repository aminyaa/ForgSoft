#pragma once
#ifndef _Mesh3d_ElementFwd_Header
#define _Mesh3d_ElementFwd_Header

#include <Mesh_ElementType.hxx>

namespace AutLib
{

	// Forward Declarations

	struct Mesh3d_ElementTraits;

	template<class ElementTraits, Mesh_ElementType ElmType = Mesh_ElementType_Tetrahedron>
	class Mesh_Element;

	typedef Mesh_Element<Mesh3d_ElementTraits, Mesh_ElementType_Tetrahedron>
		Mesh3d_Element;
}

#endif // !_Mesh3d_ElementFwd_Header
