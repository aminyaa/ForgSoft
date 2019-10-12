#pragma once
#ifndef _labelDiagTensor_Header
#define _labelDiagTensor_Header

#include <DiagTensorTemplate.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef DiagTensor<label> labelDiagTensor;

	//- Data associated with labelDiagTensor type are contiguous
	template<>
	inline bool contiguous<labelDiagTensor>() { return true; }
}

#endif // !_labelDiagTensor_Header
