#pragma once
#ifndef _Aft2d_PlnBoundary_Info_Header
#define _Aft2d_PlnBoundary_Info_Header

#include <Aft_PlnBoundary_Info.hxx>

namespace AutLib
{

	// Forward Declarations
	class Numeric_AdaptIntegrationInfo;

	typedef Aft_PlnBoundary_Info<Numeric_AdaptIntegrationInfo>
		Aft2d_PlnBoundary_Info;
}

#endif // !_Aft2d_PlnBoundary_Info_Header
