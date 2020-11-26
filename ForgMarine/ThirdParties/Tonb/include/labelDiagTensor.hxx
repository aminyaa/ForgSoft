#pragma once
#ifndef _labelDiagTensor_Header
#define _labelDiagTensor_Header

#include <DiagTensorTemplate.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef DiagTensor<label> labelDiagTensor;

	//- Data associated with labelDiagTensor type are contiguous
	template<>
	inline bool contiguous<labelDiagTensor>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_labelDiagTensor_Header
