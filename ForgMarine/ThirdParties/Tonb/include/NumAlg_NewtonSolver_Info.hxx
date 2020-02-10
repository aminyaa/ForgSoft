#pragma once
#ifndef _NumAlg_NewtonSolver_Info_Header
#define _NumAlg_NewtonSolver_Info_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

namespace tnbLib
{

	enum NewtonIterCondition
	{
		NewtonIter_LEVEL_EXCEEDED,
		NewtonIter_ZERODIVIDE,
		NewtonIter_CONVERGED
	};

	// Forward Declarations
	template<class Function, class Derivation, bool RefInfo>
	class NumAlg_NewtonSolver;

	class NumAlg_NewtonSolver_Info
	{

		template<class Function, class Derivation, bool RefInfo>
		friend class NumAlg_NewtonSolver;

		/*Private Data*/

		Standard_Integer theMaxIterations_;
		Standard_Integer theIter_;

		Standard_Real theTolerance_;
		Standard_Real theUnderRelaxation_;

		Standard_Real theResidual_;
		Standard_Real theResult_;
		Standard_Real theSmall_;
		Standard_Real theZero_;

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

		Standard_Boolean& Change_IsConverged()
		{
			return IsConverged_;
		}

		NewtonIterCondition& ChangeCondition()
		{
			return theCondition_;
		}

	public:

		static const Standard_Integer MAX_NB_ITERATIONS;

		static const Standard_Real DEFAULT_TOLERANCE;
		static const Standard_Real DEFAULT_UNDER_RELAXATION;
		static const Standard_Real DEFAULT_SMALL;
		static const Standard_Real DEFAULT_ZERO;

		NumAlg_NewtonSolver_Info();

		Standard_Integer NbIterations() const
		{
			return theIter_;
		}

		Standard_Real Residual() const
		{
			return theResidual_;
		}

		Standard_Real Result() const
		{
			return theResult_;
		}

		Standard_Boolean IsConverged() const
		{
			return IsConverged_;
		}

		NewtonIterCondition Condition() const
		{
			return theCondition_;
		}

		//- Macros

		GLOBAL_ACCESS_SINGLE(Standard_Real, Tolerance)
			GLOBAL_ACCESS_SINGLE(Standard_Real, Small)
			GLOBAL_ACCESS_SINGLE(Standard_Real, Zero)
			GLOBAL_ACCESS_SINGLE(Standard_Real, UnderRelaxation)

	};
}

#endif // !_NumAlg_NewtonSolver_Info_Header
