#pragma once
#ifndef _Leg_PropNo1_SkewForm_Header
#define _Leg_PropNo1_SkewForm_Header

#include <Global_AccessMethod.hxx>
#include <Leg_PropNo1_Form.hxx>
#include <Leg_Model_Parameter.hxx>

#include <memory>

namespace AutLib
{

	class Leg_PropNo1_SkewForm
		: public Leg_PropNo1_Form
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> theTipSkew_;
		std::shared_ptr<parameter> theTipSteep_;
		std::shared_ptr<parameter> theRootSteep_;

	protected:

		void Defaults();

	public:

		Leg_PropNo1_SkewForm();

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, TipSkew)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, TipSteep)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, RootSteep)
	};
}

#endif // !_Leg_PropNo1_SkewForm_Header
