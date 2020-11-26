#pragma once
#ifndef _Aft2d_PlnWireFwd_Header
#define _Aft2d_PlnWireFwd_Header

#include <Aft2d_PlnCurveFwd.hxx>

namespace tnbLib
{

	// Forward Declarations
	template<class PlnCurve>
	class Mesh_PlnWire;

	typedef Mesh_PlnWire<Aft2d_PlnCurve>
		Aft2d_PlnWire;
}

#endif // !_Aft2d_PlnWireFwd_Header