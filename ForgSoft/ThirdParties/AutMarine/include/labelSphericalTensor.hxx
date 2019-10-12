#pragma once
#ifndef _labelSphericalTensor_Header
#define _labelSphericalTensor_Header

#include <SphericalTensorTemplate.hxx>
#include <contiguous.hxx>

namespace AutLib
{
	typedef SphericalTensor<label> labelSphericalTensor;

	//- Global identity labelTensor
	static const labelSphericalTensor labelI(1);

	//- Data associated with labelSphericalTensor type are contiguous
	template<>
	inline bool contiguous<labelSphericalTensor>() { return true; }
}

#endif // !_labelSphericalTensor_Header
