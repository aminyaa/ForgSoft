#pragma once
#ifndef _NumAlg_AdaptiveInteg_Info_Header
#define _NumAlg_AdaptiveInteg_Info_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

namespace tnbLib
{

	template<class Function, bool RefInfo>
	class NumAlg_AdaptiveInteg;

	class NumAlg_AdaptiveInteg_Info
	{

		template<class Function, bool RefInfo>
		friend class NumAlg_AdaptiveInteg;

		/*Private Data*/

		Standard_Boolean IsConverged_;

		Standard_Real theTolerance_;
		Standard_Real theResult_;

		Standard_Integer theMaxNbIterations_;
		Standard_Integer theNbInitIterations_;

	protected:

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
			IsConverged_ = Standard_False;

			theResult_ = 0;
		}

	public:

		static const Standard_Real DEFAULT_TOLERANCE;
		static const Standard_Integer DEFAULT_MAX_ITERATIONS;
		static const Standard_Integer DEFAULT_INIT_ITERATIONS;

		NumAlg_AdaptiveInteg_Info();

		Standard_Boolean IsConverged() const
		{
			return IsConverged_;
		}

		Standard_Real Result() const
		{
			return theResult_;
		}

		//- Macros
		GLOBAL_ACCESS_SINGLE(Standard_Real, Tolerance)
			GLOBAL_ACCESS_SINGLE(Standard_Integer, MaxNbIterations)
			GLOBAL_ACCESS_SINGLE(Standard_Integer, NbInitIterations)
	};
}

#endif // !_NumAlg_AdaptiveInteg_Info_Header
