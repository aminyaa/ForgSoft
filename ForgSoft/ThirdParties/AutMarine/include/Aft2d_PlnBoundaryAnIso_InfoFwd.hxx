#pragma once
#ifndef _Aft2d_PlnBoundaryAnIso_InfoFwd_Header
#define _Aft2d_PlnBoundaryAnIso_InfoFwd_Header

namespace AutLib
{

	// Forward Declarations
	template<class MetricPrcsrInfo>
	class Aft_PlnBoundary_Info;

	class Aft_MetricPrcsrAnIso_Info;

	typedef Aft_PlnBoundary_Info<Aft_MetricPrcsrAnIso_Info>
		Aft2d_PlnBoundaryAnIso_Info;
}

#endif // !_Aft2d_PlnBoundaryAnIso_InfoFwd_Header
