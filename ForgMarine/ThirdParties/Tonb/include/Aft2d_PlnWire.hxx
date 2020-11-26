#pragma once
#ifndef _Aft2d_PlnWire_Header
#define _Aft2d_PlnWire_Header

#include <Aft2d_PlnCurveFwd.hxx>
#include <Mesh_PlnWire.hxx>

namespace tnbLib
{

	typedef Mesh_PlnWire<Aft2d_PlnCurve>
		Aft2d_PlnWire;
}

#endif // !_Aft2d_PlnWire_Header