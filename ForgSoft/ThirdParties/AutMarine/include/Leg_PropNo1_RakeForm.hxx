#pragma once
#ifndef _Leg_PropNo1_RakeForm_Header
#define _Leg_PropNo1_RakeForm_Header

#include <Global_AccessMethod.hxx>
#include <Leg_PropNo1_Form.hxx>
#include <Leg_Model_Parameter.hxx>

#include <memory>

namespace AutLib
{

	class Leg_PropNo1_RakeForm
		: public Leg_PropNo1_Form
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> theTipRake_;

	protected:

		void Defaults();

	public:

		Leg_PropNo1_RakeForm();

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, TipRake)
	};
}

#endif // !_Leg_PropNo1_RakeForm_Header
