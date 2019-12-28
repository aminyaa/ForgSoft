#pragma once
#ifndef _Aft2d_PlnBoundaryAnIso_Info_Header
#define _Aft2d_PlnBoundaryAnIso_Info_Header

#include <Aft_PlnBoundary_Info.hxx>

namespace AutLib
{

	// Forward Declarations
	class Mesh_CurveInfo;
	class Aft_MetricPrcsrAnIso_Info;

	typedef Aft_PlnBoundary_Info<Aft_MetricPrcsrAnIso_Info>
		Aft2d_PlnBoundaryAnIso_Info;
}

#endif // !_Aft2d_PlnBoundaryAnIso_Info_Header
