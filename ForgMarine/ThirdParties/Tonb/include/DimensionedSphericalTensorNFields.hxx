#pragma once
#ifndef _DimensionedSphericalTensorNFields_Header
#define _DimensionedSphericalTensorNFields_Header

#include <DimensionedField.hxx>
#include <dimensionedVectorTensorN.hxx>
#include <VectorTensorNFields.hxx>

#define TEMPLATE template<class GeoMesh>
#include <DimensionedFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define SphericalTensorN_FieldFunctions(tensorType, diagTensorType,                 \
    sphericalTensorType, vectorType, CmptType, args)                             \
                                                                                    \
UNARY_FUNCTION(sphericalTensorType, sphericalTensorType,inv,inv)                    \
UNARY_FUNCTION(sphericalTensorType, sphericalTensorType,diag,diag)                  \
UNARY_FUNCTION(CmptType, sphericalTensorType, contractLinear,contractLinear)        \
UNARY_FUNCTION(CmptType, sphericalTensorType, contractScalar,contractLinear)        \
                                                                                    \
BINARY_OPERATOR(sphericalTensorType, CmptType, sphericalTensorType, /,'|',divide)   \
BINARY_TYPE_OPERATOR(sphericalTensorType, CmptType, sphericalTensorType, /,'|',divide) \
                                                                                    \
BINARY_OPERATOR(vectorType, vectorType, sphericalTensorType, /,'|',divide)          \
BINARY_TYPE_OPERATOR(vectorType, vectorType, sphericalTensorType, /,'|',divide)     \
                                                                                    \
BINARY_OPERATOR(sphericalTensorType, sphericalTensorType, sphericalTensorType, /,'|',divide)           \
BINARY_TYPE_OPERATOR(sphericalTensorType, sphericalTensorType, sphericalTensorType, /,'|',divide)      \
                                                                                    \
BINARY_OPERATOR(sphericalTensorType, sphericalTensorType, sphericalTensorType, +,'+',add)             \
BINARY_OPERATOR(sphericalTensorType, sphericalTensorType, sphericalTensorType, -,'-',subtract)        \
                                                                                    \
