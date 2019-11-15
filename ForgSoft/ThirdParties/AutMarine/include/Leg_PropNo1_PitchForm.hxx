#pragma once
#ifndef _Leg_PropNo1_PitchForm_Header
#define _Leg_PropNo1_PitchForm_Header

#include <Global_AccessMethod.hxx>
#include <Leg_PropNo1_Form.hxx>
#include <Leg_Model_Parameter.hxx>

#include <memory>

namespace AutLib
{

	class Leg_PropNo1_PitchForm
		: public Leg_PropNo1_Form
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> theRootPitch_;
		std::shared_ptr<parameter> theRootSteep_;
		std::shared_ptr<parameter> theTipPitch_;
		std::shared_ptr<parameter> theTipSteep_;

	protected:

		void Defaults();

	public:

		Leg_PropNo1_PitchForm();

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, RootPitch)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, RootSteep)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, TipPitch)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, TipSteep)
	};
}

#endif // !_Leg_PropNo1_PitchForm_Header
