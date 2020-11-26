#pragma once
#ifndef _diagTensor2_Header
#define _diagTensor2_Header

#include <DiagTensorN.hxx>
#include <vector2.hxx>
#include <sphericalTensor2.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef DiagTensorN<scalar, 2> diagTensor2;

	//- Specify data associated with diagTensor2 type is contiguous
	template<>
	inline bool contiguous<diagTensor2>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

#include <diagTensor2I.hxx>

#endif // !_diagTensor2_Header
