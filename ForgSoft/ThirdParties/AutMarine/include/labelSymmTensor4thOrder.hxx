#pragma once
#ifndef _labelSymmTensor4thOrder_Header
#define _labelSymmTensor4thOrder_Header

#include <SymmTensor4thOrderTemplate.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef SymmTensor4thOrder<label> labelSymmTensor4thOrder;

	//- Data associated with labelSymmTensor4thOrder type are contiguous
	template<>
	inline bool contiguous<labelSymmTensor4thOrder>() { return true; }
}

#endif // !_labelSymmTensor4thOrder_Header
