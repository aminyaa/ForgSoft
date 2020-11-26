#pragma once
#ifndef _SphericalTensorNFields_Header
#define _SphericalTensorNFields_Header

#include <VectorTensorNFieldsFwd.hxx>
#include <Field.hxx>

#define TEMPLATE
#include <FieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define SphericalTensorN_FieldFunctions(tensorType, diagTensorType,                 \
    sphericalTensorType, vectorType, CmptType, args)                             \
                                                                                    \
UNARY_FUNCTION(sphericalTensorType, sphericalTensorType, inv)                       \
UNARY_FUNCTION(sphericalTensorType, sphericalTensorType, diag)                      \
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
	void inv(Field<sphericalTensor2>& res, const UList<sphericalTensor2>& f);
	tmp<Field<sphericalTensor2>> inv(const UList<sphericalTensor2>& f); 
	tmp<Field<sphericalTensor2>> inv(const tmp<Field<sphericalTensor2>>& tf);  
	void diag(Field<sphericalTensor2>& res, const UList<sphericalTensor2>& f); 
	tmp<Field<sphericalTensor2>> diag(const UList<sphericalTensor2>& f); 
	tmp<Field<sphericalTensor2>> diag(const tmp<Field<sphericalTensor2>>& tf);  
	void divide ( Field<sphericalTensor2>& f, const UList<scalar>& f1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<sphericalTensor2>> operator / ( const UList<scalar>& f1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<sphericalTensor2>> operator / ( const UList<scalar>& f1, const tmp<Field<sphericalTensor2>>& tf2 );
	tmp<Field<sphericalTensor2>> operator / ( const tmp<Field<scalar>>& tf1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<sphericalTensor2>> operator / ( const tmp<Field<scalar>>& tf1, const tmp<Field<sphericalTensor2>>& tf2 ); 
	void divide ( Field<sphericalTensor2>& f, const scalar& s1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<sphericalTensor2>> operator / ( const scalar& s1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<sphericalTensor2>> operator / ( const scalar& s1, const tmp<Field<sphericalTensor2>>& tf2 );  
	void divide ( Field<sphericalTensor2>& f, const UList<scalar>& f1, const sphericalTensor2& s2 ); 
	tmp<Field<sphericalTensor2>> operator / ( const UList<scalar>& f1, const sphericalTensor2& s2 ); 
	tmp<Field<sphericalTensor2>> operator / ( const tmp<Field<scalar>>& tf1, const sphericalTensor2& s2 );  
	void divide ( Field<vector2>& f, const UList<vector2>& f1, const UList<sphericalTensor2>& f2 );  
	tmp<Field<vector2>> operator / ( const UList<vector2>& f1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<vector2>> operator / ( const UList<vector2>& f1, const tmp<Field<sphericalTensor2>>& tf2 ); 
	tmp<Field<vector2>> operator / ( const tmp<Field<vector2>>& tf1, const UList<sphericalTensor2>& f2 );  
	tmp<Field<vector2>> operator / ( const tmp<Field<vector2>>& tf1, const tmp<Field<sphericalTensor2>>& tf2 ); 
	void divide ( Field<vector2>& f, const vector2& s1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<vector2>> operator / ( const vector2& s1, const UList<sphericalTensor2>& f2 );  
	tmp<Field<vector2>> operator / ( const vector2& s1, const tmp<Field<sphericalTensor2>>& tf2 ); 
	void divide ( Field<vector2>& f, const UList<vector2>& f1, const sphericalTensor2& s2 ); 
	tmp<Field<vector2>> operator / ( const UList<vector2>& f1, const sphericalTensor2& s2 );  
	tmp<Field<vector2>> operator / ( const tmp<Field<vector2>>& tf1, const sphericalTensor2& s2 );
	void divide ( Field<sphericalTensor2>& f, const UList<sphericalTensor2>& f1, const UList<sphericalTensor2>& f2 );
	tmp<Field<sphericalTensor2>> operator / ( const UList<sphericalTensor2>& f1, const UList<sphericalTensor2>& f2 );  
	tmp<Field<sphericalTensor2>> operator / ( const UList<sphericalTensor2>& f1, const tmp<Field<sphericalTensor2>>& tf2 ); 
	tmp<Field<sphericalTensor2>> operator / ( const tmp<Field<sphericalTensor2>>& tf1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<sphericalTensor2>> operator / ( const tmp<Field<sphericalTensor2>>& tf1, const tmp<Field<sphericalTensor2>>& tf2 ); 
	void divide ( Field<sphericalTensor2>& f, const sphericalTensor2& s1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<sphericalTensor2>> operator / ( const sphericalTensor2& s1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<sphericalTensor2>> operator / ( const sphericalTensor2& s1, const tmp<Field<sphericalTensor2>>& tf2 ); 
	void divide ( Field<sphericalTensor2>& f, const UList<sphericalTensor2>& f1, const sphericalTensor2& s2 );
	tmp<Field<sphericalTensor2>> operator / ( const UList<sphericalTensor2>& f1, const sphericalTensor2& s2 );  
	tmp<Field<sphericalTensor2>> operator / ( const tmp<Field<sphericalTensor2>>& tf1, const sphericalTensor2& s2 ); 
	void add ( Field<sphericalTensor2>& f, const UList<sphericalTensor2>& f1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<sphericalTensor2>> operator + ( const UList<sphericalTensor2>& f1, const UList<sphericalTensor2>& f2 );  
	tmp<Field<sphericalTensor2>> operator + ( const UList<sphericalTensor2>& f1, const tmp<Field<sphericalTensor2>>& tf2 ); 
	tmp<Field<sphericalTensor2>> operator + ( const tmp<Field<sphericalTensor2>>& tf1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<sphericalTensor2>> operator + ( const tmp<Field<sphericalTensor2>>& tf1, const tmp<Field<sphericalTensor2>>& tf2 );  
	void subtract ( Field<sphericalTensor2>& f, const UList<sphericalTensor2>& f1, const UList<sphericalTensor2>& f2 );
	tmp<Field<sphericalTensor2>> operator - ( const UList<sphericalTensor2>& f1, const UList<sphericalTensor2>& f2 );
	tmp<Field<sphericalTensor2>> operator - ( const UList<sphericalTensor2>& f1, const tmp<Field<sphericalTensor2>>& tf2 );
	tmp<Field<sphericalTensor2>> operator - ( const tmp<Field<sphericalTensor2>>& tf1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<sphericalTensor2>> operator - ( const tmp<Field<sphericalTensor2>>& tf1, const tmp<Field<sphericalTensor2>>& tf2 );  
	void add ( Field<sphericalTensor2>& f, const sphericalTensor2& s1, const UList<sphericalTensor2>& f2 );  
	tmp<Field<sphericalTensor2>> operator + ( const sphericalTensor2& s1, const UList<sphericalTensor2>& f2 );  
	tmp<Field<sphericalTensor2>> operator + ( const sphericalTensor2& s1, const tmp<Field<sphericalTensor2>>& tf2 );  
	void add ( Field<sphericalTensor2>& f, const UList<sphericalTensor2>& f1, const sphericalTensor2& s2 ); 
	tmp<Field<sphericalTensor2>> operator + ( const UList<sphericalTensor2>& f1, const sphericalTensor2& s2 );  
	tmp<Field<sphericalTensor2>> operator + ( const tmp<Field<sphericalTensor2>>& tf1, const sphericalTensor2& s2 );
	void subtract ( Field<sphericalTensor2>& f, const sphericalTensor2& s1, const UList<sphericalTensor2>& f2 );  
	tmp<Field<sphericalTensor2>> operator - ( const sphericalTensor2& s1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<sphericalTensor2>> operator - ( const sphericalTensor2& s1, const tmp<Field<sphericalTensor2>>& tf2 );
	void subtract ( Field<sphericalTensor2>& f, const UList<sphericalTensor2>& f1, const sphericalTensor2& s2 );
	tmp<Field<sphericalTensor2>> operator - ( const UList<sphericalTensor2>& f1, const sphericalTensor2& s2 ); 
	tmp<Field<sphericalTensor2>> operator - ( const tmp<Field<sphericalTensor2>>& tf1, const sphericalTensor2& s2 ); 

	void inv(Field<sphericalTensor3>& res, const UList<sphericalTensor3>& f); 
	tmp<Field<sphericalTensor3>> inv(const UList<sphericalTensor3>& f); 
	tmp<Field<sphericalTensor3>> inv(const tmp<Field<sphericalTensor3>>& tf); 
	void diag(Field<sphericalTensor3>& res, const UList<sphericalTensor3>& f); 
	tmp<Field<sphericalTensor3>> diag(const UList<sphericalTensor3>& f); 
	tmp<Field<sphericalTensor3>> diag(const tmp<Field<sphericalTensor3>>& tf);
	void divide ( Field<sphericalTensor3>& f, const UList<scalar>& f1, const UList<sphericalTensor3>& f2 ); 
	tmp<Field<sphericalTensor3>> operator / ( const UList<scalar>& f1, const UList<sphericalTensor3>& f2 ); 
	tmp<Field<sphericalTensor3>> operator / ( const UList<scalar>& f1, const tmp<Field<sphericalTensor3>>& tf2 );
	tmp<Field<sphericalTensor3>> operator / ( const tmp<Field<scalar>>& tf1, const UList<sphericalTensor3>& f2 ); 
	tmp<Field<sphericalTensor3>> operator / ( const tmp<Field<scalar>>& tf1, const tmp<Field<sphericalTensor3>>& tf2 ); 
	void divide ( Field<sphericalTensor3>& f, const scalar& s1, const UList<sphericalTensor3>& f2 );  
	tmp<Field<sphericalTensor3>> operator / ( const scalar& s1, const UList<sphericalTensor3>& f2 ); 
	tmp<Field<sphericalTensor3>> operator / ( const scalar& s1, const tmp<Field<sphericalTensor3>>& tf2 );  
	void divide ( Field<sphericalTensor3>& f, const UList<scalar>& f1, const sphericalTensor3& s2 ); 
	tmp<Field<sphericalTensor3>> operator / ( const UList<scalar>& f1, const sphericalTensor3& s2 );  
	tmp<Field<sphericalTensor3>> operator / ( const tmp<Field<scalar>>& tf1, const sphericalTensor3& s2 ); 
	void divide ( Field<vector3>& f, const UList<vector3>& f1, const UList<sphericalTensor3>& f2 ); 
	tmp<Field<vector3>> operator / ( const UList<vector3>& f1, const UList<sphericalTensor3>& f2 );  
	tmp<Field<vector3>> operator / ( const UList<vector3>& f1, const tmp<Field<sphericalTensor3>>& tf2 );
	tmp<Field<vector3>> operator / ( const tmp<Field<vector3>>& tf1, const UList<sphericalTensor3>& f2 );
	tmp<Field<vector3>> operator / ( const tmp<Field<vector3>>& tf1, const tmp<Field<sphericalTensor3>>& tf2 );
	void divide ( Field<vector3>& f, const vector3& s1, const UList<sphericalTensor3>& f2 ); 
	tmp<Field<vector3>> operator / ( const vector3& s1, const UList<sphericalTensor3>& f2 );  
	tmp<Field<vector3>> operator / ( const vector3& s1, const tmp<Field<sphericalTensor3>>& tf2 ); 
	void divide ( Field<vector3>& f, const UList<vector3>& f1, const sphericalTensor3& s2 ); 
	tmp<Field<vector3>> operator / ( const UList<vector3>& f1, const sphericalTensor3& s2 );  
	tmp<Field<vector3>> operator / ( const tmp<Field<vector3>>& tf1, const sphericalTensor3& s2 ); 
	void divide ( Field<sphericalTensor3>& f, const UList<sphericalTensor3>& f1, const UList<sphericalTensor3>& f2 );
	tmp<Field<sphericalTensor3>> operator / ( const UList<sphericalTensor3>& f1, const UList<sphericalTensor3>& f2 );
	tmp<Field<sphericalTensor3>> operator / ( const UList<sphericalTensor3>& f1, const tmp<Field<sphericalTensor3>>& tf2 );  
	tmp<Field<sphericalTensor3>> operator / ( const tmp<Field<sphericalTensor3>>& tf1, const UList<sphericalTensor3>& f2 ); 
	tmp<Field<sphericalTensor3>> operator / ( const tmp<Field<sphericalTensor3>>& tf1, const tmp<Field<sphericalTensor3>>& tf2 ); 
	void divide ( Field<sphericalTensor3>& f, const sphericalTensor3& s1, const UList<sphericalTensor3>& f2 ); 
	tmp<Field<sphericalTensor3>> operator / ( const sphericalTensor3& s1, const UList<sphericalTensor3>& f2 ); 
	tmp<Field<sphericalTensor3>> operator / ( const sphericalTensor3& s1, const tmp<Field<sphericalTensor3>>& tf2 ); 
	void divide ( Field<sphericalTensor3>& f, const UList<sphericalTensor3>& f1, const sphericalTensor3& s2 );  
	tmp<Field<sphericalTensor3>> operator / ( const UList<sphericalTensor3>& f1, const sphericalTensor3& s2 ); 
	tmp<Field<sphericalTensor3>> operator / ( const tmp<Field<sphericalTensor3>>& tf1, const sphericalTensor3& s2 ); 
	void add ( Field<sphericalTensor3>& f, const UList<sphericalTensor3>& f1, const UList<sphericalTensor3>& f2 );  
	tmp<Field<sphericalTensor3>> operator + ( const UList<sphericalTensor3>& f1, const UList<sphericalTensor3>& f2 );  
	tmp<Field<sphericalTensor3>> operator + ( const UList<sphericalTensor3>& f1, const tmp<Field<sphericalTensor3>>& tf2 ); 
	tmp<Field<sphericalTensor3>> operator + ( const tmp<Field<sphericalTensor3>>& tf1, const UList<sphericalTensor3>& f2 ); 
	tmp<Field<sphericalTensor3>> operator + ( const tmp<Field<sphericalTensor3>>& tf1, const tmp<Field<sphericalTensor3>>& tf2 ); 
	void subtract ( Field<sphericalTensor3>& f, const UList<sphericalTensor3>& f1, const UList<sphericalTensor3>& f2 );
	tmp<Field<sphericalTensor3>> operator - ( const UList<sphericalTensor3>& f1, const UList<sphericalTensor3>& f2 ); 
	tmp<Field<sphericalTensor3>> operator - ( const UList<sphericalTensor3>& f1, const tmp<Field<sphericalTensor3>>& tf2 );
	tmp<Field<sphericalTensor3>> operator - ( const tmp<Field<sphericalTensor3>>& tf1, const UList<sphericalTensor3>& f2 ); 
	tmp<Field<sphericalTensor3>> operator - ( const tmp<Field<sphericalTensor3>>& tf1, const tmp<Field<sphericalTensor3>>& tf2 ); 
	void add ( Field<sphericalTensor3>& f, const sphericalTensor3& s1, const UList<sphericalTensor3>& f2 ); 
	tmp<Field<sphericalTensor3>> operator + ( const sphericalTensor3& s1, const UList<sphericalTensor3>& f2 );  
	tmp<Field<sphericalTensor3>> operator + ( const sphericalTensor3& s1, const tmp<Field<sphericalTensor3>>& tf2 ); 
	void add ( Field<sphericalTensor3>& f, const UList<sphericalTensor3>& f1, const sphericalTensor3& s2 ); 
	tmp<Field<sphericalTensor3>> operator + ( const UList<sphericalTensor3>& f1, const sphericalTensor3& s2 ); 
	tmp<Field<sphericalTensor3>> operator + ( const tmp<Field<sphericalTensor3>>& tf1, const sphericalTensor3& s2 ); 
	void subtract ( Field<sphericalTensor3>& f, const sphericalTensor3& s1, const UList<sphericalTensor3>& f2 );  
	tmp<Field<sphericalTensor3>> operator - ( const sphericalTensor3& s1, const UList<sphericalTensor3>& f2 ); 
	tmp<Field<sphericalTensor3>> operator - ( const sphericalTensor3& s1, const tmp<Field<sphericalTensor3>>& tf2 ); 
	void subtract ( Field<sphericalTensor3>& f, const UList<sphericalTensor3>& f1, const sphericalTensor3& s2 ); 
	tmp<Field<sphericalTensor3>> operator - ( const UList<sphericalTensor3>& f1, const sphericalTensor3& s2 ); 
	tmp<Field<sphericalTensor3>> operator - ( const tmp<Field<sphericalTensor3>>& tf1, const sphericalTensor3& s2 ); 
	
	 void inv(Field<sphericalTensor4>& res, const UList<sphericalTensor4>& f); 
	tmp<Field<sphericalTensor4>> inv(const UList<sphericalTensor4>& f); 
	tmp<Field<sphericalTensor4>> inv(const tmp<Field<sphericalTensor4>>& tf); 
	void diag(Field<sphericalTensor4>& res, const UList<sphericalTensor4>& f); 
	tmp<Field<sphericalTensor4>> diag(const UList<sphericalTensor4>& f); 
	tmp<Field<sphericalTensor4>> diag(const tmp<Field<sphericalTensor4>>& tf); 
	void divide ( Field<sphericalTensor4>& f, const UList<scalar>& f1, const UList<sphericalTensor4>& f2 );  
	tmp<Field<sphericalTensor4>> operator / ( const UList<scalar>& f1, const UList<sphericalTensor4>& f2 ); 
	tmp<Field<sphericalTensor4>> operator / ( const UList<scalar>& f1, const tmp<Field<sphericalTensor4>>& tf2 ); 
	tmp<Field<sphericalTensor4>> operator / ( const tmp<Field<scalar>>& tf1, const UList<sphericalTensor4>& f2 ); 
	tmp<Field<sphericalTensor4>> operator / ( const tmp<Field<scalar>>& tf1, const tmp<Field<sphericalTensor4>>& tf2 );
	void divide ( Field<sphericalTensor4>& f, const scalar& s1, const UList<sphericalTensor4>& f2 ); 
	tmp<Field<sphericalTensor4>> operator / ( const scalar& s1, const UList<sphericalTensor4>& f2 );  
	tmp<Field<sphericalTensor4>> operator / ( const scalar& s1, const tmp<Field<sphericalTensor4>>& tf2 ); 
	void divide ( Field<sphericalTensor4>& f, const UList<scalar>& f1, const sphericalTensor4& s2 ); 
	tmp<Field<sphericalTensor4>> operator / ( const UList<scalar>& f1, const sphericalTensor4& s2 );  
	tmp<Field<sphericalTensor4>> operator / ( const tmp<Field<scalar>>& tf1, const sphericalTensor4& s2 ); 
	void divide ( Field<vector4>& f, const UList<vector4>& f1, const UList<sphericalTensor4>& f2 ); 
	tmp<Field<vector4>> operator / ( const UList<vector4>& f1, const UList<sphericalTensor4>& f2 ); 
	tmp<Field<vector4>> operator / ( const UList<vector4>& f1, const tmp<Field<sphericalTensor4>>& tf2 );
	tmp<Field<vector4>> operator / ( const tmp<Field<vector4>>& tf1, const UList<sphericalTensor4>& f2 ); 
	tmp<Field<vector4>> operator / ( const tmp<Field<vector4>>& tf1, const tmp<Field<sphericalTensor4>>& tf2 );  
	void divide ( Field<vector4>& f, const vector4& s1, const UList<sphericalTensor4>& f2 ); 
	tmp<Field<vector4>> operator / ( const vector4& s1, const UList<sphericalTensor4>& f2 );  
	tmp<Field<vector4>> operator / ( const vector4& s1, const tmp<Field<sphericalTensor4>>& tf2 ); 
	void divide ( Field<vector4>& f, const UList<vector4>& f1, const sphericalTensor4& s2 );  
	tmp<Field<vector4>> operator / ( const UList<vector4>& f1, const sphericalTensor4& s2 );  
	tmp<Field<vector4>> operator / ( const tmp<Field<vector4>>& tf1, const sphericalTensor4& s2 ); 
	void divide ( Field<sphericalTensor4>& f, const UList<sphericalTensor4>& f1, const UList<sphericalTensor4>& f2 );  
	tmp<Field<sphericalTensor4>> operator / ( const UList<sphericalTensor4>& f1, const UList<sphericalTensor4>& f2 );
	tmp<Field<sphericalTensor4>> operator / ( const UList<sphericalTensor4>& f1, const tmp<Field<sphericalTensor4>>& tf2 );
	tmp<Field<sphericalTensor4>> operator / ( const tmp<Field<sphericalTensor4>>& tf1, const UList<sphericalTensor4>& f2 ); 
	tmp<Field<sphericalTensor4>> operator / ( const tmp<Field<sphericalTensor4>>& tf1, const tmp<Field<sphericalTensor4>>& tf2 ); 
	void divide ( Field<sphericalTensor4>& f, const sphericalTensor4& s1, const UList<sphericalTensor4>& f2 );  
	tmp<Field<sphericalTensor4>> operator / ( const sphericalTensor4& s1, const UList<sphericalTensor4>& f2 );  
	tmp<Field<sphericalTensor4>> operator / ( const sphericalTensor4& s1, const tmp<Field<sphericalTensor4>>& tf2 );
	void divide ( Field<sphericalTensor4>& f, const UList<sphericalTensor4>& f1, const sphericalTensor4& s2 ); 
	tmp<Field<sphericalTensor4>> operator / ( const UList<sphericalTensor4>& f1, const sphericalTensor4& s2 ); 
	tmp<Field<sphericalTensor4>> operator / ( const tmp<Field<sphericalTensor4>>& tf1, const sphericalTensor4& s2 );
	void add ( Field<sphericalTensor4>& f, const UList<sphericalTensor4>& f1, const UList<sphericalTensor4>& f2 ); 
	tmp<Field<sphericalTensor4>> operator + ( const UList<sphericalTensor4>& f1, const UList<sphericalTensor4>& f2 );
	tmp<Field<sphericalTensor4>> operator + ( const UList<sphericalTensor4>& f1, const tmp<Field<sphericalTensor4>>& tf2 ); 
	tmp<Field<sphericalTensor4>> operator + ( const tmp<Field<sphericalTensor4>>& tf1, const UList<sphericalTensor4>& f2 );  
	tmp<Field<sphericalTensor4>> operator + ( const tmp<Field<sphericalTensor4>>& tf1, const tmp<Field<sphericalTensor4>>& tf2 );  
	void subtract ( Field<sphericalTensor4>& f, const UList<sphericalTensor4>& f1, const UList<sphericalTensor4>& f2 ); 
	tmp<Field<sphericalTensor4>> operator - ( const UList<sphericalTensor4>& f1, const UList<sphericalTensor4>& f2 ); 
	tmp<Field<sphericalTensor4>> operator - ( const UList<sphericalTensor4>& f1, const tmp<Field<sphericalTensor4>>& tf2 ); 
	tmp<Field<sphericalTensor4>> operator - ( const tmp<Field<sphericalTensor4>>& tf1, const UList<sphericalTensor4>& f2 );  
	tmp<Field<sphericalTensor4>> operator - ( const tmp<Field<sphericalTensor4>>& tf1, const tmp<Field<sphericalTensor4>>& tf2 ); 
	void add ( Field<sphericalTensor4>& f, const sphericalTensor4& s1, const UList<sphericalTensor4>& f2 ); 
	tmp<Field<sphericalTensor4>> operator + ( const sphericalTensor4& s1, const UList<sphericalTensor4>& f2 ); 
	tmp<Field<sphericalTensor4>> operator + ( const sphericalTensor4& s1, const tmp<Field<sphericalTensor4>>& tf2 );  
	void add ( Field<sphericalTensor4>& f, const UList<sphericalTensor4>& f1, const sphericalTensor4& s2 );  
	tmp<Field<sphericalTensor4>> operator + ( const UList<sphericalTensor4>& f1, const sphericalTensor4& s2 ); 
	tmp<Field<sphericalTensor4>> operator + ( const tmp<Field<sphericalTensor4>>& tf1, const sphericalTensor4& s2 ); 
	void subtract ( Field<sphericalTensor4>& f, const sphericalTensor4& s1, const UList<sphericalTensor4>& f2 );  
	tmp<Field<sphericalTensor4>> operator - ( const sphericalTensor4& s1, const UList<sphericalTensor4>& f2 );  
	tmp<Field<sphericalTensor4>> operator - ( const sphericalTensor4& s1, const tmp<Field<sphericalTensor4>>& tf2 );  
	void subtract ( Field<sphericalTensor4>& f, const UList<sphericalTensor4>& f1, const sphericalTensor4& s2 );  
	tmp<Field<sphericalTensor4>> operator - ( const UList<sphericalTensor4>& f1, const sphericalTensor4& s2 );  
	tmp<Field<sphericalTensor4>> operator - ( const tmp<Field<sphericalTensor4>>& tf1, const sphericalTensor4& s2 ); 
	
	 void inv(Field<sphericalTensor6>& res, const UList<sphericalTensor6>& f); 
	tmp<Field<sphericalTensor6>> inv(const UList<sphericalTensor6>& f);  
	tmp<Field<sphericalTensor6>> inv(const tmp<Field<sphericalTensor6>>& tf); 
	void diag(Field<sphericalTensor6>& res, const UList<sphericalTensor6>& f); 
	tmp<Field<sphericalTensor6>> diag(const UList<sphericalTensor6>& f); 
	tmp<Field<sphericalTensor6>> diag(const tmp<Field<sphericalTensor6>>& tf);
	void divide ( Field<sphericalTensor6>& f, const UList<scalar>& f1, const UList<sphericalTensor6>& f2 ); 
	tmp<Field<sphericalTensor6>> operator / ( const UList<scalar>& f1, const UList<sphericalTensor6>& f2 ); 
	tmp<Field<sphericalTensor6>> operator / ( const UList<scalar>& f1, const tmp<Field<sphericalTensor6>>& tf2 ); 
	tmp<Field<sphericalTensor6>> operator / ( const tmp<Field<scalar>>& tf1, const UList<sphericalTensor6>& f2 ); 
	tmp<Field<sphericalTensor6>> operator / ( const tmp<Field<scalar>>& tf1, const tmp<Field<sphericalTensor6>>& tf2 ); 
	void divide ( Field<sphericalTensor6>& f, const scalar& s1, const UList<sphericalTensor6>& f2 ); 
	tmp<Field<sphericalTensor6>> operator / ( const scalar& s1, const UList<sphericalTensor6>& f2 );  
	tmp<Field<sphericalTensor6>> operator / ( const scalar& s1, const tmp<Field<sphericalTensor6>>& tf2 );  
	void divide ( Field<sphericalTensor6>& f, const UList<scalar>& f1, const sphericalTensor6& s2 );  
	tmp<Field<sphericalTensor6>> operator / ( const UList<scalar>& f1, const sphericalTensor6& s2 );  
	tmp<Field<sphericalTensor6>> operator / ( const tmp<Field<scalar>>& tf1, const sphericalTensor6& s2 );
	void divide ( Field<vector6>& f, const UList<vector6>& f1, const UList<sphericalTensor6>& f2 );
	tmp<Field<vector6>> operator / ( const UList<vector6>& f1, const UList<sphericalTensor6>& f2 );  
	tmp<Field<vector6>> operator / ( const UList<vector6>& f1, const tmp<Field<sphericalTensor6>>& tf2 ); 
	tmp<Field<vector6>> operator / ( const tmp<Field<vector6>>& tf1, const UList<sphericalTensor6>& f2 );
	tmp<Field<vector6>> operator / ( const tmp<Field<vector6>>& tf1, const tmp<Field<sphericalTensor6>>& tf2 ); 
	void divide ( Field<vector6>& f, const vector6& s1, const UList<sphericalTensor6>& f2 ); 
	tmp<Field<vector6>> operator / ( const vector6& s1, const UList<sphericalTensor6>& f2 ); 
	tmp<Field<vector6>> operator / ( const vector6& s1, const tmp<Field<sphericalTensor6>>& tf2 ); 
	void divide ( Field<vector6>& f, const UList<vector6>& f1, const sphericalTensor6& s2 ); 
	tmp<Field<vector6>> operator / ( const UList<vector6>& f1, const sphericalTensor6& s2 );  
	tmp<Field<vector6>> operator / ( const tmp<Field<vector6>>& tf1, const sphericalTensor6& s2 );
	void divide ( Field<sphericalTensor6>& f, const UList<sphericalTensor6>& f1, const UList<sphericalTensor6>& f2 );
	tmp<Field<sphericalTensor6>> operator / ( const UList<sphericalTensor6>& f1, const UList<sphericalTensor6>& f2 ); 
	tmp<Field<sphericalTensor6>> operator / ( const UList<sphericalTensor6>& f1, const tmp<Field<sphericalTensor6>>& tf2 ); 
	tmp<Field<sphericalTensor6>> operator / ( const tmp<Field<sphericalTensor6>>& tf1, const UList<sphericalTensor6>& f2 );
	tmp<Field<sphericalTensor6>> operator / ( const tmp<Field<sphericalTensor6>>& tf1, const tmp<Field<sphericalTensor6>>& tf2 );  
	void divide ( Field<sphericalTensor6>& f, const sphericalTensor6& s1, const UList<sphericalTensor6>& f2 );  
	tmp<Field<sphericalTensor6>> operator / ( const sphericalTensor6& s1, const UList<sphericalTensor6>& f2 );  
	tmp<Field<sphericalTensor6>> operator / ( const sphericalTensor6& s1, const tmp<Field<sphericalTensor6>>& tf2 ); 
	void divide ( Field<sphericalTensor6>& f, const UList<sphericalTensor6>& f1, const sphericalTensor6& s2 );  
	tmp<Field<sphericalTensor6>> operator / ( const UList<sphericalTensor6>& f1, const sphericalTensor6& s2 );  
	tmp<Field<sphericalTensor6>> operator / ( const tmp<Field<sphericalTensor6>>& tf1, const sphericalTensor6& s2 ); 
	void add ( Field<sphericalTensor6>& f, const UList<sphericalTensor6>& f1, const UList<sphericalTensor6>& f2 ); 
	tmp<Field<sphericalTensor6>> operator + ( const UList<sphericalTensor6>& f1, const UList<sphericalTensor6>& f2 ); 
	tmp<Field<sphericalTensor6>> operator + ( const UList<sphericalTensor6>& f1, const tmp<Field<sphericalTensor6>>& tf2 ); 
	tmp<Field<sphericalTensor6>> operator + ( const tmp<Field<sphericalTensor6>>& tf1, const UList<sphericalTensor6>& f2 ); 
	tmp<Field<sphericalTensor6>> operator + ( const tmp<Field<sphericalTensor6>>& tf1, const tmp<Field<sphericalTensor6>>& tf2 );  
	void subtract ( Field<sphericalTensor6>& f, const UList<sphericalTensor6>& f1, const UList<sphericalTensor6>& f2 );  
	tmp<Field<sphericalTensor6>> operator - ( const UList<sphericalTensor6>& f1, const UList<sphericalTensor6>& f2 );  
	tmp<Field<sphericalTensor6>> operator - ( const UList<sphericalTensor6>& f1, const tmp<Field<sphericalTensor6>>& tf2 ); 
	tmp<Field<sphericalTensor6>> operator - ( const tmp<Field<sphericalTensor6>>& tf1, const UList<sphericalTensor6>& f2 ); 
	tmp<Field<sphericalTensor6>> operator - ( const tmp<Field<sphericalTensor6>>& tf1, const tmp<Field<sphericalTensor6>>& tf2 );  
	void add ( Field<sphericalTensor6>& f, const sphericalTensor6& s1, const UList<sphericalTensor6>& f2 ); 
	tmp<Field<sphericalTensor6>> operator + ( const sphericalTensor6& s1, const UList<sphericalTensor6>& f2 );  
	tmp<Field<sphericalTensor6>> operator + ( const sphericalTensor6& s1, const tmp<Field<sphericalTensor6>>& tf2 ); 
	void add ( Field<sphericalTensor6>& f, const UList<sphericalTensor6>& f1, const sphericalTensor6& s2 );  
	tmp<Field<sphericalTensor6>> operator + ( const UList<sphericalTensor6>& f1, const sphericalTensor6& s2 ); 
	tmp<Field<sphericalTensor6>> operator + ( const tmp<Field<sphericalTensor6>>& tf1, const sphericalTensor6& s2 );  
	void subtract ( Field<sphericalTensor6>& f, const sphericalTensor6& s1, const UList<sphericalTensor6>& f2 );  
	tmp<Field<sphericalTensor6>> operator - ( const sphericalTensor6& s1, const UList<sphericalTensor6>& f2 ); 
	tmp<Field<sphericalTensor6>> operator - ( const sphericalTensor6& s1, const tmp<Field<sphericalTensor6>>& tf2 );
	void subtract ( Field<sphericalTensor6>& f, const UList<sphericalTensor6>& f1, const sphericalTensor6& s2 );  
	tmp<Field<sphericalTensor6>> operator - ( const UList<sphericalTensor6>& f1, const sphericalTensor6& s2 ); 
	tmp<Field<sphericalTensor6>> operator - ( const tmp<Field<sphericalTensor6>>& tf1, const sphericalTensor6& s2 ); 
	
	void inv(Field<sphericalTensor8>& res, const UList<sphericalTensor8>& f);
	tmp<Field<sphericalTensor8>> inv(const UList<sphericalTensor8>& f);
	tmp<Field<sphericalTensor8>> inv(const tmp<Field<sphericalTensor8>>& tf);
	void diag(Field<sphericalTensor8>& res, const UList<sphericalTensor8>& f); 
	tmp<Field<sphericalTensor8>> diag(const UList<sphericalTensor8>& f); 
	tmp<Field<sphericalTensor8>> diag(const tmp<Field<sphericalTensor8>>& tf);
	void divide ( Field<sphericalTensor8>& f, const UList<scalar>& f1, const UList<sphericalTensor8>& f2 ); 
	tmp<Field<sphericalTensor8>> operator / ( const UList<scalar>& f1, const UList<sphericalTensor8>& f2 ); 
	tmp<Field<sphericalTensor8>> operator / ( const UList<scalar>& f1, const tmp<Field<sphericalTensor8>>& tf2 ); 
	tmp<Field<sphericalTensor8>> operator / ( const tmp<Field<scalar>>& tf1, const UList<sphericalTensor8>& f2 ); 
	tmp<Field<sphericalTensor8>> operator / ( const tmp<Field<scalar>>& tf1, const tmp<Field<sphericalTensor8>>& tf2 ); 
	void divide ( Field<sphericalTensor8>& f, const scalar& s1, const UList<sphericalTensor8>& f2 ); 
	tmp<Field<sphericalTensor8>> operator / ( const scalar& s1, const UList<sphericalTensor8>& f2 );  
	tmp<Field<sphericalTensor8>> operator / ( const scalar& s1, const tmp<Field<sphericalTensor8>>& tf2 ); 
	void divide ( Field<sphericalTensor8>& f, const UList<scalar>& f1, const sphericalTensor8& s2 );  
	tmp<Field<sphericalTensor8>> operator / ( const UList<scalar>& f1, const sphericalTensor8& s2 );  
	tmp<Field<sphericalTensor8>> operator / ( const tmp<Field<scalar>>& tf1, const sphericalTensor8& s2 );
	void divide ( Field<vector8>& f, const UList<vector8>& f1, const UList<sphericalTensor8>& f2 );  
	tmp<Field<vector8>> operator / ( const UList<vector8>& f1, const UList<sphericalTensor8>& f2 ); 
	tmp<Field<vector8>> operator / ( const UList<vector8>& f1, const tmp<Field<sphericalTensor8>>& tf2 ); 
	tmp<Field<vector8>> operator / ( const tmp<Field<vector8>>& tf1, const UList<sphericalTensor8>& f2 );  
	tmp<Field<vector8>> operator / ( const tmp<Field<vector8>>& tf1, const tmp<Field<sphericalTensor8>>& tf2 ); 
	void divide ( Field<vector8>& f, const vector8& s1, const UList<sphericalTensor8>& f2 );  
	tmp<Field<vector8>> operator / ( const vector8& s1, const UList<sphericalTensor8>& f2 );  
	tmp<Field<vector8>> operator / ( const vector8& s1, const tmp<Field<sphericalTensor8>>& tf2 );  
	void divide ( Field<vector8>& f, const UList<vector8>& f1, const sphericalTensor8& s2 );  
	tmp<Field<vector8>> operator / ( const UList<vector8>& f1, const sphericalTensor8& s2 );  
	tmp<Field<vector8>> operator / ( const tmp<Field<vector8>>& tf1, const sphericalTensor8& s2 );
	void divide ( Field<sphericalTensor8>& f, const UList<sphericalTensor8>& f1, const UList<sphericalTensor8>& f2 ); 
	tmp<Field<sphericalTensor8>> operator / ( const UList<sphericalTensor8>& f1, const UList<sphericalTensor8>& f2 );  
	tmp<Field<sphericalTensor8>> operator / ( const UList<sphericalTensor8>& f1, const tmp<Field<sphericalTensor8>>& tf2 );
	tmp<Field<sphericalTensor8>> operator / ( const tmp<Field<sphericalTensor8>>& tf1, const UList<sphericalTensor8>& f2 );
	tmp<Field<sphericalTensor8>> operator / ( const tmp<Field<sphericalTensor8>>& tf1, const tmp<Field<sphericalTensor8>>& tf2 ); 
	void divide ( Field<sphericalTensor8>& f, const sphericalTensor8& s1, const UList<sphericalTensor8>& f2 );  
	tmp<Field<sphericalTensor8>> operator / ( const sphericalTensor8& s1, const UList<sphericalTensor8>& f2 );  
	tmp<Field<sphericalTensor8>> operator / ( const sphericalTensor8& s1, const tmp<Field<sphericalTensor8>>& tf2 ); 
	void divide ( Field<sphericalTensor8>& f, const UList<sphericalTensor8>& f1, const sphericalTensor8& s2 ); 
	tmp<Field<sphericalTensor8>> operator / ( const UList<sphericalTensor8>& f1, const sphericalTensor8& s2 ); 
	tmp<Field<sphericalTensor8>> operator / ( const tmp<Field<sphericalTensor8>>& tf1, const sphericalTensor8& s2 );
	void add ( Field<sphericalTensor8>& f, const UList<sphericalTensor8>& f1, const UList<sphericalTensor8>& f2 ); 
	tmp<Field<sphericalTensor8>> operator + ( const UList<sphericalTensor8>& f1, const UList<sphericalTensor8>& f2 ); 
	tmp<Field<sphericalTensor8>> operator + ( const UList<sphericalTensor8>& f1, const tmp<Field<sphericalTensor8>>& tf2 );  
	tmp<Field<sphericalTensor8>> operator + ( const tmp<Field<sphericalTensor8>>& tf1, const UList<sphericalTensor8>& f2 ); 
	tmp<Field<sphericalTensor8>> operator + ( const tmp<Field<sphericalTensor8>>& tf1, const tmp<Field<sphericalTensor8>>& tf2 );  
	void subtract ( Field<sphericalTensor8>& f, const UList<sphericalTensor8>& f1, const UList<sphericalTensor8>& f2 ); 
	tmp<Field<sphericalTensor8>> operator - ( const UList<sphericalTensor8>& f1, const UList<sphericalTensor8>& f2 ); 
	tmp<Field<sphericalTensor8>> operator - ( const UList<sphericalTensor8>& f1, const tmp<Field<sphericalTensor8>>& tf2 );
	tmp<Field<sphericalTensor8>> operator - ( const tmp<Field<sphericalTensor8>>& tf1, const UList<sphericalTensor8>& f2 );
	tmp<Field<sphericalTensor8>> operator - ( const tmp<Field<sphericalTensor8>>& tf1, const tmp<Field<sphericalTensor8>>& tf2 ); 
	void add ( Field<sphericalTensor8>& f, const sphericalTensor8& s1, const UList<sphericalTensor8>& f2 ); 
	tmp<Field<sphericalTensor8>> operator + ( const sphericalTensor8& s1, const UList<sphericalTensor8>& f2 ); 
	tmp<Field<sphericalTensor8>> operator + ( const sphericalTensor8& s1, const tmp<Field<sphericalTensor8>>& tf2 );
	void add ( Field<sphericalTensor8>& f, const UList<sphericalTensor8>& f1, const sphericalTensor8& s2 );  
	tmp<Field<sphericalTensor8>> operator + ( const UList<sphericalTensor8>& f1, const sphericalTensor8& s2 ); 
	tmp<Field<sphericalTensor8>> operator + ( const tmp<Field<sphericalTensor8>>& tf1, const sphericalTensor8& s2 );
	void subtract ( Field<sphericalTensor8>& f, const sphericalTensor8& s1, const UList<sphericalTensor8>& f2 ); 
	tmp<Field<sphericalTensor8>> operator - ( const sphericalTensor8& s1, const UList<sphericalTensor8>& f2 ); 
	tmp<Field<sphericalTensor8>> operator - ( const sphericalTensor8& s1, const tmp<Field<sphericalTensor8>>& tf2 );
	void subtract ( Field<sphericalTensor8>& f, const UList<sphericalTensor8>& f1, const sphericalTensor8& s2 ); 
	tmp<Field<sphericalTensor8>> operator - ( const UList<sphericalTensor8>& f1, const sphericalTensor8& s2 );  
	tmp<Field<sphericalTensor8>> operator - ( const tmp<Field<sphericalTensor8>>& tf1, const sphericalTensor8& s2 );
}

#undef SphericalTensorN_FieldFunctions

#include <undefFieldFunctionsM.hxx>

#endif // !1
