#pragma once
#ifndef _tensor6_Header
#define _tensor6_Header

#include <TensorN.hxx>
#include <Vector6.hxx>
#include <sphericalTensor6.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef TensorN<scalar, 6> tensor6;

	//- Specify data associated with tensor6 type is contiguous
	template<>
	inline bool contiguous<tensor6>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_tensor6_Header
