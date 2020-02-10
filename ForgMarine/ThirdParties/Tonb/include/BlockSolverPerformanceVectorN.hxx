#pragma once
#ifndef _BlockSolverPerformanceVectorN_Header
#define _BlockSolverPerformanceVectorN_Header

#include <BlockSolverPerformances.hxx>
#include <VectorTensorNFieldFieldsFwd.hxx>
#include <ExpandTensorNField.hxx>
#include <VectorNFieldTypes.hxx>
#include <BlockSolverPerformance.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define makeTypedef(type, Type, args)                                      \
    typedef BlockSolverPerformance<type> BlockSolverPerformance##Type;

	typedef BlockSolverPerformance<vector2> BlockSolverPerformanceVector2;
	typedef BlockSolverPerformance<vector3> BlockSolverPerformanceVector3;
	typedef BlockSolverPerformance<vector4> BlockSolverPerformanceVector4;
	typedef BlockSolverPerformance<vector6> BlockSolverPerformanceVector6;
	typedef BlockSolverPerformance<vector8> BlockSolverPerformanceVector8;

#undef makeTypedef


		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_BlockSolverPerformanceVectorN_Header
