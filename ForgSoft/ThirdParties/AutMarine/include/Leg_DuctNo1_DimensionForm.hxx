#pragma once
#ifndef _Leg_DuctNo1_DimensionForm_Header
#define _Leg_DuctNo1_DimensionForm_Header

#include <Global_AccessMethod.hxx>
#include <Leg_PropNo1_Form.hxx>
#include <Leg_Model_Parameter.hxx>

#include <memory>

namespace AutLib
{

	class Leg_DuctNo1_DimensionForm
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> theHeightAtOutlet_;

		std::shared_ptr<parameter> theOveralLength_;
		std::shared_ptr<parameter> theBreadthAtInlet_;
		std::shared_ptr<parameter> theBreadthAtOutlet_;
		std::shared_ptr<parameter> theDepthAtInlet_;
		std::shared_ptr<parameter> theDepthAtOutlet_;

		Standard_Integer theNbSections_;

	protected:

		void Defaults();

	public:

		Leg_DuctNo1_DimensionForm();

		//- macros

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, HeightAtOutlet)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, OveralLength)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, BreadthAtInlet)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, BreadthAtOutlet)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, DepthAtInlet)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, DepthAtOutlet)

			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbSections)
	};
}

#endif // !_Leg_DuctNo1_DimensionForm_Header
