#pragma once
#ifndef _ProcessorBlockAMGInterfaceFields_Header
#define _ProcessorBlockAMGInterfaceFields_Header

#include <ProcessorBlockAMGInterfaceField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef ProcessorBlockAMGInterfaceField<scalar> ProcessorBlockAMGInterfaceFieldScalar;
	typedef ProcessorBlockAMGInterfaceField<vector> ProcessorBlockAMGInterfaceFieldVector;
	typedef ProcessorBlockAMGInterfaceField<tensor> ProcessorBlockAMGInterfaceFieldTensor;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_ProcessorBlockAMGInterfaceFields_Header
