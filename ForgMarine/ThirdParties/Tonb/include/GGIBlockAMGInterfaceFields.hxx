#pragma once
#ifndef _GGIBlockAMGInterfaceFields_Header
#define _GGIBlockAMGInterfaceFields_Header

#include <GGIBlockAMGInterfaceField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef GGIBlockAMGInterfaceField<scalar> GGIBlockAMGInterfaceFieldScalar;
	typedef GGIBlockAMGInterfaceField<vector> GGIBlockAMGInterfaceFieldVector;
	typedef GGIBlockAMGInterfaceField<tensor> GGIBlockAMGInterfaceFieldTensor;


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_GGIBlockAMGInterfaceFields_Header
