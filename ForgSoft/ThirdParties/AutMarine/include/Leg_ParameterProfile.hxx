#pragma once
#ifndef _Leg_ParameterProfile_Header
#define _Leg_ParameterProfile_Header

#include <Standard_Handle.hxx>

class Geom2d_Curve;

#include <vector>

namespace AutLib
{

	typedef Handle(Geom2d_Curve) Leg_ParameterProfile;
	typedef std::vector<Leg_ParameterProfile> Leg_ParameterProfileList;

}

#endif // !_Leg_ParameterProfile_Header
