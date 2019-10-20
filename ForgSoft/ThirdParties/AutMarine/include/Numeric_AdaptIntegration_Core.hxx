#pragma once
#ifndef _Numeric_AdaptIntegration_Core_Header
#define _Numeric_AdaptIntegration_Core_Header

#include <Numeric_IntegrationBound.hxx>
#include <Global_Done.hxx>

#include <vector>

namespace AutLib
{

	template<class Function>
	class Numeric_AdaptIntegration_Core
		: public Function
		, public Numeric_IntegrationBound
		, public Global_Done
	{

		typedef Function fun;

		typedef std::vector<Standard_Real> realList;
		typedef std::vector<Standard_Integer> intList;

		/*Private Data*/

		static const Standard_Integer RESERVED = 10;



		//- private functions and operators

		virtual Standard_Integer MaxNbIterations() const = 0;

		virtual Standard_Real Tolerance() const = 0;

		virtual Standard_Real& ChangeResult() = 0;

		virtual Standard_Boolean& Change_IsConverged() = 0;

	protected:

		Numeric_AdaptIntegration_Core
		(
			const fun& theFunction
		)
			: fun(theFunction)
		{}

		Numeric_AdaptIntegration_Core
		(
			const Function& theFunction,
			const Standard_Real theLower,
			const Standard_Real theUpper
		)
			: fun(theFunction)
			, Numeric_IntegrationBound(theLower, theUpper)
		{}

	public:

		void Perform();

	};
}

#include <Numeric_AdaptIntegration_CoreI.hxx>

#endif // !_Numeric_AdaptIntegration_Core_Header
