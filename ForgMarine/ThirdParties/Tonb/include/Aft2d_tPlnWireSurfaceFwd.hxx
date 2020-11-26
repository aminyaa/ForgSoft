#pragma once
#ifndef _Aft2d_tPlnWireSurfaceFwd_Header
#define _Aft2d_tPlnWireSurfaceFwd_Header

#include <Aft2d_tPlnCurveSurfaceFwd.hxx>

namespace tnbLib
{
	// Forward Declarations
	template<class PlnCurve>
	class Mesh_PlnWire;

	typedef Mesh_PlnWire<Aft2d_tPlnCurveSurface>
		Aft2d_tPlnWireSurface;
}

#endif // !_Aft2d_tPlnWireSurfaceFwd_Header