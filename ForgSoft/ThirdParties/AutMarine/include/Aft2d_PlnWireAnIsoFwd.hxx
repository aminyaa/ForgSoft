#pragma once
#ifndef _Aft2d_PlnWireAnIsoFwd_Header
#define _Aft2d_PlnWireAnIsoFwd_Header

#include <Aft2d_PlnCurveAnIsoFwd.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class PlnCurve>
	class Mesh_PlnWire;

	typedef Mesh_PlnWire<Aft2d_PlnCurveAnIso>
		Aft2d_PlnWireAnIso;
}

#endif // !_Aft2d_PlnWireAnIsoFwd_Header
