#pragma once
#ifndef _tensor2D_Header
#define _tensor2D_Header

#include <Tensor2DTemplate.hxx>
#include <vector2D.hxx>
#include <contiguous.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef Tensor2D<scalar> tensor2D;

	vector2D eigenValues(const tensor2D& t);
	vector2D eigenVector(const tensor2D& t, const scalar lambda);
	tensor2D eigenVectors(const tensor2D& t);

	//- Data associated with tensor2D type are contiguous
	template<>
	inline bool contiguous<tensor2D>() { return true; }


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <sphericalTensor2D.hxx>

#endif // !_tensor2D_Header
