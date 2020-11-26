#pragma once
#ifndef _SphericalTensorNFieldFields_Header
#define _SphericalTensorNFieldFields_Header

#include <VectorTensorNFieldFieldsFwd.hxx>
#include <FieldField.hxx>

#define TEMPLATE template<template<class> class Field>
#include <FieldFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define SphericalTensorN_FieldFunctions(tensorType, diagTensorType,                 \
    sphericalTensorType, vectorType, CmptType, args)								 \
                                                                                    \
UNARY_FUNCTION(sphericalTensorType, sphericalTensorType, inv)                       \
UNARY_FUNCTION(sphericalTensorType, sphericalTensorType, diag)                      \
UNARY_FUNCTION(CmptType, sphericalTensorType, contractLinear)                       \
UNARY_FUNCTION(CmptType, sphericalTensorType, contractScalar)                       \
                                                                                    \
BINARY_OPERATOR(sphericalTensorType, CmptType, sphericalTensorType, /, divide)      \
BINARY_TYPE_OPERATOR(sphericalTensorType, CmptType, sphericalTensorType, /, divide) \
                                                                                    \
BINARY_OPERATOR(vectorType, vectorType, sphericalTensorType, /, divide)             \
BINARY_TYPE_OPERATOR(vectorType, vectorType, sphericalTensorType, /, divide)        \
                                                                                    \
BINARY_OPERATOR(sphericalTensorType, sphericalTensorType, sphericalTensorType, /, divide)           \
BINARY_TYPE_OPERATOR(sphericalTensorType, sphericalTensorType, sphericalTensorType, /, divide)      \
                                                                                    \
BINARY_OPERATOR(sphericalTensorType, sphericalTensorType, sphericalTensorType, +, add)             \
BINARY_OPERATOR(sphericalTensorType, sphericalTensorType, sphericalTensorType, -, subtract)        \
                                                                                    \
