#pragma once
#ifndef _Leg_DuctNo1_DepthForm_Header
#define _Leg_DuctNo1_DepthForm_Header

#include <Leg_Model_InterpTwoSegmentNo1.hxx>

namespace AutLib
{

	class Leg_DuctNo1_DepthForm
		: public Leg_Model_InterpTwoSegmentNo1
	{

		/*Private Data*/

		void Defaults();

	public:

		Leg_DuctNo1_DepthForm();
	};
}

#endif // !_Leg_DuctNo1_DepthForm_Header
