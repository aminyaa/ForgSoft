#pragma once
#ifndef _Leg_PropNo1_Defaults_Header
#define _Leg_PropNo1_Defaults_Header

#include <Leg_Model_ConstParam.hxx>
#include <Standard_TypeDef.hxx>

namespace AutLib
{

	class Leg_PropNo1_Defaults
	{

		typedef Leg_Model_ConstParam param;

		/*Private Data*/

	public:

		static const Standard_Integer NB_BLADES;
		static const Standard_Integer NB_SECTIONS;
		static const Standard_Integer NB_SPANS;
		
		static const param DIAMETER;
		static const param HUB_RADIUS;

		static const param TIP_GAP;
		static const param TE_GAP;

		static const param HUB_LENGTH;
		static const param HUB_WEIGHT;
		static const param SHAFT_RADIUS;
		static const param SHAFT_OFFSET;
		static const param SHAFT_LENGTH;

		static const param PITCH_ROOT;
		static const param PITCH_TIP;
		static const param PITCH_ROOT_STEEP;
		static const param PITCH_TIP_STEEP;

		static const param SKEW_ROOT_STEEP;
		static const param SKEW_TIP;
		static const param SKEW_TIP_STEEP;

		static const param CHORD_MAX_LOCATION;
		static const param CHORD_ROOT;
		static const param CHORD_MAX;
		static const param CHORD_TIP;
		static const param CHORD_ROOT_WEIGHT;
		static const param CHORD_TIP_WEIGHT;

		static const param CAMBER_MAX_LOCATION;
		static const param CAMBER_ROOT;
		static const param CAMBER_MAX;
		static const param CAMBER_TIP;
		static const param CAMBER_ROOT_WEIGHT;
		static const param CAMBER_TIP_WEIGHT;

		static const param THICK_ROOT;
		static const param THICK_TIP;
		static const param THICK_ROOT_STEEP;
		static const param THICK_TIP_STEEP;

		static const param RAKE;
	};
}

#endif // !_Leg_PropNo1_Defaults_Header
