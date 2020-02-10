#pragma once
#ifndef _diagTensor8_Header
#define _diagTensor8_Header

#include <DiagTensorN.hxx>
#include <vector8.hxx>
#include <sphericalTensor8.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef DiagTensorN<scalar, 8> diagTensor8;

	//- Specify data associated with diagTensor8 type is contiguous
	template<>
	inline bool contiguous<diagTensor8>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_diagTensor8_Header
