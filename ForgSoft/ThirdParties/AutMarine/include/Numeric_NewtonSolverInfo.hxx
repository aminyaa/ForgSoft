#pragma once
#ifndef _Numeric_NewtonSolverInfo_Header
#define _Numeric_NewtonSolverInfo_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	enum NewtonIterCondition
	{
		NewtonIter_LEVEL_EXCEEDED,
		NewtonIter_ZERODIVIDE,
		NewtonIter_CONVERGED
	};

	// Forward Declarations
	template<class Function, class Derivation, bool RefInfo>
	class Numeric_NewtonSolver;

	class Numeric_NewtonSolverInfo
	{

		/*Private Data*/
		template<class Function, class Derivation, bool RefInfo>
		friend class Numeric_NewtonSolver;

		Standard_Integer theMaxIterations_;
		Standard_Integer theIter_;

		Standard_Real theTolerance_;
		Standard_Real theUnderRelaxation_;

		Standard_Real theResidual_;
		Standard_Real theResult_;
		Standard_Real theSmall_;
		Standard_Real theZero_;

		Standard_Boolean IsDone_;
		Standard_Boolean IsConverged_;

		NewtonIterCondition theCondition_;

	protected:

		Standard_Integer& ChangeNbIter()
		{
			return theIter_;
		}

		Standard_Real& ChangeResidual()
		{
			return theResidual_;
		}

		Standard_Real& ChangeResult()
		{
			return theResult_;
		}

		Standard_Boolean& Change_IsDone()
		{
			return IsDone_;
		}

		Standard_Boolean& Change_IsConverged()
		{
			return IsConverged_;
		}

		NewtonIterCondition& ChangeCondition()
		{
			return theCondition_;
		}

		void Reset()
		{
			theIter_ = 0;
			theResidual_ = 0;
			theResult_ = 0;
			IsDone_ = Standard_False;
			IsConverged_ = Standard_False;
		}

	public:

		static const Standard_Integer MAX_NB_ITERATIONS;

		static const Standard_Real DEFAULT_TOLERANCE;
		static const Standard_Real DEFAULT_UNDER_RELAXATION;
		static const Standard_Real DEFAULT_SMALL;
		static const Standard_Real DEFAULT_ZERO;

		Numeric_NewtonSolverInfo()
			: theMaxIterations_(MAX_NB_ITERATIONS)
			, theIter_(0)
			, theTolerance_(DEFAULT_TOLERANCE)
			, theUnderRelaxation_(DEFAULT_UNDER_RELAXATION)
			, theResidual_(0)
			, theResult_(0)
			, theSmall_(DEFAULT_SMALL)
			, theZero_(DEFAULT_ZERO)
			, IsDone_(Standard_False)
			, IsConverged_(Standard_False)
		{}

		Standard_Integer MaxNbIterations() const
		{
			return theMaxIterations_;
		}

		Standard_Integer& MaxNbIterations()
		{
			return theMaxIterations_;
		}

		Standard_Integer NbIterations() const
		{
			return theIter_;
		}

		Standard_Real Tolerance() const
		{
			return theTolerance_;
		}

		Standard_Real& Tolerance()
		{
			return theTolerance_;
		}

		Standard_Real UnderRelaxation() const
		{
			return theUnderRelaxation_;
		}

		Standard_Real& UnderRelaxation()
		{
			return theUnderRelaxation_;
		}

		Standard_Real Residual() const
		{
			return theResidual_;
		}

		Standard_Real Result() const
		{
			return theResult_;
		}

		Standard_Real Small() const
		{
			return theSmall_;
		}

		Standard_Real& Small()
		{
			return theSmall_;
		}

		Standard_Real Zero() const
		{
			return theZero_;
		}

		Standard_Real& Zero()
		{
			return theZero_;
		}

		Standard_Boolean IsDone() const
		{
			return IsDone_;
		}

		Standard_Boolean IsConverged() const
		{
			return IsConverged_;
		}

		NewtonIterCondition Condition() const
		{
			return theCondition_;
		}

		void SetUnderRelaxation(const Standard_Real theUR)
		{
			theUnderRelaxation_ = theUR;
		}

		void SetSmall(const Standard_Real theSmall)
		{
			theSmall_ = theSmall;
		}

		void SetZero(const Standard_Real theZero)
		{
			theZero_ = theZero;
		}

		void SetTolerance(const Standard_Real theTol)
		{
			theTolerance_ = theTol;
		}
	};
}

#endif // !_Numeric_NewtonSolverInfo_Header
