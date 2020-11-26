#pragma once
#ifndef _blockAMGInterfaceFields_Header
#define _blockAMGInterfaceFields_Header

#include <BlockAMGInterfaceField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef BlockAMGInterfaceField<scalar> blockScalarAMGInterfaceField;
	typedef BlockAMGInterfaceField<vector> blockVectorAMGInterfaceField;
	typedef BlockAMGInterfaceField<tensor> blockTensorAMGInterfaceField;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_blockAMGInterfaceFields_Header
