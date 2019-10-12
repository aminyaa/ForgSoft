#pragma once
#ifndef _diagTensor6_Header
#define _diagTensor6_Header

#include <DiagTensorN.hxx>
#include <scalar.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef DiagTensorN<scalar, 6> diagTensor6;

	//- Specify data associated with diagTensor6 type is contiguous
	template<>
	inline bool contiguous<diagTensor6>() { return true; }
}

#endif // !_diagTensor6_Header
