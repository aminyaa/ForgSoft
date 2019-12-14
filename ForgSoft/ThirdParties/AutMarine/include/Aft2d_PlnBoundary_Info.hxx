#pragma once
#ifndef _Aft2d_PlnBoundary_Info_Header
#define _Aft2d_PlnBoundary_Info_Header

#include <Aft_PlnBoundary_Info.hxx>

namespace AutLib
{

	// Forward Declarations
	class Aft_MetricPrcsr_Info;

	typedef Aft_PlnBoundary_Info<Aft_MetricPrcsr_Info>
		Aft2d_PlnBoundary_Info;
}

#endif // !_Aft2d_PlnBoundary_Info_Header
