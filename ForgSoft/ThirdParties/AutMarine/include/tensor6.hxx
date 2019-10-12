#pragma once
#ifndef _tensor6_Header
#define _tensor6_Header

#include <TensorN.hxx>
#include <scalar.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef TensorN<scalar, 6> tensor6;

	//- Specify data associated with tensor6 type is contiguous
	template<>
	inline bool contiguous<tensor6>() { return true; }
}

#endif // !_tensor6_Header
