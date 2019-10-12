#pragma once
#ifndef _sphericalTensor2D_Header
#define _sphericalTensor2D_Header

#include <SphericalTensor2DTemplate.hxx>
#include <tensor.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef SphericalTensor2D<scalar> sphericalTensor2D;

	// Global spherical tensor definitions

	static const sphericalTensor2D I2D(1);
	static const sphericalTensor2D oneThirdI2D(1.0 / 3.0);
	static const sphericalTensor2D twoThirdsI2D(2.0 / 3.0);


	//- Data associated with sphericalTensor2D type are contiguous
	template<>
	inline bool contiguous<sphericalTensor2D>() { return true; }
}

#endif // !_sphericalTensor2D_Header
