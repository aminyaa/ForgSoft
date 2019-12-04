#pragma once
#ifndef _Leg_DuctNo1_SectionForm_Header
#define _Leg_DuctNo1_SectionForm_Header

#include <Global_AccessMethod.hxx>
#include <Leg_PropNo1_Form.hxx>
#include <Leg_Model_Parameter.hxx>

#include <memory>

namespace AutLib
{

	class Leg_DuctNo1_SectionForm
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> theSideSlope_;
		std::shared_ptr<parameter> theUpperTightness_;
		std::shared_ptr<parameter> theLowerTightness_;
		std::shared_ptr<parameter> theWidth_;

	public:

		Leg_DuctNo1_SectionForm()
		{}

		//- Macros

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, SideSlope)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, UpperTightness)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, LowerTightness)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, Width)
	};
}

#endif // !_Leg_DuctNo1_SectionForm_Header
