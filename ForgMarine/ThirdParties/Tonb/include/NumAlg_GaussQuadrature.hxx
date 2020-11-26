#pragma once
#ifndef _NumAlg_GaussQuadrature_Header
#define _NumAlg_GaussQuadrature_Header

#include <Global_Done.hxx>
#include <NumAlg_IntegBond.hxx>

namespace tnbLib
{

	template<class Function, int NbPts>
	class NumAlg_GaussQuadrature
		: public Function
		, public NumAlg_IntegBond
		, public Global_Done
	{

		typedef Function fun;

		/*Private Data*/

		Standard_Real theResult_;

	public:

		NumAlg_GaussQuadrature
		(
			const fun& theFunction
		)
			: fun(theFunction)
			, NumAlg_IntegBond(-1, +1)
			, theResult_(0)
		{}

		NumAlg_GaussQuadrature
		(
			const fun& theFunction,
			const Standard_Real theLower,
			const Standard_Real theUpper
		)
			: fun(theFunction)
			, NumAlg_IntegBond(theLower, theUpper)
			, theResult_(0)
		{}


		Standard_Real Result() const
		{
			return theResult_;
		}

		void Perform();
	};
}

#include <NumAlg_GaussQuadratureI.hxx>

#endif // !_NumAlg_GaussQuadrature_Header
