#pragma once
#ifndef _VectorNFields_Header
#define _VectorNFields_Header

#include <VectorTensorNFieldsFwd.hxx>
#include <Field.hxx>

#define TEMPLATE
#include <FieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define VectorN_FieldFunctions(tensorType,diagTensorType,                    \
                               sphericalTensorType,vectorType,CmptType,      \
                               args)										 \
                                                                             \
UNARY_FUNCTION(CmptType, vectorType, cmptSum)                                \
                                                                             \
BINARY_FUNCTION(vectorType, vectorType, vectorType, cmptMultiply)            \
BINARY_TYPE_FUNCTION(vectorType, vectorType, vectorType, cmptMultiply)       \
                                                                             \
BINARY_FUNCTION(vectorType, vectorType, CmptType, scaleRow)                  \
BINARY_TYPE_FUNCTION(vectorType, vectorType, CmptType, scaleRow)             \
                                                                             \
BINARY_OPERATOR(vectorType, CmptType, vectorType, /, divide)                 \
BINARY_TYPE_OPERATOR(vectorType, CmptType, vectorType, /, divide)            \
                                                                             \
BINARY_OPERATOR(vectorType, vectorType, vectorType, +, add)                  \
BINARY_OPERATOR(vectorType, vectorType, vectorType, -, subtract)             \
                                                                             \
