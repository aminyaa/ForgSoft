#pragma once
#ifndef _Numeric_NewtonSolver_Header
#define _Numeric_NewtonSolver_Header

#include <Numeric_NewtonSolverInfo.hxx>
#include <error.hxx>
#include <OSstream.hxx>

namespace AutLib
{

	class Numeric_NewtonSolver_Bound
	{

		/*Private Data*/

		Standard_Real theLower_;
		Standard_Real theUpper_;

	public:

		Numeric_NewtonSolver_Bound
		(
			const Standard_Real theLower = 0,
			const Standard_Real theUpper = 0
		)
			: theLower_(theLower)
			, theUpper_(theUpper)
		{}

		Standard_Real Lower() const
		{
			return theLower_;
		}

		Standard_Real& Lower()
		{
			return theLower_;
		}

		Standard_Real Upper() const
		{
			return theUpper_;
		}

		Standard_Real& Upper()
		{
			return theUpper_;
		}
	};

	namespace Iter
	{
		void inline ChackFun(const char* funcName)
		{
			FatalErrorIn(funcName)
				<< " Found no function"
				<< abort(FatalError);
		}

		template<bool Cond = true>
		void inline CheckBound
		(
			Standard_Real& x,
			const Standard_Real theLower,
			const Standard_Real theUpper
		)
		{
			if (x < theLower) x = theLower;
			if (x > theUpper) x = theUpper;
		}

		template<>
		void inline CheckBound<false>
			(
				Standard_Real& x,
				const Standard_Real theLower,
				const Standard_Real theUpper
				)
		{}
	}

	struct Numeric_NewtonSolver_Value
	{
		virtual Standard_Real Value(const Standard_Real) const
		{
			Iter::ChackFun("Standard_Real Value(const Standard_Real) const");
			return 0;
		}
	};

	template<bool BoundCheck = false>
	struct Numeric_NewtonSolver_Function
		: public Numeric_NewtonSolver_Value
	{
		void CheckBound(Standard_Real& x) const
		{
			Iter::CheckBound<false>(x, 0, 0);
		}
	};

	template<>
	struct Numeric_NewtonSolver_Function<true>
		: public Numeric_NewtonSolver_Bound
		, public Numeric_NewtonSolver_Value
	{
		void CheckBound(Standard_Real& x) const
		{
			Iter::CheckBound(x, Lower(), Upper());
		}
	};

	template<bool BoundCheck = false>
	struct Numeric_NewtonSolver_Derivation
		: public Numeric_NewtonSolver_Value
	{
		void CheckBound(Standard_Real& x) const
		{
			Iter::CheckBound<false>(x, 0, 0);
		}
	};

	template<>
	struct Numeric_NewtonSolver_Derivation<true>
		: public Numeric_NewtonSolver_Bound
		, public Numeric_NewtonSolver_Value
	{
		void CheckBound(Standard_Real& x) const
		{
			Iter::CheckBound(x, Lower(), Upper());
		}
	};

	template<class Function, class Derivation>
	class Numeric_NewtonSolver_Alg
		: public Function
		, public Derivation
	{

		typedef Function fun;
		typedef Derivation der;

		/*Private Data*/

		virtual Standard_Boolean& Change_IsDone() = 0;

		virtual Standard_Integer& ChangeNbIter() = 0;

		virtual NewtonIterCondition Condition() const = 0;

		virtual NewtonIterCondition& ChangeCondition() = 0;

		virtual Standard_Real& ChangeResidual() = 0;

		virtual Standard_Real& ChangeResult() = 0;

		virtual Standard_Integer MaxNbIterations() const = 0;

		virtual Standard_Real UnderRelaxation() const = 0;

		virtual Standard_Real Tolerance() const = 0;

		virtual Standard_Real Zero() const = 0;

		virtual Standard_Real Small() const = 0;

	protected:

		Numeric_NewtonSolver_Alg
		(
			const Function& theFunction,
			const Derivation& theDerivation
		)
			: fun(theFunction)
			, der(theDerivation)
		{}

	public:

		void Perform(const Standard_Real guess)
		{
			Change_IsDone() = Standard_True;

			auto u = guess;

			fun::CheckBound(u);
			auto y0 = fun::Value(u);

			Standard_Real df, dp, p1, y1, rel_err;

			ChangeNbIter() = 0;
			ChangeResidual() = (Standard_Real)0.;
			ChangeResult() = (Standard_Real)0.;
			ChangeCondition() = NewtonIter_LEVEL_EXCEEDED;

			forThose(Iter, 1, MaxNbIterations())
			{
				ChangeNbIter()++;

				der::CheckBound(u);
				df = der::Value(u);

				if (ABS(df) <= Zero())
				{
					dp = (Standard_Real)0.;
					ChangeCondition() = NewtonIter_ZERODIVIDE;
				}
				else
					dp = y0 / df;

				p1 = u - UnderRelaxation()*dp;

				fun::CheckBound(p1);
				y1 = fun::Value(p1);

				rel_err = (Standard_Real)2.0 * ABS(dp) / (ABS(p1) + Small());

				if (rel_err < Tolerance() OR ABS(y1) < Zero())
					if (Condition() NOT_EQUAL NewtonIter_ZERODIVIDE)
						ChangeCondition() = NewtonIter_CONVERGED;

				u = p1;
				y0 = y1;

				if (Condition())
					break;
			}

			ChangeResult() = u;
			ChangeResidual() = rel_err;
		}
	};

