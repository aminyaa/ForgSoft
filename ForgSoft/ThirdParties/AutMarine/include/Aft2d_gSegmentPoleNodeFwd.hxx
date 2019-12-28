#pragma once
#ifndef _Aft2d_gSegmentPoleNodeFwd_Header
#define _Aft2d_gSegmentPoleNodeFwd_Header

#include <Aft2d_gSegmentNodeFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class BndNodeType>
	class Aft2d_PoleNodeTemplate;

	typedef Aft2d_PoleNodeTemplate<Aft2d_gSegmentNode>
		Aft2d_gSegmentPoleNode;
}

#endif // !_Aft2d_gSegmentPoleNodeFwd_Header
