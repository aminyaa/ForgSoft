#pragma once
#ifndef _Aft2d_PlnBoundary_InfoFwd_Header
#define _Aft2d_PlnBoundary_InfoFwd_Header

namespace AutLib
{

	// Forward Declarations
	template<class MetricPrcsrInfo>
	class Aft_PlnBoundary_Info;

	class Aft_MetricPrcsr_Info;

	typedef Aft_PlnBoundary_Info<Aft_MetricPrcsr_Info>
		Aft2d_PlnBoundary_Info;
}

#endif // !_Aft2d_PlnBoundary_InfoFwd_Header
