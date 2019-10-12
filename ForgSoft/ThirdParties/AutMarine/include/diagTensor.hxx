#pragma once
#ifndef _diagTensor_Header
#define _diagTensor_Header

#include <DiagTensorTemplate.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef DiagTensor<scalar> diagTensor;

	//- Data associated with diagTensor type are contiguous
	template<>
	inline bool contiguous<diagTensor>() { return true; }
}

#endif // !_diagTensor_Header
