#pragma once
#ifndef _sphericalTensor8_Header
#define _sphericalTensor8_Header

#include <SphericalTensorN.hxx>
#include <Vector6.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef SphericalTensorN<scalar, 8> sphericalTensor8;

	//- Specify data associated with sphericalTensor8 type is contiguous
	template<>
	inline bool contiguous<sphericalTensor8>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_sphericalTensor8_Header
