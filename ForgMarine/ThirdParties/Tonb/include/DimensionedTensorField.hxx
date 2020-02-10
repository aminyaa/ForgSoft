#pragma once
#ifndef _DimensionedTensorField_Header
#define _DimensionedTensorField_Header

#include <DimensionedSphericalTensorField.hxx>
#include <DimensionedSymmTensorField.hxx>
#include <tensor.hxx>

#define TEMPLATE template<class GeoMesh>
#include <DimensionedFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> tr(const DimensionedField<tensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> tr(const tmp<DimensionedField<tensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> sph(const DimensionedField<tensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> sph(const tmp<DimensionedField<tensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> symm(const DimensionedField<tensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> symm(const tmp<DimensionedField<tensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> twoSymm(const DimensionedField<tensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> twoSymm(const tmp<DimensionedField<tensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<tensor, GeoMesh>> skew(const DimensionedField<tensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<tensor, GeoMesh>> skew(const tmp<DimensionedField<tensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<tensor, GeoMesh>> dev(const DimensionedField<tensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<tensor, GeoMesh>> dev(const tmp<DimensionedField<tensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<tensor, GeoMesh>> dev2(const DimensionedField<tensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<tensor, GeoMesh>> dev2(const tmp<DimensionedField<tensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> det(const DimensionedField<tensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> det(const tmp<DimensionedField<tensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<tensor, GeoMesh>> cof(const DimensionedField<tensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<tensor, GeoMesh>> cof(const tmp<DimensionedField<tensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<tensor, GeoMesh>> inv(const DimensionedField<tensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<tensor, GeoMesh>> inv(const tmp<DimensionedField<tensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<tensor, GeoMesh>> hinv(const DimensionedField<tensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<tensor, GeoMesh>> hinv(const tmp<DimensionedField<tensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<vector, GeoMesh>> eigenValues(const DimensionedField<tensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<vector, GeoMesh>> eigenValues(const tmp<DimensionedField<tensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<tensor, GeoMesh>> eigenVectors(const DimensionedField<tensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<tensor, GeoMesh>> eigenVectors(const tmp<DimensionedField<tensor, GeoMesh>>& tdf1);

		
	template <class GeoMesh>
	tmp<DimensionedField<vector, GeoMesh>> eigenValues(const DimensionedField<symmTensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<vector, GeoMesh>> eigenValues(const tmp<DimensionedField<symmTensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> eigenVectors(const DimensionedField<symmTensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> eigenVectors(const tmp<DimensionedField<symmTensor, GeoMesh>>& tdf1);


		// * * * * * * * * * * * * * * * global operators  * * * * * * * * * * * * * //

		
	template <class GeoMesh>
	tmp<DimensionedField<vector, GeoMesh>> operator *(const DimensionedField<tensor, GeoMesh>& df1);

	template <class GeoMesh>
	tmp<DimensionedField<vector, GeoMesh>> operator *(const tmp<DimensionedField<tensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<tensor, GeoMesh>> operator *(const DimensionedField<vector, GeoMesh>& df1);

	template <class GeoMesh>
	tmp<DimensionedField<tensor, GeoMesh>> operator *(const tmp<DimensionedField<vector, GeoMesh>>& tdf1);


		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <undefFieldFunctionsM.hxx>

#ifdef NoRepository
#   include <DimensionedTensorField.cxx>
#endif

#endif // !_DimensionedTensorField_Header
