#pragma once
#ifndef _vector4_Header
#define _vector4_Header

#include <VectorN.hxx>
#include <scalar.hxx>
#include <contiguous.hxx>

namespace AutLib
{

	typedef VectorN<scalar, 4> vector4;


	//- Specify data associated with vector4 type is contiguous
	template<>
	inline bool contiguous<vector4>() { return true; }
}

#endif // !_vector4_Header
