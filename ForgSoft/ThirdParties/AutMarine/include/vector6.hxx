#pragma once
#ifndef _vector6_Header
#define _vector6_Header

#include <VectorN.hxx>
#include <scalar.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef VectorN<scalar, 6> vector6;


	//- Specify data associated with vector6 type is contiguous
	template<>
	inline bool contiguous<vector6>() { return true; }
}

#endif // !_vector6_Header
