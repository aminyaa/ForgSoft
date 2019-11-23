#pragma once
#ifndef _Leg_DuctNo1_GeneratorForm_Header
#define _Leg_DuctNo1_GeneratorForm_Header

#include <Global_AccessMethod.hxx>
#include <Leg_PropNo1_Form.hxx>
#include <Leg_Model_Parameter.hxx>

#include <memory>

namespace AutLib
{

	class Leg_DuctNo1_GeneratorForm
	{

		typedef Leg_Model_Parameter parameter;

		/*private Data*/


		std::shared_ptr<parameter> thePosition_;
		std::shared_ptr<parameter> theRisePoint_;
		std::shared_ptr<parameter> theRiseTangent_;
		std::shared_ptr<parameter> theOutletTangent_;

		void Defaults();

	public:

		Leg_DuctNo1_GeneratorForm();

		//- Macros

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, Position)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, RisePoint)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, RiseTangent)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, OutletTangent)
	};
}

#endif // !_Leg_DuctNo1_GeneratorForm_Header
