#pragma once
#ifndef _diagTensor3_Header
#define _diagTensor3_Header

#include <DiagTensorN.hxx>
#include <vector3.hxx>
#include <sphericalTensor3.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef DiagTensorN<scalar, 3> diagTensor3;

	//- Specify data associated with diagTensor3 type is contiguous
	template<>
	inline bool contiguous<diagTensor3>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// Include inline implementations

// Klas Jareteg: 2012-10-10 Not implemented!
//#include "diagTensor3I.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_diagTensor3_Header
