#pragma once
#ifndef _NumAlg_AdaptiveInteg_Core_Header
#define _NumAlg_AdaptiveInteg_Core_Header

#include <NumAlg_IntegBond.hxx>
#include <Global_Done.hxx>

#include <vector>

namespace tnbLib
{

	template<class Function>
	class NumAlg_AdaptiveInteg_Core
		: public Function
		, public NumAlg_IntegBond
		, public Global_Done
	{

		typedef Function fun;

		typedef std::vector<Standard_Real> realList;
		typedef std::vector<Standard_Integer> intList;

		/*Private Data*/

		//- private functions and operators

		virtual Standard_Integer MaxNbIterations() const = 0;

		virtual Standard_Real Tolerance() const = 0;

		virtual Standard_Real& ChangeResult() = 0;

		virtual Standard_Boolean& Change_IsConverged() = 0;

	protected:

		NumAlg_AdaptiveInteg_Core
		(
			const fun& theFunction
		)
			: fun(theFunction)
		{}

		NumAlg_AdaptiveInteg_Core
		(
			const Function& theFunction,
			const Standard_Real theLower,
			const Standard_Real theUpper
		)
			: fun(theFunction)
			, NumAlg_IntegBond(theLower, theUpper)
		{}

	public:

		void Perform();

	};
}

#include <NumAlg_AdaptiveInteg_CoreI.hxx>

#endif // !_NumAlg_AdaptiveInteg_Core_Header
