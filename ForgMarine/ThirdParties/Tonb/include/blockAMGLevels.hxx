#pragma once
#ifndef _blockAMGLevels_Header
#define _blockAMGLevels_Header

#include <BlockAMGLevel.hxx>
#include <fineBlockAMGLevel.hxx>
#include <coarseBlockAMGLevel.hxx>

#include <VectorTensorNFieldsFwd.hxx>
#include <ExpandTensorNField.hxx>
#include <VectorNFieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

	// KRJ: 2012-12-15: Is this enough to have the templating?

	typedef BlockAMGLevel<scalar> blockAmgScalarLevel;
	typedef BlockAMGLevel<vector> blockAmgVectorLevel;
	typedef BlockAMGLevel<tensor> blockAmgTensorLevel;

#define makeTypedef(type, Type, args)                \
    typedef BlockAMGLevel<type > blockAmg##Type##Level;
	forAllVectorNTypes(makeTypedef)
#undef makeTypedef

		typedef coarseBlockAMGLevel<scalar> coarseblockAmgScalarLevel;
	typedef coarseBlockAMGLevel<vector> coarseblockAmgVectorLevel;
	typedef coarseBlockAMGLevel<tensor> coarseblockAmgTensorLevel;

#define makeTypedef(type, Type, args)                \
    typedef coarseBlockAMGLevel<type > coarseblockAmg##Type##Level;
	forAllVectorNTypes(makeTypedef)
#undef makeTypedef

		typedef fineBlockAMGLevel<scalar> fineblockAmgScalarLevel;
	typedef fineBlockAMGLevel<vector> fineblockAmgVectorLevel;
	typedef fineBlockAMGLevel<tensor> fineblockAmgTensorLevel;

#define makeTypedef(type, Type, args)                \
    typedef fineBlockAMGLevel<type > fineblockAmg##Type##Level;
	forAllVectorNTypes(makeTypedef)
#undef makeTypedef

		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// ************************************************************************* //

#endif // !_blockAMGLevels_Header
