#pragma once
#ifndef _GeometricVectorNFields_Header
#define _GeometricVectorNFields_Header

#include <GeometricField.hxx>
#include <DimensionedVectorNFields.hxx>
#include <VectorNFieldFields.hxx>

#define TEMPLATE template<template<class> class PatchField, class GeoMesh>
#include <GeometricFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define VectorN_FieldFunctions(tensorType, diagTensorType, sphericalTensorType, \
    vectorType, CmptType, args)                                              \
                                                                                \
UNARY_FUNCTION(CmptType, vectorType, cmptSum, cmptSum)                          \
                                                                                \
BINARY_FUNCTION(vectorType, vectorType, vectorType, cmptMultiply)               \
BINARY_TYPE_FUNCTION(vectorType, vectorType, vectorType, cmptMultiply)          \
                                                                                \
BINARY_OPERATOR(vectorType, CmptType, vectorType, *,'*',multiply)               \
BINARY_TYPE_OPERATOR(vectorType, CmptType, vectorType, *,'*',multiply)          \
                                                                                \
BINARY_OPERATOR(vectorType, CmptType, vectorType, /,'|',divide)                 \
BINARY_TYPE_OPERATOR(vectorType, CmptType, vectorType, /,'|',divide)            \
                                                                                \
BINARY_OPERATOR(vectorType, vectorType, vectorType, +,'+',add)                  \
BINARY_OPERATOR(vectorType, vectorType, vectorType, -,'-',subtract)             \
                                                                                \
