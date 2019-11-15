#pragma once
#ifndef _Leg_PropNo1_ThicknessForm_Header
#define _Leg_PropNo1_ThicknessForm_Header

#include <Global_AccessMethod.hxx>
#include <Leg_PropNo1_Form.hxx>
#include <Leg_Model_Parameter.hxx>

#include <memory>

namespace AutLib
{

	class Leg_PropNo1_ThicknessForm
		: public Leg_PropNo1_Form
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> theRootThickness_;
		std::shared_ptr<parameter> theTipThickness_;
		std::shared_ptr<parameter> theRootSteep_;
		std::shared_ptr<parameter> theTipSteep_;

	protected:

		void Defaults();

	public:

		Leg_PropNo1_ThicknessForm();

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, RootThickness)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, TipThickness)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, RootSteep)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, TipSteep)
	};
}

#endif // !_Leg_PropNo1_ThicknessForm_Header
