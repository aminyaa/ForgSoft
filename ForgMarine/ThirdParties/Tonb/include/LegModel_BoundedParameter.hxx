#pragma once
#ifndef _LegModel_BoundedParameter_Header
#define _LegModel_BoundedParameter_Header

#include <LegModel_Parameter.hxx>
#include <Global_Bound.hxx>

namespace tnbLib
{

	class LegModel_BoundedParameter
		: public LegModel_Parameter
		, public Global_Bound<Standard_Real>
	{

		/*Private Data*/

	public:

		LegModel_BoundedParameter()
			: Global_Bound<Standard_Real>(0, 1)
		{}

		LegModel_BoundedParameter
		(
			const Standard_Real theValue, 
			const Standard_Real theLower, 
			const Standard_Real theUpper
		)
			: LegModel_Parameter(theValue)
			, Global_Bound<Standard_Real>(theLower, theUpper)
		{}

		LegModel_BoundedParameter
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Standard_Real theValue,
			const Standard_Real theLower,
			const Standard_Real theUpper
		)
			: LegModel_Parameter(theIndex, theName, theValue)
			, Global_Bound<Standard_Real>(theLower, theUpper)
		{}


		Standard_Boolean IsBounded() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_LegModel_BoundedParameter_Header
