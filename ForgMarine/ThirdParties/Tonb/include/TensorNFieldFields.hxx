#pragma once
#ifndef _TensorNFieldFields_Header
#define _TensorNFieldFields_Header

#include <VectorTensorNFieldFieldsFwd.hxx>
#include <FieldField.hxx>

#define TEMPLATE template<template<class> class Field>
#include <FieldFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define TensorN_FieldFunctions(tensorType, diagTensorType, sphericalTensorType,         \
    vectorType, CmptType, args)															\
                                                                                        \
UNARY_FUNCTION(tensorType, tensorType, inv)                                             \
UNARY_FUNCTION(diagTensorType, tensorType, diag)                                        \
UNARY_FUNCTION(tensorType, tensorType, negSumDiag)                                      \
UNARY_FUNCTION(vectorType, tensorType, contractLinear)                                  \
UNARY_FUNCTION(CmptType, tensorType, contractScalar)                                    \
                                                                                        \
BINARY_OPERATOR(tensorType, CmptType, tensorType, /, divide)                            \
BINARY_TYPE_OPERATOR(tensorType, CmptType, tensorType, /, divide)                       \
                                                                                        \
BINARY_OPERATOR(vectorType, vectorType, tensorType, /, divide)                          \
BINARY_TYPE_OPERATOR(vectorType, vectorType, tensorType, /, divide)                     \
                                                                                        \
BINARY_OPERATOR(tensorType, tensorType, tensorType, /, divide)                          \
BINARY_TYPE_OPERATOR(tensorType, tensorType, tensorType, /, divide)                     \
                                                                                        \
BINARY_OPERATOR(tensorType, tensorType, diagTensorType, /, divide)                      \
BINARY_TYPE_OPERATOR(tensorType, tensorType, diagTensorType, /, divide)                 \
                                                                                        \
BINARY_OPERATOR(tensorType, diagTensorType, tensorType, /, divide)                      \
BINARY_TYPE_OPERATOR(tensorType, diagTensorType, tensorType, /, divide)                 \
                                                                                        \
BINARY_OPERATOR(tensorType, sphericalTensorType, tensorType, /, divide)                 \
BINARY_TYPE_OPERATOR(tensorType, sphericalTensorType, tensorType, /, divide)            \
                                                                                        \
BINARY_OPERATOR(tensorType, tensorType, sphericalTensorType, /, divide)                 \
BINARY_TYPE_OPERATOR(tensorType, tensorType, sphericalTensorType, /, divide)            \
                                                                                        \
BINARY_OPERATOR(tensorType, tensorType, tensorType, +, add)                             \
BINARY_OPERATOR(tensorType, tensorType, tensorType, -, subtract)                        \
                                                                                        \
BINARY_TYPE_OPERATOR(tensorType, tensorType, tensorType, +, add)                        \
BINARY_TYPE_OPERATOR(tensorType, tensorType, tensorType, -, subtract)                   \
                                                                                        \
BINARY_OPERATOR(tensorType, diagTensorType, tensorType, +, add)                         \
BINARY_OPERATOR(tensorType, diagTensorType, tensorType, -, subtract)                    \
                                                                                        \
BINARY_TYPE_OPERATOR(tensorType, diagTensorType, tensorType, +, add)                    \
BINARY_TYPE_OPERATOR(tensorType, diagTensorType, tensorType, -, subtract)               \
                                                                                        \
BINARY_OPERATOR(tensorType, sphericalTensorType, tensorType, +, add)                    \
BINARY_OPERATOR(tensorType, sphericalTensorType, tensorType, -, subtract)               \
                                                                                        \
