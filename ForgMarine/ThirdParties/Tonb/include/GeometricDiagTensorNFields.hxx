#pragma once
#ifndef _GeometricDiagTensorNFields_Header
#define _GeometricDiagTensorNFields_Header

#include <GeometricField.hxx>
#include <DimensionedDiagTensorNFields.hxx>
#include <DiagTensorNFieldFields.hxx>

#define TEMPLATE template<template<class> class PatchField, class GeoMesh>
#include <GeometricFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define DiagTensorN_FieldFunctions(tensorType, diagTensorType, sphericalTensorType, vectorType, CmptType, args) \
                                                                                        \
UNARY_FUNCTION(diagTensorType, diagTensorType,inv,inv)                                  \
UNARY_FUNCTION(diagTensorType, diagTensorType,diag,diag)                                \
UNARY_FUNCTION(CmptType, diagTensorType,contractScalar,contractScalar)                  \
UNARY_FUNCTION(vectorType, diagTensorType,contractLinear,contractLinear)                \
                                                                                        \
BINARY_OPERATOR(diagTensorType, CmptType, diagTensorType, /,'|',divide)                 \
BINARY_TYPE_OPERATOR(diagTensorType, CmptType, diagTensorType, /,'|',divide)            \
                                                                                        \
BINARY_OPERATOR(diagTensorType, CmptType, diagTensorType, *,'*',multiply)               \
BINARY_TYPE_OPERATOR(diagTensorType, CmptType, diagTensorType, *,'*',multiply)          \
                                                                                        \
BINARY_OPERATOR(vectorType, vectorType, diagTensorType, /,'|',divide)                   \
BINARY_TYPE_OPERATOR(vectorType, vectorType, diagTensorType, /,'|',divide)              \
                                                                                        \
BINARY_OPERATOR(diagTensorType, diagTensorType, diagTensorType, /,'|',divide)           \
BINARY_TYPE_OPERATOR(diagTensorType, diagTensorType, diagTensorType, /,'|',divide)      \
                                                                                        \
BINARY_OPERATOR(diagTensorType, sphericalTensorType, diagTensorType, /,'|',divide)      \
BINARY_TYPE_OPERATOR(diagTensorType, sphericalTensorType, diagTensorType, /,'|',divide) \
                                                                                        \
BINARY_OPERATOR(diagTensorType, diagTensorType, sphericalTensorType, /,'|',divide)      \
BINARY_TYPE_OPERATOR(diagTensorType, diagTensorType, sphericalTensorType, /,'|',divide) \
                                                                                        \
BINARY_OPERATOR(diagTensorType, diagTensorType, diagTensorType, +,'+',add)              \
BINARY_OPERATOR(diagTensorType, diagTensorType, diagTensorType, -,'-',subtract)         \
                                                                                        \
BINARY_TYPE_OPERATOR(diagTensorType, diagTensorType, diagTensorType, +,'+', add)        \
BINARY_TYPE_OPERATOR(diagTensorType, diagTensorType, diagTensorType, -,'-', subtract)   \
                                                                                        \
BINARY_OPERATOR(diagTensorType, sphericalTensorType, diagTensorType, +,'+', add)        \
BINARY_OPERATOR(diagTensorType, sphericalTensorType, diagTensorType, -,'-', subtract)   \
                                                                                        \
BINARY_TYPE_OPERATOR(diagTensorType, sphericalTensorType, diagTensorType, +,'+', add)   \
BINARY_TYPE_OPERATOR(diagTensorType, sphericalTensorType, diagTensorType, -,'-', subtract)  \
                                                                                        \
BINARY_OPERATOR(diagTensorType, diagTensorType, sphericalTensorType, +,'+', add)        \
BINARY_OPERATOR(diagTensorType, diagTensorType, sphericalTensorType, -,'-', subtract)   \
                                                                                        \
