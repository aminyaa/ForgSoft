#pragma once
#ifndef _Aft2d_PlnBoundary_InfoFwd_Header
#define _Aft2d_PlnBoundary_InfoFwd_Header

namespace AutLib
{

	// Forward Declarations
	template<class MetricPrcsrInfo>
	class Aft_PlnBoundary_Info;

	class Numeric_AdaptIntegrationInfo;

	typedef Aft_PlnBoundary_Info<Numeric_AdaptIntegrationInfo>
		Aft2d_PlnBoundary_Info;
}

#endif // !_Aft2d_PlnBoundary_InfoFwd_Header
