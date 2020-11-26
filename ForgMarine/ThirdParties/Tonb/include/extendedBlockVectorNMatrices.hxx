#pragma once
#ifndef _extendedBlockVectorNMatrices_Header
#define _extendedBlockVectorNMatrices_Header

#include <extendedBlockLduMatrix.hxx>
#include <VectorTensorNFieldFieldsFwd.hxx>
#include <ExpandTensorNField.hxx>
#include <VectorNFieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

#define makeTypedef(type, Type, args)                                      \
    typedef extendedBlockLduMatrix<type> block##Type##Matrix;

	typedef extendedBlockLduMatrix<vector2> blockVector2Matrix;
	typedef extendedBlockLduMatrix<vector3> blockVector3Matrix;
	typedef extendedBlockLduMatrix<vector4> blockVector4Matrix;
	typedef extendedBlockLduMatrix<vector6> blockVector6Matrix;
	typedef extendedBlockLduMatrix<vector8> blockVector8Matrix;

#undef makeTypedef

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_extendedBlockVectorNMatrices_Header
