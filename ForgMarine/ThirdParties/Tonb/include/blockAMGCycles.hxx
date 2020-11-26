#pragma once
#ifndef _blockAMGCycles_Header
#define _blockAMGCycles_Header

#include <BlockAMGCycle.hxx>
#include <VectorTensorNFieldFieldsFwd.hxx>
#include <ExpandTensorNField.hxx>
#include <VectorNFieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

	// KRJ: 2012-12-15: Is this enough to have the templating?

	typedef BlockAMGCycle<scalar> blockAMGScalarCycle;
	typedef BlockAMGCycle<vector> blockAMGVectorCycle;
	typedef BlockAMGCycle<tensor> blockAMGTensorCycle;

#define makeTypedef(type, Type, args)                \
    typedef BlockAMGCycle<type > blockAMG##Type##Cycle;

	forAllVectorNTypes(makeTypedef)
#undef makeTypedef


		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// ************************************************************************* //

#endif // !_blockAMGCycles_Header
