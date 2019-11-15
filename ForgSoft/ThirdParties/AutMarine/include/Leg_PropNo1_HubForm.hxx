#pragma once
#ifndef _Leg_PropNo1_HubForm_Header
#define _Leg_PropNo1_HubForm_Header

#include <Global_AccessMethod.hxx>
#include <Leg_PropNo1_Form.hxx>
#include <Leg_Model_Parameter.hxx>

#include <memory>

namespace AutLib
{

	class Leg_PropNo1_HubForm
		: public Leg_PropNo1_Form
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> theHubLength_;
		std::shared_ptr<parameter> theHubWeight_;
		std::shared_ptr<parameter> theShaftRadius_;
		std::shared_ptr<parameter> theShaftOffset_;
		std::shared_ptr<parameter> theShaftLength_;

	protected:

		void Defaults();

	public:

		Leg_PropNo1_HubForm();

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, HubLength)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, HubWeight)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, ShaftRadius)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, ShaftOffset)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, ShaftLength)
	};
}

#endif // !_Leg_PropNo1_HubForm_Header
