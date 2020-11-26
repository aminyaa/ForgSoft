#pragma once
#ifndef _tensor4_Header
#define _tensor4_Header

#include <TensorN.hxx>
#include <vector4.hxx>
#include <sphericalTensor4.hxx>
#include <diagTensor4.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef TensorN<scalar, 4> tensor4;

	//- Specify data associated with tensor4 type is contiguous
	template<>
	inline bool contiguous<tensor4>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

#include <tensor4I.hxx>

#endif // !_tensor4_Header
