#pragma once
#ifndef _Aft2d_gCornerLineNodeFwd_Header
#define _Aft2d_gCornerLineNodeFwd_Header

#include <Aft2d_gCornerNodeFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class BndNodeType>
	class Aft2d_LineNodeTemplate;

	typedef Aft2d_LineNodeTemplate<Aft2d_gCornerNode>
		Aft2d_gCornerLineNode;
}

#endif // !_Aft2d_gCornerLineNodeFwd_Header
