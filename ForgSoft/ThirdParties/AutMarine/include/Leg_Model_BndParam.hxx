#pragma once
#ifndef _Leg_Model_BndParam_Header
#define _Leg_Model_BndParam_Header

#include <Leg_Model_Parameter.hxx>
#include <Global_Bound.hxx>

namespace AutLib
{

	class Leg_Model_BndParam
		: public Leg_Model_Parameter
		, public Global_Bound<Standard_Real>
	{

		/*private Data*/

	public:

		Leg_Model_BndParam()
			: Global_Bound<Standard_Real>(0, 1)
		{}

		Leg_Model_BndParam
		(
			const Standard_Real theValue,
			const Standard_Real theLower,
			const Standard_Real theUpper
		)
			: Leg_Model_Parameter(theValue)
			, Global_Bound<Standard_Real>(theLower, theUpper)
		{}

		Leg_Model_BndParam
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Standard_Real theValue,
			const Standard_Real theLower,
			const Standard_Real theUpper
		)
			: Leg_Model_Parameter(theIndex, theName, theValue)
			, Global_Bound<Standard_Real>(theLower, theUpper)
		{}


		//- override functions and operators

		Standard_Boolean IsBounded() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_Leg_Model_BndParam_Header
