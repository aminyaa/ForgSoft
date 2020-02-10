#pragma once
#ifndef _sphericalTensor4_Header
#define _sphericalTensor4_Header

#include <SphericalTensorN.hxx>
#include <vector4.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef SphericalTensorN<scalar, 4> sphericalTensor4;

	//- Specify data associated with sphericalTensor4 type is contiguous
	template<>
	inline bool contiguous<sphericalTensor4>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_sphericalTensor4_Header
