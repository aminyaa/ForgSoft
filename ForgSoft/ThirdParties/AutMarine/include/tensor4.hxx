#pragma once
#ifndef _tensor4_Header
#define _tensor4_Header

#include <TensorN.hxx>
#include <scalar.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef TensorN<scalar, 4> tensor4;

	//- Specify data associated with tensor4 type is contiguous
	template<>
	inline bool contiguous<tensor4>() { return true; }
}

#include <tensor4I.hxx>

#endif // !_tensor4_Header