BINARY_TYPE_OPERATOR(sphericalTensorType, sphericalTensorType, sphericalTensorType, +, add)        \
BINARY_TYPE_OPERATOR(sphericalTensorType, sphericalTensorType, sphericalTensorType, -, subtract)

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template <template<class> class Field>
	void inv(FieldField<Field, sphericalTensor2>& res, const FieldField<Field, sphericalTensor2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> inv(const FieldField<Field, sphericalTensor2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> inv(const tmp<FieldField<Field, sphericalTensor2>>& tf);

	template <template<class> class Field>
	void diag(FieldField<Field, sphericalTensor2>& res, const FieldField<Field, sphericalTensor2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> diag(const FieldField<Field, sphericalTensor2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> diag(const tmp<FieldField<Field, sphericalTensor2>>& tf);

	template <template<class> class Field>
	void contractLinear(FieldField<Field, scalar>& res, const FieldField<Field, sphericalTensor2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractLinear(const FieldField<Field, sphericalTensor2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractLinear(const tmp<FieldField<Field, sphericalTensor2>>& tf);

	template <template<class> class Field>
	void contractScalar(FieldField<Field, scalar>& res, const FieldField<Field, sphericalTensor2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const FieldField<Field, sphericalTensor2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const tmp<FieldField<Field, sphericalTensor2>>& tf);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor2>& f, const FieldField<Field, scalar>& f1
	            , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator /(const FieldField<Field, scalar>& f1
	                                                    , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator /(const FieldField<Field, scalar>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                                    , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor2>& f, const scalar& s1, const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator /(const scalar& s1, const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator /(const scalar& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor2>& f, const FieldField<Field, scalar>& f1, const sphericalTensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator /(const FieldField<Field, scalar>& f1, const sphericalTensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                                    , const sphericalTensor2& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector2>& f, const FieldField<Field, vector2>& f1
	            , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const FieldField<Field, vector2>& f1
	                                           , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const FieldField<Field, vector2>& f1
	                                           , const tmp<FieldField<Field, sphericalTensor2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const tmp<FieldField<Field, vector2>>& tf1
	                                           , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const tmp<FieldField<Field, vector2>>& tf1
	                                           , const tmp<FieldField<Field, sphericalTensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector2>& f, const vector2& s1, const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const vector2& s1, const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const vector2& s1, const tmp<FieldField<Field, sphericalTensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector2>& f, const FieldField<Field, vector2>& f1, const sphericalTensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const FieldField<Field, vector2>& f1, const sphericalTensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const tmp<FieldField<Field, vector2>>& tf1, const sphericalTensor2& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor2>& f, const FieldField<Field, sphericalTensor2>& f1
	            , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator /(const FieldField<Field, sphericalTensor2>& f1
	                                                    , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator /(const FieldField<Field, sphericalTensor2>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator /(const tmp<FieldField<Field, sphericalTensor2>>& tf1
	                                                    , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator /(const tmp<FieldField<Field, sphericalTensor2>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor2>& f, const sphericalTensor2& s1
	            , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator /(const sphericalTensor2& s1
	                                                    , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator /(const sphericalTensor2& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor2>& f, const FieldField<Field, sphericalTensor2>& f1
	            , const sphericalTensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator /(const FieldField<Field, sphericalTensor2>& f1
	                                                    , const sphericalTensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator /(const tmp<FieldField<Field, sphericalTensor2>>& tf1
	                                                    , const sphericalTensor2& s2);

	template <template<class> class Field>
	void add(FieldField<Field, sphericalTensor2>& f, const FieldField<Field, sphericalTensor2>& f1
	         , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator +(const FieldField<Field, sphericalTensor2>& f1
	                                                    , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator +(const FieldField<Field, sphericalTensor2>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator +(const tmp<FieldField<Field, sphericalTensor2>>& tf1
	                                                    , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator +(const tmp<FieldField<Field, sphericalTensor2>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor2>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, sphericalTensor2>& f, const FieldField<Field, sphericalTensor2>& f1
	              , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator -(const FieldField<Field, sphericalTensor2>& f1
	                                                    , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator -(const FieldField<Field, sphericalTensor2>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator -(const tmp<FieldField<Field, sphericalTensor2>>& tf1
	                                                    , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator -(const tmp<FieldField<Field, sphericalTensor2>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor2>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, sphericalTensor2>& f, const sphericalTensor2& s1
	         , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator +(const sphericalTensor2& s1
	                                                    , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator +(const sphericalTensor2& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor2>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, sphericalTensor2>& f, const FieldField<Field, sphericalTensor2>& f1
	         , const sphericalTensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator +(const FieldField<Field, sphericalTensor2>& f1
	                                                    , const sphericalTensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator +(const tmp<FieldField<Field, sphericalTensor2>>& tf1
	                                                    , const sphericalTensor2& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, sphericalTensor2>& f, const sphericalTensor2& s1
	              , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator -(const sphericalTensor2& s1
	                                                    , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator -(const sphericalTensor2& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor2>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, sphericalTensor2>& f, const FieldField<Field, sphericalTensor2>& f1
	              , const sphericalTensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator -(const FieldField<Field, sphericalTensor2>& f1
	                                                    , const sphericalTensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor2>> operator -(const tmp<FieldField<Field, sphericalTensor2>>& tf1
	                                                    , const sphericalTensor2& s2);

	template <template<class> class Field>
	void inv(FieldField<Field, sphericalTensor3>& res, const FieldField<Field, sphericalTensor3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> inv(const FieldField<Field, sphericalTensor3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> inv(const tmp<FieldField<Field, sphericalTensor3>>& tf);

	template <template<class> class Field>
	void diag(FieldField<Field, sphericalTensor3>& res, const FieldField<Field, sphericalTensor3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> diag(const FieldField<Field, sphericalTensor3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> diag(const tmp<FieldField<Field, sphericalTensor3>>& tf);

	template <template<class> class Field>
	void contractLinear(FieldField<Field, scalar>& res, const FieldField<Field, sphericalTensor3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractLinear(const FieldField<Field, sphericalTensor3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractLinear(const tmp<FieldField<Field, sphericalTensor3>>& tf);

	template <template<class> class Field>
	void contractScalar(FieldField<Field, scalar>& res, const FieldField<Field, sphericalTensor3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const FieldField<Field, sphericalTensor3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const tmp<FieldField<Field, sphericalTensor3>>& tf);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor3>& f, const FieldField<Field, scalar>& f1
	            , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator /(const FieldField<Field, scalar>& f1
	                                                    , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator /(const FieldField<Field, scalar>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                                    , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor3>& f, const scalar& s1, const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator /(const scalar& s1, const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator /(const scalar& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor3>& f, const FieldField<Field, scalar>& f1, const sphericalTensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator /(const FieldField<Field, scalar>& f1, const sphericalTensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                                    , const sphericalTensor3& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector3>& f, const FieldField<Field, vector3>& f1
	            , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const FieldField<Field, vector3>& f1
	                                           , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const FieldField<Field, vector3>& f1
	                                           , const tmp<FieldField<Field, sphericalTensor3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const tmp<FieldField<Field, vector3>>& tf1
	                                           , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const tmp<FieldField<Field, vector3>>& tf1
	                                           , const tmp<FieldField<Field, sphericalTensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector3>& f, const vector3& s1, const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const vector3& s1, const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const vector3& s1, const tmp<FieldField<Field, sphericalTensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector3>& f, const FieldField<Field, vector3>& f1, const sphericalTensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const FieldField<Field, vector3>& f1, const sphericalTensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const tmp<FieldField<Field, vector3>>& tf1, const sphericalTensor3& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor3>& f, const FieldField<Field, sphericalTensor3>& f1
	            , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator /(const FieldField<Field, sphericalTensor3>& f1
	                                                    , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator /(const FieldField<Field, sphericalTensor3>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator /(const tmp<FieldField<Field, sphericalTensor3>>& tf1
	                                                    , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator /(const tmp<FieldField<Field, sphericalTensor3>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor3>& f, const sphericalTensor3& s1
	            , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator /(const sphericalTensor3& s1
	                                                    , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator /(const sphericalTensor3& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor3>& f, const FieldField<Field, sphericalTensor3>& f1
	            , const sphericalTensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator /(const FieldField<Field, sphericalTensor3>& f1
	                                                    , const sphericalTensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator /(const tmp<FieldField<Field, sphericalTensor3>>& tf1
	                                                    , const sphericalTensor3& s2);

	template <template<class> class Field>
	void add(FieldField<Field, sphericalTensor3>& f, const FieldField<Field, sphericalTensor3>& f1
	         , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator +(const FieldField<Field, sphericalTensor3>& f1
	                                                    , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator +(const FieldField<Field, sphericalTensor3>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator +(const tmp<FieldField<Field, sphericalTensor3>>& tf1
	                                                    , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator +(const tmp<FieldField<Field, sphericalTensor3>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor3>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, sphericalTensor3>& f, const FieldField<Field, sphericalTensor3>& f1
	              , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator -(const FieldField<Field, sphericalTensor3>& f1
	                                                    , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator -(const FieldField<Field, sphericalTensor3>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator -(const tmp<FieldField<Field, sphericalTensor3>>& tf1
	                                                    , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator -(const tmp<FieldField<Field, sphericalTensor3>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor3>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, sphericalTensor3>& f, const sphericalTensor3& s1
	         , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator +(const sphericalTensor3& s1
	                                                    , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator +(const sphericalTensor3& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor3>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, sphericalTensor3>& f, const FieldField<Field, sphericalTensor3>& f1
	         , const sphericalTensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator +(const FieldField<Field, sphericalTensor3>& f1
	                                                    , const sphericalTensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator +(const tmp<FieldField<Field, sphericalTensor3>>& tf1
	                                                    , const sphericalTensor3& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, sphericalTensor3>& f, const sphericalTensor3& s1
	              , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator -(const sphericalTensor3& s1
	                                                    , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator -(const sphericalTensor3& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor3>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, sphericalTensor3>& f, const FieldField<Field, sphericalTensor3>& f1
	              , const sphericalTensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator -(const FieldField<Field, sphericalTensor3>& f1
	                                                    , const sphericalTensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor3>> operator -(const tmp<FieldField<Field, sphericalTensor3>>& tf1
	                                                    , const sphericalTensor3& s2);

	template <template<class> class Field>
	void inv(FieldField<Field, sphericalTensor4>& res, const FieldField<Field, sphericalTensor4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> inv(const FieldField<Field, sphericalTensor4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> inv(const tmp<FieldField<Field, sphericalTensor4>>& tf);

	template <template<class> class Field>
	void diag(FieldField<Field, sphericalTensor4>& res, const FieldField<Field, sphericalTensor4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> diag(const FieldField<Field, sphericalTensor4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> diag(const tmp<FieldField<Field, sphericalTensor4>>& tf);

	template <template<class> class Field>
	void contractLinear(FieldField<Field, scalar>& res, const FieldField<Field, sphericalTensor4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractLinear(const FieldField<Field, sphericalTensor4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractLinear(const tmp<FieldField<Field, sphericalTensor4>>& tf);

	template <template<class> class Field>
	void contractScalar(FieldField<Field, scalar>& res, const FieldField<Field, sphericalTensor4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const FieldField<Field, sphericalTensor4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const tmp<FieldField<Field, sphericalTensor4>>& tf);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor4>& f, const FieldField<Field, scalar>& f1
	            , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator /(const FieldField<Field, scalar>& f1
	                                                    , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator /(const FieldField<Field, scalar>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                                    , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor4>& f, const scalar& s1, const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator /(const scalar& s1, const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator /(const scalar& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor4>& f, const FieldField<Field, scalar>& f1, const sphericalTensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator /(const FieldField<Field, scalar>& f1, const sphericalTensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                                    , const sphericalTensor4& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector4>& f, const FieldField<Field, vector4>& f1
	            , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const FieldField<Field, vector4>& f1
	                                           , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const FieldField<Field, vector4>& f1
	                                           , const tmp<FieldField<Field, sphericalTensor4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const tmp<FieldField<Field, vector4>>& tf1
	                                           , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const tmp<FieldField<Field, vector4>>& tf1
	                                           , const tmp<FieldField<Field, sphericalTensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector4>& f, const vector4& s1, const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const vector4& s1, const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const vector4& s1, const tmp<FieldField<Field, sphericalTensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector4>& f, const FieldField<Field, vector4>& f1, const sphericalTensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const FieldField<Field, vector4>& f1, const sphericalTensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const tmp<FieldField<Field, vector4>>& tf1, const sphericalTensor4& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor4>& f, const FieldField<Field, sphericalTensor4>& f1
	            , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator /(const FieldField<Field, sphericalTensor4>& f1
	                                                    , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator /(const FieldField<Field, sphericalTensor4>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator /(const tmp<FieldField<Field, sphericalTensor4>>& tf1
	                                                    , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator /(const tmp<FieldField<Field, sphericalTensor4>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor4>& f, const sphericalTensor4& s1
	            , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator /(const sphericalTensor4& s1
	                                                    , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator /(const sphericalTensor4& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor4>& f, const FieldField<Field, sphericalTensor4>& f1
	            , const sphericalTensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator /(const FieldField<Field, sphericalTensor4>& f1
	                                                    , const sphericalTensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator /(const tmp<FieldField<Field, sphericalTensor4>>& tf1
	                                                    , const sphericalTensor4& s2);

	template <template<class> class Field>
	void add(FieldField<Field, sphericalTensor4>& f, const FieldField<Field, sphericalTensor4>& f1
	         , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator +(const FieldField<Field, sphericalTensor4>& f1
	                                                    , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator +(const FieldField<Field, sphericalTensor4>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator +(const tmp<FieldField<Field, sphericalTensor4>>& tf1
	                                                    , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator +(const tmp<FieldField<Field, sphericalTensor4>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor4>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, sphericalTensor4>& f, const FieldField<Field, sphericalTensor4>& f1
	              , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator -(const FieldField<Field, sphericalTensor4>& f1
	                                                    , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator -(const FieldField<Field, sphericalTensor4>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator -(const tmp<FieldField<Field, sphericalTensor4>>& tf1
	                                                    , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator -(const tmp<FieldField<Field, sphericalTensor4>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor4>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, sphericalTensor4>& f, const sphericalTensor4& s1
	         , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator +(const sphericalTensor4& s1
	                                                    , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator +(const sphericalTensor4& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor4>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, sphericalTensor4>& f, const FieldField<Field, sphericalTensor4>& f1
	         , const sphericalTensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator +(const FieldField<Field, sphericalTensor4>& f1
	                                                    , const sphericalTensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator +(const tmp<FieldField<Field, sphericalTensor4>>& tf1
	                                                    , const sphericalTensor4& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, sphericalTensor4>& f, const sphericalTensor4& s1
	              , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator -(const sphericalTensor4& s1
	                                                    , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator -(const sphericalTensor4& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor4>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, sphericalTensor4>& f, const FieldField<Field, sphericalTensor4>& f1
	              , const sphericalTensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator -(const FieldField<Field, sphericalTensor4>& f1
	                                                    , const sphericalTensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor4>> operator -(const tmp<FieldField<Field, sphericalTensor4>>& tf1
	                                                    , const sphericalTensor4& s2);

	template <template<class> class Field>
	void inv(FieldField<Field, sphericalTensor6>& res, const FieldField<Field, sphericalTensor6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> inv(const FieldField<Field, sphericalTensor6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> inv(const tmp<FieldField<Field, sphericalTensor6>>& tf);

	template <template<class> class Field>
	void diag(FieldField<Field, sphericalTensor6>& res, const FieldField<Field, sphericalTensor6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> diag(const FieldField<Field, sphericalTensor6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> diag(const tmp<FieldField<Field, sphericalTensor6>>& tf);

	template <template<class> class Field>
	void contractLinear(FieldField<Field, scalar>& res, const FieldField<Field, sphericalTensor6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractLinear(const FieldField<Field, sphericalTensor6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractLinear(const tmp<FieldField<Field, sphericalTensor6>>& tf);

	template <template<class> class Field>
	void contractScalar(FieldField<Field, scalar>& res, const FieldField<Field, sphericalTensor6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const FieldField<Field, sphericalTensor6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const tmp<FieldField<Field, sphericalTensor6>>& tf);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor6>& f, const FieldField<Field, scalar>& f1
	            , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator /(const FieldField<Field, scalar>& f1
	                                                    , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator /(const FieldField<Field, scalar>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                                    , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor6>& f, const scalar& s1, const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator /(const scalar& s1, const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator /(const scalar& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor6>& f, const FieldField<Field, scalar>& f1, const sphericalTensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator /(const FieldField<Field, scalar>& f1, const sphericalTensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                                    , const sphericalTensor6& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector6>& f, const FieldField<Field, vector6>& f1
	            , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const FieldField<Field, vector6>& f1
	                                           , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const FieldField<Field, vector6>& f1
	                                           , const tmp<FieldField<Field, sphericalTensor6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const tmp<FieldField<Field, vector6>>& tf1
	                                           , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const tmp<FieldField<Field, vector6>>& tf1
	                                           , const tmp<FieldField<Field, sphericalTensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector6>& f, const vector6& s1, const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const vector6& s1, const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const vector6& s1, const tmp<FieldField<Field, sphericalTensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector6>& f, const FieldField<Field, vector6>& f1, const sphericalTensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const FieldField<Field, vector6>& f1, const sphericalTensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const tmp<FieldField<Field, vector6>>& tf1, const sphericalTensor6& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor6>& f, const FieldField<Field, sphericalTensor6>& f1
	            , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator /(const FieldField<Field, sphericalTensor6>& f1
	                                                    , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator /(const FieldField<Field, sphericalTensor6>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator /(const tmp<FieldField<Field, sphericalTensor6>>& tf1
	                                                    , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator /(const tmp<FieldField<Field, sphericalTensor6>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor6>& f, const sphericalTensor6& s1
	            , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator /(const sphericalTensor6& s1
	                                                    , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator /(const sphericalTensor6& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor6>& f, const FieldField<Field, sphericalTensor6>& f1
	            , const sphericalTensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator /(const FieldField<Field, sphericalTensor6>& f1
	                                                    , const sphericalTensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator /(const tmp<FieldField<Field, sphericalTensor6>>& tf1
	                                                    , const sphericalTensor6& s2);

	template <template<class> class Field>
	void add(FieldField<Field, sphericalTensor6>& f, const FieldField<Field, sphericalTensor6>& f1
	         , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator +(const FieldField<Field, sphericalTensor6>& f1
	                                                    , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator +(const FieldField<Field, sphericalTensor6>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator +(const tmp<FieldField<Field, sphericalTensor6>>& tf1
	                                                    , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator +(const tmp<FieldField<Field, sphericalTensor6>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor6>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, sphericalTensor6>& f, const FieldField<Field, sphericalTensor6>& f1
	              , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator -(const FieldField<Field, sphericalTensor6>& f1
	                                                    , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator -(const FieldField<Field, sphericalTensor6>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator -(const tmp<FieldField<Field, sphericalTensor6>>& tf1
	                                                    , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator -(const tmp<FieldField<Field, sphericalTensor6>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor6>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, sphericalTensor6>& f, const sphericalTensor6& s1
	         , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator +(const sphericalTensor6& s1
	                                                    , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator +(const sphericalTensor6& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor6>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, sphericalTensor6>& f, const FieldField<Field, sphericalTensor6>& f1
	         , const sphericalTensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator +(const FieldField<Field, sphericalTensor6>& f1
	                                                    , const sphericalTensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator +(const tmp<FieldField<Field, sphericalTensor6>>& tf1
	                                                    , const sphericalTensor6& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, sphericalTensor6>& f, const sphericalTensor6& s1
	              , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator -(const sphericalTensor6& s1
	                                                    , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator -(const sphericalTensor6& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor6>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, sphericalTensor6>& f, const FieldField<Field, sphericalTensor6>& f1
	              , const sphericalTensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator -(const FieldField<Field, sphericalTensor6>& f1
	                                                    , const sphericalTensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor6>> operator -(const tmp<FieldField<Field, sphericalTensor6>>& tf1
	                                                    , const sphericalTensor6& s2);

	template <template<class> class Field>
	void inv(FieldField<Field, sphericalTensor8>& res, const FieldField<Field, sphericalTensor8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> inv(const FieldField<Field, sphericalTensor8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> inv(const tmp<FieldField<Field, sphericalTensor8>>& tf);

	template <template<class> class Field>
	void diag(FieldField<Field, sphericalTensor8>& res, const FieldField<Field, sphericalTensor8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> diag(const FieldField<Field, sphericalTensor8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> diag(const tmp<FieldField<Field, sphericalTensor8>>& tf);

	template <template<class> class Field>
	void contractLinear(FieldField<Field, scalar>& res, const FieldField<Field, sphericalTensor8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractLinear(const FieldField<Field, sphericalTensor8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractLinear(const tmp<FieldField<Field, sphericalTensor8>>& tf);

	template <template<class> class Field>
	void contractScalar(FieldField<Field, scalar>& res, const FieldField<Field, sphericalTensor8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const FieldField<Field, sphericalTensor8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const tmp<FieldField<Field, sphericalTensor8>>& tf);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor8>& f, const FieldField<Field, scalar>& f1
	            , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator /(const FieldField<Field, scalar>& f1
	                                                    , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator /(const FieldField<Field, scalar>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                                    , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor8>& f, const scalar& s1, const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator /(const scalar& s1, const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator /(const scalar& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor8>& f, const FieldField<Field, scalar>& f1, const sphericalTensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator /(const FieldField<Field, scalar>& f1, const sphericalTensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                                    , const sphericalTensor8& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector8>& f, const FieldField<Field, vector8>& f1
	            , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const FieldField<Field, vector8>& f1
	                                           , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const FieldField<Field, vector8>& f1
	                                           , const tmp<FieldField<Field, sphericalTensor8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const tmp<FieldField<Field, vector8>>& tf1
	                                           , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const tmp<FieldField<Field, vector8>>& tf1
	                                           , const tmp<FieldField<Field, sphericalTensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector8>& f, const vector8& s1, const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const vector8& s1, const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const vector8& s1, const tmp<FieldField<Field, sphericalTensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector8>& f, const FieldField<Field, vector8>& f1, const sphericalTensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const FieldField<Field, vector8>& f1, const sphericalTensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const tmp<FieldField<Field, vector8>>& tf1, const sphericalTensor8& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor8>& f, const FieldField<Field, sphericalTensor8>& f1
	            , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator /(const FieldField<Field, sphericalTensor8>& f1
	                                                    , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator /(const FieldField<Field, sphericalTensor8>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator /(const tmp<FieldField<Field, sphericalTensor8>>& tf1
	                                                    , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator /(const tmp<FieldField<Field, sphericalTensor8>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor8>& f, const sphericalTensor8& s1
	            , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator /(const sphericalTensor8& s1
	                                                    , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator /(const sphericalTensor8& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, sphericalTensor8>& f, const FieldField<Field, sphericalTensor8>& f1
	            , const sphericalTensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator /(const FieldField<Field, sphericalTensor8>& f1
	                                                    , const sphericalTensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator /(const tmp<FieldField<Field, sphericalTensor8>>& tf1
	                                                    , const sphericalTensor8& s2);

	template <template<class> class Field>
	void add(FieldField<Field, sphericalTensor8>& f, const FieldField<Field, sphericalTensor8>& f1
	         , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator +(const FieldField<Field, sphericalTensor8>& f1
	                                                    , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator +(const FieldField<Field, sphericalTensor8>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator +(const tmp<FieldField<Field, sphericalTensor8>>& tf1
	                                                    , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator +(const tmp<FieldField<Field, sphericalTensor8>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor8>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, sphericalTensor8>& f, const FieldField<Field, sphericalTensor8>& f1
	              , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator -(const FieldField<Field, sphericalTensor8>& f1
	                                                    , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator -(const FieldField<Field, sphericalTensor8>& f1
	                                                    , const tmp<FieldField<Field, sphericalTensor8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator -(const tmp<FieldField<Field, sphericalTensor8>>& tf1
	                                                    , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator -(const tmp<FieldField<Field, sphericalTensor8>>& tf1
	                                                    , const tmp<FieldField<Field, sphericalTensor8>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, sphericalTensor8>& f, const sphericalTensor8& s1
	         , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator +(const sphericalTensor8& s1
	                                                    , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator +(const sphericalTensor8& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor8>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, sphericalTensor8>& f, const FieldField<Field, sphericalTensor8>& f1
	         , const sphericalTensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator +(const FieldField<Field, sphericalTensor8>& f1
	                                                    , const sphericalTensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator +(const tmp<FieldField<Field, sphericalTensor8>>& tf1
	                                                    , const sphericalTensor8& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, sphericalTensor8>& f, const sphericalTensor8& s1
	              , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator -(const sphericalTensor8& s1
	                                                    , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator -(const sphericalTensor8& s1
	                                                    , const tmp<FieldField<Field, sphericalTensor8>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, sphericalTensor8>& f, const FieldField<Field, sphericalTensor8>& f1
	              , const sphericalTensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator -(const FieldField<Field, sphericalTensor8>& f1
	                                                    , const sphericalTensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor8>> operator -(const tmp<FieldField<Field, sphericalTensor8>>& tf1
	                                                    , const sphericalTensor8& s2);

}

#include <undefFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <SphericalTensorNFieldFields.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !1
