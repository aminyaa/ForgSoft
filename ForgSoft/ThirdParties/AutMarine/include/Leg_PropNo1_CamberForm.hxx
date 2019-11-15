#pragma once
#ifndef _Leg_PropNo1_CamberForm_Header
#define _Leg_PropNo1_CamberForm_Header

#include <Global_AccessMethod.hxx>
#include <Leg_PropNo1_Form.hxx>
#include <Leg_Model_Parameter.hxx>

#include <memory>

namespace AutLib
{

	class Leg_PropNo1_CamberForm
		: public Leg_PropNo1_Form
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> theRootCamber_;
		std::shared_ptr<parameter> theTipCamber_;

		std::shared_ptr<parameter> theMaxCamber_;
		std::shared_ptr<parameter> theMaxCamberLocation_;

		std::shared_ptr<parameter> theRootWeight_;
		std::shared_ptr<parameter> theTipWeight_;

	protected:

		void Defaults();

	public:

		Leg_PropNo1_CamberForm();

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, RootCamber)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, TipCamber)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, MaxCamber)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, MaxCamberLocation)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, RootWeight)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, TipWeight)
	};
}

#endif // !_Leg_PropNo1_CamberForm_Header
