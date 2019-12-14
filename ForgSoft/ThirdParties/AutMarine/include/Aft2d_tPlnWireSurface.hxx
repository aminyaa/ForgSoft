#pragma once
#ifndef _Aft2d_tPlnWireSurface_Header
#define _Aft2d_tPlnWireSurface_Header

#include <Aft2d_tPlnCurveSurfaceFwd.hxx>
#include <Mesh_PlnWire.hxx>

namespace AutLib
{
	typedef Mesh_PlnWire<Aft2d_tPlnCurveSurface>
		Aft2d_tPlnWireSurface;
}

#endif // !_Aft2d_tPlnWireSurface_Header
