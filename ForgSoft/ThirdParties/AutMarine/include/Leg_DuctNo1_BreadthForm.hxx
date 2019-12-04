#pragma once
#ifndef _Leg_DuctNo1_BreadthForm_Header
#define _Leg_DuctNo1_BreadthForm_Header

#include <Leg_Model_InterpTwoSegmentNo1.hxx>

namespace AutLib
{

	class Leg_DuctNo1_BreadthForm
		: public Leg_Model_InterpTwoSegmentNo1
	{

		/*Private Data*/


		void Defaults();

	public:

		Leg_DuctNo1_BreadthForm();
	};
}

#endif // !_Leg_DuctNo1_BreadthForm_Header
