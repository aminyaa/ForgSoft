#pragma once
#ifndef _Numeric_AdaptIntegration_Header
#define _Numeric_AdaptIntegration_Header

#include <Numeric_AdaptIntegrationInfo.hxx>
#include <Numeric_AdaptIntegration_Core.hxx>
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
