#pragma once
#ifndef _symmTensor_Header
#define _symmTensor_Header

#include <SymmTensorTemplate.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef SymmTensor<scalar> symmTensor;

	//- Data associated with symmTensor type are contiguous
	template<>
	inline bool contiguous<symmTensor>() { return true; }

}

#endif // !_symmTensor_Header
