#pragma once
#ifndef _sphericalTensor6_Header
#define _sphericalTensor6_Header

#include <SphericalTensorN.hxx>
#include <Vector6.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef SphericalTensorN<scalar, 6> sphericalTensor6;

	//- Specify data associated with sphericalTensor6 type is contiguous
	template<>
	inline bool contiguous<sphericalTensor6>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_sphericalTensor6_Header
