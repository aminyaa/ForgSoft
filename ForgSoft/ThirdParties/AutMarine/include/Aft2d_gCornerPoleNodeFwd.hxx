#pragma once
#ifndef _Aft2d_gCornerPoleNodeFwd_Header
#define _Aft2d_gCornerPoleNodeFwd_Header

#include <Aft2d_gCornerNodeFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class BndNodeType>
	class Aft2d_PoleNodeTemplate;

	typedef Aft2d_PoleNodeTemplate<Aft2d_gCornerNode>
		Aft2d_gCornerPoleNode;
}

#endif // !_Aft2d_gCornerPoleNodeFwd_Header
