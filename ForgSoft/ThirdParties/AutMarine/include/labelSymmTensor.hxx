#pragma once
#ifndef _labelSymmTensor_Header
#define _labelSymmTensor_Header

#include <SymmTensorTemplate.hxx>
#include <contiguous.hxx>

namespace AutLib
{

	typedef SymmTensor<label> labelSymmTensor;

	//- Data associated with labelSymmTensor type are contiguous
	template<>
	inline bool contiguous<labelSymmTensor>() { return true; }
}

#endif // !_labelSymmTensor_Header
