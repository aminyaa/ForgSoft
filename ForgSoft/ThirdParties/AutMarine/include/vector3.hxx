#pragma once
#ifndef _vector3_Header
#define _vector3_Header

#include <VectorN.hxx>
#include <scalar.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef VectorN<scalar, 3> vector3;


	//- Specify data associated with vector3 type is contiguous
	template<>
	inline bool contiguous<vector3>() { return true; }
}

#endif // !_vector3_Header
