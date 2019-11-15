#pragma once
#ifndef _Leg_Prop_BladeSection_Header
#define _Leg_Prop_BladeSection_Header

#include <Leg_ParameterProfile.hxx>
#include <Global_AccessMethod.hxx>

namespace AutLib
{

	class Leg_Prop_BladeSection
	{

		/*Private Data*/

		Leg_ParameterProfile theFace_;
		Leg_ParameterProfile theBack_;

	public:

		Leg_Prop_BladeSection()
		{}

		//- Macros

		GLOBAL_ACCESS_SINGLE(Leg_ParameterProfile, Face)
			GLOBAL_ACCESS_SINGLE(Leg_ParameterProfile, Back)
	};
}

#endif // !_Leg_Prop_BladeSection_Header
