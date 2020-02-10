#pragma once
#ifndef _sphericalTensor3_Header
#define _sphericalTensor3_Header

#include <SphericalTensorN.hxx>
#include <vector3.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef SphericalTensorN<scalar, 3> sphericalTensor3;

	//- Specify data associated with sphericalTensor3 type is contiguous
	template<>
	inline bool contiguous<sphericalTensor3>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// Include inline implementations

// Klas Jareteg: 2012-10-10 Not implemented!
//#include "sphericalTensor3I.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_sphericalTensor3_Header
