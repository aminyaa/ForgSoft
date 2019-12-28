#pragma once
#ifndef _Aft2d_tSegmentPoleNodeFwd_Header
#define _Aft2d_tSegmentPoleNodeFwd_Header

#include <Aft2d_tSegmentNodeFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class BndNodeType>
	class Aft2d_PoleNodeTemplate;

	typedef Aft2d_PoleNodeTemplate<Aft2d_tSegmentNode>
		Aft2d_tSegmentPoleNode;
}

#endif // !_Aft2d_tSegmentPoleNodeFwd_Header
