#pragma once
#ifndef _tensor_Header
#define _tensor_Header

#include <TensorTemplate.hxx>
#include <vector.hxx>
#include <sphericalTensor.hxx>
#include <symmTensor.hxx>
#include <contiguous.hxx>

namespace AutLib
{

	typedef Tensor<scalar> tensor;

	vector eigenValues(const tensor&);
	vector eigenVector(const tensor&, const scalar lambda);
	tensor eigenVectors(const tensor&);

	vector eigenValues(const symmTensor&);
	vector eigenVector(const symmTensor&, const scalar lambda);
	tensor eigenVectors(const symmTensor&);

	// Tensor inverse with singular value decomposition
	// (Householder transformations)
	// HJ, 24/Oct/2009
	tensor hinv(const tensor& t);
	symmTensor hinv(const symmTensor& t);


	//- Data associated with tensor type are contiguous
	template<>
	inline bool contiguous<tensor>() { return true; }
}

#endif // !_tensor_Header
