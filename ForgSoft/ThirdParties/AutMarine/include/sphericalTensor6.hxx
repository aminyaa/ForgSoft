#pragma once
#ifndef _sphericalTensor6_Header
#define _sphericalTensor6_Header

#include <SphericalTensorN.hxx>
#include <scalar.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef SphericalTensorN<scalar, 6> sphericalTensor6;

	//- Specify data associated with sphericalTensor6 type is contiguous
	template<>
	inline bool contiguous<sphericalTensor6>() { return true; }
}

#endif // !_sphericalTensor6_Header
