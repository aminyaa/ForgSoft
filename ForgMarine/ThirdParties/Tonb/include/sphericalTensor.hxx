#pragma once
#ifndef _sphericalTensor_Header
#define _sphericalTensor_Header

#include <SphericalTensorTemplate.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef SphericalTensor<scalar> sphericalTensor;

	// Global spherical tensor definitions

	static const sphericalTensor I(1);
	static const sphericalTensor oneThirdI(1.0 / 3.0);
	static const sphericalTensor twoThirdsI(2.0 / 3.0);


	//- Specify data associated with sphericalTensor type are contiguous
	template<>
	inline bool contiguous<sphericalTensor>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_sphericalTensor_Header
