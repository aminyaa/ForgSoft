#pragma once
#ifndef _Numeric_AdaptIntegrationInfo_Header
#define _Numeric_AdaptIntegrationInfo_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	template<class Function, bool RefInfo>
	class Numeric_AdaptIntegration;

	class Numeric_AdaptIntegrationInfo
	{

		template<class Function, bool RefInfo>
		friend class Numeric_AdaptIntegration;

		/*private Data*/

		Standard_Boolean IsDone_;
		Standard_Boolean IsConverged_;

		Standard_Real theTolerance_;
		Standard_Real theResult_;

		Standard_Integer theMaxIters_;
		Standard_Integer theInitialIter_;

	protected:

		Standard_Boolean& Change_IsDone()
		{
			return IsDone_;
		}

		Standard_Boolean& Change_IsConverged()
		{
			return IsConverged_;
		}

		Standard_Real& ChangeResult()
		{
			return theResult_;
		}

		void Reset()
		{
			IsDone_ = Standard_False;
			IsConverged_ = Standard_False;

			theResult_ = 0;
		}

	public:

		static const Standard_Real DEFAULT_TOLERANCE;
		static const Standard_Integer DEFAULT_MAX_ITERATIONS;
		static const Standard_Integer DEFAULT_INIT_ITERATIONS;

		Numeric_AdaptIntegrationInfo()
			: IsDone_(Standard_False)
			, IsConverged_(Standard_False)
			, theTolerance_(DEFAULT_TOLERANCE)
			, theMaxIters_(DEFAULT_MAX_ITERATIONS)
			, theInitialIter_(DEFAULT_INIT_ITERATIONS)
			, theResult_(0)
		{}

		Standard_Boolean IsDone() const
		{
			return IsDone_;
		}

		Standard_Boolean IsConverged() const
		{
			return IsConverged_;
		}

		Standard_Real Tolerance() const
		{
			return theTolerance_;
		}

		Standard_Real& Tolerance()
		{
			return theTolerance_;
		}

		Standard_Real Result() const
		{
			return theResult_;
		}

		Standard_Integer MaxNbIterations() const
		{
			return theMaxIters_;
		}

		Standard_Integer& MaxNbIterations()
		{
			return theMaxIters_;
		}

		Standard_Integer NbInitIterations() const
		{
			return theInitialIter_;
		}

		Standard_Integer& NbInitIterations()
		{
			return theInitialIter_;
		}

		void SetTolerance(const Standard_Real theTol)
		{
			theTolerance_ = theTol;
		}

		void SetMaxNbIterations(const Standard_Integer theMaxNb)
		{
			theMaxIters_ = theMaxNb;
		}

		void SetNbInitIterations(const Standard_Integer theNb)
		{
			theInitialIter_ = theNb;
		}
	};
}

#endif // !_Numeric_AdaptIntegrationInfo_Header
