#pragma once
#ifndef _tensor2_Header
#define _tensor2_Header

#include <TensorN.hxx>
#include <vector2.hxx>
#include <sphericalTensor2.hxx>
#include <diagTensor2.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef TensorN<scalar, 2> tensor2;

	//- Specify data associated with tensor2 type is contiguous
	template<>
	inline bool contiguous<tensor2>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

#include <tensor2I.hxx>

#endif // !_tensor2_Header
