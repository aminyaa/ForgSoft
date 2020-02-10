#pragma once
#ifndef _DimensionedTensorNFields_Header
#define _DimensionedTensorNFields_Header

#include <DimensionedField.hxx>
#include <dimensionedVectorTensorN.hxx>
#include <VectorTensorNFields.hxx>

#define TEMPLATE template<class GeoMesh>
#include <DimensionedFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define TensorN_FieldFunctions(tensorType, diagTensorType, sphericalTensorType,     \
    vectorType, CmptType, args)                                                  \
                                                                                    \
UNARY_FUNCTION(tensorType, tensorType,inv,inv)                                      \
UNARY_FUNCTION(diagTensorType, tensorType,diag,diag)                                \
UNARY_FUNCTION(tensorType, tensorType, negSumDiag, negSumDiag)                      \
UNARY_FUNCTION(vectorType, tensorType, contractLinear,contractLinear)               \
UNARY_FUNCTION(CmptType, tensorType, contractScalar,contractLinear)                 \
                                                                                    \
BINARY_OPERATOR(tensorType, CmptType, tensorType, /,'|',divide)                     \
BINARY_TYPE_OPERATOR(tensorType, CmptType, tensorType, /,'|',divide)                \
                                                                                    \
BINARY_OPERATOR(vectorType, vectorType, tensorType, /,'|',divide)                   \
BINARY_TYPE_OPERATOR(vectorType, vectorType, tensorType, /,'|',divide)              \
                                                                                    \
BINARY_OPERATOR(tensorType, tensorType, tensorType, /,'|',divide)                   \
BINARY_TYPE_OPERATOR(tensorType, tensorType, tensorType, /,'|',divide)              \
                                                                                    \
BINARY_OPERATOR(tensorType, tensorType, diagTensorType, /,'|',divide)               \
BINARY_TYPE_OPERATOR(tensorType, tensorType, diagTensorType, /,'|',divide)          \
                                                                                    \
BINARY_OPERATOR(tensorType, diagTensorType, tensorType, /,'|',divide)               \
BINARY_TYPE_OPERATOR(tensorType, diagTensorType, tensorType, /,'|',divide)          \
                                                                                    \
BINARY_OPERATOR(tensorType, sphericalTensorType, tensorType, /,'|',divide)          \
BINARY_TYPE_OPERATOR(tensorType, sphericalTensorType, tensorType, /,'|',divide)     \
                                                                                    \
BINARY_OPERATOR(tensorType, tensorType, sphericalTensorType, /,'|',divide)          \
BINARY_TYPE_OPERATOR(tensorType, tensorType, sphericalTensorType, /,'|',divide)     \
                                                                                    \
BINARY_OPERATOR(tensorType, tensorType, tensorType, +,'+',add)                      \
BINARY_OPERATOR(tensorType, tensorType, tensorType, -,'-',subtract)                 \
                                                                                    \
BINARY_TYPE_OPERATOR(tensorType, tensorType, tensorType, +,'+',add)                 \
BINARY_TYPE_OPERATOR(tensorType, tensorType, tensorType, -,'-',subtract)            \
                                                                                    \
BINARY_OPERATOR(tensorType, diagTensorType, tensorType, +,'+',add)                  \
BINARY_OPERATOR(tensorType, diagTensorType, tensorType, -,'-',subtract)             \
                                                                                    \
BINARY_TYPE_OPERATOR(tensorType, diagTensorType, tensorType, +,'+',add)             \
BINARY_TYPE_OPERATOR(tensorType, diagTensorType, tensorType, -,'-',subtract)        \
                                                                                    \
BINARY_OPERATOR(tensorType, sphericalTensorType, tensorType, +,'+',add)             \
BINARY_OPERATOR(tensorType, sphericalTensorType, tensorType, -,'-',subtract)        \
                                                                                    \
