#pragma once
#ifndef _diagTensor6_Header
#define _diagTensor6_Header

#include <DiagTensorN.hxx>
#include <Vector6.hxx>
#include <sphericalTensor6.hxx>
#include <contiguous.hxx>

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef DiagTensorN<scalar, 6> diagTensor6;

	//- Specify data associated with diagTensor6 type is contiguous
	template<>
	inline bool contiguous<diagTensor6>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_diagTensor6_Header
