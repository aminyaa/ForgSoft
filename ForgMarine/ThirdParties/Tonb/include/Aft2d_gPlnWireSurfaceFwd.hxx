#pragma once
#ifndef _Aft2d_gPlnWireSurfaceFwd_Header
#define _Aft2d_gPlnWireSurfaceFwd_Header

#include <Aft2d_gPlnCurveSurfaceFwd.hxx>

namespace tnbLib
{
	// Forward Declarations
	template<class PlnCurve>
	class Mesh_PlnWire;

	typedef Mesh_PlnWire<Aft2d_gPlnCurveSurface>
		Aft2d_gPlnWireSurface;
}

#endif // !_Aft2d_gPlnWireSurfaceFwd_Header