BINARY_TYPE_OPERATOR(sphericalTensorType, sphericalTensorType, sphericalTensorType, +,'+',add)        \
BINARY_TYPE_OPERATOR(sphericalTensorType, sphericalTensorType, sphericalTensorType, -,'-',subtract)


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> inv(const DimensionedField<sphericalTensor2, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> inv(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> diag(const DimensionedField<sphericalTensor2, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> diag(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractLinear(const DimensionedField<sphericalTensor2, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractLinear(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const DimensionedField<sphericalTensor2, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                            , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const scalar& t1
	                                                            , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const scalar& t1
	                                                            , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const sphericalTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const dimensioned<sphericalTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const sphericalTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const DimensionedField<vector2, GeoMesh>& df1
	                                                   , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const DimensionedField<vector2, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const dimensioned<vector2>& dt1
	                                                   , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const vector2& t1
	                                                   , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const dimensioned<vector2>& dt1
	                                                   , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const vector2& t1
	                                                   , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const DimensionedField<vector2, GeoMesh>& df1
	                                                   , const dimensioned<sphericalTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const DimensionedField<vector2, GeoMesh>& df1
	                                                   , const sphericalTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const dimensioned<sphericalTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector2, GeoMesh>> operator /(const tmp<DimensionedField<vector2, GeoMesh>>& tdf1
	                                                   , const sphericalTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1, const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
		, const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const dimensioned<sphericalTensor2>& dt1
	                                                            , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const sphericalTensor2& t1
	                                                            , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const dimensioned<sphericalTensor2>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const sphericalTensor2& t1
	                                                            , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                            , const sphericalTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1, const dimensioned<sphericalTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1, const sphericalTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator +(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator +(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1, const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
		, const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator -(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator -(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1, const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1
		, const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator +(const dimensioned<sphericalTensor2>& dt1
	                                                            , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator +(const sphericalTensor2& t1
	                                                            , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator +(const dimensioned<sphericalTensor2>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator +(const sphericalTensor2& t1
	                                                            , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator +(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator +(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                            , const sphericalTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1, const dimensioned<sphericalTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1, const sphericalTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator -(const dimensioned<sphericalTensor2>& dt1
	                                                            , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator -(const sphericalTensor2& t1
	                                                            , const DimensionedField<sphericalTensor2, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator -(const dimensioned<sphericalTensor2>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator -(const sphericalTensor2& t1
	                                                            , const tmp<DimensionedField<sphericalTensor2, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator -(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator -(const DimensionedField<sphericalTensor2, GeoMesh>& df1
	                                                            , const sphericalTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1, const dimensioned<sphericalTensor2>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor2, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor2, GeoMesh>>& tdf1, const sphericalTensor2& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> inv(const DimensionedField<sphericalTensor3, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> inv(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> diag(const DimensionedField<sphericalTensor3, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> diag(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractLinear(const DimensionedField<sphericalTensor3, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractLinear(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const DimensionedField<sphericalTensor3, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                            , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const scalar& t1
	                                                            , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const scalar& t1
	                                                            , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const sphericalTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const dimensioned<sphericalTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const sphericalTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const DimensionedField<vector3, GeoMesh>& df1
	                                                   , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const DimensionedField<vector3, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const dimensioned<vector3>& dt1
	                                                   , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const vector3& t1
	                                                   , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const dimensioned<vector3>& dt1
	                                                   , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const vector3& t1
	                                                   , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const DimensionedField<vector3, GeoMesh>& df1
	                                                   , const dimensioned<sphericalTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const DimensionedField<vector3, GeoMesh>& df1
	                                                   , const sphericalTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const dimensioned<sphericalTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector3, GeoMesh>> operator /(const tmp<DimensionedField<vector3, GeoMesh>>& tdf1
	                                                   , const sphericalTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1, const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
		, const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const dimensioned<sphericalTensor3>& dt1
	                                                            , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const sphericalTensor3& t1
	                                                            , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const dimensioned<sphericalTensor3>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const sphericalTensor3& t1
	                                                            , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                            , const sphericalTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1, const dimensioned<sphericalTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1, const sphericalTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator +(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator +(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1, const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
		, const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator -(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator -(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1, const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1
		, const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator +(const dimensioned<sphericalTensor3>& dt1
	                                                            , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator +(const sphericalTensor3& t1
	                                                            , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator +(const dimensioned<sphericalTensor3>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator +(const sphericalTensor3& t1
	                                                            , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator +(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator +(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                            , const sphericalTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1, const dimensioned<sphericalTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1, const sphericalTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator -(const dimensioned<sphericalTensor3>& dt1
	                                                            , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator -(const sphericalTensor3& t1
	                                                            , const DimensionedField<sphericalTensor3, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator -(const dimensioned<sphericalTensor3>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator -(const sphericalTensor3& t1
	                                                            , const tmp<DimensionedField<sphericalTensor3, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator -(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator -(const DimensionedField<sphericalTensor3, GeoMesh>& df1
	                                                            , const sphericalTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1, const dimensioned<sphericalTensor3>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor3, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor3, GeoMesh>>& tdf1, const sphericalTensor3& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> inv(const DimensionedField<sphericalTensor4, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> inv(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> diag(const DimensionedField<sphericalTensor4, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> diag(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractLinear(const DimensionedField<sphericalTensor4, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractLinear(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const DimensionedField<sphericalTensor4, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                            , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const scalar& t1
	                                                            , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const scalar& t1
	                                                            , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const sphericalTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const dimensioned<sphericalTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const sphericalTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const DimensionedField<vector4, GeoMesh>& df1
	                                                   , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const DimensionedField<vector4, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const dimensioned<vector4>& dt1
	                                                   , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const vector4& t1
	                                                   , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const dimensioned<vector4>& dt1
	                                                   , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const vector4& t1
	                                                   , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const DimensionedField<vector4, GeoMesh>& df1
	                                                   , const dimensioned<sphericalTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const DimensionedField<vector4, GeoMesh>& df1
	                                                   , const sphericalTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const dimensioned<sphericalTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector4, GeoMesh>> operator /(const tmp<DimensionedField<vector4, GeoMesh>>& tdf1
	                                                   , const sphericalTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1, const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
		, const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const dimensioned<sphericalTensor4>& dt1
	                                                            , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const sphericalTensor4& t1
	                                                            , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const dimensioned<sphericalTensor4>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const sphericalTensor4& t1
	                                                            , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                            , const sphericalTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1, const dimensioned<sphericalTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1, const sphericalTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator +(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator +(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1, const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
		, const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator -(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator -(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1, const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1
		, const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator +(const dimensioned<sphericalTensor4>& dt1
	                                                            , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator +(const sphericalTensor4& t1
	                                                            , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator +(const dimensioned<sphericalTensor4>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator +(const sphericalTensor4& t1
	                                                            , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator +(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator +(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                            , const sphericalTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1, const dimensioned<sphericalTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1, const sphericalTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator -(const dimensioned<sphericalTensor4>& dt1
	                                                            , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator -(const sphericalTensor4& t1
	                                                            , const DimensionedField<sphericalTensor4, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator -(const dimensioned<sphericalTensor4>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator -(const sphericalTensor4& t1
	                                                            , const tmp<DimensionedField<sphericalTensor4, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator -(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator -(const DimensionedField<sphericalTensor4, GeoMesh>& df1
	                                                            , const sphericalTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1, const dimensioned<sphericalTensor4>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor4, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor4, GeoMesh>>& tdf1, const sphericalTensor4& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> inv(const DimensionedField<sphericalTensor6, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> inv(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> diag(const DimensionedField<sphericalTensor6, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> diag(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractLinear(const DimensionedField<sphericalTensor6, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractLinear(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const DimensionedField<sphericalTensor6, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                            , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const scalar& t1
	                                                            , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const scalar& t1
	                                                            , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const sphericalTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const dimensioned<sphericalTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const sphericalTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const DimensionedField<vector6, GeoMesh>& df1
	                                                   , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const DimensionedField<vector6, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const dimensioned<vector6>& dt1
	                                                   , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const vector6& t1
	                                                   , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const dimensioned<vector6>& dt1
	                                                   , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const vector6& t1
	                                                   , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const DimensionedField<vector6, GeoMesh>& df1
	                                                   , const dimensioned<sphericalTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const DimensionedField<vector6, GeoMesh>& df1
	                                                   , const sphericalTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const dimensioned<sphericalTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector6, GeoMesh>> operator /(const tmp<DimensionedField<vector6, GeoMesh>>& tdf1
	                                                   , const sphericalTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1, const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
		, const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const dimensioned<sphericalTensor6>& dt1
	                                                            , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const sphericalTensor6& t1
	                                                            , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const dimensioned<sphericalTensor6>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const sphericalTensor6& t1
	                                                            , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                            , const sphericalTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1, const dimensioned<sphericalTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1, const sphericalTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator +(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator +(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1, const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
		, const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator -(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator -(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1, const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1
		, const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator +(const dimensioned<sphericalTensor6>& dt1
	                                                            , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator +(const sphericalTensor6& t1
	                                                            , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator +(const dimensioned<sphericalTensor6>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator +(const sphericalTensor6& t1
	                                                            , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator +(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator +(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                            , const sphericalTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1, const dimensioned<sphericalTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1, const sphericalTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator -(const dimensioned<sphericalTensor6>& dt1
	                                                            , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator -(const sphericalTensor6& t1
	                                                            , const DimensionedField<sphericalTensor6, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator -(const dimensioned<sphericalTensor6>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator -(const sphericalTensor6& t1
	                                                            , const tmp<DimensionedField<sphericalTensor6, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator -(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator -(const DimensionedField<sphericalTensor6, GeoMesh>& df1
	                                                            , const sphericalTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1, const dimensioned<sphericalTensor6>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor6, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor6, GeoMesh>>& tdf1, const sphericalTensor6& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> inv(const DimensionedField<sphericalTensor8, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> inv(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> diag(const DimensionedField<sphericalTensor8, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> diag(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractLinear(const DimensionedField<sphericalTensor8, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractLinear(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const DimensionedField<sphericalTensor8, GeoMesh>& df);

	template <class GeoMesh>
	tmp<DimensionedField<scalar, GeoMesh>> contractScalar(const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                            , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const scalar& t1
	                                                            , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const dimensioned<scalar>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const scalar& t1
	                                                            , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const DimensionedField<scalar, GeoMesh>& df1
	                                                            , const sphericalTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const dimensioned<sphericalTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const tmp<DimensionedField<scalar, GeoMesh>>& tdf1
	                                                            , const sphericalTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const DimensionedField<vector8, GeoMesh>& df1
	                                                   , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const DimensionedField<vector8, GeoMesh>& df1
	                                                   , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const dimensioned<vector8>& dt1
	                                                   , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const vector8& t1
	                                                   , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const dimensioned<vector8>& dt1
	                                                   , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const vector8& t1
	                                                   , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const DimensionedField<vector8, GeoMesh>& df1
	                                                   , const dimensioned<sphericalTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const DimensionedField<vector8, GeoMesh>& df1
	                                                   , const sphericalTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const dimensioned<sphericalTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<vector8, GeoMesh>> operator /(const tmp<DimensionedField<vector8, GeoMesh>>& tdf1
	                                                   , const sphericalTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1, const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
		, const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const dimensioned<sphericalTensor8>& dt1
	                                                            , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const sphericalTensor8& t1
	                                                            , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const dimensioned<sphericalTensor8>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const sphericalTensor8& t1
	                                                            , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                            , const sphericalTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1, const dimensioned<sphericalTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator /(
		const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1, const sphericalTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator +(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator +(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1, const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
		, const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator -(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                            , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator -(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                            , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1, const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1
		, const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator +(const dimensioned<sphericalTensor8>& dt1
	                                                            , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator +(const sphericalTensor8& t1
	                                                            , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator +(const dimensioned<sphericalTensor8>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator +(const sphericalTensor8& t1
	                                                            , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator +(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator +(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                            , const sphericalTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1, const dimensioned<sphericalTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator +(
		const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1, const sphericalTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator -(const dimensioned<sphericalTensor8>& dt1
	                                                            , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator -(const sphericalTensor8& t1
	                                                            , const DimensionedField<sphericalTensor8, GeoMesh>& df2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator -(const dimensioned<sphericalTensor8>& dt1
	                                                            , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator -(const sphericalTensor8& t1
	                                                            , const tmp<DimensionedField<sphericalTensor8, GeoMesh>>&
	                                                            tdf2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator -(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                            , const dimensioned<sphericalTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator -(const DimensionedField<sphericalTensor8, GeoMesh>& df1
	                                                            , const sphericalTensor8& t2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1, const dimensioned<sphericalTensor8>& dt2);

	template <class GeoMesh>
	tmp<DimensionedField<sphericalTensor8, GeoMesh>> operator -(
		const tmp<DimensionedField<sphericalTensor8, GeoMesh>>& tdf1, const sphericalTensor8& t2);

}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#undef SphericalTensorN_FieldFunctions

#include <undefFieldFunctionsM.hxx>

 // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <DimensionedSphericalTensorNFields.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !1
