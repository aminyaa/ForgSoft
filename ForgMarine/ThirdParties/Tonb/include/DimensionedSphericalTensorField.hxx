#pragma once
#ifndef _DimensionedSphericalTensorField_Header
#define _DimensionedSphericalTensorField_Header

#include <DimensionedField.hxx>
#include <sphericalTensor.hxx>

#define TEMPLATE template<class GeoMesh>
#include <DimensionedFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> tr(const DimensionedField<sphericalTensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> tr(const tmp<DimensionedField<sphericalTensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> sph(const DimensionedField<sphericalTensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> sph(const tmp<DimensionedField<sphericalTensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> det(const DimensionedField<sphericalTensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> det(const tmp<DimensionedField<sphericalTensor, GeoMesh>>& tdf1);
		
	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> inv(const DimensionedField<sphericalTensor, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> inv(const tmp<DimensionedField<sphericalTensor, GeoMesh>>& tdf1);

		
	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                           , const DimensionedField<sphericalTensor, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                           , const tmp<DimensionedField<sphericalTensor, GeoMesh>>&
	                                                           tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                           , const DimensionedField<sphericalTensor, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                           , const tmp<DimensionedField<sphericalTensor, GeoMesh>>&
	                                                           tdf2);
		
	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                           , const DimensionedField<sphericalTensor, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> operator /(const scalar& t1
	                                                           , const DimensionedField<sphericalTensor, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                           , const tmp<DimensionedField<sphericalTensor, GeoMesh>>&
	                                                           tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> operator /(const scalar& t1
	                                                           , const tmp<DimensionedField<sphericalTensor, GeoMesh>>&
	                                                           tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                           , const dimensioned<sphericalTensor>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                           , const sphericalTensor& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                           , const dimensioned<sphericalTensor>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                           , const sphericalTensor& t2);


		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <undefFieldFunctionsM.hxx>

#ifdef NoRepository
#   include <DimensionedSphericalTensorField.cxx>
#endif

#endif // !_DimensionedSphericalTensorField_Header