BINARY_TYPE_OPERATOR(diagTensorType, diagTensorType, sphericalTensorType, +,'+', add)   \
BINARY_TYPE_OPERATOR(diagTensorType, diagTensorType, sphericalTensorType, -,'+', subtract)


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> inv(const GeometricField<diagTensor2, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> inv(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> diag(const GeometricField<diagTensor2, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> diag(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>> contractScalar(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>> contractScalar(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> contractLinear(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> contractLinear(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const GeometricField<diagTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                 const GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                 const GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<diagTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const diagTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const diagTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const GeometricField<diagTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                 const GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                 const GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<diagTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const diagTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const diagTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<diagTensor2, PatchField, GeoMesh>&
	                                                             df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                             >& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const dimensioned<vector2>& dt1,
	                                                             const GeometricField<diagTensor2, PatchField, GeoMesh>&
	                                                             df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const vector2& t1,
	                                                             const GeometricField<diagTensor2, PatchField, GeoMesh>&
	                                                             df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const dimensioned<vector2>& dt1,
	                                                             const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                             >& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const vector2& t1,
	                                                             const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                             >& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<diagTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(const GeometricField<vector2, PatchField, GeoMesh>& df1,
	                                                             const diagTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector2, PatchField, GeoMesh>>& tdf1, const diagTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor2>& dt1,
	                                                                 const GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(const diagTensor2& t1,
	                                                                 const GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor2>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(const diagTensor2& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1, const dimensioned<diagTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1, const diagTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1, const diagTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor2>& dt1,
	                                                                 const GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(const sphericalTensor2& t1,
	                                                                 const GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor2>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(const sphericalTensor2& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1, const dimensioned<diagTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1, const diagTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1, const diagTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor2>& dt1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(const diagTensor2& t1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor2>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(const diagTensor2& t1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1, const sphericalTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1, const sphericalTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor2>& dt1,
	                                                                 const GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(const diagTensor2& t1,
	                                                                 const GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor2>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(const diagTensor2& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1, const dimensioned<diagTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1, const diagTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1, const diagTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor2>& dt1,
	                                                                 const GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(const diagTensor2& t1,
	                                                                 const GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor2>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(const diagTensor2& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1, const dimensioned<diagTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1, const diagTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1, const diagTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor2>& dt1,
	                                                                 const GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(const sphericalTensor2& t1,
	                                                                 const GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor2>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(const sphericalTensor2& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1, const dimensioned<diagTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1, const diagTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1, const diagTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor2>& dt1,
	                                                                 const GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(const sphericalTensor2& t1,
	                                                                 const GeometricField<diagTensor2, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor2>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(const sphericalTensor2& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1, const dimensioned<diagTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df1, const diagTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf1, const diagTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor2>& dt1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(const diagTensor2& t1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor2>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(const diagTensor2& t1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1, const sphericalTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1, const sphericalTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor2>& dt1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(const diagTensor2& t1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor2, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor2>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(const diagTensor2& t1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor2, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor2, PatchField, GeoMesh>& df1, const sphericalTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor2>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor2, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor2, PatchField, GeoMesh>>& tdf1, const sphericalTensor2& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> inv(const GeometricField<diagTensor3, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> inv(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> diag(const GeometricField<diagTensor3, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> diag(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>> contractScalar(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>> contractScalar(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> contractLinear(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> contractLinear(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const GeometricField<diagTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                 const GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                 const GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<diagTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const diagTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const diagTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const GeometricField<diagTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                 const GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                 const GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<diagTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const diagTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const diagTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<diagTensor3, PatchField, GeoMesh>&
	                                                             df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                             >& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const dimensioned<vector3>& dt1,
	                                                             const GeometricField<diagTensor3, PatchField, GeoMesh>&
	                                                             df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const vector3& t1,
	                                                             const GeometricField<diagTensor3, PatchField, GeoMesh>&
	                                                             df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const dimensioned<vector3>& dt1,
	                                                             const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                             >& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const vector3& t1,
	                                                             const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                             >& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<diagTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(const GeometricField<vector3, PatchField, GeoMesh>& df1,
	                                                             const diagTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector3, PatchField, GeoMesh>>& tdf1, const diagTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor3>& dt1,
	                                                                 const GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(const diagTensor3& t1,
	                                                                 const GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor3>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(const diagTensor3& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1, const dimensioned<diagTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1, const diagTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1, const diagTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor3>& dt1,
	                                                                 const GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(const sphericalTensor3& t1,
	                                                                 const GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor3>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(const sphericalTensor3& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1, const dimensioned<diagTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1, const diagTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1, const diagTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor3>& dt1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(const diagTensor3& t1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor3>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(const diagTensor3& t1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1, const sphericalTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1, const sphericalTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor3>& dt1,
	                                                                 const GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(const diagTensor3& t1,
	                                                                 const GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor3>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(const diagTensor3& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1, const dimensioned<diagTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1, const diagTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1, const diagTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor3>& dt1,
	                                                                 const GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(const diagTensor3& t1,
	                                                                 const GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor3>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(const diagTensor3& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1, const dimensioned<diagTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1, const diagTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1, const diagTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor3>& dt1,
	                                                                 const GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(const sphericalTensor3& t1,
	                                                                 const GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor3>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(const sphericalTensor3& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1, const dimensioned<diagTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1, const diagTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1, const diagTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor3>& dt1,
	                                                                 const GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(const sphericalTensor3& t1,
	                                                                 const GeometricField<diagTensor3, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor3>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(const sphericalTensor3& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1, const dimensioned<diagTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df1, const diagTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf1, const diagTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor3>& dt1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(const diagTensor3& t1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor3>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(const diagTensor3& t1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1, const sphericalTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1, const sphericalTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor3>& dt1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(const diagTensor3& t1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor3, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor3>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(const diagTensor3& t1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor3, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor3, PatchField, GeoMesh>& df1, const sphericalTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor3>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor3, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor3, PatchField, GeoMesh>>& tdf1, const sphericalTensor3& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> inv(const GeometricField<diagTensor4, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> inv(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> diag(const GeometricField<diagTensor4, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> diag(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>> contractScalar(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>> contractScalar(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> contractLinear(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> contractLinear(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const GeometricField<diagTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                 const GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                 const GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<diagTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const diagTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const diagTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const GeometricField<diagTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                 const GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                 const GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<diagTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const diagTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const diagTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<diagTensor4, PatchField, GeoMesh>&
	                                                             df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                             >& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const dimensioned<vector4>& dt1,
	                                                             const GeometricField<diagTensor4, PatchField, GeoMesh>&
	                                                             df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const vector4& t1,
	                                                             const GeometricField<diagTensor4, PatchField, GeoMesh>&
	                                                             df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const dimensioned<vector4>& dt1,
	                                                             const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                             >& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const vector4& t1,
	                                                             const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                             >& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<diagTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(const GeometricField<vector4, PatchField, GeoMesh>& df1,
	                                                             const diagTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector4, PatchField, GeoMesh>>& tdf1, const diagTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor4>& dt1,
	                                                                 const GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(const diagTensor4& t1,
	                                                                 const GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor4>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(const diagTensor4& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1, const dimensioned<diagTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1, const diagTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1, const diagTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor4>& dt1,
	                                                                 const GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(const sphericalTensor4& t1,
	                                                                 const GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor4>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(const sphericalTensor4& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1, const dimensioned<diagTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1, const diagTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1, const diagTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor4>& dt1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(const diagTensor4& t1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor4>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(const diagTensor4& t1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1, const sphericalTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1, const sphericalTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor4>& dt1,
	                                                                 const GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(const diagTensor4& t1,
	                                                                 const GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor4>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(const diagTensor4& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1, const dimensioned<diagTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1, const diagTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1, const diagTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor4>& dt1,
	                                                                 const GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(const diagTensor4& t1,
	                                                                 const GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor4>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(const diagTensor4& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1, const dimensioned<diagTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1, const diagTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1, const diagTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor4>& dt1,
	                                                                 const GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(const sphericalTensor4& t1,
	                                                                 const GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor4>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(const sphericalTensor4& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1, const dimensioned<diagTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1, const diagTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1, const diagTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor4>& dt1,
	                                                                 const GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(const sphericalTensor4& t1,
	                                                                 const GeometricField<diagTensor4, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor4>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(const sphericalTensor4& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1, const dimensioned<diagTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df1, const diagTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf1, const diagTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor4>& dt1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(const diagTensor4& t1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor4>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(const diagTensor4& t1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1, const sphericalTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1, const sphericalTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor4>& dt1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(const diagTensor4& t1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor4, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor4>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(const diagTensor4& t1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor4, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor4, PatchField, GeoMesh>& df1, const sphericalTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor4>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor4, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor4, PatchField, GeoMesh>>& tdf1, const sphericalTensor4& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> inv(const GeometricField<diagTensor6, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> inv(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> diag(const GeometricField<diagTensor6, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> diag(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>> contractScalar(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>> contractScalar(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> contractLinear(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> contractLinear(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const GeometricField<diagTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                 const GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                 const GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<diagTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const diagTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const diagTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const GeometricField<diagTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                 const GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                 const GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<diagTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const diagTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const diagTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<diagTensor6, PatchField, GeoMesh>&
	                                                             df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                             >& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const dimensioned<vector6>& dt1,
	                                                             const GeometricField<diagTensor6, PatchField, GeoMesh>&
	                                                             df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const vector6& t1,
	                                                             const GeometricField<diagTensor6, PatchField, GeoMesh>&
	                                                             df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const dimensioned<vector6>& dt1,
	                                                             const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                             >& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const vector6& t1,
	                                                             const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                             >& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<diagTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(const GeometricField<vector6, PatchField, GeoMesh>& df1,
	                                                             const diagTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector6, PatchField, GeoMesh>>& tdf1, const diagTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor6>& dt1,
	                                                                 const GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(const diagTensor6& t1,
	                                                                 const GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor6>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(const diagTensor6& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1, const dimensioned<diagTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1, const diagTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1, const diagTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor6>& dt1,
	                                                                 const GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(const sphericalTensor6& t1,
	                                                                 const GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor6>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(const sphericalTensor6& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1, const dimensioned<diagTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1, const diagTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1, const diagTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor6>& dt1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(const diagTensor6& t1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor6>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(const diagTensor6& t1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1, const sphericalTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1, const sphericalTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor6>& dt1,
	                                                                 const GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(const diagTensor6& t1,
	                                                                 const GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor6>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(const diagTensor6& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1, const dimensioned<diagTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1, const diagTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1, const diagTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor6>& dt1,
	                                                                 const GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(const diagTensor6& t1,
	                                                                 const GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor6>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(const diagTensor6& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1, const dimensioned<diagTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1, const diagTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1, const diagTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor6>& dt1,
	                                                                 const GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(const sphericalTensor6& t1,
	                                                                 const GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor6>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(const sphericalTensor6& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1, const dimensioned<diagTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1, const diagTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1, const diagTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor6>& dt1,
	                                                                 const GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(const sphericalTensor6& t1,
	                                                                 const GeometricField<diagTensor6, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor6>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(const sphericalTensor6& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1, const dimensioned<diagTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df1, const diagTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf1, const diagTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor6>& dt1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(const diagTensor6& t1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor6>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(const diagTensor6& t1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1, const sphericalTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1, const sphericalTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor6>& dt1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(const diagTensor6& t1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor6, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor6>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(const diagTensor6& t1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor6, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor6, PatchField, GeoMesh>& df1, const sphericalTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor6>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor6, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor6, PatchField, GeoMesh>>& tdf1, const sphericalTensor6& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> inv(const GeometricField<diagTensor8, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> inv(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> diag(const GeometricField<diagTensor8, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> diag(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>> contractScalar(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<scalar, PatchField, GeoMesh>> contractScalar(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> contractLinear(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> contractLinear(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const GeometricField<diagTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                 const GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                 const GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(const dimensioned<scalar>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(const scalar& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<diagTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const diagTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const diagTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const GeometricField<diagTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                 const GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                 const GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator *(const dimensioned<scalar>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator *(const scalar& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const dimensioned<diagTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator *(
		const GeometricField<scalar, PatchField, GeoMesh>& df1, const diagTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator *(
		const tmp<GeometricField<scalar, PatchField, GeoMesh>>& tdf1, const diagTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                             const GeometricField<diagTensor8, PatchField, GeoMesh>&
	                                                             df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                             const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                             >& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const dimensioned<vector8>& dt1,
	                                                             const GeometricField<diagTensor8, PatchField, GeoMesh>&
	                                                             df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const vector8& t1,
	                                                             const GeometricField<diagTensor8, PatchField, GeoMesh>&
	                                                             df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const dimensioned<vector8>& dt1,
	                                                             const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                             >& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const vector8& t1,
	                                                             const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                             >& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                             const dimensioned<diagTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(const GeometricField<vector8, PatchField, GeoMesh>& df1,
	                                                             const diagTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<vector8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<vector8, PatchField, GeoMesh>>& tdf1, const diagTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor8>& dt1,
	                                                                 const GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(const diagTensor8& t1,
	                                                                 const GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor8>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(const diagTensor8& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1, const dimensioned<diagTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1, const diagTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1, const diagTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor8>& dt1,
	                                                                 const GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(const sphericalTensor8& t1,
	                                                                 const GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(const dimensioned<sphericalTensor8>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(const sphericalTensor8& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1, const dimensioned<diagTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1, const diagTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1, const diagTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor8>& dt1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(const diagTensor8& t1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(const dimensioned<diagTensor8>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(const diagTensor8& t1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1, const sphericalTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator /(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1, const sphericalTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor8>& dt1,
	                                                                 const GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(const diagTensor8& t1,
	                                                                 const GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor8>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(const diagTensor8& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1, const dimensioned<diagTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1, const diagTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1, const diagTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor8>& dt1,
	                                                                 const GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(const diagTensor8& t1,
	                                                                 const GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor8>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(const diagTensor8& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1, const dimensioned<diagTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1, const diagTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1, const diagTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1,
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1,
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor8>& dt1,
	                                                                 const GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(const sphericalTensor8& t1,
	                                                                 const GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(const dimensioned<sphericalTensor8>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(const sphericalTensor8& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1, const dimensioned<diagTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1, const diagTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1, const diagTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor8>& dt1,
	                                                                 const GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(const sphericalTensor8& t1,
	                                                                 const GeometricField<diagTensor8, PatchField, GeoMesh>
	                                                                 & df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(const dimensioned<sphericalTensor8>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(const sphericalTensor8& t1,
	                                                                 const tmp<GeometricField<
		                                                                 diagTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1, const dimensioned<diagTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df1, const diagTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1, const dimensioned<diagTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf1, const diagTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1,
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1,
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1,
		const GeometricField<sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1,
		const tmp<GeometricField<sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor8>& dt1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(const diagTensor8& t1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(const dimensioned<diagTensor8>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(const diagTensor8& t1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1, const sphericalTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator +(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1, const sphericalTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor8>& dt1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(const diagTensor8& t1,
	                                                                 const GeometricField<
		                                                                 sphericalTensor8, PatchField, GeoMesh>& df2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(const dimensioned<diagTensor8>& dt1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(const diagTensor8& t1,
	                                                                 const tmp<GeometricField<
		                                                                 sphericalTensor8, PatchField, GeoMesh>>& tdf2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1, const dimensioned<sphericalTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const GeometricField<diagTensor8, PatchField, GeoMesh>& df1, const sphericalTensor8& t2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1, const dimensioned<sphericalTensor8>& dt2);
	template <template<class> class PatchField, class GeoMesh>
	tmp<GeometricField<diagTensor8, PatchField, GeoMesh>> operator -(
		const tmp<GeometricField<diagTensor8, PatchField, GeoMesh>>& tdf1, const sphericalTensor8& t2);

}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#undef DiagTensorN_FieldFunctions

#include <undefFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <GeometricDiagTensorNFields.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_GeometricDiagTensorNFields_Header