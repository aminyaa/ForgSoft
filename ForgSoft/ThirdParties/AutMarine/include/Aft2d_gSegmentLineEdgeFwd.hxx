#pragma once
#ifndef _Aft2d_gSegmentLineEdgeFwd_Header
#define _Aft2d_gSegmentLineEdgeFwd_Header

#include <Aft2d_gSegmentEdge.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class BndEdgeType>
	class Aft2d_LineEdgeTemplate;

	typedef Aft2d_LineEdgeTemplate<Aft2d_gSegmentEdge>
		Aft2d_gSegmentLineEdge;
}

#endif // !_Aft2d_gSegmentLineEdgeFwd_Header
