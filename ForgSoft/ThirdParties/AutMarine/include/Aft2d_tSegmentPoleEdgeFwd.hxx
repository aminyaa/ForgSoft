#pragma once
#ifndef _Aft2d_tSegmentPoleEdgeFwd_Header
#define _Aft2d_tSegmentPoleEdgeFwd_Header

#include <Aft2d_tSegmentEdgeFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class BndEdgeType>
	class Aft2d_PoleEdgeTemplate;

	typedef Aft2d_PoleEdgeTemplate<Aft2d_tSegmentEdge>
		Aft2d_tSegmentPoleEdge;
}

#endif // !_Aft2d_tSegmentPoleEdgeFwd_Header
