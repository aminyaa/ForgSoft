#pragma once
#ifndef _tensor8_Header
#define _tensor8_Header

#include <TensorN.hxx>
#include <vector8.hxx>
#include <sphericalTensor8.hxx>
#include <diagTensor8.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef TensorN<scalar, 8> tensor8;

	//- Specify data associated with tensor8 type is contiguous
	template<>
	inline bool contiguous<tensor8>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_tensor8_Header
