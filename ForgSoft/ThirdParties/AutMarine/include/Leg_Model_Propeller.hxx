#pragma once
#ifndef _Leg_Model_Propeller_Header
#define _Leg_Model_Propeller_Header

#include <Leg_Model_Entity.hxx>

namespace AutLib
{

	class Leg_Model_Propeller
		: public Leg_Model_Entity
	{

		/*Private Data*/

	protected:

		Leg_Model_Propeller()
		{}

		Leg_Model_Propeller(const Standard_Integer theIndex)
			: Leg_Model_Entity(theIndex)
		{}

		Leg_Model_Propeller(const Standard_Integer theIndex, const word& theName)
			: Leg_Model_Entity(theIndex, theName)
		{}

	};
}

#endif // !_Leg_Model_Propeller_Header
