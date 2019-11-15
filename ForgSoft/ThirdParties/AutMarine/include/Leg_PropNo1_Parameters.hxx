#pragma once
#ifndef _Leg_PropNo1_Parameters_Header
#define _Leg_PropNo1_Parameters_Header

#include <Leg_PropNo1_BladeForm.hxx>
#include <Leg_PropNo1_HubForm.hxx>

namespace AutLib
{

	class Leg_PropNo1_Parameters
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		Leg_PropNo1_BladeForm theBlade_;

		Leg_PropNo1_HubForm theHub_;

		Standard_Integer theNbBlades_;
		Standard_Integer theNbSections_;
		Standard_Integer theNbSpans_;

		std::shared_ptr<parameter> theDiameter_;
		std::shared_ptr<parameter> theHubRadius_;

		std::shared_ptr<parameter> theTipGap_;
		std::shared_ptr<parameter> theTEGap_;

		Standard_Boolean RemoveHubApex_;

		void Defaults();

	public:

		Leg_PropNo1_Parameters();

		Standard_Boolean RemoveHubApex() const
		{
			return RemoveHubApex_;
		}

		void SetToRemoveHubApex(Standard_Boolean condition)
		{
			RemoveHubApex_ = condition;
		}

		//- Macros

		GLOBAL_ACCESS_SINGLE(Leg_PropNo1_BladeForm, Blade)
			GLOBAL_ACCESS_SINGLE(Leg_PropNo1_HubForm, Hub)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, Diameter)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, HubRadius)

			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbBlades)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbSections)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbSpans)

			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, TipGap)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, TEGap)
	};
}

#endif // !_Leg_PropNo1_Parameters_Header
