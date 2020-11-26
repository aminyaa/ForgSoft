#pragma once
#ifndef _Aft2d_PlnRegion_Header
#define _Aft2d_PlnRegion_Header

#include <Mesh_PlnRegion.hxx>
#include <Aft2d_PlnCurveFwd.hxx>
#include <Aft2d_PlnWireFwd.hxx>

namespace tnbLib
{

	// Forward Declarations
	class Pln_Curve;

	typedef Mesh_PlnRegion<Pln_Curve, Geo2d_SizeFunction>
		Aft2d_PlnRegion;
}

#endif // !_Aft2d_PlnRegion_header