BINARY_TYPE_OPERATOR(tensorType, sphericalTensorType, tensorType, +,'+',add)        \
BINARY_TYPE_OPERATOR(tensorType, sphericalTensorType, tensorType, -,'-',subtract)


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> inv(const DimensionedField<tensor2, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> inv(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> diag(const DimensionedField<tensor2, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> diag(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> negSumDiag(const DimensionedField<tensor2, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> negSumDiag(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> contractLinear(const DimensionedField<tensor2, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> contractLinear(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const DimensionedField<tensor2, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const scalar& t1, const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const scalar& t1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1, const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const DimensionedField<vector2, GeoMesh>& df1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const DimensionedField<vector2, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const dimensioned<vector2>& dt1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const vector2& t1, const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const dimensioned<vector2>& dt1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const vector2& t1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const DimensionedField<vector2, GeoMesh>& df1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const DimensionedField<vector2, GeoMesh>& df1, const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<tensor2, GeoMesh>& df1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<tensor2, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const dimensioned<tensor2>& dt1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tensor2& t1, const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const dimensioned<tensor2>& dt1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tensor2& t1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<tensor2, GeoMesh>& df1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<tensor2, GeoMesh>& df1, const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<tensor2, GeoMesh>& df1
	                                                   , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<tensor2, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const dimensioned<tensor2>& dt1
	                                                   , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tensor2& t1
	                                                   , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const dimensioned<tensor2>& dt1
	                                                   , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tensor2& t1
	                                                   , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<tensor2, GeoMesh>& df1
	                                                   , const dimensioned<diagTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<tensor2, GeoMesh>& df1
	                                                   , const diagTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const dimensioned<diagTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const diagTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const dimensioned<diagTensor2>& dt1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const diagTensor2& t1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const dimensioned<diagTensor2>& dt1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const diagTensor2& t1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                   , const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                   , const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const dimensioned<sphericalTensor2>& dt1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const sphericalTensor2& t1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const dimensioned<sphericalTensor2>& dt1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const sphericalTensor2& t1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                   , const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                   , const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<tensor2, GeoMesh>& df1
	                                                   , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<tensor2, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const dimensioned<tensor2>& dt1
	                                                   , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tensor2& t1
	                                                   , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const dimensioned<tensor2>& dt1
	                                                   , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tensor2& t1
	                                                   , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<tensor2, GeoMesh>& df1
	                                                   , const dimensioned<sphericalTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const DimensionedField<tensor2, GeoMesh>& df1
	                                                   , const sphericalTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const dimensioned<sphericalTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator /(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const sphericalTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const DimensionedField<tensor2, GeoMesh>& df1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const DimensionedField<tensor2, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const DimensionedField<tensor2, GeoMesh>& df1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const DimensionedField<tensor2, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const dimensioned<tensor2>& dt1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const tensor2& t1, const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const dimensioned<tensor2>& dt1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const tensor2& t1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const DimensionedField<tensor2, GeoMesh>& df1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const DimensionedField<tensor2, GeoMesh>& df1, const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const dimensioned<tensor2>& dt1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const tensor2& t1, const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const dimensioned<tensor2>& dt1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const tensor2& t1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const DimensionedField<tensor2, GeoMesh>& df1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const DimensionedField<tensor2, GeoMesh>& df1, const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const tmp<DimensionedField<tensor2, GeoMesh>>& tdf1
	                                                   , const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const dimensioned<diagTensor2>& dt1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const diagTensor2& t1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const dimensioned<diagTensor2>& dt1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const diagTensor2& t1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                   , const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                   , const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const dimensioned<diagTensor2>& dt1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const diagTensor2& t1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const dimensioned<diagTensor2>& dt1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const diagTensor2& t1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                   , const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                   , const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const dimensioned<sphericalTensor2>& dt1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const sphericalTensor2& t1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const dimensioned<sphericalTensor2>& dt1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const sphericalTensor2& t1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                   , const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                   , const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const dimensioned<sphericalTensor2>& dt1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const sphericalTensor2& t1
	                                                   , const DimensionedField<tensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const dimensioned<sphericalTensor2>& dt1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const sphericalTensor2& t1
	                                                   , const tmp<DimensionedField<tensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                   , const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor2, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                   , const tensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> inv(const DimensionedField<tensor3, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> inv(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> diag(const DimensionedField<tensor3, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> diag(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> negSumDiag(const DimensionedField<tensor3, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> negSumDiag(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> contractLinear(const DimensionedField<tensor3, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> contractLinear(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const DimensionedField<tensor3, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const scalar& t1, const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const scalar& t1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1, const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const DimensionedField<vector3, GeoMesh>& df1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const DimensionedField<vector3, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const dimensioned<vector3>& dt1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const vector3& t1, const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const dimensioned<vector3>& dt1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const vector3& t1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const DimensionedField<vector3, GeoMesh>& df1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const DimensionedField<vector3, GeoMesh>& df1, const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<tensor3, GeoMesh>& df1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<tensor3, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const dimensioned<tensor3>& dt1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tensor3& t1, const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const dimensioned<tensor3>& dt1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tensor3& t1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<tensor3, GeoMesh>& df1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<tensor3, GeoMesh>& df1, const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<tensor3, GeoMesh>& df1
	                                                   , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<tensor3, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const dimensioned<tensor3>& dt1
	                                                   , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tensor3& t1
	                                                   , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const dimensioned<tensor3>& dt1
	                                                   , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tensor3& t1
	                                                   , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<tensor3, GeoMesh>& df1
	                                                   , const dimensioned<diagTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<tensor3, GeoMesh>& df1
	                                                   , const diagTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const dimensioned<diagTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const diagTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const dimensioned<diagTensor3>& dt1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const diagTensor3& t1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const dimensioned<diagTensor3>& dt1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const diagTensor3& t1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                   , const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                   , const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const dimensioned<sphericalTensor3>& dt1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const sphericalTensor3& t1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const dimensioned<sphericalTensor3>& dt1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const sphericalTensor3& t1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                   , const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                   , const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<tensor3, GeoMesh>& df1
	                                                   , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<tensor3, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const dimensioned<tensor3>& dt1
	                                                   , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tensor3& t1
	                                                   , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const dimensioned<tensor3>& dt1
	                                                   , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tensor3& t1
	                                                   , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<tensor3, GeoMesh>& df1
	                                                   , const dimensioned<sphericalTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const DimensionedField<tensor3, GeoMesh>& df1
	                                                   , const sphericalTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const dimensioned<sphericalTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator /(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const sphericalTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const DimensionedField<tensor3, GeoMesh>& df1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const DimensionedField<tensor3, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const DimensionedField<tensor3, GeoMesh>& df1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const DimensionedField<tensor3, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const dimensioned<tensor3>& dt1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const tensor3& t1, const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const dimensioned<tensor3>& dt1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const tensor3& t1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const DimensionedField<tensor3, GeoMesh>& df1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const DimensionedField<tensor3, GeoMesh>& df1, const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const dimensioned<tensor3>& dt1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const tensor3& t1, const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const dimensioned<tensor3>& dt1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const tensor3& t1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const DimensionedField<tensor3, GeoMesh>& df1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const DimensionedField<tensor3, GeoMesh>& df1, const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const tmp<DimensionedField<tensor3, GeoMesh>>& tdf1
	                                                   , const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const dimensioned<diagTensor3>& dt1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const diagTensor3& t1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const dimensioned<diagTensor3>& dt1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const diagTensor3& t1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                   , const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                   , const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const dimensioned<diagTensor3>& dt1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const diagTensor3& t1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const dimensioned<diagTensor3>& dt1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const diagTensor3& t1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                   , const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                   , const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const dimensioned<sphericalTensor3>& dt1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const sphericalTensor3& t1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const dimensioned<sphericalTensor3>& dt1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const sphericalTensor3& t1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                   , const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                   , const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const dimensioned<sphericalTensor3>& dt1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const sphericalTensor3& t1
	                                                   , const DimensionedField<tensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const dimensioned<sphericalTensor3>& dt1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const sphericalTensor3& t1
	                                                   , const tmp<DimensionedField<tensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                   , const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor3, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                   , const tensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> inv(const DimensionedField<tensor4, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> inv(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> diag(const DimensionedField<tensor4, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> diag(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> negSumDiag(const DimensionedField<tensor4, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> negSumDiag(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> contractLinear(const DimensionedField<tensor4, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> contractLinear(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const DimensionedField<tensor4, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const scalar& t1, const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const scalar& t1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1, const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const DimensionedField<vector4, GeoMesh>& df1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const DimensionedField<vector4, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const dimensioned<vector4>& dt1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const vector4& t1, const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const dimensioned<vector4>& dt1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const vector4& t1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const DimensionedField<vector4, GeoMesh>& df1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const DimensionedField<vector4, GeoMesh>& df1, const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<tensor4, GeoMesh>& df1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<tensor4, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const dimensioned<tensor4>& dt1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tensor4& t1, const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const dimensioned<tensor4>& dt1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tensor4& t1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<tensor4, GeoMesh>& df1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<tensor4, GeoMesh>& df1, const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<tensor4, GeoMesh>& df1
	                                                   , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<tensor4, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const dimensioned<tensor4>& dt1
	                                                   , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tensor4& t1
	                                                   , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const dimensioned<tensor4>& dt1
	                                                   , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tensor4& t1
	                                                   , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<tensor4, GeoMesh>& df1
	                                                   , const dimensioned<diagTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<tensor4, GeoMesh>& df1
	                                                   , const diagTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const dimensioned<diagTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const diagTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const dimensioned<diagTensor4>& dt1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const diagTensor4& t1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const dimensioned<diagTensor4>& dt1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const diagTensor4& t1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                   , const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                   , const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const dimensioned<sphericalTensor4>& dt1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const sphericalTensor4& t1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const dimensioned<sphericalTensor4>& dt1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const sphericalTensor4& t1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                   , const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                   , const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<tensor4, GeoMesh>& df1
	                                                   , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<tensor4, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const dimensioned<tensor4>& dt1
	                                                   , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tensor4& t1
	                                                   , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const dimensioned<tensor4>& dt1
	                                                   , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tensor4& t1
	                                                   , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<tensor4, GeoMesh>& df1
	                                                   , const dimensioned<sphericalTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const DimensionedField<tensor4, GeoMesh>& df1
	                                                   , const sphericalTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const dimensioned<sphericalTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator /(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const sphericalTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const DimensionedField<tensor4, GeoMesh>& df1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const DimensionedField<tensor4, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const DimensionedField<tensor4, GeoMesh>& df1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const DimensionedField<tensor4, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const dimensioned<tensor4>& dt1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const tensor4& t1, const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const dimensioned<tensor4>& dt1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const tensor4& t1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const DimensionedField<tensor4, GeoMesh>& df1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const DimensionedField<tensor4, GeoMesh>& df1, const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const dimensioned<tensor4>& dt1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const tensor4& t1, const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const dimensioned<tensor4>& dt1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const tensor4& t1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const DimensionedField<tensor4, GeoMesh>& df1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const DimensionedField<tensor4, GeoMesh>& df1, const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const tmp<DimensionedField<tensor4, GeoMesh>>& tdf1
	                                                   , const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const dimensioned<diagTensor4>& dt1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const diagTensor4& t1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const dimensioned<diagTensor4>& dt1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const diagTensor4& t1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                   , const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                   , const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const dimensioned<diagTensor4>& dt1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const diagTensor4& t1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const dimensioned<diagTensor4>& dt1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const diagTensor4& t1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                   , const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                   , const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const dimensioned<sphericalTensor4>& dt1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const sphericalTensor4& t1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const dimensioned<sphericalTensor4>& dt1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const sphericalTensor4& t1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                   , const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                   , const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const dimensioned<sphericalTensor4>& dt1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const sphericalTensor4& t1
	                                                   , const DimensionedField<tensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const dimensioned<sphericalTensor4>& dt1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const sphericalTensor4& t1
	                                                   , const tmp<DimensionedField<tensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                   , const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor4, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                   , const tensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> inv(const DimensionedField<tensor6, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> inv(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> diag(const DimensionedField<tensor6, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> diag(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> negSumDiag(const DimensionedField<tensor6, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> negSumDiag(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> contractLinear(const DimensionedField<tensor6, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> contractLinear(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const DimensionedField<tensor6, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const scalar& t1, const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const scalar& t1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1, const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const DimensionedField<vector6, GeoMesh>& df1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const DimensionedField<vector6, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const dimensioned<vector6>& dt1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const vector6& t1, const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const dimensioned<vector6>& dt1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const vector6& t1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const DimensionedField<vector6, GeoMesh>& df1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const DimensionedField<vector6, GeoMesh>& df1, const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<tensor6, GeoMesh>& df1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<tensor6, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const dimensioned<tensor6>& dt1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tensor6& t1, const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const dimensioned<tensor6>& dt1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tensor6& t1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<tensor6, GeoMesh>& df1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<tensor6, GeoMesh>& df1, const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<tensor6, GeoMesh>& df1
	                                                   , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<tensor6, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const dimensioned<tensor6>& dt1
	                                                   , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tensor6& t1
	                                                   , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const dimensioned<tensor6>& dt1
	                                                   , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tensor6& t1
	                                                   , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<tensor6, GeoMesh>& df1
	                                                   , const dimensioned<diagTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<tensor6, GeoMesh>& df1
	                                                   , const diagTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const dimensioned<diagTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const diagTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const dimensioned<diagTensor6>& dt1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const diagTensor6& t1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const dimensioned<diagTensor6>& dt1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const diagTensor6& t1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                   , const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                   , const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const dimensioned<sphericalTensor6>& dt1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const sphericalTensor6& t1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const dimensioned<sphericalTensor6>& dt1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const sphericalTensor6& t1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                   , const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                   , const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<tensor6, GeoMesh>& df1
	                                                   , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<tensor6, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const dimensioned<tensor6>& dt1
	                                                   , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tensor6& t1
	                                                   , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const dimensioned<tensor6>& dt1
	                                                   , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tensor6& t1
	                                                   , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<tensor6, GeoMesh>& df1
	                                                   , const dimensioned<sphericalTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const DimensionedField<tensor6, GeoMesh>& df1
	                                                   , const sphericalTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const dimensioned<sphericalTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator /(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const sphericalTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const DimensionedField<tensor6, GeoMesh>& df1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const DimensionedField<tensor6, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const DimensionedField<tensor6, GeoMesh>& df1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const DimensionedField<tensor6, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const dimensioned<tensor6>& dt1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const tensor6& t1, const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const dimensioned<tensor6>& dt1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const tensor6& t1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const DimensionedField<tensor6, GeoMesh>& df1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const DimensionedField<tensor6, GeoMesh>& df1, const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const dimensioned<tensor6>& dt1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const tensor6& t1, const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const dimensioned<tensor6>& dt1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const tensor6& t1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const DimensionedField<tensor6, GeoMesh>& df1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const DimensionedField<tensor6, GeoMesh>& df1, const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const tmp<DimensionedField<tensor6, GeoMesh>>& tdf1
	                                                   , const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const dimensioned<diagTensor6>& dt1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const diagTensor6& t1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const dimensioned<diagTensor6>& dt1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const diagTensor6& t1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                   , const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                   , const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const dimensioned<diagTensor6>& dt1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const diagTensor6& t1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const dimensioned<diagTensor6>& dt1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const diagTensor6& t1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                   , const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                   , const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const dimensioned<sphericalTensor6>& dt1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const sphericalTensor6& t1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const dimensioned<sphericalTensor6>& dt1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const sphericalTensor6& t1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                   , const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                   , const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const dimensioned<sphericalTensor6>& dt1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const sphericalTensor6& t1
	                                                   , const DimensionedField<tensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const dimensioned<sphericalTensor6>& dt1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const sphericalTensor6& t1
	                                                   , const tmp<DimensionedField<tensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                   , const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor6, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                   , const tensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> inv(const DimensionedField<tensor8, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> inv(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> diag(const DimensionedField<tensor8, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> diag(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> negSumDiag(const DimensionedField<tensor8, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> negSumDiag(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> contractLinear(const DimensionedField<tensor8, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> contractLinear(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const DimensionedField<tensor8, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const scalar& t1, const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const scalar& t1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1, const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                   , const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const DimensionedField<vector8, GeoMesh>& df1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const DimensionedField<vector8, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const dimensioned<vector8>& dt1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const vector8& t1, const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const dimensioned<vector8>& dt1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const vector8& t1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const DimensionedField<vector8, GeoMesh>& df1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const DimensionedField<vector8, GeoMesh>& df1, const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<tensor8, GeoMesh>& df1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<tensor8, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const dimensioned<tensor8>& dt1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tensor8& t1, const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const dimensioned<tensor8>& dt1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tensor8& t1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<tensor8, GeoMesh>& df1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<tensor8, GeoMesh>& df1, const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<tensor8, GeoMesh>& df1
	                                                   , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<tensor8, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const dimensioned<tensor8>& dt1
	                                                   , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tensor8& t1
	                                                   , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const dimensioned<tensor8>& dt1
	                                                   , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tensor8& t1
	                                                   , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<tensor8, GeoMesh>& df1
	                                                   , const dimensioned<diagTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<tensor8, GeoMesh>& df1
	                                                   , const diagTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const dimensioned<diagTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const diagTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const dimensioned<diagTensor8>& dt1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const diagTensor8& t1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const dimensioned<diagTensor8>& dt1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const diagTensor8& t1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                   , const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                   , const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const dimensioned<sphericalTensor8>& dt1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const sphericalTensor8& t1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const dimensioned<sphericalTensor8>& dt1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const sphericalTensor8& t1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                   , const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                   , const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<tensor8, GeoMesh>& df1
	                                                   , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<tensor8, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const dimensioned<tensor8>& dt1
	                                                   , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tensor8& t1
	                                                   , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const dimensioned<tensor8>& dt1
	                                                   , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tensor8& t1
	                                                   , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<tensor8, GeoMesh>& df1
	                                                   , const dimensioned<sphericalTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const DimensionedField<tensor8, GeoMesh>& df1
	                                                   , const sphericalTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const dimensioned<sphericalTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator /(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const sphericalTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const DimensionedField<tensor8, GeoMesh>& df1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const DimensionedField<tensor8, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const DimensionedField<tensor8, GeoMesh>& df1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const DimensionedField<tensor8, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const dimensioned<tensor8>& dt1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const tensor8& t1, const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const dimensioned<tensor8>& dt1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const tensor8& t1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const DimensionedField<tensor8, GeoMesh>& df1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const DimensionedField<tensor8, GeoMesh>& df1, const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const dimensioned<tensor8>& dt1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const tensor8& t1, const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const dimensioned<tensor8>& dt1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const tensor8& t1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const DimensionedField<tensor8, GeoMesh>& df1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const DimensionedField<tensor8, GeoMesh>& df1, const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const tmp<DimensionedField<tensor8, GeoMesh>>& tdf1
	                                                   , const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const dimensioned<diagTensor8>& dt1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const diagTensor8& t1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const dimensioned<diagTensor8>& dt1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const diagTensor8& t1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                   , const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                   , const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const dimensioned<diagTensor8>& dt1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const diagTensor8& t1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const dimensioned<diagTensor8>& dt1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const diagTensor8& t1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                   , const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                   , const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const dimensioned<sphericalTensor8>& dt1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const sphericalTensor8& t1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const dimensioned<sphericalTensor8>& dt1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const sphericalTensor8& t1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                   , const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                   , const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const dimensioned<sphericalTensor8>& dt1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const sphericalTensor8& t1
	                                                   , const DimensionedField<tensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const dimensioned<sphericalTensor8>& dt1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const sphericalTensor8& t1
	                                                   , const tmp<DimensionedField<tensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                   , const tensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                   , const dimensioned<tensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<tensor8, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                   , const tensor8& t2);

}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#undef TensorN_FieldFunctions

#include <undefFieldFunctionsM.hxx>

#endif // !1
