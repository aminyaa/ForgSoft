#pragma once
#ifndef _Mesh2d_tPlnWireSurface_Header
#define _Mesh2d_tPlnWireSurface_Header

#include <Mesh2d_tPlnCurveSurfaceFwd.hxx>
#include <Mesh_PlnWire.hxx>

namespace AutLib
{
	typedef Mesh_PlnWire<Mesh2d_tPlnCurveSurface>
		Mesh2d_tPlnWireSurface;
}

#endif // !_Mesh2d_tPlnWireSurface_Header
