#pragma once
#ifndef _Aft2d_gPlnWireSurface_Header
#define _Aft2d_gPlnWireSurface_Header

#include <Aft2d_gPlnCurveSurfaceFwd.hxx>
#include <Mesh_PlnWire.hxx>

namespace AutLib
{
	typedef Mesh_PlnWire<Aft2d_gPlnCurveSurface>
		Aft2d_gPlnWireSurface;
}

#endif // !_Aft2d_gPlnWireSurface_Header
