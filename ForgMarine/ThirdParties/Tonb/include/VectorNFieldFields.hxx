#pragma once
#ifndef _VectorNFieldFields_Header
#define _VectorNFieldFields_Header

#include <VectorTensorNFieldFieldsFwd.hxx>
#include <FieldField.hxx>

#define TEMPLATE template<template<class> class Field>
#include <FieldFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define VectorN_FieldFunctions(tensorType, diagTensorType, sphericalTensorType,         \
    vectorType, CmptType, args)                                                      \
                                                                                        \
UNARY_FUNCTION(CmptType, vectorType, cmptSum)                                           \
                                                                                        \
BINARY_FUNCTION(vectorType, vectorType, vectorType, cmptMultiply)                       \
BINARY_TYPE_FUNCTION(vectorType, vectorType, vectorType, cmptMultiply)                  \
                                                                                        \
BINARY_OPERATOR(vectorType, vectorType, CmptType, /,divide)                             \
BINARY_TYPE_OPERATOR(vectorType, vectorType, CmptType, /,divide)                        \
                                                                                        \
BINARY_OPERATOR(vectorType, vectorType, vectorType, +, add)                             \
BINARY_OPERATOR(vectorType, vectorType, vectorType, -, subtract)                        \
                                                                                        \
BINARY_TYPE_OPERATOR(vectorType, vectorType, vectorType, +, add)                        \
BINARY_TYPE_OPERATOR(vectorType, vectorType, vectorType, -, subtract)


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	template <template<class> class Field>
	void cmptSum(FieldField<Field, scalar>& res, const FieldField<Field, vector2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> cmptSum(const FieldField<Field, vector2>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> cmptSum(const tmp<FieldField<Field, vector2>>& tf);

	template <template<class> class Field>
	void func(FieldField<Field, vector2>& f, const FieldField<Field, vector2>& f1, const FieldField<Field, vector2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> func(const FieldField<Field, vector2>& f1, const FieldField<Field, vector2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> func(const FieldField<Field, vector2>& f1, const tmp<FieldField<Field, vector2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> func(const tmp<FieldField<Field, vector2>>& tf1, const FieldField<Field, vector2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> func(const tmp<FieldField<Field, vector2>>& tf1
	                                     , const tmp<FieldField<Field, vector2>>& tf2);

	template <template<class> class Field>
	void func(FieldField<Field, vector2>& f, const vector2& s1, const FieldField<Field, vector2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> func(const vector2& s1, const FieldField<Field, vector2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> func(const vector2& s1, const tmp<FieldField<Field, vector2>>& tf2);

	template <template<class> class Field>
	void func(FieldField<Field, vector2>& f, const FieldField<Field, vector2>& f1, const vector2& s);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> func(const FieldField<Field, vector2>& f1, const vector2& s);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> func(const tmp<FieldField<Field, vector2>>& tf1, const vector2& s);

	template <template<class> class Field>
	void divide(FieldField<Field, vector2>& f, const FieldField<Field, vector2>& f1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const FieldField<Field, vector2>& f1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const FieldField<Field, vector2>& f1
	                                           , const tmp<FieldField<Field, scalar>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const tmp<FieldField<Field, vector2>>& tf1
	                                           , const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const tmp<FieldField<Field, vector2>>& tf1
	                                           , const tmp<FieldField<Field, scalar>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector2>& f, const vector2& s1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const vector2& s1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const vector2& s1, const tmp<FieldField<Field, scalar>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector2>& f, const FieldField<Field, vector2>& f1, const scalar& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const FieldField<Field, vector2>& f1, const scalar& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator /(const tmp<FieldField<Field, vector2>>& tf1, const scalar& s2);

	template <template<class> class Field>
	void add(FieldField<Field, vector2>& f, const FieldField<Field, vector2>& f1, const FieldField<Field, vector2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator +(const FieldField<Field, vector2>& f1, const FieldField<Field, vector2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator +(const FieldField<Field, vector2>& f1
	                                           , const tmp<FieldField<Field, vector2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator +(const tmp<FieldField<Field, vector2>>& tf1
	                                           , const FieldField<Field, vector2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator +(const tmp<FieldField<Field, vector2>>& tf1
	                                           , const tmp<FieldField<Field, vector2>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, vector2>& f, const FieldField<Field, vector2>& f1
	              , const FieldField<Field, vector2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator -(const FieldField<Field, vector2>& f1, const FieldField<Field, vector2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator -(const FieldField<Field, vector2>& f1
	                                           , const tmp<FieldField<Field, vector2>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator -(const tmp<FieldField<Field, vector2>>& tf1
	                                           , const FieldField<Field, vector2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator -(const tmp<FieldField<Field, vector2>>& tf1
	                                           , const tmp<FieldField<Field, vector2>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, vector2>& f, const vector2& s1, const FieldField<Field, vector2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator +(const vector2& s1, const FieldField<Field, vector2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator +(const vector2& s1, const tmp<FieldField<Field, vector2>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, vector2>& f, const FieldField<Field, vector2>& f1, const vector2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator +(const FieldField<Field, vector2>& f1, const vector2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator +(const tmp<FieldField<Field, vector2>>& tf1, const vector2& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, vector2>& f, const vector2& s1, const FieldField<Field, vector2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator -(const vector2& s1, const FieldField<Field, vector2>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator -(const vector2& s1, const tmp<FieldField<Field, vector2>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, vector2>& f, const FieldField<Field, vector2>& f1, const vector2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator -(const FieldField<Field, vector2>& f1, const vector2& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector2>> operator -(const tmp<FieldField<Field, vector2>>& tf1, const vector2& s2);

	template <template<class> class Field>
	void cmptSum(FieldField<Field, scalar>& res, const FieldField<Field, vector3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> cmptSum(const FieldField<Field, vector3>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> cmptSum(const tmp<FieldField<Field, vector3>>& tf);

	template <template<class> class Field>
	void func(FieldField<Field, vector3>& f, const FieldField<Field, vector3>& f1, const FieldField<Field, vector3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> func(const FieldField<Field, vector3>& f1, const FieldField<Field, vector3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> func(const FieldField<Field, vector3>& f1, const tmp<FieldField<Field, vector3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> func(const tmp<FieldField<Field, vector3>>& tf1, const FieldField<Field, vector3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> func(const tmp<FieldField<Field, vector3>>& tf1
	                                     , const tmp<FieldField<Field, vector3>>& tf2);

	template <template<class> class Field>
	void func(FieldField<Field, vector3>& f, const vector3& s1, const FieldField<Field, vector3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> func(const vector3& s1, const FieldField<Field, vector3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> func(const vector3& s1, const tmp<FieldField<Field, vector3>>& tf2);

	template <template<class> class Field>
	void func(FieldField<Field, vector3>& f, const FieldField<Field, vector3>& f1, const vector3& s);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> func(const FieldField<Field, vector3>& f1, const vector3& s);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> func(const tmp<FieldField<Field, vector3>>& tf1, const vector3& s);

	template <template<class> class Field>
	void divide(FieldField<Field, vector3>& f, const FieldField<Field, vector3>& f1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const FieldField<Field, vector3>& f1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const FieldField<Field, vector3>& f1
	                                           , const tmp<FieldField<Field, scalar>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const tmp<FieldField<Field, vector3>>& tf1
	                                           , const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const tmp<FieldField<Field, vector3>>& tf1
	                                           , const tmp<FieldField<Field, scalar>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector3>& f, const vector3& s1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const vector3& s1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const vector3& s1, const tmp<FieldField<Field, scalar>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector3>& f, const FieldField<Field, vector3>& f1, const scalar& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const FieldField<Field, vector3>& f1, const scalar& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator /(const tmp<FieldField<Field, vector3>>& tf1, const scalar& s2);

	template <template<class> class Field>
	void add(FieldField<Field, vector3>& f, const FieldField<Field, vector3>& f1, const FieldField<Field, vector3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator +(const FieldField<Field, vector3>& f1, const FieldField<Field, vector3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator +(const FieldField<Field, vector3>& f1
	                                           , const tmp<FieldField<Field, vector3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator +(const tmp<FieldField<Field, vector3>>& tf1
	                                           , const FieldField<Field, vector3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator +(const tmp<FieldField<Field, vector3>>& tf1
	                                           , const tmp<FieldField<Field, vector3>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, vector3>& f, const FieldField<Field, vector3>& f1
	              , const FieldField<Field, vector3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator -(const FieldField<Field, vector3>& f1, const FieldField<Field, vector3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator -(const FieldField<Field, vector3>& f1
	                                           , const tmp<FieldField<Field, vector3>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator -(const tmp<FieldField<Field, vector3>>& tf1
	                                           , const FieldField<Field, vector3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator -(const tmp<FieldField<Field, vector3>>& tf1
	                                           , const tmp<FieldField<Field, vector3>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, vector3>& f, const vector3& s1, const FieldField<Field, vector3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator +(const vector3& s1, const FieldField<Field, vector3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator +(const vector3& s1, const tmp<FieldField<Field, vector3>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, vector3>& f, const FieldField<Field, vector3>& f1, const vector3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator +(const FieldField<Field, vector3>& f1, const vector3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator +(const tmp<FieldField<Field, vector3>>& tf1, const vector3& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, vector3>& f, const vector3& s1, const FieldField<Field, vector3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator -(const vector3& s1, const FieldField<Field, vector3>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator -(const vector3& s1, const tmp<FieldField<Field, vector3>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, vector3>& f, const FieldField<Field, vector3>& f1, const vector3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator -(const FieldField<Field, vector3>& f1, const vector3& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector3>> operator -(const tmp<FieldField<Field, vector3>>& tf1, const vector3& s2);

	template <template<class> class Field>
	void cmptSum(FieldField<Field, scalar>& res, const FieldField<Field, vector4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> cmptSum(const FieldField<Field, vector4>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> cmptSum(const tmp<FieldField<Field, vector4>>& tf);

	template <template<class> class Field>
	void func(FieldField<Field, vector4>& f, const FieldField<Field, vector4>& f1, const FieldField<Field, vector4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> func(const FieldField<Field, vector4>& f1, const FieldField<Field, vector4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> func(const FieldField<Field, vector4>& f1, const tmp<FieldField<Field, vector4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> func(const tmp<FieldField<Field, vector4>>& tf1, const FieldField<Field, vector4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> func(const tmp<FieldField<Field, vector4>>& tf1
	                                     , const tmp<FieldField<Field, vector4>>& tf2);

	template <template<class> class Field>
	void func(FieldField<Field, vector4>& f, const vector4& s1, const FieldField<Field, vector4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> func(const vector4& s1, const FieldField<Field, vector4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> func(const vector4& s1, const tmp<FieldField<Field, vector4>>& tf2);

	template <template<class> class Field>
	void func(FieldField<Field, vector4>& f, const FieldField<Field, vector4>& f1, const vector4& s);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> func(const FieldField<Field, vector4>& f1, const vector4& s);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> func(const tmp<FieldField<Field, vector4>>& tf1, const vector4& s);

	template <template<class> class Field>
	void divide(FieldField<Field, vector4>& f, const FieldField<Field, vector4>& f1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const FieldField<Field, vector4>& f1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const FieldField<Field, vector4>& f1
	                                           , const tmp<FieldField<Field, scalar>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const tmp<FieldField<Field, vector4>>& tf1
	                                           , const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const tmp<FieldField<Field, vector4>>& tf1
	                                           , const tmp<FieldField<Field, scalar>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector4>& f, const vector4& s1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const vector4& s1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const vector4& s1, const tmp<FieldField<Field, scalar>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector4>& f, const FieldField<Field, vector4>& f1, const scalar& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const FieldField<Field, vector4>& f1, const scalar& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator /(const tmp<FieldField<Field, vector4>>& tf1, const scalar& s2);

	template <template<class> class Field>
	void add(FieldField<Field, vector4>& f, const FieldField<Field, vector4>& f1, const FieldField<Field, vector4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator +(const FieldField<Field, vector4>& f1, const FieldField<Field, vector4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator +(const FieldField<Field, vector4>& f1
	                                           , const tmp<FieldField<Field, vector4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator +(const tmp<FieldField<Field, vector4>>& tf1
	                                           , const FieldField<Field, vector4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator +(const tmp<FieldField<Field, vector4>>& tf1
	                                           , const tmp<FieldField<Field, vector4>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, vector4>& f, const FieldField<Field, vector4>& f1
	              , const FieldField<Field, vector4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator -(const FieldField<Field, vector4>& f1, const FieldField<Field, vector4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator -(const FieldField<Field, vector4>& f1
	                                           , const tmp<FieldField<Field, vector4>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator -(const tmp<FieldField<Field, vector4>>& tf1
	                                           , const FieldField<Field, vector4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator -(const tmp<FieldField<Field, vector4>>& tf1
	                                           , const tmp<FieldField<Field, vector4>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, vector4>& f, const vector4& s1, const FieldField<Field, vector4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator +(const vector4& s1, const FieldField<Field, vector4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator +(const vector4& s1, const tmp<FieldField<Field, vector4>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, vector4>& f, const FieldField<Field, vector4>& f1, const vector4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator +(const FieldField<Field, vector4>& f1, const vector4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator +(const tmp<FieldField<Field, vector4>>& tf1, const vector4& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, vector4>& f, const vector4& s1, const FieldField<Field, vector4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator -(const vector4& s1, const FieldField<Field, vector4>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator -(const vector4& s1, const tmp<FieldField<Field, vector4>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, vector4>& f, const FieldField<Field, vector4>& f1, const vector4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator -(const FieldField<Field, vector4>& f1, const vector4& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector4>> operator -(const tmp<FieldField<Field, vector4>>& tf1, const vector4& s2);

	template <template<class> class Field>
	void cmptSum(FieldField<Field, scalar>& res, const FieldField<Field, vector6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> cmptSum(const FieldField<Field, vector6>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> cmptSum(const tmp<FieldField<Field, vector6>>& tf);

	template <template<class> class Field>
	void func(FieldField<Field, vector6>& f, const FieldField<Field, vector6>& f1, const FieldField<Field, vector6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> func(const FieldField<Field, vector6>& f1, const FieldField<Field, vector6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> func(const FieldField<Field, vector6>& f1, const tmp<FieldField<Field, vector6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> func(const tmp<FieldField<Field, vector6>>& tf1, const FieldField<Field, vector6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> func(const tmp<FieldField<Field, vector6>>& tf1
	                                     , const tmp<FieldField<Field, vector6>>& tf2);

	template <template<class> class Field>
	void func(FieldField<Field, vector6>& f, const vector6& s1, const FieldField<Field, vector6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> func(const vector6& s1, const FieldField<Field, vector6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> func(const vector6& s1, const tmp<FieldField<Field, vector6>>& tf2);

	template <template<class> class Field>
	void func(FieldField<Field, vector6>& f, const FieldField<Field, vector6>& f1, const vector6& s);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> func(const FieldField<Field, vector6>& f1, const vector6& s);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> func(const tmp<FieldField<Field, vector6>>& tf1, const vector6& s);

	template <template<class> class Field>
	void divide(FieldField<Field, vector6>& f, const FieldField<Field, vector6>& f1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const FieldField<Field, vector6>& f1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const FieldField<Field, vector6>& f1
	                                           , const tmp<FieldField<Field, scalar>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const tmp<FieldField<Field, vector6>>& tf1
	                                           , const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const tmp<FieldField<Field, vector6>>& tf1
	                                           , const tmp<FieldField<Field, scalar>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector6>& f, const vector6& s1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const vector6& s1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const vector6& s1, const tmp<FieldField<Field, scalar>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector6>& f, const FieldField<Field, vector6>& f1, const scalar& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const FieldField<Field, vector6>& f1, const scalar& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator /(const tmp<FieldField<Field, vector6>>& tf1, const scalar& s2);

	template <template<class> class Field>
	void add(FieldField<Field, vector6>& f, const FieldField<Field, vector6>& f1, const FieldField<Field, vector6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator +(const FieldField<Field, vector6>& f1, const FieldField<Field, vector6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator +(const FieldField<Field, vector6>& f1
	                                           , const tmp<FieldField<Field, vector6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator +(const tmp<FieldField<Field, vector6>>& tf1
	                                           , const FieldField<Field, vector6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator +(const tmp<FieldField<Field, vector6>>& tf1
	                                           , const tmp<FieldField<Field, vector6>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, vector6>& f, const FieldField<Field, vector6>& f1
	              , const FieldField<Field, vector6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator -(const FieldField<Field, vector6>& f1, const FieldField<Field, vector6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator -(const FieldField<Field, vector6>& f1
	                                           , const tmp<FieldField<Field, vector6>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator -(const tmp<FieldField<Field, vector6>>& tf1
	                                           , const FieldField<Field, vector6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator -(const tmp<FieldField<Field, vector6>>& tf1
	                                           , const tmp<FieldField<Field, vector6>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, vector6>& f, const vector6& s1, const FieldField<Field, vector6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator +(const vector6& s1, const FieldField<Field, vector6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator +(const vector6& s1, const tmp<FieldField<Field, vector6>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, vector6>& f, const FieldField<Field, vector6>& f1, const vector6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator +(const FieldField<Field, vector6>& f1, const vector6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator +(const tmp<FieldField<Field, vector6>>& tf1, const vector6& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, vector6>& f, const vector6& s1, const FieldField<Field, vector6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator -(const vector6& s1, const FieldField<Field, vector6>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator -(const vector6& s1, const tmp<FieldField<Field, vector6>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, vector6>& f, const FieldField<Field, vector6>& f1, const vector6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator -(const FieldField<Field, vector6>& f1, const vector6& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector6>> operator -(const tmp<FieldField<Field, vector6>>& tf1, const vector6& s2);

	template <template<class> class Field>
	void cmptSum(FieldField<Field, scalar>& res, const FieldField<Field, vector8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> cmptSum(const FieldField<Field, vector8>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> cmptSum(const tmp<FieldField<Field, vector8>>& tf);

	template <template<class> class Field>
	void func(FieldField<Field, vector8>& f, const FieldField<Field, vector8>& f1, const FieldField<Field, vector8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> func(const FieldField<Field, vector8>& f1, const FieldField<Field, vector8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> func(const FieldField<Field, vector8>& f1, const tmp<FieldField<Field, vector8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> func(const tmp<FieldField<Field, vector8>>& tf1, const FieldField<Field, vector8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> func(const tmp<FieldField<Field, vector8>>& tf1
	                                     , const tmp<FieldField<Field, vector8>>& tf2);

	template <template<class> class Field>
	void func(FieldField<Field, vector8>& f, const vector8& s1, const FieldField<Field, vector8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> func(const vector8& s1, const FieldField<Field, vector8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> func(const vector8& s1, const tmp<FieldField<Field, vector8>>& tf2);

	template <template<class> class Field>
	void func(FieldField<Field, vector8>& f, const FieldField<Field, vector8>& f1, const vector8& s);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> func(const FieldField<Field, vector8>& f1, const vector8& s);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> func(const tmp<FieldField<Field, vector8>>& tf1, const vector8& s);

	template <template<class> class Field>
	void divide(FieldField<Field, vector8>& f, const FieldField<Field, vector8>& f1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const FieldField<Field, vector8>& f1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const FieldField<Field, vector8>& f1
	                                           , const tmp<FieldField<Field, scalar>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const tmp<FieldField<Field, vector8>>& tf1
	                                           , const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const tmp<FieldField<Field, vector8>>& tf1
	                                           , const tmp<FieldField<Field, scalar>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector8>& f, const vector8& s1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const vector8& s1, const FieldField<Field, scalar>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const vector8& s1, const tmp<FieldField<Field, scalar>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector8>& f, const FieldField<Field, vector8>& f1, const scalar& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const FieldField<Field, vector8>& f1, const scalar& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator /(const tmp<FieldField<Field, vector8>>& tf1, const scalar& s2);

	template <template<class> class Field>
	void add(FieldField<Field, vector8>& f, const FieldField<Field, vector8>& f1, const FieldField<Field, vector8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator +(const FieldField<Field, vector8>& f1, const FieldField<Field, vector8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator +(const FieldField<Field, vector8>& f1
	                                           , const tmp<FieldField<Field, vector8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator +(const tmp<FieldField<Field, vector8>>& tf1
	                                           , const FieldField<Field, vector8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator +(const tmp<FieldField<Field, vector8>>& tf1
	                                           , const tmp<FieldField<Field, vector8>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, vector8>& f, const FieldField<Field, vector8>& f1
	              , const FieldField<Field, vector8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator -(const FieldField<Field, vector8>& f1, const FieldField<Field, vector8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator -(const FieldField<Field, vector8>& f1
	                                           , const tmp<FieldField<Field, vector8>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator -(const tmp<FieldField<Field, vector8>>& tf1
	                                           , const FieldField<Field, vector8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator -(const tmp<FieldField<Field, vector8>>& tf1
	                                           , const tmp<FieldField<Field, vector8>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, vector8>& f, const vector8& s1, const FieldField<Field, vector8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator +(const vector8& s1, const FieldField<Field, vector8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator +(const vector8& s1, const tmp<FieldField<Field, vector8>>& tf2);

	template <template<class> class Field>
	void add(FieldField<Field, vector8>& f, const FieldField<Field, vector8>& f1, const vector8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator +(const FieldField<Field, vector8>& f1, const vector8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator +(const tmp<FieldField<Field, vector8>>& tf1, const vector8& s2);

	template <template<class> class Field>
	void subtract(FieldField<Field, vector8>& f, const vector8& s1, const FieldField<Field, vector8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator -(const vector8& s1, const FieldField<Field, vector8>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator -(const vector8& s1, const tmp<FieldField<Field, vector8>>& tf2);

	template <template<class> class Field>
	void subtract(FieldField<Field, vector8>& f, const FieldField<Field, vector8>& f1, const vector8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator -(const FieldField<Field, vector8>& f1, const vector8& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector8>> operator -(const tmp<FieldField<Field, vector8>>& tf1, const vector8& s2);
}

#undef VectorN_FieldFunctions

#include <undefFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <VectorNFieldFields.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !1
