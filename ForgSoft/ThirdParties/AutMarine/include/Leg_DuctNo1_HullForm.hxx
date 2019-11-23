#pragma once
#ifndef _Leg_DuctNo1_HullForm_Header
#define _Leg_DuctNo1_HullForm_Header

#include <Global_AccessMethod.hxx>
#include <Leg_PropNo1_Form.hxx>
#include <Leg_Model_Parameter.hxx>
#include <Leg_DuctNo1_SectionForm.hxx>

#include <memory>

namespace AutLib
{

	class Leg_DuctNo1_HullForm
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		Leg_DuctNo1_SectionForm theInlet_;
		Leg_DuctNo1_SectionForm theMid_;
		Leg_DuctNo1_SectionForm theOutlet_;

		std::shared_ptr<parameter> theMidLocation_;


		void Defaults();

	public:

		Leg_DuctNo1_HullForm();

		//- Macros

		GLOBAL_ACCESS_SINGLE(Leg_DuctNo1_SectionForm, Inlet)
			GLOBAL_ACCESS_SINGLE(Leg_DuctNo1_SectionForm, Mid)
			GLOBAL_ACCESS_SINGLE(Leg_DuctNo1_SectionForm, Outlet)

			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, MidLocation)
	};
}

#endif // !_Leg_DuctNo1_HullForm_Header
