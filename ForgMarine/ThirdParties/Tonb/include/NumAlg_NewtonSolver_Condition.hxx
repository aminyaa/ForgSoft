#pragma once
#ifndef _NumAlg_NewtonSolver_Condition_Header
#define _NumAlg_NewtonSolver_Condition_Header

namespace tnbLib
{

	enum class NumAlg_NewtonSolver_Condition
	{
		LEVEL_EXCEEDED,
		ZERODIVIDE,
		CONVERGED
	};
}

#endif // !_NumAlg_NewtonSolver_Condition_Header
