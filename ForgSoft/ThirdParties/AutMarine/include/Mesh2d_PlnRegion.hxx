#pragma once
#ifndef _Mesh2d_PlnRegion_Header
#define _Mesh2d_PlnRegion_Header

#include <Mesh_PlnRegion.hxx>
#include <Mesh2d_PlnCurveFwd.hxx>
#include <Mesh2d_PlnWireFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	class Pln_Curve;

	typedef Mesh_PlnRegion<Pln_Curve, Geo2d_SizeFunction>
		Mesh2d_PlnRegion;
}

#endif // !_Mesh2d_PlnRegion_header
