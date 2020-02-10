#pragma once
#ifndef _diagTensor4_Header
#define _diagTensor4_Header

#include <DiagTensorN.hxx>
#include <vector4.hxx>
#include <sphericalTensor4.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef DiagTensorN<scalar, 4> diagTensor4;

	//- Specify data associated with diagTensor4 type is contiguous
	template<>
	inline bool contiguous<diagTensor4>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_diagTensor4_Header
