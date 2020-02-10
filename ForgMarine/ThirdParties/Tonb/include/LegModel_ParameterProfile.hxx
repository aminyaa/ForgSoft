#pragma once
#ifndef _LegModel_ParameterProfile_Header
#define _LegModel_ParameterProfile_Header

#include <Standard_Handle.hxx>

class Geom2d_Curve;

#include <vector>

namespace tnbLib
{

	typedef Handle(Geom2d_Curve) LegModel_ParameterProfile;
	typedef std::vector<LegModel_ParameterProfile> Leg_ParameterProfileList;
}

#endif // !_LegModel_ParameterProfile_Header
