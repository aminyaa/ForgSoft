#pragma once
#ifndef _symmTensor4thOrder_Header
#define _symmTensor4thOrder_Header

#include <SymmTensor4thOrderTemplate.hxx>
#include <vector.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef SymmTensor4thOrder<scalar> symmTensor4thOrder;

	//- Data associated with symmTensor4thOrder type are contiguous
	template<>
	inline bool contiguous<symmTensor4thOrder>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_symmTensor4thOrder_Header
