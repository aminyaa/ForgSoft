#pragma once
#ifndef _DimensionedSymmTensorField_Header
#define _DimensionedSymmTensorField_Header

#include <DimensionedField.hxx>
#include <symmTensor.hxx>
#include <sphericalTensor.hxx>

#define TEMPLATE template<class GeoMesh>
#include <DimensionedFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> sqr(const DimensionedField<vector, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> sqr(const tmp<DimensionedField<vector, GeoMesh>>& tdf1);

		
	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> tr(const DimensionedField<symmTensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> tr(const tmp<DimensionedField<symmTensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> sph(const DimensionedField<symmTensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> sph(const tmp<DimensionedField<symmTensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> symm(const DimensionedField<symmTensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> symm(const tmp<DimensionedField<symmTensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> twoSymm(const DimensionedField<symmTensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> twoSymm(const tmp<DimensionedField<symmTensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> dev(const DimensionedField<symmTensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> dev(const tmp<DimensionedField<symmTensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> dev2(const DimensionedField<symmTensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> dev2(const tmp<DimensionedField<symmTensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> det(const DimensionedField<symmTensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> det(const tmp<DimensionedField<symmTensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> cof(const DimensionedField<symmTensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> cof(const tmp<DimensionedField<symmTensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> inv(const DimensionedField<symmTensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> inv(const tmp<DimensionedField<symmTensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> hinv(const DimensionedField<symmTensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<symmTensor, GeoMesh>> hinv(const tmp<DimensionedField<symmTensor, GeoMesh>>& tdf1);


		// * * * * * * * * * * * * * * * global operators  * * * * * * * * * * * * * //

		
	template <class GeoMesh>
	tmp<DimensionedField<vector, GeoMesh>> operator *(const DimensionedField<symmTensor, GeoMesh>& df1);

	template <class GeoMesh>
	tmp<DimensionedField<vector, GeoMesh>> operator *(const tmp<DimensionedField<symmTensor, GeoMesh>>& tdf1);


		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <undefFieldFunctionsM.hxx>

#ifdef NoRepository
#   include <DimensionedSymmTensorField.cxx>
#endif

#endif // !_DimensionedSymmTensorField_Header
