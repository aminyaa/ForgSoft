#pragma once
#ifndef _Leg_Model_ConstParam_Header
#define _Leg_Model_ConstParam_Header

#include <Leg_Model_Parameter.hxx>

namespace AutLib
{

	class Leg_Model_ConstParam
		: public Leg_Model_Parameter
	{

		/*Private Data*/

	public:

		Leg_Model_ConstParam()
		{}

		Leg_Model_ConstParam(const Standard_Real theValue)
			: Leg_Model_Parameter(theValue)
		{}

		Leg_Model_ConstParam
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Standard_Real theValue
		)
			: Leg_Model_Parameter(theIndex, theName, theValue)
		{}

		//- override functions and operators

		Standard_Boolean IsConstant() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_Leg_Model_ConstParam_Header
