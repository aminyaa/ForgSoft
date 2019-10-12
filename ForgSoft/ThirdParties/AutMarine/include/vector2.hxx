#pragma once
#ifndef _vector2_Header
#define _vector2_Header

#include <VectorN.hxx>
#include <scalar.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef VectorN<scalar, 2> vector2;


	//- Specify data associated with vector2 type is contiguous
	template<>
	inline bool contiguous<vector2>() { return true; }
}

#endif // !_vector2_Header
