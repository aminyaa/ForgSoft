#pragma once
#ifndef _Marine_FirstOrderWave_Header
#define _Marine_FirstOrderWave_Header

#include <Marine_Wave.hxx>
#include <Marine_FirstOrderWave_CharType.hxx>

namespace tnbLib
{

	class Marine_FirstOrderWave
		: public Marine_Wave
	{

		/*Private Data*/

		Standard_Real theDepth_;

		Standard_Boolean DeepApprox_;

		Vec3d theAdvancingDirection_;

		Marine_FirstOrderWave_CharType theCharType_;

	public:

		auto DeepApprox() const
		{
			return DeepApprox_;
		}

		auto CharType() const
		{
			return theCharType_;
		}

		void SetCharType
		(
			const Marine_FirstOrderWave_CharType theType
		)
		{
			theCharType_ = theType;
		}

		void SetDeepApprox(const Standard_Boolean theSense)
		{
			DeepApprox_ = theSense;
		}

		//- Macros
		GLOBAL_ACCESS_ONLY_SINGLE(Vec3d, AdvancingDirection)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Depth)
	};
}

#endif // !_Marine_FirstOrderWave_Header
