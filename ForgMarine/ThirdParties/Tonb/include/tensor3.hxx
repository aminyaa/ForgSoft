#pragma once
#ifndef _tensor3_Header
#define _tensor3_Header

#include <TensorN.hxx>
#include <vector3.hxx>
#include <sphericalTensor3.hxx>
#include <diagTensor3.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef TensorN<scalar, 3> tensor3;

	//- Specify data associated with tensor3 type is contiguous
	template<>
	inline bool contiguous<tensor3>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// Include inline implementations

// Klas Jareteg: 2012-10-10 Not implemented!
//#include "tensor3I.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_tensor3_Header
