#pragma once
#ifndef _NumOpt_NelderMead_Header
#define _NumOpt_NelderMead_Header

#include <Standard_TypeDef.hxx>
#include <Global_Done.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <gp.hxx>

#include <vector>

namespace AutLib
{

	class NumOpt_NelderMeadInfo
	{

		/*Private Data*/

		Standard_Real theTolerance_;

		Standard_Integer theMinNbIters_;
		Standard_Integer theMaxNbIters_;

		Standard_Real theNorm_;

	protected:

		Standard_Real& ChangeNorm()
		{
			return theNorm_;
		}

	public:

		static const Standard_Real DEFAULT_TOLERANCE;
		static const Standard_Integer DEFAULT_MIN_ITERS;
		static const Standard_Integer DEFAULT_MAX_ITERS;

		NumOpt_NelderMeadInfo()
			: theTolerance_(DEFAULT_TOLERANCE)
			, theMinNbIters_(DEFAULT_MIN_ITERS)
			, theMaxNbIters_(DEFAULT_MAX_ITERS)
		{}

		Standard_Real Tolerance() const
		{
			return theTolerance_;
		}

		Standard_Integer MinNbIterations() const
		{
			return theMinNbIters_;
		}

		Standard_Integer MaxNbIterations() const
		{
			return theMaxNbIters_;
		}

		Standard_Real Norm() const
		{
			return theNorm_;
		}

		void SetTolerance(const Standard_Real theTol)
		{
			theTolerance_ = theTol;
		}

		void SetMinNbIterations(const Standard_Integer theNb)
		{
			theMinNbIters_ = theNb;
		}

		void SetMaxNbIterations(const Standard_Integer theNb)
		{
			theMaxNbIters_ = theNb;
		}
	};

	class NumOpt_NelderMead_Coefficients
	{

		/*Private Data*/

		Standard_Real theReflection_;
		Standard_Real theExpansion_;
		Standard_Real theContraction_;
		Standard_Real theShrink_;

	public:

		static const Standard_Real DEFAULT_REFLECTION;
		static const Standard_Real DEFAULT_EXPANSION;
		static const Standard_Real DEFAULT_CONTRACTION;
		static const Standard_Real DEFAULT_SHRINK;

		NumOpt_NelderMead_Coefficients()
			: theReflection_(DEFAULT_REFLECTION)
			, theExpansion_(DEFAULT_EXPANSION)
			, theContraction_(DEFAULT_CONTRACTION)
			, theShrink_(DEFAULT_SHRINK)
		{}

		Standard_Real ReflectionCoeff() const
		{
			return theReflection_;
		}

		Standard_Real ExpansionCoeff() const
		{
			return theExpansion_;
		}

		Standard_Real ContractionCoeff() const
		{
			return theContraction_;
		}

		Standard_Real ShrinkCoeff() const
		{
			return theShrink_;
		}

		void SetReflectionCoeff(const Standard_Real x)
		{
			if (x <= gp::Resolution())
			{
				FatalErrorIn("void SetReflection(const Standard_Real x)")
					<< "Invalid coefficient for reflection" << endl
					<< abort(FatalError);
			}

			theReflection_ = x;
		}

		void SetExpansionCoeff(const Standard_Real x)
		{
			if (x <= (Standard_Real)1.0)
			{
				FatalErrorIn("void SetExpansion(const Standard_Real x)")
					<< "Invalid coefficient for expansion" << endl
					<< " - the x > 1.0" << endl
					<< abort(FatalError);
			}
			theExpansion_ = x;
		}

		void SetContractionCoeff(const Standard_Real x)
		{
			if (x <= gp::Resolution() OR x > (Standard_Real)1.0)
			{
				FatalErrorIn("void SetContractionCoeff(const Standard_Real x)")
					<< "Invalid coefficient for contraction" << endl
					<< " - the x <= 0.0 or x > 1.0" << endl
					<< abort(FatalError);
			}
			theContraction_ = x;
		}

		void SetShrinkCoeff(const Standard_Real x)
		{
			theShrink_ = x;
		}
	};

	template<class Function>
	struct NumOpt_NelderMead_Caches
	{

	protected:

		typedef typename Function::varType varType;

		Standard_Integer Lo;  // best vertex
		Standard_Integer Hi;  // worst vertex;

		Standard_Integer Li; // after the best vertex
		Standard_Integer Ho; // after the worst vertex

		Standard_Real YR;
		Standard_Real YE;
		Standard_Real YC;

		varType M;
		varType E;
		varType R;
		varType C;

	};

	template<class Function>
	class NumOpt_NelderMead
		: public NumOpt_NelderMeadInfo
		, public NumOpt_NelderMead_Caches<Function>
		, public NumOpt_NelderMead_Coefficients
		, public Function
	{

		typedef typename Function::varType varType;
		typedef Function fun;
		typedef NumOpt_NelderMead_Caches<Function> caches;
		typedef NumOpt_NelderMead_Coefficients coeff;

		varType theVariables_[fun::dim + 1];
		Standard_Real theY_[fun::dim + 1];

		Standard_Boolean IsConv;

		/*Private Data*/

		varType& ChangeVariable(const int theIndex)
		{
			return theVariables_[theIndex];
		}

		Standard_Real& ChangeY(const int theIndex)
		{
			return theY_[theIndex];
		}

		Standard_Real Size() const;

		void Order();

		void NewPoints();

		void Shrink();

		void Replace();

		void Improve();

	public:

		NumOpt_NelderMead()
			: IsConv(Standard_False)
		{}

		Standard_Integer NbVariables() const
		{
			return (Standard_Integer)Function::nbVariables;
		}

		Standard_Boolean IsConverged() const
		{
			return IsConv;
		}

		const varType& Variable(const int theIndex) const
		{
			return theVariables_[theIndex];
		}

		Standard_Real Y(const int theIndex) const
		{
			return theY_[theIndex];
		}

		Standard_Real MinY() const
		{
			return theY_[caches::Lo];
		}

		const varType& BestVertex() const
		{
			return Variable(caches::Lo);
		}

		void Perform();
	};
}

#include <NumOpt_NelderMeadI.hxx>

#endif // !_NumOpt_NelderMead_Header
