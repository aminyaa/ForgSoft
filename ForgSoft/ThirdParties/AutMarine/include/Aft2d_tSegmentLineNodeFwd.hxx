#pragma once
#ifndef _Aft2d_tSegmentLineNodeFwd_Header
#define _Aft2d_tSegmentLineNodeFwd_Header

#include <Aft2d_tSegmentNode.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class BndNodeType>
	class Aft2d_LineNodeTemplate;

	typedef Aft2d_LineNodeTemplate<Aft2d_tSegmentNode>
		Aft2d_tSegmentLineNode;
}

#endif // !_Aft2d_tSegmentLineNodeFwd_Header
