#pragma once
#ifndef _DimensionedVectorNFields_Header
#define _DimensionedVectorNFields_Header

#include <DimensionedField.hxx>
#include <dimensionedVectorTensorN.hxx>
#include <VectorTensorNFields.hxx>

#define TEMPLATE template<class GeoMesh>
#include <DimensionedFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define VectorN_FieldFunctions(tensorType, diagTensorType, sphericalTensorType, \
    vectorType, CmptType, args)                                              \
                                                                                \
UNARY_FUNCTION(CmptType, vectorType, cmptSum, cmptSum)                          \
                                                                                \
BINARY_FUNCTION(vectorType, vectorType, vectorType, cmptMultiply)               \
BINARY_TYPE_FUNCTION(vectorType, vectorType, vectorType, cmptMultiply)          \
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

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> cmptSum(const DimensionedField<vector2, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> cmptSum(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> cmptMultiply(const DimensionedField<vector2, GeoMesh>& df1
	                                                     , const DimensionedField<vector2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> cmptMultiply(const DimensionedField<vector2, GeoMesh>& df1
	                                                     , const tmp<DimensionedField<vector2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                     , const DimensionedField<vector2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                     , const tmp<DimensionedField<vector2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> cmptMultiply(const dimensioned<vector2>& dt1
	                                                     , const DimensionedField<vector2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> cmptMultiply(const vector2& t1, const DimensionedField<vector2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> cmptMultiply(const dimensioned<vector2>& dt1
	                                                     , const tmp<DimensionedField<vector2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> cmptMultiply(const vector2& t1
	                                                     , const tmp<DimensionedField<vector2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> cmptMultiply(const DimensionedField<vector2, GeoMesh>& df1
	                                                     , const dimensioned<vector2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> cmptMultiply(const DimensionedField<vector2, GeoMesh>& df1, const vector2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                     , const dimensioned<vector2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector2, GeoMesh>>& tdf2
	                                                     , const vector2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const DimensionedField<vector2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<vector2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const DimensionedField<vector2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<vector2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const DimensionedField<vector2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const scalar& t1, const DimensionedField<vector2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const tmp<DimensionedField<vector2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const scalar& t1
	                                                   , const tmp<DimensionedField<vector2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const dimensioned<vector2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1, const vector2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const dimensioned<vector2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const vector2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator +(const DimensionedField<vector2, GeoMesh>& df1
	                                                   , const DimensionedField<vector2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator +(const DimensionedField<vector2, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<vector2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator +(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const DimensionedField<vector2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator +(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<vector2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator -(const DimensionedField<vector2, GeoMesh>& df1
	                                                   , const DimensionedField<vector2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator -(const DimensionedField<vector2, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<vector2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator -(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const DimensionedField<vector2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator -(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<vector2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator +(const dimensioned<vector2>& dt1
	                                                   , const DimensionedField<vector2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator +(const vector2& t1, const DimensionedField<vector2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator +(const dimensioned<vector2>& dt1
	                                                   , const tmp<DimensionedField<vector2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator +(const vector2& t1
	                                                   , const tmp<DimensionedField<vector2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator +(const DimensionedField<vector2, GeoMesh>& df1
	                                                   , const dimensioned<vector2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator +(const DimensionedField<vector2, GeoMesh>& df1, const vector2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator +(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const dimensioned<vector2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator +(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const vector2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator -(const dimensioned<vector2>& dt1
	                                                   , const DimensionedField<vector2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator -(const vector2& t1, const DimensionedField<vector2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator -(const dimensioned<vector2>& dt1
	                                                   , const tmp<DimensionedField<vector2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator -(const vector2& t1
	                                                   , const tmp<DimensionedField<vector2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator -(const DimensionedField<vector2, GeoMesh>& df1
	                                                   , const dimensioned<vector2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator -(const DimensionedField<vector2, GeoMesh>& df1, const vector2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator -(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const dimensioned<vector2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator -(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const vector2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> cmptSum(const DimensionedField<vector3, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> cmptSum(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> cmptMultiply(const DimensionedField<vector3, GeoMesh>& df1
	                                                     , const DimensionedField<vector3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> cmptMultiply(const DimensionedField<vector3, GeoMesh>& df1
	                                                     , const tmp<DimensionedField<vector3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                     , const DimensionedField<vector3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                     , const tmp<DimensionedField<vector3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> cmptMultiply(const dimensioned<vector3>& dt1
	                                                     , const DimensionedField<vector3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> cmptMultiply(const vector3& t1, const DimensionedField<vector3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> cmptMultiply(const dimensioned<vector3>& dt1
	                                                     , const tmp<DimensionedField<vector3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> cmptMultiply(const vector3& t1
	                                                     , const tmp<DimensionedField<vector3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> cmptMultiply(const DimensionedField<vector3, GeoMesh>& df1
	                                                     , const dimensioned<vector3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> cmptMultiply(const DimensionedField<vector3, GeoMesh>& df1, const vector3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                     , const dimensioned<vector3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector3, GeoMesh>>& tdf2
	                                                     , const vector3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const DimensionedField<vector3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<vector3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const DimensionedField<vector3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<vector3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const DimensionedField<vector3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const scalar& t1, const DimensionedField<vector3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const tmp<DimensionedField<vector3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const scalar& t1
	                                                   , const tmp<DimensionedField<vector3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const dimensioned<vector3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1, const vector3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const dimensioned<vector3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const vector3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator +(const DimensionedField<vector3, GeoMesh>& df1
	                                                   , const DimensionedField<vector3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator +(const DimensionedField<vector3, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<vector3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator +(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const DimensionedField<vector3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator +(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<vector3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator -(const DimensionedField<vector3, GeoMesh>& df1
	                                                   , const DimensionedField<vector3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator -(const DimensionedField<vector3, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<vector3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator -(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const DimensionedField<vector3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator -(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<vector3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator +(const dimensioned<vector3>& dt1
	                                                   , const DimensionedField<vector3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator +(const vector3& t1, const DimensionedField<vector3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator +(const dimensioned<vector3>& dt1
	                                                   , const tmp<DimensionedField<vector3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator +(const vector3& t1
	                                                   , const tmp<DimensionedField<vector3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator +(const DimensionedField<vector3, GeoMesh>& df1
	                                                   , const dimensioned<vector3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator +(const DimensionedField<vector3, GeoMesh>& df1, const vector3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator +(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const dimensioned<vector3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator +(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const vector3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator -(const dimensioned<vector3>& dt1
	                                                   , const DimensionedField<vector3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator -(const vector3& t1, const DimensionedField<vector3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator -(const dimensioned<vector3>& dt1
	                                                   , const tmp<DimensionedField<vector3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator -(const vector3& t1
	                                                   , const tmp<DimensionedField<vector3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator -(const DimensionedField<vector3, GeoMesh>& df1
	                                                   , const dimensioned<vector3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator -(const DimensionedField<vector3, GeoMesh>& df1, const vector3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator -(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const dimensioned<vector3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator -(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const vector3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> cmptSum(const DimensionedField<vector4, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> cmptSum(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> cmptMultiply(const DimensionedField<vector4, GeoMesh>& df1
	                                                     , const DimensionedField<vector4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> cmptMultiply(const DimensionedField<vector4, GeoMesh>& df1
	                                                     , const tmp<DimensionedField<vector4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                     , const DimensionedField<vector4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                     , const tmp<DimensionedField<vector4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> cmptMultiply(const dimensioned<vector4>& dt1
	                                                     , const DimensionedField<vector4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> cmptMultiply(const vector4& t1, const DimensionedField<vector4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> cmptMultiply(const dimensioned<vector4>& dt1
	                                                     , const tmp<DimensionedField<vector4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> cmptMultiply(const vector4& t1
	                                                     , const tmp<DimensionedField<vector4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> cmptMultiply(const DimensionedField<vector4, GeoMesh>& df1
	                                                     , const dimensioned<vector4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> cmptMultiply(const DimensionedField<vector4, GeoMesh>& df1, const vector4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                     , const dimensioned<vector4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector4, GeoMesh>>& tdf2
	                                                     , const vector4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const DimensionedField<vector4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<vector4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const DimensionedField<vector4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<vector4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const DimensionedField<vector4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const scalar& t1, const DimensionedField<vector4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const tmp<DimensionedField<vector4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const scalar& t1
	                                                   , const tmp<DimensionedField<vector4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const dimensioned<vector4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1, const vector4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const dimensioned<vector4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const vector4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator +(const DimensionedField<vector4, GeoMesh>& df1
	                                                   , const DimensionedField<vector4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator +(const DimensionedField<vector4, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<vector4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator +(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const DimensionedField<vector4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator +(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<vector4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator -(const DimensionedField<vector4, GeoMesh>& df1
	                                                   , const DimensionedField<vector4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator -(const DimensionedField<vector4, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<vector4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator -(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const DimensionedField<vector4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator -(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<vector4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator +(const dimensioned<vector4>& dt1
	                                                   , const DimensionedField<vector4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator +(const vector4& t1, const DimensionedField<vector4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator +(const dimensioned<vector4>& dt1
	                                                   , const tmp<DimensionedField<vector4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator +(const vector4& t1
	                                                   , const tmp<DimensionedField<vector4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator +(const DimensionedField<vector4, GeoMesh>& df1
	                                                   , const dimensioned<vector4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator +(const DimensionedField<vector4, GeoMesh>& df1, const vector4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator +(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const dimensioned<vector4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator +(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const vector4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator -(const dimensioned<vector4>& dt1
	                                                   , const DimensionedField<vector4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator -(const vector4& t1, const DimensionedField<vector4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator -(const dimensioned<vector4>& dt1
	                                                   , const tmp<DimensionedField<vector4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator -(const vector4& t1
	                                                   , const tmp<DimensionedField<vector4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator -(const DimensionedField<vector4, GeoMesh>& df1
	                                                   , const dimensioned<vector4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator -(const DimensionedField<vector4, GeoMesh>& df1, const vector4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator -(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const dimensioned<vector4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator -(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const vector4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> cmptSum(const DimensionedField<vector6, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> cmptSum(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> cmptMultiply(const DimensionedField<vector6, GeoMesh>& df1
	                                                     , const DimensionedField<vector6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> cmptMultiply(const DimensionedField<vector6, GeoMesh>& df1
	                                                     , const tmp<DimensionedField<vector6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                     , const DimensionedField<vector6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                     , const tmp<DimensionedField<vector6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> cmptMultiply(const dimensioned<vector6>& dt1
	                                                     , const DimensionedField<vector6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> cmptMultiply(const vector6& t1, const DimensionedField<vector6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> cmptMultiply(const dimensioned<vector6>& dt1
	                                                     , const tmp<DimensionedField<vector6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> cmptMultiply(const vector6& t1
	                                                     , const tmp<DimensionedField<vector6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> cmptMultiply(const DimensionedField<vector6, GeoMesh>& df1
	                                                     , const dimensioned<vector6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> cmptMultiply(const DimensionedField<vector6, GeoMesh>& df1, const vector6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                     , const dimensioned<vector6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector6, GeoMesh>>& tdf2
	                                                     , const vector6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const DimensionedField<vector6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<vector6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const DimensionedField<vector6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<vector6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const DimensionedField<vector6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const scalar& t1, const DimensionedField<vector6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const tmp<DimensionedField<vector6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const scalar& t1
	                                                   , const tmp<DimensionedField<vector6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const dimensioned<vector6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1, const vector6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const dimensioned<vector6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const vector6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator +(const DimensionedField<vector6, GeoMesh>& df1
	                                                   , const DimensionedField<vector6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator +(const DimensionedField<vector6, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<vector6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator +(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const DimensionedField<vector6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator +(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<vector6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator -(const DimensionedField<vector6, GeoMesh>& df1
	                                                   , const DimensionedField<vector6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator -(const DimensionedField<vector6, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<vector6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator -(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const DimensionedField<vector6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator -(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<vector6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator +(const dimensioned<vector6>& dt1
	                                                   , const DimensionedField<vector6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator +(const vector6& t1, const DimensionedField<vector6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator +(const dimensioned<vector6>& dt1
	                                                   , const tmp<DimensionedField<vector6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator +(const vector6& t1
	                                                   , const tmp<DimensionedField<vector6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator +(const DimensionedField<vector6, GeoMesh>& df1
	                                                   , const dimensioned<vector6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator +(const DimensionedField<vector6, GeoMesh>& df1, const vector6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator +(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const dimensioned<vector6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator +(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const vector6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator -(const dimensioned<vector6>& dt1
	                                                   , const DimensionedField<vector6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator -(const vector6& t1, const DimensionedField<vector6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator -(const dimensioned<vector6>& dt1
	                                                   , const tmp<DimensionedField<vector6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator -(const vector6& t1
	                                                   , const tmp<DimensionedField<vector6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator -(const DimensionedField<vector6, GeoMesh>& df1
	                                                   , const dimensioned<vector6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator -(const DimensionedField<vector6, GeoMesh>& df1, const vector6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator -(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const dimensioned<vector6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator -(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const vector6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> cmptSum(const DimensionedField<vector8, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> cmptSum(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> cmptMultiply(const DimensionedField<vector8, GeoMesh>& df1
	                                                     , const DimensionedField<vector8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> cmptMultiply(const DimensionedField<vector8, GeoMesh>& df1
	                                                     , const tmp<DimensionedField<vector8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                     , const DimensionedField<vector8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                     , const tmp<DimensionedField<vector8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> cmptMultiply(const dimensioned<vector8>& dt1
	                                                     , const DimensionedField<vector8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> cmptMultiply(const vector8& t1, const DimensionedField<vector8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> cmptMultiply(const dimensioned<vector8>& dt1
	                                                     , const tmp<DimensionedField<vector8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> cmptMultiply(const vector8& t1
	                                                     , const tmp<DimensionedField<vector8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> cmptMultiply(const DimensionedField<vector8, GeoMesh>& df1
	                                                     , const dimensioned<vector8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> cmptMultiply(const DimensionedField<vector8, GeoMesh>& df1, const vector8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                     , const dimensioned<vector8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> cmptMultiply(const tmp<DimensionedField<vector8, GeoMesh>>& tdf2
	                                                     , const vector8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const DimensionedField<vector8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<vector8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const DimensionedField<vector8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<vector8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const DimensionedField<vector8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const scalar& t1, const DimensionedField<vector8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const tmp<DimensionedField<vector8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const scalar& t1
	                                                   , const tmp<DimensionedField<vector8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const dimensioned<vector8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1, const vector8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const dimensioned<vector8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const vector8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator +(const DimensionedField<vector8, GeoMesh>& df1
	                                                   , const DimensionedField<vector8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator +(const DimensionedField<vector8, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<vector8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator +(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const DimensionedField<vector8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator +(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<vector8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator -(const DimensionedField<vector8, GeoMesh>& df1
	                                                   , const DimensionedField<vector8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator -(const DimensionedField<vector8, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<vector8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator -(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const DimensionedField<vector8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator -(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<vector8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator +(const dimensioned<vector8>& dt1
	                                                   , const DimensionedField<vector8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator +(const vector8& t1, const DimensionedField<vector8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator +(const dimensioned<vector8>& dt1
	                                                   , const tmp<DimensionedField<vector8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator +(const vector8& t1
	                                                   , const tmp<DimensionedField<vector8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator +(const DimensionedField<vector8, GeoMesh>& df1
	                                                   , const dimensioned<vector8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator +(const DimensionedField<vector8, GeoMesh>& df1, const vector8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator +(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const dimensioned<vector8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator +(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const vector8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator -(const dimensioned<vector8>& dt1
	                                                   , const DimensionedField<vector8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator -(const vector8& t1, const DimensionedField<vector8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator -(const dimensioned<vector8>& dt1
	                                                   , const tmp<DimensionedField<vector8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator -(const vector8& t1
	                                                   , const tmp<DimensionedField<vector8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator -(const DimensionedField<vector8, GeoMesh>& df1
	                                                   , const dimensioned<vector8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator -(const DimensionedField<vector8, GeoMesh>& df1, const vector8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator -(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const dimensioned<vector8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator -(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const vector8& t2);

}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#undef VectorN_FieldFunctions

#include <undefFieldFunctionsM.hxx>

#ifdef NoRepository
#   include <DimensionedVectorNFields.cxx>
#endif

#endif // !_DimensionedVectorNFields_Header
