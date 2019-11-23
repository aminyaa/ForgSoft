#pragma once
#ifndef _Leg_Model_Duct_Header
#define _Leg_Model_Duct_Header

#include <Leg_Model_Entity.hxx>

namespace AutLib
{

	class Leg_Model_Duct
		: public Leg_Model_Entity
	{

		/*Private Data*/

	protected:

		Leg_Model_Duct()
		{}

		Leg_Model_Duct(const Standard_Integer theIndex)
			: Leg_Model_Entity(theIndex)
		{}

		Leg_Model_Duct(const Standard_Integer theIndex, const word& theName)
			: Leg_Model_Entity(theIndex, theName)
		{}
	};
}

#endif // !_Leg_Model_Duct_Header
