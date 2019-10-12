#pragma once
#ifndef _tensor8_Header
#define _tensor8_Header

#include <TensorN.hxx>
#include <scalar.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef TensorN<scalar, 8> tensor8;

	//- Specify data associated with tensor8 type is contiguous
	template<>
	inline bool contiguous<tensor8>() { return true; }
}

#endif // !_tensor8_Header
