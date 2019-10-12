#pragma once
#ifndef _SizeMap2d_AnIso_OptmPoint_IterCorrectInfo_Header
#define _SizeMap2d_AnIso_OptmPoint_IterCorrectInfo_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	class SizeMap2d_AnIso_OptmPoint_IterCorrectInfo
	{

		/*Private Data*/

		Standard_Integer theMaxNbIters_;

		Standard_Real theTolerance_;
		Standard_Real theUnderRelaxation_;

	public:

		static const Standard_Integer DEFAULT_MAX_NB_ITERATIONS;

		static const Standard_Real DEFAULT_TOLERANCE;
		static const Standard_Real DEFAULT_UNDER_RELAXATION;

		SizeMap2d_AnIso_OptmPoint_IterCorrectInfo()
			: theMaxNbIters_(DEFAULT_MAX_NB_ITERATIONS)
			, theTolerance_(DEFAULT_TOLERANCE)
			, theUnderRelaxation_(DEFAULT_UNDER_RELAXATION)
		{}

		Standard_Integer MaxNbIterations() const
		{
			return theMaxNbIters_;
		}

		Standard_Real Tolerance() const
		{
			return theTolerance_;
		}

		Standard_Real UnderRelaxation() const
		{
			return theUnderRelaxation_;
		}

		void SetMaxNbIterations(const Standard_Integer theValue)
		{
			theMaxNbIters_ = theValue;
		}

		void SetTolerance(const Standard_Real x)
		{
			theTolerance_ = x;
		}

		void SetUnderRelaxation(const Standard_Real theTol)
		{
			theUnderRelaxation_ = theTol;
		}
	};
}

#endif // !_SizeMap2d_AnIso_OptmPoint_IterCorrectInfo_Header