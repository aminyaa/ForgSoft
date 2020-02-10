#pragma once
#ifndef _GeometricSphericalTensorNFields_Header
#define _GeometricSphericalTensorNFields_Header

#include <GeometricField.hxx>
#include <DimensionedSphericalTensorNFields.hxx>
#include <SphericalTensorNFieldFields.hxx>

#define TEMPLATE template<template<class> class PatchField, class GeoMesh>
#include <GeometricFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define SphericalTensorN_FieldFunctions(tensorType, diagTensorType, sphericalTensorType, vectorType, CmptType, args) \
                                                                                    \
UNARY_FUNCTION(sphericalTensorType, sphericalTensorType,inv,inv)                    \
UNARY_FUNCTION(sphericalTensorType, sphericalTensorType,diag,diag)                  \
                                                                                    \
BINARY_OPERATOR(sphericalTensorType, CmptType, sphericalTensorType, *,'*',multiply)                   \
BINARY_TYPE_OPERATOR(sphericalTensorType, CmptType, sphericalTensorType, *,'*',multiply)              \
                                                                                    \
BINARY_OPERATOR(sphericalTensorType, CmptType, sphericalTensorType, /,'|',divide)   \
BINARY_TYPE_OPERATOR(sphericalTensorType, CmptType, sphericalTensorType, /,'|',divide) \
                                                                                    \
BINARY_OPERATOR(vectorType, vectorType, sphericalTensorType, /,'|',divide)          \
BINARY_TYPE_OPERATOR(vectorType, vectorType, sphericalTensorType, /,'|',divide)     \
                                                                                    \
BINARY_OPERATOR(sphericalTensorType, sphericalTensorType, sphericalTensorType, /,'|',divide)          \
BINARY_TYPE_OPERATOR(sphericalTensorType, sphericalTensorType, sphericalTensorType, /,'|',divide)     \
                                                                                    \
BINARY_OPERATOR(sphericalTensorType, sphericalTensorType, sphericalTensorType, +,'+',add)             \
BINARY_OPERATOR(sphericalTensorType, sphericalTensorType, sphericalTensorType, -,'-',subtract)        \
                                                                                    \
BINARY_TYPE_OPERATOR(sphericalTensorType, sphericalTensorType, sphericalTensorType, +,'+',add)        \
BINARY_TYPE_OPERATOR(sphericalTensorType, sphericalTensorType, sphericalTensorType, -,'-',subtract)


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> inv(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> inv(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> diag(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> diag(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const sphericalTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const sphericalTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const sphericalTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const sphericalTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<
		                                                             sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<
		                                                             sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const dimensioned<vector2>& dt1,
	                                                             const GeometricField<
		                                                             sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const vector2& t1,
	                                                             const GeometricField<
		                                                             sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const dimensioned<vector2>& dt1,
	                                                             const tmp<GeometricField<
		                                                             sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const vector2& t1,
	                                                             const tmp<GeometricField<
		                                                             sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<sphericalTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                             const sphericalTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1, const sphericalTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor2>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(const sphericalTensor2& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor2>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(const sphericalTensor2& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1, const sphericalTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1, const sphericalTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor2>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator +(const sphericalTensor2& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor2>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator +(const sphericalTensor2& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1, const sphericalTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1, const sphericalTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor2>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator -(const sphericalTensor2& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor2>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator -(const sphericalTensor2& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1, const sphericalTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1, const sphericalTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> inv(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> inv(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> diag(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> diag(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const sphericalTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const sphericalTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const sphericalTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const sphericalTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<
		                                                             sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<
		                                                             sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const dimensioned<vector3>& dt1,
	                                                             const GeometricField<
		                                                             sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const vector3& t1,
	                                                             const GeometricField<
		                                                             sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const dimensioned<vector3>& dt1,
	                                                             const tmp<GeometricField<
		                                                             sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const vector3& t1,
	                                                             const tmp<GeometricField<
		                                                             sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<sphericalTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                             const sphericalTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1, const sphericalTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor3>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(const sphericalTensor3& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor3>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(const sphericalTensor3& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1, const sphericalTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1, const sphericalTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor3>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator +(const sphericalTensor3& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor3>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator +(const sphericalTensor3& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1, const sphericalTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1, const sphericalTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor3>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator -(const sphericalTensor3& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor3>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator -(const sphericalTensor3& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1, const sphericalTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1, const sphericalTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> inv(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> inv(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> diag(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> diag(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const sphericalTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const sphericalTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const sphericalTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const sphericalTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<
		                                                             sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<
		                                                             sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const dimensioned<vector4>& dt1,
	                                                             const GeometricField<
		                                                             sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const vector4& t1,
	                                                             const GeometricField<
		                                                             sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const dimensioned<vector4>& dt1,
	                                                             const tmp<GeometricField<
		                                                             sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const vector4& t1,
	                                                             const tmp<GeometricField<
		                                                             sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<sphericalTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                             const sphericalTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1, const sphericalTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor4>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(const sphericalTensor4& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor4>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(const sphericalTensor4& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1, const sphericalTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1, const sphericalTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor4>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator +(const sphericalTensor4& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor4>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator +(const sphericalTensor4& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1, const sphericalTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1, const sphericalTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor4>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator -(const sphericalTensor4& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor4>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator -(const sphericalTensor4& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1, const sphericalTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1, const sphericalTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> inv(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> inv(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> diag(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> diag(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const sphericalTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const sphericalTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const sphericalTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const sphericalTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<
		                                                             sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<
		                                                             sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const dimensioned<vector6>& dt1,
	                                                             const GeometricField<
		                                                             sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const vector6& t1,
	                                                             const GeometricField<
		                                                             sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const dimensioned<vector6>& dt1,
	                                                             const tmp<GeometricField<
		                                                             sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const vector6& t1,
	                                                             const tmp<GeometricField<
		                                                             sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<sphericalTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                             const sphericalTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1, const sphericalTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor6>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(const sphericalTensor6& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor6>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(const sphericalTensor6& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1, const sphericalTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1, const sphericalTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor6>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator +(const sphericalTensor6& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor6>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator +(const sphericalTensor6& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1, const sphericalTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1, const sphericalTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor6>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator -(const sphericalTensor6& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor6>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator -(const sphericalTensor6& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1, const sphericalTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1, const sphericalTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> inv(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> inv(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> diag(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> diag(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const sphericalTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const sphericalTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const sphericalTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const sphericalTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<
		                                                             sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<
		                                                             sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const dimensioned<vector8>& dt1,
	                                                             const GeometricField<
		                                                             sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const vector8& t1,
	                                                             const GeometricField<
		                                                             sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const dimensioned<vector8>& dt1,
	                                                             const tmp<GeometricField<
		                                                             sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const vector8& t1,
	                                                             const tmp<GeometricField<
		                                                             sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<sphericalTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                             const sphericalTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1, const sphericalTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor8>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(const sphericalTensor8& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor8>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(const sphericalTensor8& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1, const sphericalTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1, const sphericalTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor8>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator +(const sphericalTensor8& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor8>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator +(const sphericalTensor8& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1, const sphericalTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1, const sphericalTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor8>& dt1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator -(const sphericalTensor8& t1,
	                                                                      const GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor8>& dt1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator -(const sphericalTensor8& t1,
	                                                                      const tmp<GeometricField<
		                                                                      sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1, const sphericalTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1, const sphericalTensor8& t2);

}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#undef SphericalTensorN_FieldFunctions

#include <undefFieldFunctionsM.hxx>

 // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <GeometricSphericalTensorNFields.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_GeometricSphericalTensorNFields_Header