	template<class Function, class Derivation, bool RefInfo = true>
	class Numeric_NewtonSolver
		: public Numeric_NewtonSolver_Alg<Function, Derivation>
	{

		typedef Function fun;
		typedef Derivation der;

		/*Private Data*/

		Numeric_NewtonSolverInfo& theInfo_;

		Standard_Boolean& Change_IsDone() override
		{
			return theInfo_.Change_IsDone();
		}

		Standard_Integer& ChangeNbIter() override
		{
			return theInfo_.ChangeNbIter();
		}

		NewtonIterCondition Condition() const override
		{
			return theInfo_.Condition();
		}

		NewtonIterCondition& ChangeCondition() override
		{
			return theInfo_.ChangeCondition();
		}

		Standard_Real& ChangeResidual() override
		{
			return theInfo_.ChangeResidual();
		}

		Standard_Real& ChangeResult() override
		{
			return theInfo_.ChangeResult();
		}

		Standard_Integer MaxNbIterations() const override
		{
			return theInfo_.MaxNbIterations();
		}

		Standard_Real UnderRelaxation() const override
		{
			return theInfo_.UnderRelaxation();
		}

		Standard_Real Tolerance() const override
		{
			return theInfo_.Tolerance();
		}

		Standard_Real Zero() const override
		{
			return theInfo_.Zero();
		}

		Standard_Real Small() const override
		{
			return theInfo_.Small();
		}

	public:

		Numeric_NewtonSolver
		(
			const Function& theFunction,
			const Derivation& theDerivation,
			Numeric_NewtonSolverInfo& theInfo
		)
			: Numeric_NewtonSolver_Alg<Function, Derivation>(theFunction, theDerivation)
			, theInfo_(theInfo)
		{
			theInfo_.Reset();
		}

		const Numeric_NewtonSolverInfo& Info() const
		{
			return theInfo_;
		}

		Numeric_NewtonSolverInfo& Info()
		{
			return theInfo_;
		}
	};

	template<class Function, class Derivation>
	class Numeric_NewtonSolver<Function, Derivation, false>
		: public Numeric_NewtonSolver_Alg<Function, Derivation>
		, public Numeric_NewtonSolverInfo
	{

		typedef Function fun;
		typedef Derivation der;
		typedef Numeric_NewtonSolverInfo info;

		/*Private Data*/

		Standard_Boolean& Change_IsDone() override
		{
			return info::Change_IsDone();
		}

		Standard_Integer& ChangeNbIter() override
		{
			return info::ChangeNbIter();
		}

		NewtonIterCondition Condition() const override
		{
			return info::Condition();
		}

		NewtonIterCondition& ChangeCondition() override
		{
			return info::ChangeCondition();
		}

		Standard_Real& ChangeResidual() override
		{
			return info::ChangeResidual();
		}

		Standard_Real& ChangeResult() override
		{
			return info::ChangeResult();
		}

		Standard_Integer MaxNbIterations() const
		{
			return info::MaxNbIterations();
		}

		Standard_Real UnderRelaxation() const override
		{
			return info::UnderRelaxation();
		}

		Standard_Real Tolerance() const override
		{
			return info::Tolerance();
		}

		Standard_Real Zero() const override
		{
			return info::Zero();
		}

		Standard_Real Small() const override
		{
			return info::Small();
		}

	public:

		Numeric_NewtonSolver
		(
			const Function& theFunction,
			const Derivation& theDerivation
		)
			: Numeric_NewtonSolver_Alg<Function, Derivation>(theFunction, theDerivation)
		{}

		/*Numeric_NewtonSolver
		(
			const Function& theFunction,
			const Derivation& theDerivation,
			const Numeric_NewtonSolverInfo& theInfo
		)
			: Numeric_NewtonSolver_Alg<Function, Derivation>(theFunction, theDerivation)
			, info(theInfo)
		{}*/


	};
}

#endif // !_Numeric_NewtonSolver_Header
