#pragma once
#ifndef _DimensionedDiagTensorNFields_Header
#define _DimensionedDiagTensorNFields_Header

#include <DimensionedField.hxx>
#include <dimensionedVectorTensorN.hxx>
#include <VectorTensorNFields.hxx>

#define TEMPLATE template<class GeoMesh>
#include <DimensionedFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define DiagTensorN_FieldFunctions(tensorType, diagTensorType, sphericalTensorType,     \
    vectorType, CmptType, args)                                                      \
                                                                                        \
UNARY_FUNCTION(diagTensorType, diagTensorType,inv,inv)                                  \
UNARY_FUNCTION(diagTensorType, diagTensorType,diag,diag)                                \
UNARY_FUNCTION(vectorType, diagTensorType, contractLinear,contractLinear)               \
UNARY_FUNCTION(CmptType, diagTensorType, contractScalar,contractLinear)                 \
                                                                                        \
BINARY_OPERATOR(diagTensorType, CmptType, diagTensorType, /,'|',divide)                 \
BINARY_TYPE_OPERATOR(diagTensorType, CmptType, diagTensorType, /,'|',divide)            \
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

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> inv(const DimensionedField<diagTensor2, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> inv(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> diag(const DimensionedField<diagTensor2, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> diag(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> contractLinear(const DimensionedField<diagTensor2, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> contractLinear(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const DimensionedField<diagTensor2, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const scalar& t1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const scalar& t1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const diagTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const diagTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const DimensionedField<vector2, GeoMesh>& df1
	                                                   , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const DimensionedField<vector2, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const dimensioned<vector2>& dt1
	                                                   , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const vector2& t1
	                                                   , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const dimensioned<vector2>& dt1
	                                                   , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const vector2& t1
	                                                   , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const DimensionedField<vector2, GeoMesh>& df1
	                                                   , const dimensioned<diagTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const DimensionedField<vector2, GeoMesh>& df1
	                                                   , const diagTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const dimensioned<diagTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const diagTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const dimensioned<diagTensor2>& dt1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const diagTensor2& t1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const dimensioned<diagTensor2>& dt1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const diagTensor2& t1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const diagTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const diagTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const dimensioned<sphericalTensor2>& dt1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const sphericalTensor2& t1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const dimensioned<sphericalTensor2>& dt1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const sphericalTensor2& t1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                       , const diagTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                       , const diagTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const dimensioned<diagTensor2>& dt1
	                                                       , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const diagTensor2& t1
	                                                       , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const dimensioned<diagTensor2>& dt1
	                                                       , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const diagTensor2& t1
	                                                       , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const dimensioned<sphericalTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const sphericalTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const dimensioned<sphericalTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const sphericalTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const dimensioned<diagTensor2>& dt1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const diagTensor2& t1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const dimensioned<diagTensor2>& dt1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const diagTensor2& t1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const diagTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const diagTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const dimensioned<diagTensor2>& dt1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const diagTensor2& t1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const dimensioned<diagTensor2>& dt1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const diagTensor2& t1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const diagTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const diagTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const dimensioned<sphericalTensor2>& dt1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const sphericalTensor2& t1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const dimensioned<sphericalTensor2>& dt1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const sphericalTensor2& t1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                       , const diagTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                       , const diagTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const dimensioned<sphericalTensor2>& dt1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const sphericalTensor2& t1
	                                                       , const DimensionedField<diagTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const dimensioned<sphericalTensor2>& dt1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const sphericalTensor2& t1
	                                                       , const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                       , const diagTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
	                                                       , const diagTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const dimensioned<diagTensor2>& dt1
	                                                       , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const diagTensor2& t1
	                                                       , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const dimensioned<diagTensor2>& dt1
	                                                       , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const diagTensor2& t1
	                                                       , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const dimensioned<sphericalTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const sphericalTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const dimensioned<sphericalTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const sphericalTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const dimensioned<diagTensor2>& dt1
	                                                       , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const diagTensor2& t1
	                                                       , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const dimensioned<diagTensor2>& dt1
	                                                       , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const diagTensor2& t1
	                                                       , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const dimensioned<sphericalTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const DimensionedField<diagTensor2, GeoMesh>& df1
	                                                       , const sphericalTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const dimensioned<sphericalTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor2, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor2, GeoMesh>>& tdf1
	                                                       , const sphericalTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> inv(const DimensionedField<diagTensor3, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> inv(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> diag(const DimensionedField<diagTensor3, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> diag(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> contractLinear(const DimensionedField<diagTensor3, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> contractLinear(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const DimensionedField<diagTensor3, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const scalar& t1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const scalar& t1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const diagTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const diagTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const DimensionedField<vector3, GeoMesh>& df1
	                                                   , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const DimensionedField<vector3, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const dimensioned<vector3>& dt1
	                                                   , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const vector3& t1
	                                                   , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const dimensioned<vector3>& dt1
	                                                   , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const vector3& t1
	                                                   , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const DimensionedField<vector3, GeoMesh>& df1
	                                                   , const dimensioned<diagTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const DimensionedField<vector3, GeoMesh>& df1
	                                                   , const diagTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const dimensioned<diagTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const diagTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const dimensioned<diagTensor3>& dt1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const diagTensor3& t1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const dimensioned<diagTensor3>& dt1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const diagTensor3& t1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const diagTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const diagTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const dimensioned<sphericalTensor3>& dt1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const sphericalTensor3& t1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const dimensioned<sphericalTensor3>& dt1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const sphericalTensor3& t1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                       , const diagTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                       , const diagTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const dimensioned<diagTensor3>& dt1
	                                                       , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const diagTensor3& t1
	                                                       , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const dimensioned<diagTensor3>& dt1
	                                                       , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const diagTensor3& t1
	                                                       , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const dimensioned<sphericalTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const sphericalTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const dimensioned<sphericalTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const sphericalTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const dimensioned<diagTensor3>& dt1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const diagTensor3& t1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const dimensioned<diagTensor3>& dt1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const diagTensor3& t1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const diagTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const diagTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const dimensioned<diagTensor3>& dt1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const diagTensor3& t1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const dimensioned<diagTensor3>& dt1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const diagTensor3& t1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const diagTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const diagTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const dimensioned<sphericalTensor3>& dt1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const sphericalTensor3& t1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const dimensioned<sphericalTensor3>& dt1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const sphericalTensor3& t1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                       , const diagTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                       , const diagTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const dimensioned<sphericalTensor3>& dt1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const sphericalTensor3& t1
	                                                       , const DimensionedField<diagTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const dimensioned<sphericalTensor3>& dt1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const sphericalTensor3& t1
	                                                       , const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                       , const diagTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
	                                                       , const diagTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const dimensioned<diagTensor3>& dt1
	                                                       , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const diagTensor3& t1
	                                                       , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const dimensioned<diagTensor3>& dt1
	                                                       , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const diagTensor3& t1
	                                                       , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const dimensioned<sphericalTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const sphericalTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const dimensioned<sphericalTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const sphericalTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const dimensioned<diagTensor3>& dt1
	                                                       , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const diagTensor3& t1
	                                                       , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const dimensioned<diagTensor3>& dt1
	                                                       , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const diagTensor3& t1
	                                                       , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const dimensioned<sphericalTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const DimensionedField<diagTensor3, GeoMesh>& df1
	                                                       , const sphericalTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const dimensioned<sphericalTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor3, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor3, GeoMesh>>& tdf1
	                                                       , const sphericalTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> inv(const DimensionedField<diagTensor4, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> inv(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> diag(const DimensionedField<diagTensor4, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> diag(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> contractLinear(const DimensionedField<diagTensor4, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> contractLinear(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const DimensionedField<diagTensor4, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const scalar& t1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const scalar& t1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const diagTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const diagTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const DimensionedField<vector4, GeoMesh>& df1
	                                                   , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const DimensionedField<vector4, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const dimensioned<vector4>& dt1
	                                                   , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const vector4& t1
	                                                   , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const dimensioned<vector4>& dt1
	                                                   , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const vector4& t1
	                                                   , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const DimensionedField<vector4, GeoMesh>& df1
	                                                   , const dimensioned<diagTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const DimensionedField<vector4, GeoMesh>& df1
	                                                   , const diagTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const dimensioned<diagTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const diagTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const dimensioned<diagTensor4>& dt1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const diagTensor4& t1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const dimensioned<diagTensor4>& dt1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const diagTensor4& t1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const diagTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const diagTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const dimensioned<sphericalTensor4>& dt1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const sphericalTensor4& t1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const dimensioned<sphericalTensor4>& dt1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const sphericalTensor4& t1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                       , const diagTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                       , const diagTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const dimensioned<diagTensor4>& dt1
	                                                       , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const diagTensor4& t1
	                                                       , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const dimensioned<diagTensor4>& dt1
	                                                       , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const diagTensor4& t1
	                                                       , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const dimensioned<sphericalTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const sphericalTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const dimensioned<sphericalTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const sphericalTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const dimensioned<diagTensor4>& dt1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const diagTensor4& t1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const dimensioned<diagTensor4>& dt1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const diagTensor4& t1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const diagTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const diagTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const dimensioned<diagTensor4>& dt1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const diagTensor4& t1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const dimensioned<diagTensor4>& dt1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const diagTensor4& t1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const diagTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const diagTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const dimensioned<sphericalTensor4>& dt1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const sphericalTensor4& t1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const dimensioned<sphericalTensor4>& dt1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const sphericalTensor4& t1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                       , const diagTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                       , const diagTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const dimensioned<sphericalTensor4>& dt1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const sphericalTensor4& t1
	                                                       , const DimensionedField<diagTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const dimensioned<sphericalTensor4>& dt1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const sphericalTensor4& t1
	                                                       , const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                       , const diagTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
	                                                       , const diagTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const dimensioned<diagTensor4>& dt1
	                                                       , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const diagTensor4& t1
	                                                       , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const dimensioned<diagTensor4>& dt1
	                                                       , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const diagTensor4& t1
	                                                       , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const dimensioned<sphericalTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const sphericalTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const dimensioned<sphericalTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const sphericalTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const dimensioned<diagTensor4>& dt1
	                                                       , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const diagTensor4& t1
	                                                       , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const dimensioned<diagTensor4>& dt1
	                                                       , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const diagTensor4& t1
	                                                       , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const dimensioned<sphericalTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const DimensionedField<diagTensor4, GeoMesh>& df1
	                                                       , const sphericalTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const dimensioned<sphericalTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor4, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor4, GeoMesh>>& tdf1
	                                                       , const sphericalTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> inv(const DimensionedField<diagTensor6, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> inv(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> diag(const DimensionedField<diagTensor6, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> diag(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> contractLinear(const DimensionedField<diagTensor6, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> contractLinear(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const DimensionedField<diagTensor6, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const scalar& t1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const scalar& t1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const diagTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const diagTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const DimensionedField<vector6, GeoMesh>& df1
	                                                   , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const DimensionedField<vector6, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const dimensioned<vector6>& dt1
	                                                   , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const vector6& t1
	                                                   , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const dimensioned<vector6>& dt1
	                                                   , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const vector6& t1
	                                                   , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const DimensionedField<vector6, GeoMesh>& df1
	                                                   , const dimensioned<diagTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const DimensionedField<vector6, GeoMesh>& df1
	                                                   , const diagTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const dimensioned<diagTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const diagTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const dimensioned<diagTensor6>& dt1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const diagTensor6& t1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const dimensioned<diagTensor6>& dt1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const diagTensor6& t1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const diagTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const diagTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const dimensioned<sphericalTensor6>& dt1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const sphericalTensor6& t1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const dimensioned<sphericalTensor6>& dt1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const sphericalTensor6& t1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                       , const diagTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                       , const diagTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const dimensioned<diagTensor6>& dt1
	                                                       , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const diagTensor6& t1
	                                                       , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const dimensioned<diagTensor6>& dt1
	                                                       , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const diagTensor6& t1
	                                                       , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const dimensioned<sphericalTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const sphericalTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const dimensioned<sphericalTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const sphericalTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const dimensioned<diagTensor6>& dt1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const diagTensor6& t1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const dimensioned<diagTensor6>& dt1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const diagTensor6& t1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const diagTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const diagTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const dimensioned<diagTensor6>& dt1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const diagTensor6& t1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const dimensioned<diagTensor6>& dt1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const diagTensor6& t1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const diagTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const diagTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const dimensioned<sphericalTensor6>& dt1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const sphericalTensor6& t1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const dimensioned<sphericalTensor6>& dt1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const sphericalTensor6& t1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                       , const diagTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                       , const diagTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const dimensioned<sphericalTensor6>& dt1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const sphericalTensor6& t1
	                                                       , const DimensionedField<diagTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const dimensioned<sphericalTensor6>& dt1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const sphericalTensor6& t1
	                                                       , const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                       , const diagTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
	                                                       , const diagTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const dimensioned<diagTensor6>& dt1
	                                                       , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const diagTensor6& t1
	                                                       , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const dimensioned<diagTensor6>& dt1
	                                                       , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const diagTensor6& t1
	                                                       , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const dimensioned<sphericalTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const sphericalTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const dimensioned<sphericalTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const sphericalTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const dimensioned<diagTensor6>& dt1
	                                                       , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const diagTensor6& t1
	                                                       , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const dimensioned<diagTensor6>& dt1
	                                                       , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const diagTensor6& t1
	                                                       , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const dimensioned<sphericalTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const DimensionedField<diagTensor6, GeoMesh>& df1
	                                                       , const sphericalTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const dimensioned<sphericalTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor6, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor6, GeoMesh>>& tdf1
	                                                       , const sphericalTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> inv(const DimensionedField<diagTensor8, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> inv(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> diag(const DimensionedField<diagTensor8, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> diag(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> contractLinear(const DimensionedField<diagTensor8, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> contractLinear(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const DimensionedField<diagTensor8, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const scalar& t1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const scalar& t1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                       , const diagTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                       , const diagTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const DimensionedField<vector8, GeoMesh>& df1
	                                                   , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const DimensionedField<vector8, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const dimensioned<vector8>& dt1
	                                                   , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const vector8& t1
	                                                   , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const dimensioned<vector8>& dt1
	                                                   , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const vector8& t1
	                                                   , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const DimensionedField<vector8, GeoMesh>& df1
	                                                   , const dimensioned<diagTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const DimensionedField<vector8, GeoMesh>& df1
	                                                   , const diagTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const dimensioned<diagTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const diagTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const dimensioned<diagTensor8>& dt1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const diagTensor8& t1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const dimensioned<diagTensor8>& dt1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const diagTensor8& t1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const diagTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const diagTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const dimensioned<sphericalTensor8>& dt1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const sphericalTensor8& t1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const dimensioned<sphericalTensor8>& dt1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const sphericalTensor8& t1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                       , const diagTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                       , const diagTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const dimensioned<diagTensor8>& dt1
	                                                       , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const diagTensor8& t1
	                                                       , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const dimensioned<diagTensor8>& dt1
	                                                       , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const diagTensor8& t1
	                                                       , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const dimensioned<sphericalTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const sphericalTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const dimensioned<sphericalTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator /(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const sphericalTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const dimensioned<diagTensor8>& dt1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const diagTensor8& t1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const dimensioned<diagTensor8>& dt1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const diagTensor8& t1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const diagTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const diagTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const dimensioned<diagTensor8>& dt1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const diagTensor8& t1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const dimensioned<diagTensor8>& dt1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const diagTensor8& t1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const diagTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const diagTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const dimensioned<sphericalTensor8>& dt1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const sphericalTensor8& t1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const dimensioned<sphericalTensor8>& dt1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const sphericalTensor8& t1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                       , const diagTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                       , const diagTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const dimensioned<sphericalTensor8>& dt1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const sphericalTensor8& t1
	                                                       , const DimensionedField<diagTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const dimensioned<sphericalTensor8>& dt1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const sphericalTensor8& t1
	                                                       , const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                       , const dimensioned<diagTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                       , const diagTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                       , const dimensioned<diagTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
	                                                       , const diagTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const dimensioned<diagTensor8>& dt1
	                                                       , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const diagTensor8& t1
	                                                       , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const dimensioned<diagTensor8>& dt1
	                                                       , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const diagTensor8& t1
	                                                       , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const dimensioned<sphericalTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const sphericalTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const dimensioned<sphericalTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator +(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const sphericalTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const dimensioned<diagTensor8>& dt1
	                                                       , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const diagTensor8& t1
	                                                       , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const dimensioned<diagTensor8>& dt1
	                                                       , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const diagTensor8& t1
	                                                       , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const dimensioned<sphericalTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const DimensionedField<diagTensor8, GeoMesh>& df1
	                                                       , const sphericalTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const dimensioned<sphericalTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<diagTensor8, GeoMesh>> operator -(const tmp<DimensionedField<diagTensor8, GeoMesh>>& tdf1
	                                                       , const sphericalTensor8& t2);

}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#undef DiagTensorN_FieldFunctions

#include <undefFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <DimensionedDiagTensorNFields.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !1
