#pragma once
#ifndef _symmTensor_Header
#define _symmTensor_Header

#include <SymmTensorTemplate.hxx>
#include <vector.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef SymmTensor<scalar> symmTensor;

	//- Data associated with symmTensor type are contiguous
	template<>
	inline bool contiguous<symmTensor>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_symmTensor_Header
