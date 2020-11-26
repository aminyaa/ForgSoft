#pragma once
#ifndef _NumAlg_AdaptiveInteg_Header
#define _NumAlg_AdaptiveInteg_Header

#include <NumAlg_AdaptiveInteg_Info.hxx>
#include <NumAlg_AdaptiveInteg_Core.hxx>
#include <NumAlg_IntegBond.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <vector>

namespace tnbLib
{

	namespace Integ
	{

		void inline ChackFun(const char* funcName)
		{
			FatalErrorIn(funcName)
				<< " Found no function"
				<< abort(FatalError);
		}
	}

	struct NumAlg_AdaptiveInteg_Value
	{

		virtual Standard_Real Value(const Standard_Real) const
		{
			Integ::ChackFun("Standard_Real Value(const Standard_Real) const");
			return 0;
		}
	};

	template<class Function, bool RefInfo = true>
	class NumAlg_AdaptiveInteg
		: public NumAlg_AdaptiveInteg_Core<Function>
	{

		typedef Function fun;

		/*Private Data*/

		NumAlg_AdaptiveInteg_Info& theInfo_;

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

		NumAlg_AdaptiveInteg
		(
			const Function& theFun,
			NumAlg_AdaptiveInteg_Info& theInfo
		)
			: NumAlg_AdaptiveInteg_Core<Function>(theFun)
			, theInfo_(theInfo)
		{
			theInfo_.Reset();
		}

		NumAlg_AdaptiveInteg
		(
			const Function& theFun,
			const Standard_Real theLower,
			const Standard_Real theUpper,
			NumAlg_AdaptiveInteg_Info& theInfo
		)
			: NumAlg_AdaptiveInteg_Core<Function>(theFun, theLower, theUpper)
			, theInfo_(theInfo)
		{
			theInfo_.Reset();
		}

		const NumAlg_AdaptiveInteg_Info& Info() const
		{
			return theInfo_;
		}

	};

	template<class Function>
	class NumAlg_AdaptiveInteg<Function, false>
		: public NumAlg_AdaptiveInteg_Core<Function>
		, public NumAlg_AdaptiveInteg_Info
	{

		typedef Function fun;
		typedef NumAlg_AdaptiveInteg_Info info;

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

		NumAlg_AdaptiveInteg
		(
			const Function& theFun
		)
			: NumAlg_AdaptiveInteg_Core<Function>(theFun)
		{}

		NumAlg_AdaptiveInteg
		(
			const Function& theFun,
			const Standard_Real theLower,
			const Standard_Real theUpper
		)
			: NumAlg_AdaptiveInteg_Core<Function>(theFun, theLower, theUpper)
		{}

		NumAlg_AdaptiveInteg_Info& Info()
		{
			return *this;
		}
	};
}

#endif // !_NumAlg_AdaptiveInteg_Header