BINARY_TYPE_OPERATOR(tensorType, sphericalTensorType, tensorType, +, add)               \
BINARY_TYPE_OPERATOR(tensorType, sphericalTensorType, tensorType, -, subtract)


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	template <template<class> class Field>
	void inv(FieldField<Field, tensor2>& res, const FieldField<Field, tensor2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> inv(const FieldField<Field, tensor2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> inv(const tmp<FieldField<Field, tensor2>>& tf);

	template <template<class> class Field>
	void diag(FieldField<Field, diagTensor2>& res, const FieldField<Field, tensor2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, diagTensor2>> diag(const FieldField<Field, tensor2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, diagTensor2>> diag(const tmp<FieldField<Field, tensor2>>& tf);

	template <template<class> class Field>
	void negSumDiag(FieldField<Field, tensor2>& res, const FieldField<Field, tensor2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> negSumDiag(const FieldField<Field, tensor2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> negSumDiag(const tmp<FieldField<Field, tensor2>>& tf);

	template <template<class> class Field>
	void contractLinear(FieldField<Field, vector2>& res, const FieldField<Field, tensor2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> contractLinear(const FieldField<Field, tensor2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> contractLinear(const tmp<FieldField<Field, tensor2>>& tf);

	template <template<class> class Field>
	void contractScalar(FieldField<Field, scalar>& res, const FieldField<Field, tensor2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const FieldField<Field, tensor2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const tmp<FieldField<Field, tensor2>>& tf);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor2>& f, const FieldField<Field, scalar>& f1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const FieldField<Field, scalar>& f1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const FieldField<Field, scalar>& f1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                           , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor2>& f, const scalar& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const scalar& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const scalar& s1, const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor2>& f, const FieldField<Field, scalar>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const FieldField<Field, scalar>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tmp<FieldField<Field, scalar>>& tf1, const tensor2& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector2>& f, const FieldField<Field, vector2>& f1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const FieldField<Field, vector2>& f1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const FieldField<Field, vector2>& f1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const tmp<FieldField<Field, vector2>>& tf1
	                                           , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const tmp<FieldField<Field, vector2>>& tf1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector2>& f, const vector2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const vector2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const vector2& s1, const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector2>& f, const FieldField<Field, vector2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const FieldField<Field, vector2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const tmp<FieldField<Field, vector2>>& tf1, const tensor2& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor2>& f, const FieldField<Field, tensor2>& f1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const FieldField<Field, tensor2>& f1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const FieldField<Field, tensor2>& f1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tmp<FieldField<Field, tensor2>>& tf1
	                                           , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tmp<FieldField<Field, tensor2>>& tf1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor2>& f, const tensor2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tensor2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tensor2& s1, const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor2>& f, const FieldField<Field, tensor2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const FieldField<Field, tensor2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tmp<FieldField<Field, tensor2>>& tf1, const tensor2& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor2>& f, const FieldField<Field, tensor2>& f1
	            , const FieldField<Field, diagTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const FieldField<Field, tensor2>& f1
	                                           , const FieldField<Field, diagTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const FieldField<Field, tensor2>& f1
	                                           , const tmp<FieldField<Field, diagTensor2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tmp<FieldField<Field, tensor2>>& tf1
	                                           , const FieldField<Field, diagTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tmp<FieldField<Field, tensor2>>& tf1
	                                           , const tmp<FieldField<Field, diagTensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor2>& f, const tensor2& s1, const FieldField<Field, diagTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tensor2& s1, const FieldField<Field, diagTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tensor2& s1, const tmp<FieldField<Field, diagTensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor2>& f, const FieldField<Field, tensor2>& f1, const diagTensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const FieldField<Field, tensor2>& f1, const diagTensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tmp<FieldField<Field, tensor2>>& tf1, const diagTensor2& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor2>& f, const FieldField<Field, diagTensor2>& f1
	            , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const FieldField<Field, diagTensor2>& f1
	                                           , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const FieldField<Field, diagTensor2>& f1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tmp<FieldField<Field, diagTensor2>>& tf1
	                                           , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tmp<FieldField<Field, diagTensor2>>& tf1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor2>& f, const diagTensor2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const diagTensor2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const diagTensor2& s1, const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor2>& f, const FieldField<Field, diagTensor2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const FieldField<Field, diagTensor2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tmp<FieldField<Field, diagTensor2>>& tf1, const tensor2& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor2>& f, const FieldField<Field, sphericalTensor2>& f1
	            , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const FieldField<Field, sphericalTensor2>& f1
	                                           , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const FieldField<Field, sphericalTensor2>& f1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tmp<FieldField<Field, sphericalTensor2>>& tf1
	                                           , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tmp<FieldField<Field, sphericalTensor2>>& tf1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor2>& f, const sphericalTensor2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const sphericalTensor2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const sphericalTensor2& s1, const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor2>& f, const FieldField<Field, sphericalTensor2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const FieldField<Field, sphericalTensor2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tmp<FieldField<Field, sphericalTensor2>>& tf1, const tensor2& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor2>& f, const FieldField<Field, tensor2>& f1
	            , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const FieldField<Field, tensor2>& f1
	                                           , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const FieldField<Field, tensor2>& f1
	                                           , const tmp<FieldField<Field, sphericalTensor2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tmp<FieldField<Field, tensor2>>& tf1
	                                           , const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tmp<FieldField<Field, tensor2>>& tf1
	                                           , const tmp<FieldField<Field, sphericalTensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor2>& f, const tensor2& s1, const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tensor2& s1, const FieldField<Field, sphericalTensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tensor2& s1, const tmp<FieldField<Field, sphericalTensor2>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor2>& f, const FieldField<Field, tensor2>& f1, const sphericalTensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const FieldField<Field, tensor2>& f1, const sphericalTensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator /(const tmp<FieldField<Field, tensor2>>& tf1, const sphericalTensor2& s2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor2>& f, const FieldField<Field, tensor2>& f1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const FieldField<Field, tensor2>& f1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const FieldField<Field, tensor2>& f1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const tmp<FieldField<Field, tensor2>>& tf1
	                                           , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const tmp<FieldField<Field, tensor2>>& tf1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor2>& f, const FieldField<Field, tensor2>& f1
	              , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const FieldField<Field, tensor2>& f1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const FieldField<Field, tensor2>& f1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const tmp<FieldField<Field, tensor2>>& tf1
	                                           , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const tmp<FieldField<Field, tensor2>>& tf1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor2>& f, const tensor2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const tensor2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const tensor2& s1, const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor2>& f, const FieldField<Field, tensor2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const FieldField<Field, tensor2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const tmp<FieldField<Field, tensor2>>& tf1, const tensor2& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor2>& f, const tensor2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const tensor2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const tensor2& s1, const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor2>& f, const FieldField<Field, tensor2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const FieldField<Field, tensor2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const tmp<FieldField<Field, tensor2>>& tf1, const tensor2& s2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor2>& f, const FieldField<Field, diagTensor2>& f1
	         , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const FieldField<Field, diagTensor2>& f1
	                                           , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const FieldField<Field, diagTensor2>& f1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const tmp<FieldField<Field, diagTensor2>>& tf1
	                                           , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const tmp<FieldField<Field, diagTensor2>>& tf1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor2>& f, const FieldField<Field, diagTensor2>& f1
	              , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const FieldField<Field, diagTensor2>& f1
	                                           , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const FieldField<Field, diagTensor2>& f1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const tmp<FieldField<Field, diagTensor2>>& tf1
	                                           , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const tmp<FieldField<Field, diagTensor2>>& tf1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor2>& f, const diagTensor2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const diagTensor2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const diagTensor2& s1, const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor2>& f, const FieldField<Field, diagTensor2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const FieldField<Field, diagTensor2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const tmp<FieldField<Field, diagTensor2>>& tf1, const tensor2& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor2>& f, const diagTensor2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const diagTensor2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const diagTensor2& s1, const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor2>& f, const FieldField<Field, diagTensor2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const FieldField<Field, diagTensor2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const tmp<FieldField<Field, diagTensor2>>& tf1, const tensor2& s2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor2>& f, const FieldField<Field, sphericalTensor2>& f1
	         , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const FieldField<Field, sphericalTensor2>& f1
	                                           , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const FieldField<Field, sphericalTensor2>& f1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const tmp<FieldField<Field, sphericalTensor2>>& tf1
	                                           , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const tmp<FieldField<Field, sphericalTensor2>>& tf1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor2>& f, const FieldField<Field, sphericalTensor2>& f1
	              , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const FieldField<Field, sphericalTensor2>& f1
	                                           , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const FieldField<Field, sphericalTensor2>& f1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const tmp<FieldField<Field, sphericalTensor2>>& tf1
	                                           , const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const tmp<FieldField<Field, sphericalTensor2>>& tf1
	                                           , const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor2>& f, const sphericalTensor2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const sphericalTensor2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const sphericalTensor2& s1, const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor2>& f, const FieldField<Field, sphericalTensor2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const FieldField<Field, sphericalTensor2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator +(const tmp<FieldField<Field, sphericalTensor2>>& tf1, const tensor2& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor2>& f, const sphericalTensor2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const sphericalTensor2& s1, const FieldField<Field, tensor2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const sphericalTensor2& s1, const tmp<FieldField<Field, tensor2>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor2>& f, const FieldField<Field, sphericalTensor2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const FieldField<Field, sphericalTensor2>& f1, const tensor2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor2>> operator -(const tmp<FieldField<Field, sphericalTensor2>>& tf1, const tensor2& s2);

	template <template<class> class Field>
	void inv(FieldField<Field, tensor3>& res, const FieldField<Field, tensor3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> inv(const FieldField<Field, tensor3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> inv(const tmp<FieldField<Field, tensor3>>& tf);

	template <template<class> class Field>
	void diag(FieldField<Field, diagTensor3>& res, const FieldField<Field, tensor3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, diagTensor3>> diag(const FieldField<Field, tensor3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, diagTensor3>> diag(const tmp<FieldField<Field, tensor3>>& tf);

	template <template<class> class Field>
	void negSumDiag(FieldField<Field, tensor3>& res, const FieldField<Field, tensor3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> negSumDiag(const FieldField<Field, tensor3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> negSumDiag(const tmp<FieldField<Field, tensor3>>& tf);

	template <template<class> class Field>
	void contractLinear(FieldField<Field, vector3>& res, const FieldField<Field, tensor3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> contractLinear(const FieldField<Field, tensor3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> contractLinear(const tmp<FieldField<Field, tensor3>>& tf);

	template <template<class> class Field>
	void contractScalar(FieldField<Field, scalar>& res, const FieldField<Field, tensor3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const FieldField<Field, tensor3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const tmp<FieldField<Field, tensor3>>& tf);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor3>& f, const FieldField<Field, scalar>& f1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const FieldField<Field, scalar>& f1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const FieldField<Field, scalar>& f1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                           , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor3>& f, const scalar& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const scalar& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const scalar& s1, const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor3>& f, const FieldField<Field, scalar>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const FieldField<Field, scalar>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tmp<FieldField<Field, scalar>>& tf1, const tensor3& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector3>& f, const FieldField<Field, vector3>& f1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const FieldField<Field, vector3>& f1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const FieldField<Field, vector3>& f1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const tmp<FieldField<Field, vector3>>& tf1
	                                           , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const tmp<FieldField<Field, vector3>>& tf1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector3>& f, const vector3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const vector3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const vector3& s1, const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector3>& f, const FieldField<Field, vector3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const FieldField<Field, vector3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const tmp<FieldField<Field, vector3>>& tf1, const tensor3& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor3>& f, const FieldField<Field, tensor3>& f1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const FieldField<Field, tensor3>& f1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const FieldField<Field, tensor3>& f1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tmp<FieldField<Field, tensor3>>& tf1
	                                           , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tmp<FieldField<Field, tensor3>>& tf1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor3>& f, const tensor3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tensor3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tensor3& s1, const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor3>& f, const FieldField<Field, tensor3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const FieldField<Field, tensor3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tmp<FieldField<Field, tensor3>>& tf1, const tensor3& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor3>& f, const FieldField<Field, tensor3>& f1
	            , const FieldField<Field, diagTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const FieldField<Field, tensor3>& f1
	                                           , const FieldField<Field, diagTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const FieldField<Field, tensor3>& f1
	                                           , const tmp<FieldField<Field, diagTensor3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tmp<FieldField<Field, tensor3>>& tf1
	                                           , const FieldField<Field, diagTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tmp<FieldField<Field, tensor3>>& tf1
	                                           , const tmp<FieldField<Field, diagTensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor3>& f, const tensor3& s1, const FieldField<Field, diagTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tensor3& s1, const FieldField<Field, diagTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tensor3& s1, const tmp<FieldField<Field, diagTensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor3>& f, const FieldField<Field, tensor3>& f1, const diagTensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const FieldField<Field, tensor3>& f1, const diagTensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tmp<FieldField<Field, tensor3>>& tf1, const diagTensor3& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor3>& f, const FieldField<Field, diagTensor3>& f1
	            , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const FieldField<Field, diagTensor3>& f1
	                                           , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const FieldField<Field, diagTensor3>& f1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tmp<FieldField<Field, diagTensor3>>& tf1
	                                           , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tmp<FieldField<Field, diagTensor3>>& tf1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor3>& f, const diagTensor3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const diagTensor3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const diagTensor3& s1, const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor3>& f, const FieldField<Field, diagTensor3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const FieldField<Field, diagTensor3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tmp<FieldField<Field, diagTensor3>>& tf1, const tensor3& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor3>& f, const FieldField<Field, sphericalTensor3>& f1
	            , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const FieldField<Field, sphericalTensor3>& f1
	                                           , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const FieldField<Field, sphericalTensor3>& f1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tmp<FieldField<Field, sphericalTensor3>>& tf1
	                                           , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tmp<FieldField<Field, sphericalTensor3>>& tf1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor3>& f, const sphericalTensor3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const sphericalTensor3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const sphericalTensor3& s1, const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor3>& f, const FieldField<Field, sphericalTensor3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const FieldField<Field, sphericalTensor3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tmp<FieldField<Field, sphericalTensor3>>& tf1, const tensor3& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor3>& f, const FieldField<Field, tensor3>& f1
	            , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const FieldField<Field, tensor3>& f1
	                                           , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const FieldField<Field, tensor3>& f1
	                                           , const tmp<FieldField<Field, sphericalTensor3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tmp<FieldField<Field, tensor3>>& tf1
	                                           , const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tmp<FieldField<Field, tensor3>>& tf1
	                                           , const tmp<FieldField<Field, sphericalTensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor3>& f, const tensor3& s1, const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tensor3& s1, const FieldField<Field, sphericalTensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tensor3& s1, const tmp<FieldField<Field, sphericalTensor3>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor3>& f, const FieldField<Field, tensor3>& f1, const sphericalTensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const FieldField<Field, tensor3>& f1, const sphericalTensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator /(const tmp<FieldField<Field, tensor3>>& tf1, const sphericalTensor3& s2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor3>& f, const FieldField<Field, tensor3>& f1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const FieldField<Field, tensor3>& f1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const FieldField<Field, tensor3>& f1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const tmp<FieldField<Field, tensor3>>& tf1
	                                           , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const tmp<FieldField<Field, tensor3>>& tf1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor3>& f, const FieldField<Field, tensor3>& f1
	              , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const FieldField<Field, tensor3>& f1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const FieldField<Field, tensor3>& f1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const tmp<FieldField<Field, tensor3>>& tf1
	                                           , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const tmp<FieldField<Field, tensor3>>& tf1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor3>& f, const tensor3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const tensor3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const tensor3& s1, const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor3>& f, const FieldField<Field, tensor3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const FieldField<Field, tensor3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const tmp<FieldField<Field, tensor3>>& tf1, const tensor3& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor3>& f, const tensor3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const tensor3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const tensor3& s1, const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor3>& f, const FieldField<Field, tensor3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const FieldField<Field, tensor3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const tmp<FieldField<Field, tensor3>>& tf1, const tensor3& s2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor3>& f, const FieldField<Field, diagTensor3>& f1
	         , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const FieldField<Field, diagTensor3>& f1
	                                           , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const FieldField<Field, diagTensor3>& f1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const tmp<FieldField<Field, diagTensor3>>& tf1
	                                           , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const tmp<FieldField<Field, diagTensor3>>& tf1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor3>& f, const FieldField<Field, diagTensor3>& f1
	              , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const FieldField<Field, diagTensor3>& f1
	                                           , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const FieldField<Field, diagTensor3>& f1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const tmp<FieldField<Field, diagTensor3>>& tf1
	                                           , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const tmp<FieldField<Field, diagTensor3>>& tf1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor3>& f, const diagTensor3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const diagTensor3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const diagTensor3& s1, const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor3>& f, const FieldField<Field, diagTensor3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const FieldField<Field, diagTensor3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const tmp<FieldField<Field, diagTensor3>>& tf1, const tensor3& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor3>& f, const diagTensor3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const diagTensor3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const diagTensor3& s1, const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor3>& f, const FieldField<Field, diagTensor3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const FieldField<Field, diagTensor3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const tmp<FieldField<Field, diagTensor3>>& tf1, const tensor3& s2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor3>& f, const FieldField<Field, sphericalTensor3>& f1
	         , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const FieldField<Field, sphericalTensor3>& f1
	                                           , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const FieldField<Field, sphericalTensor3>& f1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const tmp<FieldField<Field, sphericalTensor3>>& tf1
	                                           , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const tmp<FieldField<Field, sphericalTensor3>>& tf1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor3>& f, const FieldField<Field, sphericalTensor3>& f1
	              , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const FieldField<Field, sphericalTensor3>& f1
	                                           , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const FieldField<Field, sphericalTensor3>& f1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const tmp<FieldField<Field, sphericalTensor3>>& tf1
	                                           , const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const tmp<FieldField<Field, sphericalTensor3>>& tf1
	                                           , const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor3>& f, const sphericalTensor3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const sphericalTensor3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const sphericalTensor3& s1, const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor3>& f, const FieldField<Field, sphericalTensor3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const FieldField<Field, sphericalTensor3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator +(const tmp<FieldField<Field, sphericalTensor3>>& tf1, const tensor3& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor3>& f, const sphericalTensor3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const sphericalTensor3& s1, const FieldField<Field, tensor3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const sphericalTensor3& s1, const tmp<FieldField<Field, tensor3>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor3>& f, const FieldField<Field, sphericalTensor3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const FieldField<Field, sphericalTensor3>& f1, const tensor3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor3>> operator -(const tmp<FieldField<Field, sphericalTensor3>>& tf1, const tensor3& s2);

	template <template<class> class Field>
	void inv(FieldField<Field, tensor4>& res, const FieldField<Field, tensor4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> inv(const FieldField<Field, tensor4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> inv(const tmp<FieldField<Field, tensor4>>& tf);

	template <template<class> class Field>
	void diag(FieldField<Field, diagTensor4>& res, const FieldField<Field, tensor4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, diagTensor4>> diag(const FieldField<Field, tensor4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, diagTensor4>> diag(const tmp<FieldField<Field, tensor4>>& tf);

	template <template<class> class Field>
	void negSumDiag(FieldField<Field, tensor4>& res, const FieldField<Field, tensor4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> negSumDiag(const FieldField<Field, tensor4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> negSumDiag(const tmp<FieldField<Field, tensor4>>& tf);

	template <template<class> class Field>
	void contractLinear(FieldField<Field, vector4>& res, const FieldField<Field, tensor4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> contractLinear(const FieldField<Field, tensor4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> contractLinear(const tmp<FieldField<Field, tensor4>>& tf);

	template <template<class> class Field>
	void contractScalar(FieldField<Field, scalar>& res, const FieldField<Field, tensor4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const FieldField<Field, tensor4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const tmp<FieldField<Field, tensor4>>& tf);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor4>& f, const FieldField<Field, scalar>& f1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const FieldField<Field, scalar>& f1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const FieldField<Field, scalar>& f1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                           , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor4>& f, const scalar& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const scalar& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const scalar& s1, const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor4>& f, const FieldField<Field, scalar>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const FieldField<Field, scalar>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tmp<FieldField<Field, scalar>>& tf1, const tensor4& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector4>& f, const FieldField<Field, vector4>& f1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const FieldField<Field, vector4>& f1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const FieldField<Field, vector4>& f1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const tmp<FieldField<Field, vector4>>& tf1
	                                           , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const tmp<FieldField<Field, vector4>>& tf1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector4>& f, const vector4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const vector4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const vector4& s1, const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector4>& f, const FieldField<Field, vector4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const FieldField<Field, vector4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const tmp<FieldField<Field, vector4>>& tf1, const tensor4& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor4>& f, const FieldField<Field, tensor4>& f1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const FieldField<Field, tensor4>& f1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const FieldField<Field, tensor4>& f1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tmp<FieldField<Field, tensor4>>& tf1
	                                           , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tmp<FieldField<Field, tensor4>>& tf1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor4>& f, const tensor4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tensor4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tensor4& s1, const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor4>& f, const FieldField<Field, tensor4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const FieldField<Field, tensor4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tmp<FieldField<Field, tensor4>>& tf1, const tensor4& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor4>& f, const FieldField<Field, tensor4>& f1
	            , const FieldField<Field, diagTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const FieldField<Field, tensor4>& f1
	                                           , const FieldField<Field, diagTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const FieldField<Field, tensor4>& f1
	                                           , const tmp<FieldField<Field, diagTensor4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tmp<FieldField<Field, tensor4>>& tf1
	                                           , const FieldField<Field, diagTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tmp<FieldField<Field, tensor4>>& tf1
	                                           , const tmp<FieldField<Field, diagTensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor4>& f, const tensor4& s1, const FieldField<Field, diagTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tensor4& s1, const FieldField<Field, diagTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tensor4& s1, const tmp<FieldField<Field, diagTensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor4>& f, const FieldField<Field, tensor4>& f1, const diagTensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const FieldField<Field, tensor4>& f1, const diagTensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tmp<FieldField<Field, tensor4>>& tf1, const diagTensor4& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor4>& f, const FieldField<Field, diagTensor4>& f1
	            , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const FieldField<Field, diagTensor4>& f1
	                                           , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const FieldField<Field, diagTensor4>& f1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tmp<FieldField<Field, diagTensor4>>& tf1
	                                           , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tmp<FieldField<Field, diagTensor4>>& tf1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor4>& f, const diagTensor4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const diagTensor4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const diagTensor4& s1, const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor4>& f, const FieldField<Field, diagTensor4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const FieldField<Field, diagTensor4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tmp<FieldField<Field, diagTensor4>>& tf1, const tensor4& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor4>& f, const FieldField<Field, sphericalTensor4>& f1
	            , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const FieldField<Field, sphericalTensor4>& f1
	                                           , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const FieldField<Field, sphericalTensor4>& f1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tmp<FieldField<Field, sphericalTensor4>>& tf1
	                                           , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tmp<FieldField<Field, sphericalTensor4>>& tf1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor4>& f, const sphericalTensor4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const sphericalTensor4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const sphericalTensor4& s1, const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor4>& f, const FieldField<Field, sphericalTensor4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const FieldField<Field, sphericalTensor4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tmp<FieldField<Field, sphericalTensor4>>& tf1, const tensor4& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor4>& f, const FieldField<Field, tensor4>& f1
	            , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const FieldField<Field, tensor4>& f1
	                                           , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const FieldField<Field, tensor4>& f1
	                                           , const tmp<FieldField<Field, sphericalTensor4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tmp<FieldField<Field, tensor4>>& tf1
	                                           , const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tmp<FieldField<Field, tensor4>>& tf1
	                                           , const tmp<FieldField<Field, sphericalTensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor4>& f, const tensor4& s1, const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tensor4& s1, const FieldField<Field, sphericalTensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tensor4& s1, const tmp<FieldField<Field, sphericalTensor4>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor4>& f, const FieldField<Field, tensor4>& f1, const sphericalTensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const FieldField<Field, tensor4>& f1, const sphericalTensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator /(const tmp<FieldField<Field, tensor4>>& tf1, const sphericalTensor4& s2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor4>& f, const FieldField<Field, tensor4>& f1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const FieldField<Field, tensor4>& f1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const FieldField<Field, tensor4>& f1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const tmp<FieldField<Field, tensor4>>& tf1
	                                           , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const tmp<FieldField<Field, tensor4>>& tf1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor4>& f, const FieldField<Field, tensor4>& f1
	              , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const FieldField<Field, tensor4>& f1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const FieldField<Field, tensor4>& f1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const tmp<FieldField<Field, tensor4>>& tf1
	                                           , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const tmp<FieldField<Field, tensor4>>& tf1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor4>& f, const tensor4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const tensor4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const tensor4& s1, const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor4>& f, const FieldField<Field, tensor4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const FieldField<Field, tensor4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const tmp<FieldField<Field, tensor4>>& tf1, const tensor4& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor4>& f, const tensor4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const tensor4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const tensor4& s1, const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor4>& f, const FieldField<Field, tensor4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const FieldField<Field, tensor4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const tmp<FieldField<Field, tensor4>>& tf1, const tensor4& s2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor4>& f, const FieldField<Field, diagTensor4>& f1
	         , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const FieldField<Field, diagTensor4>& f1
	                                           , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const FieldField<Field, diagTensor4>& f1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const tmp<FieldField<Field, diagTensor4>>& tf1
	                                           , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const tmp<FieldField<Field, diagTensor4>>& tf1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor4>& f, const FieldField<Field, diagTensor4>& f1
	              , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const FieldField<Field, diagTensor4>& f1
	                                           , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const FieldField<Field, diagTensor4>& f1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const tmp<FieldField<Field, diagTensor4>>& tf1
	                                           , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const tmp<FieldField<Field, diagTensor4>>& tf1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor4>& f, const diagTensor4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const diagTensor4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const diagTensor4& s1, const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor4>& f, const FieldField<Field, diagTensor4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const FieldField<Field, diagTensor4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const tmp<FieldField<Field, diagTensor4>>& tf1, const tensor4& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor4>& f, const diagTensor4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const diagTensor4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const diagTensor4& s1, const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor4>& f, const FieldField<Field, diagTensor4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const FieldField<Field, diagTensor4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const tmp<FieldField<Field, diagTensor4>>& tf1, const tensor4& s2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor4>& f, const FieldField<Field, sphericalTensor4>& f1
	         , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const FieldField<Field, sphericalTensor4>& f1
	                                           , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const FieldField<Field, sphericalTensor4>& f1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const tmp<FieldField<Field, sphericalTensor4>>& tf1
	                                           , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const tmp<FieldField<Field, sphericalTensor4>>& tf1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor4>& f, const FieldField<Field, sphericalTensor4>& f1
	              , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const FieldField<Field, sphericalTensor4>& f1
	                                           , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const FieldField<Field, sphericalTensor4>& f1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const tmp<FieldField<Field, sphericalTensor4>>& tf1
	                                           , const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const tmp<FieldField<Field, sphericalTensor4>>& tf1
	                                           , const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor4>& f, const sphericalTensor4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const sphericalTensor4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const sphericalTensor4& s1, const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor4>& f, const FieldField<Field, sphericalTensor4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const FieldField<Field, sphericalTensor4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator +(const tmp<FieldField<Field, sphericalTensor4>>& tf1, const tensor4& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor4>& f, const sphericalTensor4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const sphericalTensor4& s1, const FieldField<Field, tensor4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const sphericalTensor4& s1, const tmp<FieldField<Field, tensor4>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor4>& f, const FieldField<Field, sphericalTensor4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const FieldField<Field, sphericalTensor4>& f1, const tensor4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor4>> operator -(const tmp<FieldField<Field, sphericalTensor4>>& tf1, const tensor4& s2);

	template <template<class> class Field>
	void inv(FieldField<Field, tensor6>& res, const FieldField<Field, tensor6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> inv(const FieldField<Field, tensor6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> inv(const tmp<FieldField<Field, tensor6>>& tf);

	template <template<class> class Field>
	void diag(FieldField<Field, diagTensor6>& res, const FieldField<Field, tensor6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, diagTensor6>> diag(const FieldField<Field, tensor6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, diagTensor6>> diag(const tmp<FieldField<Field, tensor6>>& tf);

	template <template<class> class Field>
	void negSumDiag(FieldField<Field, tensor6>& res, const FieldField<Field, tensor6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> negSumDiag(const FieldField<Field, tensor6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> negSumDiag(const tmp<FieldField<Field, tensor6>>& tf);

	template <template<class> class Field>
	void contractLinear(FieldField<Field, vector6>& res, const FieldField<Field, tensor6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> contractLinear(const FieldField<Field, tensor6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> contractLinear(const tmp<FieldField<Field, tensor6>>& tf);

	template <template<class> class Field>
	void contractScalar(FieldField<Field, scalar>& res, const FieldField<Field, tensor6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const FieldField<Field, tensor6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const tmp<FieldField<Field, tensor6>>& tf);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor6>& f, const FieldField<Field, scalar>& f1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const FieldField<Field, scalar>& f1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const FieldField<Field, scalar>& f1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                           , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor6>& f, const scalar& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const scalar& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const scalar& s1, const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor6>& f, const FieldField<Field, scalar>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const FieldField<Field, scalar>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tmp<FieldField<Field, scalar>>& tf1, const tensor6& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector6>& f, const FieldField<Field, vector6>& f1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const FieldField<Field, vector6>& f1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const FieldField<Field, vector6>& f1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const tmp<FieldField<Field, vector6>>& tf1
	                                           , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const tmp<FieldField<Field, vector6>>& tf1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector6>& f, const vector6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const vector6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const vector6& s1, const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector6>& f, const FieldField<Field, vector6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const FieldField<Field, vector6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const tmp<FieldField<Field, vector6>>& tf1, const tensor6& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor6>& f, const FieldField<Field, tensor6>& f1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const FieldField<Field, tensor6>& f1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const FieldField<Field, tensor6>& f1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tmp<FieldField<Field, tensor6>>& tf1
	                                           , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tmp<FieldField<Field, tensor6>>& tf1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor6>& f, const tensor6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tensor6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tensor6& s1, const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor6>& f, const FieldField<Field, tensor6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const FieldField<Field, tensor6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tmp<FieldField<Field, tensor6>>& tf1, const tensor6& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor6>& f, const FieldField<Field, tensor6>& f1
	            , const FieldField<Field, diagTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const FieldField<Field, tensor6>& f1
	                                           , const FieldField<Field, diagTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const FieldField<Field, tensor6>& f1
	                                           , const tmp<FieldField<Field, diagTensor6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tmp<FieldField<Field, tensor6>>& tf1
	                                           , const FieldField<Field, diagTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tmp<FieldField<Field, tensor6>>& tf1
	                                           , const tmp<FieldField<Field, diagTensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor6>& f, const tensor6& s1, const FieldField<Field, diagTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tensor6& s1, const FieldField<Field, diagTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tensor6& s1, const tmp<FieldField<Field, diagTensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor6>& f, const FieldField<Field, tensor6>& f1, const diagTensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const FieldField<Field, tensor6>& f1, const diagTensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tmp<FieldField<Field, tensor6>>& tf1, const diagTensor6& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor6>& f, const FieldField<Field, diagTensor6>& f1
	            , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const FieldField<Field, diagTensor6>& f1
	                                           , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const FieldField<Field, diagTensor6>& f1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tmp<FieldField<Field, diagTensor6>>& tf1
	                                           , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tmp<FieldField<Field, diagTensor6>>& tf1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor6>& f, const diagTensor6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const diagTensor6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const diagTensor6& s1, const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor6>& f, const FieldField<Field, diagTensor6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const FieldField<Field, diagTensor6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tmp<FieldField<Field, diagTensor6>>& tf1, const tensor6& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor6>& f, const FieldField<Field, sphericalTensor6>& f1
	            , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const FieldField<Field, sphericalTensor6>& f1
	                                           , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const FieldField<Field, sphericalTensor6>& f1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tmp<FieldField<Field, sphericalTensor6>>& tf1
	                                           , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tmp<FieldField<Field, sphericalTensor6>>& tf1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor6>& f, const sphericalTensor6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const sphericalTensor6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const sphericalTensor6& s1, const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor6>& f, const FieldField<Field, sphericalTensor6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const FieldField<Field, sphericalTensor6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tmp<FieldField<Field, sphericalTensor6>>& tf1, const tensor6& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor6>& f, const FieldField<Field, tensor6>& f1
	            , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const FieldField<Field, tensor6>& f1
	                                           , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const FieldField<Field, tensor6>& f1
	                                           , const tmp<FieldField<Field, sphericalTensor6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tmp<FieldField<Field, tensor6>>& tf1
	                                           , const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tmp<FieldField<Field, tensor6>>& tf1
	                                           , const tmp<FieldField<Field, sphericalTensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor6>& f, const tensor6& s1, const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tensor6& s1, const FieldField<Field, sphericalTensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tensor6& s1, const tmp<FieldField<Field, sphericalTensor6>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor6>& f, const FieldField<Field, tensor6>& f1, const sphericalTensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const FieldField<Field, tensor6>& f1, const sphericalTensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator /(const tmp<FieldField<Field, tensor6>>& tf1, const sphericalTensor6& s2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor6>& f, const FieldField<Field, tensor6>& f1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const FieldField<Field, tensor6>& f1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const FieldField<Field, tensor6>& f1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const tmp<FieldField<Field, tensor6>>& tf1
	                                           , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const tmp<FieldField<Field, tensor6>>& tf1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor6>& f, const FieldField<Field, tensor6>& f1
	              , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const FieldField<Field, tensor6>& f1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const FieldField<Field, tensor6>& f1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const tmp<FieldField<Field, tensor6>>& tf1
	                                           , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const tmp<FieldField<Field, tensor6>>& tf1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor6>& f, const tensor6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const tensor6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const tensor6& s1, const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor6>& f, const FieldField<Field, tensor6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const FieldField<Field, tensor6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const tmp<FieldField<Field, tensor6>>& tf1, const tensor6& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor6>& f, const tensor6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const tensor6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const tensor6& s1, const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor6>& f, const FieldField<Field, tensor6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const FieldField<Field, tensor6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const tmp<FieldField<Field, tensor6>>& tf1, const tensor6& s2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor6>& f, const FieldField<Field, diagTensor6>& f1
	         , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const FieldField<Field, diagTensor6>& f1
	                                           , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const FieldField<Field, diagTensor6>& f1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const tmp<FieldField<Field, diagTensor6>>& tf1
	                                           , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const tmp<FieldField<Field, diagTensor6>>& tf1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor6>& f, const FieldField<Field, diagTensor6>& f1
	              , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const FieldField<Field, diagTensor6>& f1
	                                           , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const FieldField<Field, diagTensor6>& f1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const tmp<FieldField<Field, diagTensor6>>& tf1
	                                           , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const tmp<FieldField<Field, diagTensor6>>& tf1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor6>& f, const diagTensor6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const diagTensor6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const diagTensor6& s1, const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor6>& f, const FieldField<Field, diagTensor6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const FieldField<Field, diagTensor6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const tmp<FieldField<Field, diagTensor6>>& tf1, const tensor6& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor6>& f, const diagTensor6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const diagTensor6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const diagTensor6& s1, const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor6>& f, const FieldField<Field, diagTensor6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const FieldField<Field, diagTensor6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const tmp<FieldField<Field, diagTensor6>>& tf1, const tensor6& s2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor6>& f, const FieldField<Field, sphericalTensor6>& f1
	         , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const FieldField<Field, sphericalTensor6>& f1
	                                           , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const FieldField<Field, sphericalTensor6>& f1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const tmp<FieldField<Field, sphericalTensor6>>& tf1
	                                           , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const tmp<FieldField<Field, sphericalTensor6>>& tf1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor6>& f, const FieldField<Field, sphericalTensor6>& f1
	              , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const FieldField<Field, sphericalTensor6>& f1
	                                           , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const FieldField<Field, sphericalTensor6>& f1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const tmp<FieldField<Field, sphericalTensor6>>& tf1
	                                           , const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const tmp<FieldField<Field, sphericalTensor6>>& tf1
	                                           , const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor6>& f, const sphericalTensor6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const sphericalTensor6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const sphericalTensor6& s1, const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor6>& f, const FieldField<Field, sphericalTensor6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const FieldField<Field, sphericalTensor6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator +(const tmp<FieldField<Field, sphericalTensor6>>& tf1, const tensor6& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor6>& f, const sphericalTensor6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const sphericalTensor6& s1, const FieldField<Field, tensor6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const sphericalTensor6& s1, const tmp<FieldField<Field, tensor6>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor6>& f, const FieldField<Field, sphericalTensor6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const FieldField<Field, sphericalTensor6>& f1, const tensor6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor6>> operator -(const tmp<FieldField<Field, sphericalTensor6>>& tf1, const tensor6& s2);

	template <template<class> class Field>
	void inv(FieldField<Field, tensor8>& res, const FieldField<Field, tensor8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> inv(const FieldField<Field, tensor8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> inv(const tmp<FieldField<Field, tensor8>>& tf);

	template <template<class> class Field>
	void diag(FieldField<Field, diagTensor8>& res, const FieldField<Field, tensor8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, diagTensor8>> diag(const FieldField<Field, tensor8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, diagTensor8>> diag(const tmp<FieldField<Field, tensor8>>& tf);

	template <template<class> class Field>
	void negSumDiag(FieldField<Field, tensor8>& res, const FieldField<Field, tensor8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> negSumDiag(const FieldField<Field, tensor8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> negSumDiag(const tmp<FieldField<Field, tensor8>>& tf);

	template <template<class> class Field>
	void contractLinear(FieldField<Field, vector8>& res, const FieldField<Field, tensor8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> contractLinear(const FieldField<Field, tensor8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> contractLinear(const tmp<FieldField<Field, tensor8>>& tf);

	template <template<class> class Field>
	void contractScalar(FieldField<Field, scalar>& res, const FieldField<Field, tensor8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const FieldField<Field, tensor8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> contractScalar(const tmp<FieldField<Field, tensor8>>& tf);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor8>& f, const FieldField<Field, scalar>& f1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const FieldField<Field, scalar>& f1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const FieldField<Field, scalar>& f1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                           , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tmp<FieldField<Field, scalar>>& tf1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor8>& f, const scalar& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const scalar& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const scalar& s1, const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor8>& f, const FieldField<Field, scalar>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const FieldField<Field, scalar>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tmp<FieldField<Field, scalar>>& tf1, const tensor8& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector8>& f, const FieldField<Field, vector8>& f1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const FieldField<Field, vector8>& f1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const FieldField<Field, vector8>& f1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const tmp<FieldField<Field, vector8>>& tf1
	                                           , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const tmp<FieldField<Field, vector8>>& tf1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector8>& f, const vector8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const vector8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const vector8& s1, const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector8>& f, const FieldField<Field, vector8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const FieldField<Field, vector8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const tmp<FieldField<Field, vector8>>& tf1, const tensor8& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor8>& f, const FieldField<Field, tensor8>& f1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const FieldField<Field, tensor8>& f1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const FieldField<Field, tensor8>& f1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tmp<FieldField<Field, tensor8>>& tf1
	                                           , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tmp<FieldField<Field, tensor8>>& tf1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor8>& f, const tensor8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tensor8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tensor8& s1, const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor8>& f, const FieldField<Field, tensor8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const FieldField<Field, tensor8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tmp<FieldField<Field, tensor8>>& tf1, const tensor8& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor8>& f, const FieldField<Field, tensor8>& f1
	            , const FieldField<Field, diagTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const FieldField<Field, tensor8>& f1
	                                           , const FieldField<Field, diagTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const FieldField<Field, tensor8>& f1
	                                           , const tmp<FieldField<Field, diagTensor8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tmp<FieldField<Field, tensor8>>& tf1
	                                           , const FieldField<Field, diagTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tmp<FieldField<Field, tensor8>>& tf1
	                                           , const tmp<FieldField<Field, diagTensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor8>& f, const tensor8& s1, const FieldField<Field, diagTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tensor8& s1, const FieldField<Field, diagTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tensor8& s1, const tmp<FieldField<Field, diagTensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor8>& f, const FieldField<Field, tensor8>& f1, const diagTensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const FieldField<Field, tensor8>& f1, const diagTensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tmp<FieldField<Field, tensor8>>& tf1, const diagTensor8& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor8>& f, const FieldField<Field, diagTensor8>& f1
	            , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const FieldField<Field, diagTensor8>& f1
	                                           , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const FieldField<Field, diagTensor8>& f1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tmp<FieldField<Field, diagTensor8>>& tf1
	                                           , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tmp<FieldField<Field, diagTensor8>>& tf1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor8>& f, const diagTensor8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const diagTensor8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const diagTensor8& s1, const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor8>& f, const FieldField<Field, diagTensor8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const FieldField<Field, diagTensor8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tmp<FieldField<Field, diagTensor8>>& tf1, const tensor8& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor8>& f, const FieldField<Field, sphericalTensor8>& f1
	            , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const FieldField<Field, sphericalTensor8>& f1
	                                           , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const FieldField<Field, sphericalTensor8>& f1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tmp<FieldField<Field, sphericalTensor8>>& tf1
	                                           , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tmp<FieldField<Field, sphericalTensor8>>& tf1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor8>& f, const sphericalTensor8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const sphericalTensor8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const sphericalTensor8& s1, const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor8>& f, const FieldField<Field, sphericalTensor8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const FieldField<Field, sphericalTensor8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tmp<FieldField<Field, sphericalTensor8>>& tf1, const tensor8& s2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor8>& f, const FieldField<Field, tensor8>& f1
	            , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const FieldField<Field, tensor8>& f1
	                                           , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const FieldField<Field, tensor8>& f1
	                                           , const tmp<FieldField<Field, sphericalTensor8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tmp<FieldField<Field, tensor8>>& tf1
	                                           , const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tmp<FieldField<Field, tensor8>>& tf1
	                                           , const tmp<FieldField<Field, sphericalTensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor8>& f, const tensor8& s1, const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tensor8& s1, const FieldField<Field, sphericalTensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tensor8& s1, const tmp<FieldField<Field, sphericalTensor8>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, tensor8>& f, const FieldField<Field, tensor8>& f1, const sphericalTensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const FieldField<Field, tensor8>& f1, const sphericalTensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator /(const tmp<FieldField<Field, tensor8>>& tf1, const sphericalTensor8& s2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor8>& f, const FieldField<Field, tensor8>& f1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const FieldField<Field, tensor8>& f1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const FieldField<Field, tensor8>& f1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const tmp<FieldField<Field, tensor8>>& tf1
	                                           , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const tmp<FieldField<Field, tensor8>>& tf1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor8>& f, const FieldField<Field, tensor8>& f1
	              , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const FieldField<Field, tensor8>& f1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const FieldField<Field, tensor8>& f1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const tmp<FieldField<Field, tensor8>>& tf1
	                                           , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const tmp<FieldField<Field, tensor8>>& tf1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor8>& f, const tensor8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const tensor8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const tensor8& s1, const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor8>& f, const FieldField<Field, tensor8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const FieldField<Field, tensor8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const tmp<FieldField<Field, tensor8>>& tf1, const tensor8& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor8>& f, const tensor8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const tensor8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const tensor8& s1, const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor8>& f, const FieldField<Field, tensor8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const FieldField<Field, tensor8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const tmp<FieldField<Field, tensor8>>& tf1, const tensor8& s2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor8>& f, const FieldField<Field, diagTensor8>& f1
	         , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const FieldField<Field, diagTensor8>& f1
	                                           , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const FieldField<Field, diagTensor8>& f1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const tmp<FieldField<Field, diagTensor8>>& tf1
	                                           , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const tmp<FieldField<Field, diagTensor8>>& tf1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor8>& f, const FieldField<Field, diagTensor8>& f1
	              , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const FieldField<Field, diagTensor8>& f1
	                                           , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const FieldField<Field, diagTensor8>& f1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const tmp<FieldField<Field, diagTensor8>>& tf1
	                                           , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const tmp<FieldField<Field, diagTensor8>>& tf1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor8>& f, const diagTensor8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const diagTensor8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const diagTensor8& s1, const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor8>& f, const FieldField<Field, diagTensor8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const FieldField<Field, diagTensor8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const tmp<FieldField<Field, diagTensor8>>& tf1, const tensor8& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor8>& f, const diagTensor8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const diagTensor8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const diagTensor8& s1, const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor8>& f, const FieldField<Field, diagTensor8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const FieldField<Field, diagTensor8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const tmp<FieldField<Field, diagTensor8>>& tf1, const tensor8& s2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor8>& f, const FieldField<Field, sphericalTensor8>& f1
	         , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const FieldField<Field, sphericalTensor8>& f1
	                                           , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const FieldField<Field, sphericalTensor8>& f1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const tmp<FieldField<Field, sphericalTensor8>>& tf1
	                                           , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const tmp<FieldField<Field, sphericalTensor8>>& tf1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor8>& f, const FieldField<Field, sphericalTensor8>& f1
	              , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const FieldField<Field, sphericalTensor8>& f1
	                                           , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const FieldField<Field, sphericalTensor8>& f1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const tmp<FieldField<Field, sphericalTensor8>>& tf1
	                                           , const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const tmp<FieldField<Field, sphericalTensor8>>& tf1
	                                           , const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor8>& f, const sphericalTensor8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const sphericalTensor8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const sphericalTensor8& s1, const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, tensor8>& f, const FieldField<Field, sphericalTensor8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const FieldField<Field, sphericalTensor8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator +(const tmp<FieldField<Field, sphericalTensor8>>& tf1, const tensor8& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor8>& f, const sphericalTensor8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const sphericalTensor8& s1, const FieldField<Field, tensor8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const sphericalTensor8& s1, const tmp<FieldField<Field, tensor8>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, tensor8>& f, const FieldField<Field, sphericalTensor8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const FieldField<Field, sphericalTensor8>& f1, const tensor8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor8>> operator -(const tmp<FieldField<Field, sphericalTensor8>>& tf1, const tensor8& s2);
}

#undef TensorN_FieldFunctions

#include <undefFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <TensorNFieldFields.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !1