BINARY_TYPE_OPERATOR(vectorType, vectorType, vectorType, +, add)             \
BINARY_TYPE_OPERATOR(vectorType, vectorType, vectorType, -, subtract)        

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	void cmptSum(Field<scalar>& res, const UList<vector2>& f);  
	tmp<Field<scalar>> cmptSum(const UList<vector2>& f);
	tmp<Field<scalar>> cmptSum(const tmp<Field<vector2>>& tf); 
	void cmptMultiply ( Field<vector2>& f, const UList<vector2>& f1, const UList<vector2>& f2 ); 
	tmp<Field<vector2>> cmptMultiply ( const UList<vector2>& f1, const UList<vector2>& f2 ); 
	tmp<Field<vector2>> cmptMultiply ( const UList<vector2>& f1, const tmp<Field<vector2>>& tf2 ); 
	tmp<Field<vector2>> cmptMultiply ( const tmp<Field<vector2>>& tf1, const UList<vector2>& f2 ); 
	tmp<Field<vector2>> cmptMultiply ( const tmp<Field<vector2>>& tf1, const tmp<Field<vector2>>& tf2 ); 
	void cmptMultiply ( Field<vector2>& f, const vector2& s1, const UList<vector2>& f2 ); 
	tmp<Field<vector2>> cmptMultiply ( const vector2& s1, const UList<vector2>& f2 );
	tmp<Field<vector2>> cmptMultiply ( const vector2& s1, const tmp<Field<vector2>>& tf2 );  
	void cmptMultiply ( Field<vector2>& f, const UList<vector2>& f1, const vector2& s2 ); 
	tmp<Field<vector2>> cmptMultiply ( const UList<vector2>& f1, const vector2& s2 );  
	tmp<Field<vector2>> cmptMultiply ( const tmp<Field<vector2>>& tf1, const vector2& s2 ); 
	void scaleRow ( Field<vector2>& f, const UList<vector2>& f1, const UList<scalar>& f2 ); 
	tmp<Field<vector2>> scaleRow ( const UList<vector2>& f1, const UList<scalar>& f2 );  
	tmp<Field<vector2>> scaleRow ( const UList<vector2>& f1, const tmp<Field<scalar>>& tf2 );
	tmp<Field<vector2>> scaleRow ( const tmp<Field<vector2>>& tf1, const UList<scalar>& f2 );
	tmp<Field<vector2>> scaleRow ( const tmp<Field<vector2>>& tf1, const tmp<Field<scalar>>& tf2 );
	void scaleRow ( Field<vector2>& f, const vector2& s1, const UList<scalar>& f2 );  
	tmp<Field<vector2>> scaleRow ( const vector2& s1, const UList<scalar>& f2 ); 
	tmp<Field<vector2>> scaleRow ( const vector2& s1, const tmp<Field<scalar>>& tf2 ); 
	void scaleRow ( Field<vector2>& f, const UList<vector2>& f1, const scalar& s2 ); 
	tmp<Field<vector2>> scaleRow ( const UList<vector2>& f1, const scalar& s2 ); 
	tmp<Field<vector2>> scaleRow ( const tmp<Field<vector2>>& tf1, const scalar& s2 );  
	void divide ( Field<vector2>& f, const UList<scalar>& f1, const UList<vector2>& f2 ); 
	tmp<Field<vector2>> operator / ( const UList<scalar>& f1, const UList<vector2>& f2 );  
	tmp<Field<vector2>> operator / ( const UList<scalar>& f1, const tmp<Field<vector2>>& tf2 );  
	tmp<Field<vector2>> operator / ( const tmp<Field<scalar>>& tf1, const UList<vector2>& f2 );  
	tmp<Field<vector2>> operator / ( const tmp<Field<scalar>>& tf1, const tmp<Field<vector2>>& tf2 );
	void divide ( Field<vector2>& f, const scalar& s1, const UList<vector2>& f2 );
	tmp<Field<vector2>> operator / ( const scalar& s1, const UList<vector2>& f2 ); 
	tmp<Field<vector2>> operator / ( const scalar& s1, const tmp<Field<vector2>>& tf2 );  
	void divide ( Field<vector2>& f, const UList<scalar>& f1, const vector2& s2 ); 
	tmp<Field<vector2>> operator / ( const UList<scalar>& f1, const vector2& s2 );  
	tmp<Field<vector2>> operator / ( const tmp<Field<scalar>>& tf1, const vector2& s2 ); 
	void add ( Field<vector2>& f, const UList<vector2>& f1, const UList<vector2>& f2 ); 
	tmp<Field<vector2>> operator + ( const UList<vector2>& f1, const UList<vector2>& f2 );
	tmp<Field<vector2>> operator + ( const UList<vector2>& f1, const tmp<Field<vector2>>& tf2 );
	tmp<Field<vector2>> operator + ( const tmp<Field<vector2>>& tf1, const UList<vector2>& f2 );
	tmp<Field<vector2>> operator + ( const tmp<Field<vector2>>& tf1, const tmp<Field<vector2>>& tf2 ); 
	void subtract ( Field<vector2>& f, const UList<vector2>& f1, const UList<vector2>& f2 ); 
	tmp<Field<vector2>> operator - ( const UList<vector2>& f1, const UList<vector2>& f2 );  
	tmp<Field<vector2>> operator - ( const UList<vector2>& f1, const tmp<Field<vector2>>& tf2 ); 
	tmp<Field<vector2>> operator - ( const tmp<Field<vector2>>& tf1, const UList<vector2>& f2 );  
	tmp<Field<vector2>> operator - ( const tmp<Field<vector2>>& tf1, const tmp<Field<vector2>>& tf2 );
	void add ( Field<vector2>& f, const vector2& s1, const UList<vector2>& f2 ); 
	tmp<Field<vector2>> operator + ( const vector2& s1, const UList<vector2>& f2 ); 
	tmp<Field<vector2>> operator + ( const vector2& s1, const tmp<Field<vector2>>& tf2 ); 
	void add ( Field<vector2>& f, const UList<vector2>& f1, const vector2& s2 ); 
	tmp<Field<vector2>> operator + ( const UList<vector2>& f1, const vector2& s2 ); 
	tmp<Field<vector2>> operator + ( const tmp<Field<vector2>>& tf1, const vector2& s2 );
	void subtract ( Field<vector2>& f, const vector2& s1, const UList<vector2>& f2 ); 
	tmp<Field<vector2>> operator - ( const vector2& s1, const UList<vector2>& f2 ); 
	tmp<Field<vector2>> operator - ( const vector2& s1, const tmp<Field<vector2>>& tf2 ); 
	void subtract ( Field<vector2>& f, const UList<vector2>& f1, const vector2& s2 );  
	tmp<Field<vector2>> operator - ( const UList<vector2>& f1, const vector2& s2 );  
	tmp<Field<vector2>> operator - ( const tmp<Field<vector2>>& tf1, const vector2& s2 ); 
	void cmptSum(Field<scalar>& res, const UList<vector3>& f);  
	tmp<Field<scalar>> cmptSum(const UList<vector3>& f); 
	tmp<Field<scalar>> cmptSum(const tmp<Field<vector3>>& tf);  
	void cmptMultiply ( Field<vector3>& f, const UList<vector3>& f1, const UList<vector3>& f2 ); 
	tmp<Field<vector3>> cmptMultiply ( const UList<vector3>& f1, const UList<vector3>& f2 ); 
	tmp<Field<vector3>> cmptMultiply ( const UList<vector3>& f1, const tmp<Field<vector3>>& tf2 );  
	tmp<Field<vector3>> cmptMultiply ( const tmp<Field<vector3>>& tf1, const UList<vector3>& f2 );
	tmp<Field<vector3>> cmptMultiply ( const tmp<Field<vector3>>& tf1, const tmp<Field<vector3>>& tf2 ); 
	void cmptMultiply ( Field<vector3>& f, const vector3& s1, const UList<vector3>& f2 ); 
	tmp<Field<vector3>> cmptMultiply ( const vector3& s1, const UList<vector3>& f2 ); 
	tmp<Field<vector3>> cmptMultiply ( const vector3& s1, const tmp<Field<vector3>>& tf2 );
	void cmptMultiply ( Field<vector3>& f, const UList<vector3>& f1, const vector3& s2 );
	tmp<Field<vector3>> cmptMultiply ( const UList<vector3>& f1, const vector3& s2 );  
	tmp<Field<vector3>> cmptMultiply ( const tmp<Field<vector3>>& tf1, const vector3& s2 );
	void scaleRow ( Field<vector3>& f, const UList<vector3>& f1, const UList<scalar>& f2 ); 
	tmp<Field<vector3>> scaleRow ( const UList<vector3>& f1, const UList<scalar>& f2 ); 
	tmp<Field<vector3>> scaleRow ( const UList<vector3>& f1, const tmp<Field<scalar>>& tf2 );
	tmp<Field<vector3>> scaleRow ( const tmp<Field<vector3>>& tf1, const UList<scalar>& f2 );  
	tmp<Field<vector3>> scaleRow ( const tmp<Field<vector3>>& tf1, const tmp<Field<scalar>>& tf2 );
	void scaleRow ( Field<vector3>& f, const vector3& s1, const UList<scalar>& f2 ); 
	tmp<Field<vector3>> scaleRow ( const vector3& s1, const UList<scalar>& f2 ); 
	tmp<Field<vector3>> scaleRow ( const vector3& s1, const tmp<Field<scalar>>& tf2 );  
	void scaleRow ( Field<vector3>& f, const UList<vector3>& f1, const scalar& s2 ); 
	tmp<Field<vector3>> scaleRow ( const UList<vector3>& f1, const scalar& s2 );  
	tmp<Field<vector3>> scaleRow ( const tmp<Field<vector3>>& tf1, const scalar& s2 ); 
	void divide ( Field<vector3>& f, const UList<scalar>& f1, const UList<vector3>& f2 ); 
	tmp<Field<vector3>> operator / ( const UList<scalar>& f1, const UList<vector3>& f2 ); 
	tmp<Field<vector3>> operator / ( const UList<scalar>& f1, const tmp<Field<vector3>>& tf2 );
	tmp<Field<vector3>> operator / ( const tmp<Field<scalar>>& tf1, const UList<vector3>& f2 );  
	tmp<Field<vector3>> operator / ( const tmp<Field<scalar>>& tf1, const tmp<Field<vector3>>& tf2 ); 
	void divide ( Field<vector3>& f, const scalar& s1, const UList<vector3>& f2 );  
	tmp<Field<vector3>> operator / ( const scalar& s1, const UList<vector3>& f2 ); 
	tmp<Field<vector3>> operator / ( const scalar& s1, const tmp<Field<vector3>>& tf2 );
	void divide ( Field<vector3>& f, const UList<scalar>& f1, const vector3& s2 ); 
	tmp<Field<vector3>> operator / ( const UList<scalar>& f1, const vector3& s2 );  
	tmp<Field<vector3>> operator / ( const tmp<Field<scalar>>& tf1, const vector3& s2 );
	void add ( Field<vector3>& f, const UList<vector3>& f1, const UList<vector3>& f2 ); 
	tmp<Field<vector3>> operator + ( const UList<vector3>& f1, const UList<vector3>& f2 ); 
	tmp<Field<vector3>> operator + ( const UList<vector3>& f1, const tmp<Field<vector3>>& tf2 ); 
	tmp<Field<vector3>> operator + ( const tmp<Field<vector3>>& tf1, const UList<vector3>& f2 ); 
	tmp<Field<vector3>> operator + ( const tmp<Field<vector3>>& tf1, const tmp<Field<vector3>>& tf2 );
	void subtract ( Field<vector3>& f, const UList<vector3>& f1, const UList<vector3>& f2 ); 
	tmp<Field<vector3>> operator - ( const UList<vector3>& f1, const UList<vector3>& f2 );
	tmp<Field<vector3>> operator - ( const UList<vector3>& f1, const tmp<Field<vector3>>& tf2 ); 
	tmp<Field<vector3>> operator - ( const tmp<Field<vector3>>& tf1, const UList<vector3>& f2 ); 
	tmp<Field<vector3>> operator - ( const tmp<Field<vector3>>& tf1, const tmp<Field<vector3>>& tf2 );
	void add ( Field<vector3>& f, const vector3& s1, const UList<vector3>& f2 ); 
	tmp<Field<vector3>> operator + ( const vector3& s1, const UList<vector3>& f2 ); 
	tmp<Field<vector3>> operator + ( const vector3& s1, const tmp<Field<vector3>>& tf2 ); 
	void add ( Field<vector3>& f, const UList<vector3>& f1, const vector3& s2 ); 
	tmp<Field<vector3>> operator + ( const UList<vector3>& f1, const vector3& s2 );
	tmp<Field<vector3>> operator + ( const tmp<Field<vector3>>& tf1, const vector3& s2 ); 
	void subtract ( Field<vector3>& f, const vector3& s1, const UList<vector3>& f2 );  
	tmp<Field<vector3>> operator - ( const vector3& s1, const UList<vector3>& f2 ); 
	tmp<Field<vector3>> operator - ( const vector3& s1, const tmp<Field<vector3>>& tf2 );
	void subtract ( Field<vector3>& f, const UList<vector3>& f1, const vector3& s2 ); 
	tmp<Field<vector3>> operator - ( const UList<vector3>& f1, const vector3& s2 ); 
	tmp<Field<vector3>> operator - ( const tmp<Field<vector3>>& tf1, const vector3& s2 ); 
	void cmptSum(Field<scalar>& res, const UList<vector4>& f);
	tmp<Field<scalar>> cmptSum(const UList<vector4>& f);  
	tmp<Field<scalar>> cmptSum(const tmp<Field<vector4>>& tf);  
	void cmptMultiply ( Field<vector4>& f, const UList<vector4>& f1, const UList<vector4>& f2 ); 
	tmp<Field<vector4>> cmptMultiply ( const UList<vector4>& f1, const UList<vector4>& f2 );  
	tmp<Field<vector4>> cmptMultiply ( const UList<vector4>& f1, const tmp<Field<vector4>>& tf2 ); 
	tmp<Field<vector4>> cmptMultiply ( const tmp<Field<vector4>>& tf1, const UList<vector4>& f2 ); 
	tmp<Field<vector4>> cmptMultiply ( const tmp<Field<vector4>>& tf1, const tmp<Field<vector4>>& tf2 ); 
	void cmptMultiply ( Field<vector4>& f, const vector4& s1, const UList<vector4>& f2 );  
	tmp<Field<vector4>> cmptMultiply ( const vector4& s1, const UList<vector4>& f2 ); 
	tmp<Field<vector4>> cmptMultiply ( const vector4& s1, const tmp<Field<vector4>>& tf2 );  
	void cmptMultiply ( Field<vector4>& f, const UList<vector4>& f1, const vector4& s2 ); 
	tmp<Field<vector4>> cmptMultiply ( const UList<vector4>& f1, const vector4& s2 );  
	tmp<Field<vector4>> cmptMultiply ( const tmp<Field<vector4>>& tf1, const vector4& s2 );  
	void scaleRow ( Field<vector4>& f, const UList<vector4>& f1, const UList<scalar>& f2 );  
	tmp<Field<vector4>> scaleRow ( const UList<vector4>& f1, const UList<scalar>& f2 ); 
	tmp<Field<vector4>> scaleRow ( const UList<vector4>& f1, const tmp<Field<scalar>>& tf2 );
	tmp<Field<vector4>> scaleRow ( const tmp<Field<vector4>>& tf1, const UList<scalar>& f2 ); 
	tmp<Field<vector4>> scaleRow ( const tmp<Field<vector4>>& tf1, const tmp<Field<scalar>>& tf2 ); 
	void scaleRow ( Field<vector4>& f, const vector4& s1, const UList<scalar>& f2 ); 
	tmp<Field<vector4>> scaleRow ( const vector4& s1, const UList<scalar>& f2 );
	tmp<Field<vector4>> scaleRow ( const vector4& s1, const tmp<Field<scalar>>& tf2 );  
	void scaleRow ( Field<vector4>& f, const UList<vector4>& f1, const scalar& s2 ); 
	tmp<Field<vector4>> scaleRow ( const UList<vector4>& f1, const scalar& s2 ); 
	tmp<Field<vector4>> scaleRow ( const tmp<Field<vector4>>& tf1, const scalar& s2 );
	void divide ( Field<vector4>& f, const UList<scalar>& f1, const UList<vector4>& f2 ); 
	tmp<Field<vector4>> operator / ( const UList<scalar>& f1, const UList<vector4>& f2 );
	tmp<Field<vector4>> operator / ( const UList<scalar>& f1, const tmp<Field<vector4>>& tf2 );  
	tmp<Field<vector4>> operator / ( const tmp<Field<scalar>>& tf1, const UList<vector4>& f2 ); 
	tmp<Field<vector4>> operator / ( const tmp<Field<scalar>>& tf1, const tmp<Field<vector4>>& tf2 );  
	void divide ( Field<vector4>& f, const scalar& s1, const UList<vector4>& f2 );  
	tmp<Field<vector4>> operator / ( const scalar& s1, const UList<vector4>& f2 ); 
	tmp<Field<vector4>> operator / ( const scalar& s1, const tmp<Field<vector4>>& tf2 );  
	void divide ( Field<vector4>& f, const UList<scalar>& f1, const vector4& s2 );  
	tmp<Field<vector4>> operator / ( const UList<scalar>& f1, const vector4& s2 );  
	tmp<Field<vector4>> operator / ( const tmp<Field<scalar>>& tf1, const vector4& s2 ); 
	void add ( Field<vector4>& f, const UList<vector4>& f1, const UList<vector4>& f2 );  
	tmp<Field<vector4>> operator + ( const UList<vector4>& f1, const UList<vector4>& f2 );  
	tmp<Field<vector4>> operator + ( const UList<vector4>& f1, const tmp<Field<vector4>>& tf2 ); 
	tmp<Field<vector4>> operator + ( const tmp<Field<vector4>>& tf1, const UList<vector4>& f2 );  
	tmp<Field<vector4>> operator + ( const tmp<Field<vector4>>& tf1, const tmp<Field<vector4>>& tf2 );
	void subtract ( Field<vector4>& f, const UList<vector4>& f1, const UList<vector4>& f2 ); 
	tmp<Field<vector4>> operator - ( const UList<vector4>& f1, const UList<vector4>& f2 ); 
	tmp<Field<vector4>> operator - ( const UList<vector4>& f1, const tmp<Field<vector4>>& tf2 ); 
	tmp<Field<vector4>> operator - ( const tmp<Field<vector4>>& tf1, const UList<vector4>& f2 ); 
	tmp<Field<vector4>> operator - ( const tmp<Field<vector4>>& tf1, const tmp<Field<vector4>>& tf2 );  
	void add ( Field<vector4>& f, const vector4& s1, const UList<vector4>& f2 ); 
	tmp<Field<vector4>> operator + ( const vector4& s1, const UList<vector4>& f2 ); 
	tmp<Field<vector4>> operator + ( const vector4& s1, const tmp<Field<vector4>>& tf2 );  
	void add ( Field<vector4>& f, const UList<vector4>& f1, const vector4& s2 );  
	tmp<Field<vector4>> operator + ( const UList<vector4>& f1, const vector4& s2 ); 
	tmp<Field<vector4>> operator + ( const tmp<Field<vector4>>& tf1, const vector4& s2 ); 
	void subtract ( Field<vector4>& f, const vector4& s1, const UList<vector4>& f2 );  
	tmp<Field<vector4>> operator - ( const vector4& s1, const UList<vector4>& f2 );  
	tmp<Field<vector4>> operator - ( const vector4& s1, const tmp<Field<vector4>>& tf2 );
	void subtract ( Field<vector4>& f, const UList<vector4>& f1, const vector4& s2 );  
	tmp<Field<vector4>> operator - ( const UList<vector4>& f1, const vector4& s2 ); 
	tmp<Field<vector4>> operator - ( const tmp<Field<vector4>>& tf1, const vector4& s2 );
	void cmptSum(Field<scalar>& res, const UList<vector6>& f);  
	tmp<Field<scalar>> cmptSum(const UList<vector6>& f); 
	tmp<Field<scalar>> cmptSum(const tmp<Field<vector6>>& tf); 
	void cmptMultiply ( Field<vector6>& f, const UList<vector6>& f1, const UList<vector6>& f2 ); 
	tmp<Field<vector6>> cmptMultiply ( const UList<vector6>& f1, const UList<vector6>& f2 ); 
	tmp<Field<vector6>> cmptMultiply ( const UList<vector6>& f1, const tmp<Field<vector6>>& tf2 );
	tmp<Field<vector6>> cmptMultiply ( const tmp<Field<vector6>>& tf1, const UList<vector6>& f2 ); 
	tmp<Field<vector6>> cmptMultiply ( const tmp<Field<vector6>>& tf1, const tmp<Field<vector6>>& tf2 ); 
	void cmptMultiply ( Field<vector6>& f, const vector6& s1, const UList<vector6>& f2 ); 
	tmp<Field<vector6>> cmptMultiply ( const vector6& s1, const UList<vector6>& f2 ); 
	tmp<Field<vector6>> cmptMultiply ( const vector6& s1, const tmp<Field<vector6>>& tf2 );
	void cmptMultiply ( Field<vector6>& f, const UList<vector6>& f1, const vector6& s2 ); 
	tmp<Field<vector6>> cmptMultiply ( const UList<vector6>& f1, const vector6& s2 );  
	tmp<Field<vector6>> cmptMultiply ( const tmp<Field<vector6>>& tf1, const vector6& s2 );
	void scaleRow ( Field<vector6>& f, const UList<vector6>& f1, const UList<scalar>& f2 ); 
	tmp<Field<vector6>> scaleRow ( const UList<vector6>& f1, const UList<scalar>& f2 );  
	tmp<Field<vector6>> scaleRow ( const UList<vector6>& f1, const tmp<Field<scalar>>& tf2 ); 
	tmp<Field<vector6>> scaleRow ( const tmp<Field<vector6>>& tf1, const UList<scalar>& f2 ); 
	tmp<Field<vector6>> scaleRow ( const tmp<Field<vector6>>& tf1, const tmp<Field<scalar>>& tf2 );  
	void scaleRow ( Field<vector6>& f, const vector6& s1, const UList<scalar>& f2 );  
	tmp<Field<vector6>> scaleRow ( const vector6& s1, const UList<scalar>& f2 );  
	tmp<Field<vector6>> scaleRow ( const vector6& s1, const tmp<Field<scalar>>& tf2 );
	void scaleRow ( Field<vector6>& f, const UList<vector6>& f1, const scalar& s2 ); 
	tmp<Field<vector6>> scaleRow ( const UList<vector6>& f1, const scalar& s2 ); 
	tmp<Field<vector6>> scaleRow ( const tmp<Field<vector6>>& tf1, const scalar& s2 ); 
	void divide ( Field<vector6>& f, const UList<scalar>& f1, const UList<vector6>& f2 );  
	tmp<Field<vector6>> operator / ( const UList<scalar>& f1, const UList<vector6>& f2 );
	tmp<Field<vector6>> operator / ( const UList<scalar>& f1, const tmp<Field<vector6>>& tf2 );
	tmp<Field<vector6>> operator / ( const tmp<Field<scalar>>& tf1, const UList<vector6>& f2 ); 
	tmp<Field<vector6>> operator / ( const tmp<Field<scalar>>& tf1, const tmp<Field<vector6>>& tf2 );
	void divide ( Field<vector6>& f, const scalar& s1, const UList<vector6>& f2 ); 
	tmp<Field<vector6>> operator / ( const scalar& s1, const UList<vector6>& f2 ); 
	tmp<Field<vector6>> operator / ( const scalar& s1, const tmp<Field<vector6>>& tf2 ); 
	void divide ( Field<vector6>& f, const UList<scalar>& f1, const vector6& s2 ); 
	tmp<Field<vector6>> operator / ( const UList<scalar>& f1, const vector6& s2 ); 
	tmp<Field<vector6>> operator / ( const tmp<Field<scalar>>& tf1, const vector6& s2 ); 
	void add ( Field<vector6>& f, const UList<vector6>& f1, const UList<vector6>& f2 );
	tmp<Field<vector6>> operator + ( const UList<vector6>& f1, const UList<vector6>& f2 ); 
	tmp<Field<vector6>> operator + ( const UList<vector6>& f1, const tmp<Field<vector6>>& tf2 ); 
	tmp<Field<vector6>> operator + ( const tmp<Field<vector6>>& tf1, const UList<vector6>& f2 );  
	tmp<Field<vector6>> operator + ( const tmp<Field<vector6>>& tf1, const tmp<Field<vector6>>& tf2 ); 
	void subtract ( Field<vector6>& f, const UList<vector6>& f1, const UList<vector6>& f2 );
	tmp<Field<vector6>> operator - ( const UList<vector6>& f1, const UList<vector6>& f2 );  
	tmp<Field<vector6>> operator - ( const UList<vector6>& f1, const tmp<Field<vector6>>& tf2 ); 
	tmp<Field<vector6>> operator - ( const tmp<Field<vector6>>& tf1, const UList<vector6>& f2 ); 
	tmp<Field<vector6>> operator - ( const tmp<Field<vector6>>& tf1, const tmp<Field<vector6>>& tf2 );
	void add ( Field<vector6>& f, const vector6& s1, const UList<vector6>& f2 );
	tmp<Field<vector6>> operator + ( const vector6& s1, const UList<vector6>& f2 );
	tmp<Field<vector6>> operator + ( const vector6& s1, const tmp<Field<vector6>>& tf2 );
	void add ( Field<vector6>& f, const UList<vector6>& f1, const vector6& s2 ); 
	tmp<Field<vector6>> operator + ( const UList<vector6>& f1, const vector6& s2 );  
	tmp<Field<vector6>> operator + ( const tmp<Field<vector6>>& tf1, const vector6& s2 );
	void subtract ( Field<vector6>& f, const vector6& s1, const UList<vector6>& f2 );  
	tmp<Field<vector6>> operator - ( const vector6& s1, const UList<vector6>& f2 ); 
	tmp<Field<vector6>> operator - ( const vector6& s1, const tmp<Field<vector6>>& tf2 );
	void subtract ( Field<vector6>& f, const UList<vector6>& f1, const vector6& s2 ); 
	tmp<Field<vector6>> operator - ( const UList<vector6>& f1, const vector6& s2 ); 
	tmp<Field<vector6>> operator - ( const tmp<Field<vector6>>& tf1, const vector6& s2 ); 
	void cmptSum(Field<scalar>& res, const UList<vector8>& f); 
	tmp<Field<scalar>> cmptSum(const UList<vector8>& f);
	tmp<Field<scalar>> cmptSum(const tmp<Field<vector8>>& tf); 
	void cmptMultiply ( Field<vector8>& f, const UList<vector8>& f1, const UList<vector8>& f2 ); 
	tmp<Field<vector8>> cmptMultiply ( const UList<vector8>& f1, const UList<vector8>& f2 );
	tmp<Field<vector8>> cmptMultiply ( const UList<vector8>& f1, const tmp<Field<vector8>>& tf2 );
	tmp<Field<vector8>> cmptMultiply ( const tmp<Field<vector8>>& tf1, const UList<vector8>& f2 ); 
	tmp<Field<vector8>> cmptMultiply ( const tmp<Field<vector8>>& tf1, const tmp<Field<vector8>>& tf2 );
	void cmptMultiply ( Field<vector8>& f, const vector8& s1, const UList<vector8>& f2 ); 
	tmp<Field<vector8>> cmptMultiply ( const vector8& s1, const UList<vector8>& f2 ); 
	tmp<Field<vector8>> cmptMultiply ( const vector8& s1, const tmp<Field<vector8>>& tf2 );
	void cmptMultiply ( Field<vector8>& f, const UList<vector8>& f1, const vector8& s2 );  
	tmp<Field<vector8>> cmptMultiply ( const UList<vector8>& f1, const vector8& s2 ); 
	tmp<Field<vector8>> cmptMultiply ( const tmp<Field<vector8>>& tf1, const vector8& s2 ); 
	void scaleRow ( Field<vector8>& f, const UList<vector8>& f1, const UList<scalar>& f2 );
	tmp<Field<vector8>> scaleRow ( const UList<vector8>& f1, const UList<scalar>& f2 ); 
	tmp<Field<vector8>> scaleRow ( const UList<vector8>& f1, const tmp<Field<scalar>>& tf2 ); 
	tmp<Field<vector8>> scaleRow ( const tmp<Field<vector8>>& tf1, const UList<scalar>& f2 ); 
	tmp<Field<vector8>> scaleRow ( const tmp<Field<vector8>>& tf1, const tmp<Field<scalar>>& tf2 ); 
	void scaleRow ( Field<vector8>& f, const vector8& s1, const UList<scalar>& f2 );  
	tmp<Field<vector8>> scaleRow ( const vector8& s1, const UList<scalar>& f2 ); 
	tmp<Field<vector8>> scaleRow ( const vector8& s1, const tmp<Field<scalar>>& tf2 );
	void scaleRow ( Field<vector8>& f, const UList<vector8>& f1, const scalar& s2 );  
	tmp<Field<vector8>> scaleRow ( const UList<vector8>& f1, const scalar& s2 );  
	tmp<Field<vector8>> scaleRow ( const tmp<Field<vector8>>& tf1, const scalar& s2 );
	void divide ( Field<vector8>& f, const UList<scalar>& f1, const UList<vector8>& f2 );
	tmp<Field<vector8>> operator / ( const UList<scalar>& f1, const UList<vector8>& f2 ); 
	tmp<Field<vector8>> operator / ( const UList<scalar>& f1, const tmp<Field<vector8>>& tf2 ); 
	tmp<Field<vector8>> operator / ( const tmp<Field<scalar>>& tf1, const UList<vector8>& f2 ); 
	tmp<Field<vector8>> operator / ( const tmp<Field<scalar>>& tf1, const tmp<Field<vector8>>& tf2 );
	void divide ( Field<vector8>& f, const scalar& s1, const UList<vector8>& f2 );  
	tmp<Field<vector8>> operator / ( const scalar& s1, const UList<vector8>& f2 ); 
	tmp<Field<vector8>> operator / ( const scalar& s1, const tmp<Field<vector8>>& tf2 ); 
	void divide ( Field<vector8>& f, const UList<scalar>& f1, const vector8& s2 ); 
	tmp<Field<vector8>> operator / ( const UList<scalar>& f1, const vector8& s2 );  
	tmp<Field<vector8>> operator / ( const tmp<Field<scalar>>& tf1, const vector8& s2 );
	void add ( Field<vector8>& f, const UList<vector8>& f1, const UList<vector8>& f2 ); 
	tmp<Field<vector8>> operator + ( const UList<vector8>& f1, const UList<vector8>& f2 );
	tmp<Field<vector8>> operator + ( const UList<vector8>& f1, const tmp<Field<vector8>>& tf2 ); 
	tmp<Field<vector8>> operator + ( const tmp<Field<vector8>>& tf1, const UList<vector8>& f2 ); 
	tmp<Field<vector8>> operator + ( const tmp<Field<vector8>>& tf1, const tmp<Field<vector8>>& tf2 );
	void subtract ( Field<vector8>& f, const UList<vector8>& f1, const UList<vector8>& f2 );  
	tmp<Field<vector8>> operator - ( const UList<vector8>& f1, const UList<vector8>& f2 ); 
	tmp<Field<vector8>> operator - ( const UList<vector8>& f1, const tmp<Field<vector8>>& tf2 );
	tmp<Field<vector8>> operator - ( const tmp<Field<vector8>>& tf1, const UList<vector8>& f2 );
	tmp<Field<vector8>> operator - ( const tmp<Field<vector8>>& tf1, const tmp<Field<vector8>>& tf2 );  
	void add ( Field<vector8>& f, const vector8& s1, const UList<vector8>& f2 ); 
	tmp<Field<vector8>> operator + ( const vector8& s1, const UList<vector8>& f2 ); 
	tmp<Field<vector8>> operator + ( const vector8& s1, const tmp<Field<vector8>>& tf2 ); 
	void add ( Field<vector8>& f, const UList<vector8>& f1, const vector8& s2 ); 
	tmp<Field<vector8>> operator + ( const UList<vector8>& f1, const vector8& s2 ); 
	tmp<Field<vector8>> operator + ( const tmp<Field<vector8>>& tf1, const vector8& s2 ); 
	void subtract ( Field<vector8>& f, const vector8& s1, const UList<vector8>& f2 );
	tmp<Field<vector8>> operator - ( const vector8& s1, const UList<vector8>& f2 );  
	tmp<Field<vector8>> operator - ( const vector8& s1, const tmp<Field<vector8>>& tf2 ); 
	void subtract ( Field<vector8>& f, const UList<vector8>& f1, const vector8& s2 ); 
	tmp<Field<vector8>> operator - ( const UList<vector8>& f1, const vector8& s2 );  
	tmp<Field<vector8>> operator - ( const tmp<Field<vector8>>& tf1, const vector8& s2 );
}

#undef VectorN_FieldFunctions

#include <undefFieldFunctionsM.hxx>

#endif // !_VectorNFields_Header
