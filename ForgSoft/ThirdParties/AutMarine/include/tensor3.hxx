#pragma once
#ifndef _tensor3_Header
#define _tensor3_Header

#include <TensorN.hxx>
#include <scalar.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef TensorN<scalar, 3> tensor3;

	//- Specify data associated with tensor3 type is contiguous
	template<>
	inline bool contiguous<tensor3>() { return true; }
}

#endif // !_tensor3_Header
