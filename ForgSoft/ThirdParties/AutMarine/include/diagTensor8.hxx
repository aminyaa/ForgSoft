#pragma once
#ifndef _diagTensor8_Header
#define _diagTensor8_Header

#include <DiagTensorN.hxx>
#include <scalar.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef DiagTensorN<scalar, 8> diagTensor8;

	//- Specify data associated with diagTensor8 type is contiguous
	template<>
	inline bool contiguous<diagTensor8>() { return true; }
}

#endif // !_diagTensor8_Header
