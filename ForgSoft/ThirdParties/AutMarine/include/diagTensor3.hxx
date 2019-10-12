#pragma once
#ifndef _diagTensor3_Header
#define _diagTensor3_Header

#include <DiagTensorN.hxx>
#include <contiguous.hxx>
#include <scalar.hxx>

namespace AutLib
{
	typedef DiagTensorN<scalar, 3> diagTensor3;

	//- Specify data associated with diagTensor3 type is contiguous
	template<>
	inline bool contiguous<diagTensor3>() { return true; }
}

#endif // !_diagTensor3_Header
