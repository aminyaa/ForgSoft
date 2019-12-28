#pragma once
#ifndef _Aft2d_tCornerPoleNodeFwd_Header
#define _Aft2d_tCornerPoleNodeFwd_Header

#include <Aft2d_tCornerNodeFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class BndNodeType>
	class Aft2d_PoleNodeTemplate;

	typedef Aft2d_PoleNodeTemplate<Aft2d_tCornerNode>
		Aft2d_tCornerPoleNode;
}

#endif // !_Aft2d_tCornerPoleNodeFwd_Header
