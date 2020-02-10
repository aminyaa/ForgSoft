#pragma once
#ifndef _blockVectorNMatrices_Header
#define _blockVectorNMatrices_Header

#include <blockLduMatrices.hxx>
#include <VectorTensorNFieldsFwd.hxx>
#include <ExpandTensorNField.hxx>
#include <VectorNFieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<class Type>
	class BlockLduMatrix;

#define makeTypedef(type, Type, args)                \
    typedef BlockLduMatrix<type > block##Type##Matrix;

	typedef BlockLduMatrix<vector2> blockVector2Matrix;
	typedef BlockLduMatrix<vector3> blockVector3Matrix;
	typedef BlockLduMatrix<vector4> blockVector4Matrix;
	typedef BlockLduMatrix<vector6> blockVector6Matrix;
	typedef BlockLduMatrix<vector8> blockVector8Matrix;

#undef makeTypedef

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockVectorNMatrices_Header
