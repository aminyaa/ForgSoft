#pragma once
#ifndef _Mesh2d_PlnWireFwd_Header
#define _Mesh2d_PlnWireFwd_Header

#include <Mesh2d_PlnCurveFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class PlnCurve>
	class Mesh_PlnWire;

	typedef Mesh_PlnWire<Mesh2d_PlnCurve>
		Mesh2d_PlnWire;
}

#endif // !_Mesh2d_PlnWireFwd_Header
