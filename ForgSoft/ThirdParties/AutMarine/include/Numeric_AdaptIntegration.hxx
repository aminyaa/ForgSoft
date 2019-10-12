#pragma once
#ifndef _Numeric_AdaptIntegration_Header
#define _Numeric_AdaptIntegration_Header

#include <Numeric_AdaptIntegrationInfo.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <vector>

namespace AutLib
{

	class Numeric_AdaptIntegration_Bound
	{

		/*Private Data*/

		Standard_Real theLower_;
		Standard_Real theUpper_;

	public:

		Numeric_AdaptIntegration_Bound
		(
			const Standard_Real theLower,
			const Standard_Real theUpper
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

		void SetLower(const Standard_Real theLower)
		{
			theLower_ = theLower;
		}

		void SetUpper(const Standard_Real theUpper)
		{
			theUpper_ = theUpper;
		}
	};

	namespace Integ
	{
		void inline ChackFun(const char* funcName)
		{
			FatalErrorIn(funcName)
				<< " Found no function"
				<< abort(FatalError);
		}
	}

	struct Numeric_AdaptIntegration_Value
	{
		virtual Standard_Real Value(const Standard_Real) const
		{
			Integ::ChackFun("Standard_Real Value(const Standard_Real) const");
			return 0;
		}
	};

