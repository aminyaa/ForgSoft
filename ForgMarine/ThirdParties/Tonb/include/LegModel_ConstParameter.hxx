#pragma once
#ifndef _LegModel_ConstParameter_Header
#define _LegModel_ConstParameter_Header

#include <LegModel_Parameter.hxx>

namespace tnbLib
{

	class LegModel_ConstParameter
		: public LegModel_Parameter
	{

		/*Private Data*/

	public:

		LegModel_ConstParameter()
		{}

		LegModel_ConstParameter
		(
			const Standard_Real theValue
		)
			: LegModel_Parameter(theValue)
		{}

		LegModel_ConstParameter
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Standard_Real theValue
		)
			: LegModel_Parameter(theIndex, theName, theValue)
		{}

		//- override functions and operators

		Standard_Boolean IsConstant() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_LegModel_ConstParameter_Header