BINARY_TYPE_OPERATOR(vectorType, vectorType, vectorType, +,'+',add)             \
BINARY_TYPE_OPERATOR(vectorType, vectorType, vectorType, -,'-',subtract)


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>> cmptSum(const GeometricField<vector2, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>>
	cmptSum(const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                               const GeometricField<vector2, PatchField, GeoMesh>&
	                                                               df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                               const tmp<GeometricField<vector2, PatchField, GeoMesh>>&
	                                                               tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> cmptMultiply(const dimensioned<vector2>& dt1,
	                                                               const GeometricField<vector2, PatchField, GeoMesh>&
	                                                               df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> cmptMultiply(const vector2& t1,
	                                                               const GeometricField<vector2, PatchField, GeoMesh>&
	                                                               df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> cmptMultiply(const dimensioned<vector2>& dt1,
	                                                               const tmp<GeometricField<vector2, PatchField, GeoMesh>>&
	                                                               tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> cmptMultiply(const vector2& t1,
	                                                               const tmp<GeometricField<vector2, PatchField, GeoMesh>>&
	                                                               tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                               const dimensioned<vector2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                               const vector2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1, const dimensioned<vector2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf2, const vector2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector2, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                             const GeometricField<vector2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                             const GeometricField<vector2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                             const tmp<GeometricField<vector2, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                             const tmp<GeometricField<vector2, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const vector2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<vector2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const vector2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector2, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                             const GeometricField<vector2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                             const GeometricField<vector2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                             const tmp<GeometricField<vector2, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                             const tmp<GeometricField<vector2, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const vector2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<vector2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const vector2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator +(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator +(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector2, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator -(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator -(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector2, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator +(const dimensioned<vector2>& dt1,
	                                                             const GeometricField<vector2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator +(const vector2& t1,
	                                                             const GeometricField<vector2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator +(const dimensioned<vector2>& dt1,
	                                                             const tmp<GeometricField<vector2, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator +(const vector2& t1,
	                                                             const tmp<GeometricField<vector2, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator +(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator +(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                             const vector2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1, const dimensioned<vector2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1, const vector2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator -(const dimensioned<vector2>& dt1,
	                                                             const GeometricField<vector2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator -(const vector2& t1,
	                                                             const GeometricField<vector2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator -(const dimensioned<vector2>& dt1,
	                                                             const tmp<GeometricField<vector2, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator -(const vector2& t1,
	                                                             const tmp<GeometricField<vector2, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator -(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator -(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                             const vector2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1, const dimensioned<vector2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1, const vector2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>> cmptSum(const GeometricField<vector3, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>>
	cmptSum(const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                               const GeometricField<vector3, PatchField, GeoMesh>&
	                                                               df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                               const tmp<GeometricField<vector3, PatchField, GeoMesh>>&
	                                                               tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> cmptMultiply(const dimensioned<vector3>& dt1,
	                                                               const GeometricField<vector3, PatchField, GeoMesh>&
	                                                               df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> cmptMultiply(const vector3& t1,
	                                                               const GeometricField<vector3, PatchField, GeoMesh>&
	                                                               df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> cmptMultiply(const dimensioned<vector3>& dt1,
	                                                               const tmp<GeometricField<vector3, PatchField, GeoMesh>>&
	                                                               tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> cmptMultiply(const vector3& t1,
	                                                               const tmp<GeometricField<vector3, PatchField, GeoMesh>>&
	                                                               tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                               const dimensioned<vector3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                               const vector3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1, const dimensioned<vector3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf2, const vector3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector3, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                             const GeometricField<vector3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                             const GeometricField<vector3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                             const tmp<GeometricField<vector3, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                             const tmp<GeometricField<vector3, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const vector3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<vector3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const vector3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector3, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                             const GeometricField<vector3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                             const GeometricField<vector3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                             const tmp<GeometricField<vector3, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                             const tmp<GeometricField<vector3, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const vector3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<vector3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const vector3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator +(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator +(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector3, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator -(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator -(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector3, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator +(const dimensioned<vector3>& dt1,
	                                                             const GeometricField<vector3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator +(const vector3& t1,
	                                                             const GeometricField<vector3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator +(const dimensioned<vector3>& dt1,
	                                                             const tmp<GeometricField<vector3, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator +(const vector3& t1,
	                                                             const tmp<GeometricField<vector3, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator +(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator +(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                             const vector3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1, const dimensioned<vector3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1, const vector3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator -(const dimensioned<vector3>& dt1,
	                                                             const GeometricField<vector3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator -(const vector3& t1,
	                                                             const GeometricField<vector3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator -(const dimensioned<vector3>& dt1,
	                                                             const tmp<GeometricField<vector3, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator -(const vector3& t1,
	                                                             const tmp<GeometricField<vector3, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator -(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator -(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                             const vector3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1, const dimensioned<vector3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1, const vector3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>> cmptSum(const GeometricField<vector4, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>>
	cmptSum(const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                               const GeometricField<vector4, PatchField, GeoMesh>&
	                                                               df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                               const tmp<GeometricField<vector4, PatchField, GeoMesh>>&
	                                                               tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> cmptMultiply(const dimensioned<vector4>& dt1,
	                                                               const GeometricField<vector4, PatchField, GeoMesh>&
	                                                               df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> cmptMultiply(const vector4& t1,
	                                                               const GeometricField<vector4, PatchField, GeoMesh>&
	                                                               df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> cmptMultiply(const dimensioned<vector4>& dt1,
	                                                               const tmp<GeometricField<vector4, PatchField, GeoMesh>>&
	                                                               tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> cmptMultiply(const vector4& t1,
	                                                               const tmp<GeometricField<vector4, PatchField, GeoMesh>>&
	                                                               tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                               const dimensioned<vector4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                               const vector4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1, const dimensioned<vector4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf2, const vector4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector4, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                             const GeometricField<vector4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                             const GeometricField<vector4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                             const tmp<GeometricField<vector4, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                             const tmp<GeometricField<vector4, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const vector4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<vector4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const vector4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector4, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                             const GeometricField<vector4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                             const GeometricField<vector4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                             const tmp<GeometricField<vector4, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                             const tmp<GeometricField<vector4, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const vector4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<vector4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const vector4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator +(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator +(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector4, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator -(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator -(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector4, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator +(const dimensioned<vector4>& dt1,
	                                                             const GeometricField<vector4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator +(const vector4& t1,
	                                                             const GeometricField<vector4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator +(const dimensioned<vector4>& dt1,
	                                                             const tmp<GeometricField<vector4, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator +(const vector4& t1,
	                                                             const tmp<GeometricField<vector4, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator +(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator +(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                             const vector4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1, const dimensioned<vector4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1, const vector4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator -(const dimensioned<vector4>& dt1,
	                                                             const GeometricField<vector4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator -(const vector4& t1,
	                                                             const GeometricField<vector4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator -(const dimensioned<vector4>& dt1,
	                                                             const tmp<GeometricField<vector4, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator -(const vector4& t1,
	                                                             const tmp<GeometricField<vector4, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator -(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator -(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                             const vector4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1, const dimensioned<vector4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1, const vector4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>> cmptSum(const GeometricField<vector6, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>>
	cmptSum(const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                               const GeometricField<vector6, PatchField, GeoMesh>&
	                                                               df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                               const tmp<GeometricField<vector6, PatchField, GeoMesh>>&
	                                                               tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> cmptMultiply(const dimensioned<vector6>& dt1,
	                                                               const GeometricField<vector6, PatchField, GeoMesh>&
	                                                               df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> cmptMultiply(const vector6& t1,
	                                                               const GeometricField<vector6, PatchField, GeoMesh>&
	                                                               df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> cmptMultiply(const dimensioned<vector6>& dt1,
	                                                               const tmp<GeometricField<vector6, PatchField, GeoMesh>>&
	                                                               tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> cmptMultiply(const vector6& t1,
	                                                               const tmp<GeometricField<vector6, PatchField, GeoMesh>>&
	                                                               tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                               const dimensioned<vector6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                               const vector6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1, const dimensioned<vector6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf2, const vector6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector6, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                             const GeometricField<vector6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                             const GeometricField<vector6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                             const tmp<GeometricField<vector6, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                             const tmp<GeometricField<vector6, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const vector6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<vector6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const vector6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector6, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                             const GeometricField<vector6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                             const GeometricField<vector6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                             const tmp<GeometricField<vector6, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                             const tmp<GeometricField<vector6, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const vector6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<vector6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const vector6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator +(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator +(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector6, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator -(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator -(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector6, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator +(const dimensioned<vector6>& dt1,
	                                                             const GeometricField<vector6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator +(const vector6& t1,
	                                                             const GeometricField<vector6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator +(const dimensioned<vector6>& dt1,
	                                                             const tmp<GeometricField<vector6, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator +(const vector6& t1,
	                                                             const tmp<GeometricField<vector6, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator +(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator +(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                             const vector6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1, const dimensioned<vector6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1, const vector6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator -(const dimensioned<vector6>& dt1,
	                                                             const GeometricField<vector6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator -(const vector6& t1,
	                                                             const GeometricField<vector6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator -(const dimensioned<vector6>& dt1,
	                                                             const tmp<GeometricField<vector6, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator -(const vector6& t1,
	                                                             const tmp<GeometricField<vector6, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator -(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator -(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                             const vector6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1, const dimensioned<vector6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1, const vector6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>> cmptSum(const GeometricField<vector8, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>>
	cmptSum(const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                               const GeometricField<vector8, PatchField, GeoMesh>&
	                                                               df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                               const tmp<GeometricField<vector8, PatchField, GeoMesh>>&
	                                                               tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> cmptMultiply(const dimensioned<vector8>& dt1,
	                                                               const GeometricField<vector8, PatchField, GeoMesh>&
	                                                               df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> cmptMultiply(const vector8& t1,
	                                                               const GeometricField<vector8, PatchField, GeoMesh>&
	                                                               df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> cmptMultiply(const dimensioned<vector8>& dt1,
	                                                               const tmp<GeometricField<vector8, PatchField, GeoMesh>>&
	                                                               tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> cmptMultiply(const vector8& t1,
	                                                               const tmp<GeometricField<vector8, PatchField, GeoMesh>>&
	                                                               tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                               const dimensioned<vector8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> cmptMultiply(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                               const vector8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1, const dimensioned<vector8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> cmptMultiply(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf2, const vector8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector8, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                             const GeometricField<vector8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                             const GeometricField<vector8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                             const tmp<GeometricField<vector8, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                             const tmp<GeometricField<vector8, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator *(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const vector8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<vector8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const vector8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector8, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                             const GeometricField<vector8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                             const GeometricField<vector8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                             const tmp<GeometricField<vector8, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                             const tmp<GeometricField<vector8, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const GeometricField<scalar, PatchField, GeoMesh>& df1,
	                                                             const vector8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<vector8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const vector8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator +(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator +(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector8, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator -(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<vector8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator -(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<vector8, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1,
		const GeometricField<vector8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator +(const dimensioned<vector8>& dt1,
	                                                             const GeometricField<vector8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator +(const vector8& t1,
	                                                             const GeometricField<vector8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator +(const dimensioned<vector8>& dt1,
	                                                             const tmp<GeometricField<vector8, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator +(const vector8& t1,
	                                                             const tmp<GeometricField<vector8, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator +(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator +(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                             const vector8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1, const dimensioned<vector8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1, const vector8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator -(const dimensioned<vector8>& dt1,
	                                                             const GeometricField<vector8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator -(const vector8& t1,
	                                                             const GeometricField<vector8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator -(const dimensioned<vector8>& dt1,
	                                                             const tmp<GeometricField<vector8, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator -(const vector8& t1,
	                                                             const tmp<GeometricField<vector8, PatchField, GeoMesh>>&
	                                                             tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator -(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<vector8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator -(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                             const vector8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1, const dimensioned<vector8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1, const vector8& t2);

}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#undef VectorN_FieldFunctions

#include <undefFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <GeometricVectorNFields.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_GeometricVectorNFields_Header
