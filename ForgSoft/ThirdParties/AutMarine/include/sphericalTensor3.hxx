#pragma once
#ifndef _sphericalTensor3_Header
#define _sphericalTensor3_Header

#include <SphericalTensorN.hxx>
#include <contiguous.hxx>
#include <scalar.hxx>

namespace AutLib
{
	typedef SphericalTensorN<scalar, 3> sphericalTensor3;

	//- Specify data associated with sphericalTensor3 type is contiguous
	template<>
	inline bool contiguous<sphericalTensor3>() { return true; }
}

#endif // !_sphericalTensor3_Header

