#pragma once
#ifndef _symmTensor4thOrder_Header
#define _symmTensor4thOrder_Header

#include <SymmTensor4thOrderTemplate.hxx>
#include <scalar.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef SymmTensor4thOrder<scalar> symmTensor4thOrder;

	//- Data associated with symmTensor4thOrder type are contiguous
	template<>
	inline bool contiguous<symmTensor4thOrder>() { return true; }
}

#endif // !_symmTensor4thOrder_Header
