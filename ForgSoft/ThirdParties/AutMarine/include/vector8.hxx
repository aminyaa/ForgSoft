#pragma once
#ifndef _vector8_Header
#define _vector8_Header

#include <VectorN.hxx>
#include <scalar.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef VectorN<scalar, 8> vector8;


	//- Specify data associated with vector4 type is contiguous
	template<>
	inline bool contiguous<vector8>() { return true; }
}

#endif // !_vector8_Header
