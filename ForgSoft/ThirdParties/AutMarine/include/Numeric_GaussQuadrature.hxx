#pragma once
#ifndef _Numeric_GaussQuadrature_Header
#define _Numeric_GaussQuadrature_Header

#include <Global_Done.hxx>
#include <Numeric_IntegrationBound.hxx>

namespace AutLib
{

	template<class Function, int NbPts>
	class Numeric_GaussQuadrature
		: public Function
		, public Numeric_IntegrationBound
		, public Global_Done
	{

		typedef Function fun;

		/*Private Data*/

		Standard_Real theResult_;

	public:

		Numeric_GaussQuadrature
		(
			const fun& theFunction
		)
			: fun(theFunction)
			, Numeric_IntegrationBound(-1, +1)
			, theResult_(0)
		{}

		Numeric_GaussQuadrature
		(
			const fun& theFunction,
			const Standard_Real theLower,
			const Standard_Real theUpper
		)
			: fun(theFunction)
			, Numeric_IntegrationBound(theLower, theUpper)
			, theResult_(0)
		{}


		Standard_Real Result() const
		{
			return theResult_;
		}

		void Perform();
	};

	


}

#include <Numeric_GaussQuadratureI.hxx>

#endif // !_Numeric_GaussQuadrature_Header