	template<class Function>
	class Numeric_AdaptIntegration_Core
		: public Function
		, public Numeric_AdaptIntegration_Bound
	{

		typedef Function fun;

		typedef std::vector<Standard_Real> realList;
		typedef std::vector<Standard_Integer> intList;

		/*Private Data*/

		virtual Standard_Integer MaxNbIterations() const = 0;

		virtual Standard_Real Tolerance() const = 0;

		virtual Standard_Real& ChangeResult() = 0;

		virtual Standard_Boolean& Change_IsDone() = 0;

		virtual Standard_Boolean& Change_IsConverged() = 0;

		static const Standard_Integer RESERVED = 10;

	protected:

		Numeric_AdaptIntegration_Core
		(
			const Function& theFunction
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
			, Numeric_AdaptIntegration_Bound(theLower, theUpper)
		{}

	public:

		void Perform()
		{
			if (Upper() <= Lower())
			{
				FatalErrorIn(" void Perform()")
					<< " Invalid Integration bound" << endl
					<< " - Lower: " << Lower() << endl
					<< " - Upper: " << Upper() << endl
					<< abort(FatalError);
			}

			Change_IsDone() = Standard_True;

			auto U0 = Lower();
			auto U1 = Upper();
			auto MaxSize = MaxNbIterations() + RESERVED;

			realList
				tol(MaxSize),
				a(MaxSize),
				h(MaxSize),
				FA(MaxSize),
				FC(MaxSize),
				FB(MaxSize),
				S(MaxSize);

			intList L(MaxSize);

			auto APP = (Standard_Real)0.;
			auto i = (Standard_Integer)1;

			tol[i] = (Standard_Real)10.0 * Tolerance();
			a[i] = U0;
			h[i] = (Standard_Real)0.5*(U1 - U0);

			FA[i] = fun::Value(U0);
			FC[i] = fun::Value(U0 + h[i]);
			FB[i] = fun::Value(U1);

			S[i] = h[i] * (FA[i] + (Standard_Real)4.0*FC[i] + FB[i]) / (Standard_Real)3.0;

			L[i] = 1;

			Standard_Real FD, FE, S1, S2;
			Standard_Real v1, v2, v3, v4, v5, v6, v7;
			Standard_Integer v8;
			Standard_Integer k = 0;

			Standard_Real C6 = (Standard_Real)1.0 / (Standard_Real)6.0;

			while (i > 0)
			{
				FD = fun::Value(a[i] + (Standard_Real)0.5*h[i]);
				FE = fun::Value(a[i] + (Standard_Real)1.5*h[i]);

				S1 = h[i] * (FA[i] + (Standard_Real)4.0 * FD + FC[i]) * C6;
				S2 = h[i] * (FC[i] + (Standard_Real)4.0 * FE + FB[i]) * C6;

				v1 = a[i];
				v2 = FA[i];
				v3 = FC[i];
				v4 = FB[i];
				v5 = h[i];
				v6 = tol[i];
				v7 = S[i];
				v8 = L[i];

				i--;

				k++;

				if (ABS(S1 + S2 - v7) < v6)
				{
					APP += (S1 + S2);
				}
				else
				{
					if (v8 >= MaxNbIterations() + 1)
					{
						Change_IsConverged() = Standard_False;
						ChangeResult() = APP;

						return;
					}
					else
					{
						i++;

						a[i] = v1 + v5;
						FA[i] = v3;
						FC[i] = FE;
						FB[i] = v4;
						h[i] = (Standard_Real)0.5*v5;
						tol[i] = MAX((Standard_Real)0.5*v6, 1.0E-16);
						S[i] = S2;
						L[i] = v8 + 1;

						i++;

						a[i] = v1;
						FA[i] = v2;
						FC[i] = FD;
						FB[i] = v3;
						h[i] = h[i - 1];
						tol[i] = tol[i - 1];
						S[i] = S1;
						L[i] = L[i - 1];
					}
				}
			}

			ChangeResult() = APP;
			Change_IsConverged() = Standard_True;
		}
	};

	template<class Function, bool RefInfo = true>
	class Numeric_AdaptIntegration
		: public Numeric_AdaptIntegration_Core<Function>
	{

		typedef Function fun;

		/*Private Data*/

		Numeric_AdaptIntegrationInfo& theInfo_;

		Standard_Integer MaxNbIterations() const override
		{
			return theInfo_.MaxNbIterations();
		}

		Standard_Real Tolerance() const override
		{
			return theInfo_.Tolerance();
		}

		Standard_Real& ChangeResult() override
		{
			return theInfo_.ChangeResult();
		}

		Standard_Boolean& Change_IsDone() override
		{
			return theInfo_.Change_IsDone();
		}

		Standard_Boolean& Change_IsConverged() override
		{
			return theInfo_.Change_IsConverged();
		}

	public:

		Numeric_AdaptIntegration
		(
			const Function& theFun,
			Numeric_AdaptIntegrationInfo& theInfo
		)
			: Numeric_AdaptIntegration_Core<Function>(theFun)
			, theInfo_(theInfo)
		{
			theInfo_.Reset();
		}

		Numeric_AdaptIntegration
		(
			const Function& theFun, 
			const Standard_Real theLower,
			const Standard_Real theUpper,
			Numeric_AdaptIntegrationInfo& theInfo
		)
			: Numeric_AdaptIntegration_Core<Function>(theFun, theLower, theUpper)
			, theInfo_(theInfo)
		{
			theInfo_.Reset();
		}

		const Numeric_AdaptIntegrationInfo& Info() const
		{
			return theInfo_;
		}

	};


	template<class Function>
	class Numeric_AdaptIntegration<Function, false>
		: public Numeric_AdaptIntegration_Core<Function>
		, public Numeric_AdaptIntegrationInfo
	{

		typedef Function fun;
		typedef Numeric_AdaptIntegrationInfo info;

		/*Private Data*/

		Standard_Integer MaxNbIterations() const override
		{
			return info::MaxNbIterations();
		}

		Standard_Real Tolerance() const override
		{
			return info::Tolerance();
		}

		Standard_Real& ChangeResult() override
		{
			return info::ChangeResult();
		}

		Standard_Boolean& Change_IsDone() override
		{
			return info::Change_IsDone();
		}

		Standard_Boolean& Change_IsConverged() override
		{
			return info::Change_IsConverged();
		}

	public:

		Numeric_AdaptIntegration
		(
			const Function& theFun
		)
			: Numeric_AdaptIntegration_Core<Function>(theFun)
		{}

		Numeric_AdaptIntegration
		(
			const Function& theFun,
			const Standard_Real theLower,
			const Standard_Real theUpper
		)
			: Numeric_AdaptIntegration_Core<Function>(theFun, theLower, theUpper)
		{}

		Numeric_AdaptIntegrationInfo& Info()
		{
			return *this;
		}
	};
}

#endif // !_Numeric_AdaptIntegration_Header
