#pragma once
#ifndef _sphericalTensor2_Header
#define _sphericalTensor2_Header

#include <SphericalTensorN.hxx>
#include <vector2.hxx>
#include <contiguous.hxx>

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef SphericalTensorN<scalar, 2> sphericalTensor2;

	//- Specify data associated with sphericalTensor2 type is contiguous
	template<>
	inline bool contiguous<sphericalTensor2>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

#include <sphericalTensor2I.hxx>

#endif // !_sphericalTensor2_Header
