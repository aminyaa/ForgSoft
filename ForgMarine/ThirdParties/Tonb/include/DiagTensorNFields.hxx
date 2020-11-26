#pragma once
#ifndef _DiagTensorNFields_Header
#define _DiagTensorNFields_Header

#include <VectorTensorNFieldsFwd.hxx>
#include <Field.hxx>

#define TEMPLATE
#include <FieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define DiagTensorN_FieldFunctions(tensorType, diagTensorType, sphericalTensorType, \
    vectorType, CmptType, args)                                                  \
                                                                                    \
UNARY_FUNCTION(diagTensorType, diagTensorType, inv)                                 \
UNARY_FUNCTION(diagTensorType, diagTensorType, diag)                                \
                                                                                    \
BINARY_OPERATOR(diagTensorType, CmptType, diagTensorType, /, divide)                \
BINARY_TYPE_OPERATOR(diagTensorType, CmptType, diagTensorType, /, divide)           \
                                                                                    \
BINARY_OPERATOR(vectorType, vectorType, diagTensorType, /, divide)                  \
BINARY_TYPE_OPERATOR(vectorType, vectorType, diagTensorType, /, divide)             \
                                                                                    \
BINARY_OPERATOR(diagTensorType, diagTensorType, diagTensorType, /, divide)          \
BINARY_TYPE_OPERATOR(diagTensorType, diagTensorType, diagTensorType, /, divide)     \
                                                                                    \
BINARY_OPERATOR(diagTensorType, sphericalTensorType, diagTensorType, /, divide)     \
BINARY_TYPE_OPERATOR(diagTensorType, sphericalTensorType, diagTensorType, /, divide)\
                                                                                    \
BINARY_OPERATOR(diagTensorType, diagTensorType, sphericalTensorType, /, divide)     \
BINARY_TYPE_OPERATOR(diagTensorType, diagTensorType, sphericalTensorType, /, divide)\
                                                                                    \
BINARY_OPERATOR(diagTensorType, diagTensorType, diagTensorType, +, add)             \
BINARY_OPERATOR(diagTensorType, diagTensorType, diagTensorType, -, subtract)        \
                                                                                    \
BINARY_TYPE_OPERATOR(diagTensorType, diagTensorType, diagTensorType, +, add)        \
BINARY_TYPE_OPERATOR(diagTensorType, diagTensorType, diagTensorType, -, subtract)   \
                                                                                    \
BINARY_OPERATOR(diagTensorType, sphericalTensorType, diagTensorType, +, add)        \
BINARY_OPERATOR(diagTensorType, sphericalTensorType, diagTensorType, -, subtract)   \
                                                                                    \
BINARY_TYPE_OPERATOR(diagTensorType, sphericalTensorType, diagTensorType, +, add)   \
BINARY_TYPE_OPERATOR(diagTensorType, sphericalTensorType, diagTensorType, -, subtract)  \
                                                                                    \
BINARY_OPERATOR(diagTensorType, diagTensorType, sphericalTensorType, +, add)        \
BINARY_OPERATOR(diagTensorType, diagTensorType, sphericalTensorType, -, subtract)   \
                                                                                    \
BINARY_TYPE_OPERATOR(diagTensorType, diagTensorType, sphericalTensorType, +, add)   \
BINARY_TYPE_OPERATOR(diagTensorType, diagTensorType, sphericalTensorType, -, subtract)

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{
	void inv(Field<diagTensor2>& res, const UList<diagTensor2>& f); 
	tmp<Field<diagTensor2>> inv(const UList<diagTensor2>& f);
	tmp<Field<diagTensor2>> inv(const tmp<Field<diagTensor2>>& tf);
	void diag(Field<diagTensor2>& res, const UList<diagTensor2>& f); 
	tmp<Field<diagTensor2>> diag(const UList<diagTensor2>& f);
	tmp<Field<diagTensor2>> diag(const tmp<Field<diagTensor2>>& tf);  
	void divide ( Field<diagTensor2>& f, const UList<scalar>& f1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator / ( const UList<scalar>& f1, const UList<diagTensor2>& f2 );  
	tmp<Field<diagTensor2>> operator / ( const UList<scalar>& f1, const tmp<Field<diagTensor2>>& tf2 );
	tmp<Field<diagTensor2>> operator / ( const tmp<Field<scalar>>& tf1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator / ( const tmp<Field<scalar>>& tf1, const tmp<Field<diagTensor2>>& tf2 );
	void divide ( Field<diagTensor2>& f, const scalar& s1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator / ( const scalar& s1, const UList<diagTensor2>& f2 );  
	tmp<Field<diagTensor2>> operator / ( const scalar& s1, const tmp<Field<diagTensor2>>& tf2 );
	void divide ( Field<diagTensor2>& f, const UList<scalar>& f1, const diagTensor2& s2 ); 
	tmp<Field<diagTensor2>> operator / ( const UList<scalar>& f1, const diagTensor2& s2 ); 
	tmp<Field<diagTensor2>> operator / ( const tmp<Field<scalar>>& tf1, const diagTensor2& s2 );
	void divide ( Field<vector2>& f, const UList<vector2>& f1, const UList<diagTensor2>& f2 );  
	tmp<Field<vector2>> operator / ( const UList<vector2>& f1, const UList<diagTensor2>& f2 );  
	tmp<Field<vector2>> operator / ( const UList<vector2>& f1, const tmp<Field<diagTensor2>>& tf2 );
	tmp<Field<vector2>> operator / ( const tmp<Field<vector2>>& tf1, const UList<diagTensor2>& f2 ); 
	tmp<Field<vector2>> operator / ( const tmp<Field<vector2>>& tf1, const tmp<Field<diagTensor2>>& tf2 );
	void divide ( Field<vector2>& f, const vector2& s1, const UList<diagTensor2>& f2 ); 
	tmp<Field<vector2>> operator / ( const vector2& s1, const UList<diagTensor2>& f2 ); 
	tmp<Field<vector2>> operator / ( const vector2& s1, const tmp<Field<diagTensor2>>& tf2 ); 
	void divide ( Field<vector2>& f, const UList<vector2>& f1, const diagTensor2& s2 );  
	tmp<Field<vector2>> operator / ( const UList<vector2>& f1, const diagTensor2& s2 );  
	tmp<Field<vector2>> operator / ( const tmp<Field<vector2>>& tf1, const diagTensor2& s2 );
	void divide ( Field<diagTensor2>& f, const UList<diagTensor2>& f1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator / ( const UList<diagTensor2>& f1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator / ( const UList<diagTensor2>& f1, const tmp<Field<diagTensor2>>& tf2 );  
	tmp<Field<diagTensor2>> operator / ( const tmp<Field<diagTensor2>>& tf1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator / ( const tmp<Field<diagTensor2>>& tf1, const tmp<Field<diagTensor2>>& tf2 );
	void divide ( Field<diagTensor2>& f, const diagTensor2& s1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator / ( const diagTensor2& s1, const UList<diagTensor2>& f2 );  
	tmp<Field<diagTensor2>> operator / ( const diagTensor2& s1, const tmp<Field<diagTensor2>>& tf2 ); 
	void divide ( Field<diagTensor2>& f, const UList<diagTensor2>& f1, const diagTensor2& s2 );
	tmp<Field<diagTensor2>> operator / ( const UList<diagTensor2>& f1, const diagTensor2& s2 );  
	tmp<Field<diagTensor2>> operator / ( const tmp<Field<diagTensor2>>& tf1, const diagTensor2& s2 ); 
	void divide ( Field<diagTensor2>& f, const UList<sphericalTensor2>& f1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator / ( const UList<sphericalTensor2>& f1, const UList<diagTensor2>& f2 );  
	tmp<Field<diagTensor2>> operator / ( const UList<sphericalTensor2>& f1, const tmp<Field<diagTensor2>>& tf2 );
	tmp<Field<diagTensor2>> operator / ( const tmp<Field<sphericalTensor2>>& tf1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator / ( const tmp<Field<sphericalTensor2>>& tf1, const tmp<Field<diagTensor2>>& tf2 );  
	void divide ( Field<diagTensor2>& f, const sphericalTensor2& s1, const UList<diagTensor2>& f2 );  
	tmp<Field<diagTensor2>> operator / ( const sphericalTensor2& s1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator / ( const sphericalTensor2& s1, const tmp<Field<diagTensor2>>& tf2 ); 
	void divide ( Field<diagTensor2>& f, const UList<sphericalTensor2>& f1, const diagTensor2& s2 ); 
	tmp<Field<diagTensor2>> operator / ( const UList<sphericalTensor2>& f1, const diagTensor2& s2 ); 
	tmp<Field<diagTensor2>> operator / ( const tmp<Field<sphericalTensor2>>& tf1, const diagTensor2& s2 );
	void divide ( Field<diagTensor2>& f, const UList<diagTensor2>& f1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator / ( const UList<diagTensor2>& f1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator / ( const UList<diagTensor2>& f1, const tmp<Field<sphericalTensor2>>& tf2 ); 
	tmp<Field<diagTensor2>> operator / ( const tmp<Field<diagTensor2>>& tf1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator / ( const tmp<Field<diagTensor2>>& tf1, const tmp<Field<sphericalTensor2>>& tf2 );  
	void divide ( Field<diagTensor2>& f, const diagTensor2& s1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator / ( const diagTensor2& s1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator / ( const diagTensor2& s1, const tmp<Field<sphericalTensor2>>& tf2 ); 
	void divide ( Field<diagTensor2>& f, const UList<diagTensor2>& f1, const sphericalTensor2& s2 ); 
	tmp<Field<diagTensor2>> operator / ( const UList<diagTensor2>& f1, const sphericalTensor2& s2 ); 
	tmp<Field<diagTensor2>> operator / ( const tmp<Field<diagTensor2>>& tf1, const sphericalTensor2& s2 );  
	void add ( Field<diagTensor2>& f, const UList<diagTensor2>& f1, const UList<diagTensor2>& f2 );  
	tmp<Field<diagTensor2>> operator + ( const UList<diagTensor2>& f1, const UList<diagTensor2>& f2 );  
	tmp<Field<diagTensor2>> operator + ( const UList<diagTensor2>& f1, const tmp<Field<diagTensor2>>& tf2 );  
	tmp<Field<diagTensor2>> operator + ( const tmp<Field<diagTensor2>>& tf1, const UList<diagTensor2>& f2 );  
	tmp<Field<diagTensor2>> operator + ( const tmp<Field<diagTensor2>>& tf1, const tmp<Field<diagTensor2>>& tf2 );  
	void subtract ( Field<diagTensor2>& f, const UList<diagTensor2>& f1, const UList<diagTensor2>& f2 );  
	tmp<Field<diagTensor2>> operator - ( const UList<diagTensor2>& f1, const UList<diagTensor2>& f2 );
	tmp<Field<diagTensor2>> operator - ( const UList<diagTensor2>& f1, const tmp<Field<diagTensor2>>& tf2 ); 
	tmp<Field<diagTensor2>> operator - ( const tmp<Field<diagTensor2>>& tf1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator - ( const tmp<Field<diagTensor2>>& tf1, const tmp<Field<diagTensor2>>& tf2 ); 
	void add ( Field<diagTensor2>& f, const diagTensor2& s1, const UList<diagTensor2>& f2 );  
	tmp<Field<diagTensor2>> operator + ( const diagTensor2& s1, const UList<diagTensor2>& f2 );  
	tmp<Field<diagTensor2>> operator + ( const diagTensor2& s1, const tmp<Field<diagTensor2>>& tf2 );  
	void add ( Field<diagTensor2>& f, const UList<diagTensor2>& f1, const diagTensor2& s2 );  
	tmp<Field<diagTensor2>> operator + ( const UList<diagTensor2>& f1, const diagTensor2& s2 );  
	tmp<Field<diagTensor2>> operator + ( const tmp<Field<diagTensor2>>& tf1, const diagTensor2& s2 );
	void subtract ( Field<diagTensor2>& f, const diagTensor2& s1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator - ( const diagTensor2& s1, const UList<diagTensor2>& f2 );  
	tmp<Field<diagTensor2>> operator - ( const diagTensor2& s1, const tmp<Field<diagTensor2>>& tf2 );  
	void subtract ( Field<diagTensor2>& f, const UList<diagTensor2>& f1, const diagTensor2& s2 );  
	tmp<Field<diagTensor2>> operator - ( const UList<diagTensor2>& f1, const diagTensor2& s2 ); 
	tmp<Field<diagTensor2>> operator - ( const tmp<Field<diagTensor2>>& tf1, const diagTensor2& s2 );  
	void add ( Field<diagTensor2>& f, const UList<sphericalTensor2>& f1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator + ( const UList<sphericalTensor2>& f1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator + ( const UList<sphericalTensor2>& f1, const tmp<Field<diagTensor2>>& tf2 ); 
	tmp<Field<diagTensor2>> operator + ( const tmp<Field<sphericalTensor2>>& tf1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator + ( const tmp<Field<sphericalTensor2>>& tf1, const tmp<Field<diagTensor2>>& tf2 );
	void subtract ( Field<diagTensor2>& f, const UList<sphericalTensor2>& f1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator - ( const UList<sphericalTensor2>& f1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator - ( const UList<sphericalTensor2>& f1, const tmp<Field<diagTensor2>>& tf2 ); 
	tmp<Field<diagTensor2>> operator - ( const tmp<Field<sphericalTensor2>>& tf1, const UList<diagTensor2>& f2 );
	tmp<Field<diagTensor2>> operator - ( const tmp<Field<sphericalTensor2>>& tf1, const tmp<Field<diagTensor2>>& tf2 );
	void add ( Field<diagTensor2>& f, const sphericalTensor2& s1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator + ( const sphericalTensor2& s1, const UList<diagTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator + ( const sphericalTensor2& s1, const tmp<Field<diagTensor2>>& tf2 ); 
	void add ( Field<diagTensor2>& f, const UList<sphericalTensor2>& f1, const diagTensor2& s2 );
	tmp<Field<diagTensor2>> operator + ( const UList<sphericalTensor2>& f1, const diagTensor2& s2 );  
	tmp<Field<diagTensor2>> operator + ( const tmp<Field<sphericalTensor2>>& tf1, const diagTensor2& s2 ); 
	void subtract ( Field<diagTensor2>& f, const sphericalTensor2& s1, const UList<diagTensor2>& f2 );
	tmp<Field<diagTensor2>> operator - ( const sphericalTensor2& s1, const UList<diagTensor2>& f2 );  
	tmp<Field<diagTensor2>> operator - ( const sphericalTensor2& s1, const tmp<Field<diagTensor2>>& tf2 );
	void subtract ( Field<diagTensor2>& f, const UList<sphericalTensor2>& f1, const diagTensor2& s2 );  
	tmp<Field<diagTensor2>> operator - ( const UList<sphericalTensor2>& f1, const diagTensor2& s2 ); 
	tmp<Field<diagTensor2>> operator - ( const tmp<Field<sphericalTensor2>>& tf1, const diagTensor2& s2 );
	void add ( Field<diagTensor2>& f, const UList<diagTensor2>& f1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator + ( const UList<diagTensor2>& f1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator + ( const UList<diagTensor2>& f1, const tmp<Field<sphericalTensor2>>& tf2 ); 
	tmp<Field<diagTensor2>> operator + ( const tmp<Field<diagTensor2>>& tf1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator + ( const tmp<Field<diagTensor2>>& tf1, const tmp<Field<sphericalTensor2>>& tf2 );  
	void subtract ( Field<diagTensor2>& f, const UList<diagTensor2>& f1, const UList<sphericalTensor2>& f2 );  
	tmp<Field<diagTensor2>> operator - ( const UList<diagTensor2>& f1, const UList<sphericalTensor2>& f2 );  
	tmp<Field<diagTensor2>> operator - ( const UList<diagTensor2>& f1, const tmp<Field<sphericalTensor2>>& tf2 ); 
	tmp<Field<diagTensor2>> operator - ( const tmp<Field<diagTensor2>>& tf1, const UList<sphericalTensor2>& f2 );  
	tmp<Field<diagTensor2>> operator - ( const tmp<Field<diagTensor2>>& tf1, const tmp<Field<sphericalTensor2>>& tf2 );
	void add ( Field<diagTensor2>& f, const diagTensor2& s1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator + ( const diagTensor2& s1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator + ( const diagTensor2& s1, const tmp<Field<sphericalTensor2>>& tf2 ); 
	void add ( Field<diagTensor2>& f, const UList<diagTensor2>& f1, const sphericalTensor2& s2 ); 
	tmp<Field<diagTensor2>> operator + ( const UList<diagTensor2>& f1, const sphericalTensor2& s2 );  
	tmp<Field<diagTensor2>> operator + ( const tmp<Field<diagTensor2>>& tf1, const sphericalTensor2& s2 );
	void subtract ( Field<diagTensor2>& f, const diagTensor2& s1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator - ( const diagTensor2& s1, const UList<sphericalTensor2>& f2 ); 
	tmp<Field<diagTensor2>> operator - ( const diagTensor2& s1, const tmp<Field<sphericalTensor2>>& tf2 );
	void subtract ( Field<diagTensor2>& f, const UList<diagTensor2>& f1, const sphericalTensor2& s2 );  
	tmp<Field<diagTensor2>> operator - ( const UList<diagTensor2>& f1, const sphericalTensor2& s2 ); 
	tmp<Field<diagTensor2>> operator - ( const tmp<Field<diagTensor2>>& tf1, const sphericalTensor2& s2 );

	 void inv(Field<diagTensor3>& res, const UList<diagTensor3>& f);

	tmp<Field<diagTensor3>> inv(const UList<diagTensor3>& f);

	tmp<Field<diagTensor3>> inv(const tmp<Field<diagTensor3>>& tf);

	void diag(Field<diagTensor3>& res, const UList<diagTensor3>& f);

	tmp<Field<diagTensor3>> diag(const UList<diagTensor3>& f);

	tmp<Field<diagTensor3>> diag(const tmp<Field<diagTensor3>>& tf);

	void divide(Field<diagTensor3>& f, const UList<scalar>& f1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const UList<scalar>& f1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const UList<scalar>& f1, const tmp<Field<diagTensor3>>& tf2);

	tmp<Field<diagTensor3>> operator /(const tmp<Field<scalar>>& tf1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const tmp<Field<scalar>>& tf1, const tmp<Field<diagTensor3>>& tf2);

	void divide(Field<diagTensor3>& f, const scalar& s1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const scalar& s1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const scalar& s1, const tmp<Field<diagTensor3>>& tf2);

	void divide(Field<diagTensor3>& f, const UList<scalar>& f1, const diagTensor3& s2);

	tmp<Field<diagTensor3>> operator /(const UList<scalar>& f1, const diagTensor3& s2);

	tmp<Field<diagTensor3>> operator /(const tmp<Field<scalar>>& tf1, const diagTensor3& s2);

	void divide(Field<vector3>& f, const UList<vector3>& f1, const UList<diagTensor3>& f2);

	tmp<Field<vector3>> operator /(const UList<vector3>& f1, const UList<diagTensor3>& f2);

	tmp<Field<vector3>> operator /(const UList<vector3>& f1, const tmp<Field<diagTensor3>>& tf2);

	tmp<Field<vector3>> operator /(const tmp<Field<vector3>>& tf1, const UList<diagTensor3>& f2);

	tmp<Field<vector3>> operator /(const tmp<Field<vector3>>& tf1, const tmp<Field<diagTensor3>>& tf2);

	void divide(Field<vector3>& f, const vector3& s1, const UList<diagTensor3>& f2);

	tmp<Field<vector3>> operator /(const vector3& s1, const UList<diagTensor3>& f2);

	tmp<Field<vector3>> operator /(const vector3& s1, const tmp<Field<diagTensor3>>& tf2);

	void divide(Field<vector3>& f, const UList<vector3>& f1, const diagTensor3& s2);

	tmp<Field<vector3>> operator /(const UList<vector3>& f1, const diagTensor3& s2);

	tmp<Field<vector3>> operator /(const tmp<Field<vector3>>& tf1, const diagTensor3& s2);

	void divide(Field<diagTensor3>& f, const UList<diagTensor3>& f1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const UList<diagTensor3>& f1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const UList<diagTensor3>& f1, const tmp<Field<diagTensor3>>& tf2);

	tmp<Field<diagTensor3>> operator /(const tmp<Field<diagTensor3>>& tf1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const tmp<Field<diagTensor3>>& tf1, const tmp<Field<diagTensor3>>& tf2);

	void divide(Field<diagTensor3>& f, const diagTensor3& s1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const diagTensor3& s1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const diagTensor3& s1, const tmp<Field<diagTensor3>>& tf2);

	void divide(Field<diagTensor3>& f, const UList<diagTensor3>& f1, const diagTensor3& s2);

	tmp<Field<diagTensor3>> operator /(const UList<diagTensor3>& f1, const diagTensor3& s2);

	tmp<Field<diagTensor3>> operator /(const tmp<Field<diagTensor3>>& tf1, const diagTensor3& s2);

	void divide(Field<diagTensor3>& f, const UList<sphericalTensor3>& f1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const UList<sphericalTensor3>& f1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const UList<sphericalTensor3>& f1, const tmp<Field<diagTensor3>>& tf2);

	tmp<Field<diagTensor3>> operator /(const tmp<Field<sphericalTensor3>>& tf1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const tmp<Field<sphericalTensor3>>& tf1, const tmp<Field<diagTensor3>>& tf2);

	void divide(Field<diagTensor3>& f, const sphericalTensor3& s1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const sphericalTensor3& s1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const sphericalTensor3& s1, const tmp<Field<diagTensor3>>& tf2);

	void divide(Field<diagTensor3>& f, const UList<sphericalTensor3>& f1, const diagTensor3& s2);

	tmp<Field<diagTensor3>> operator /(const UList<sphericalTensor3>& f1, const diagTensor3& s2);

	tmp<Field<diagTensor3>> operator /(const tmp<Field<sphericalTensor3>>& tf1, const diagTensor3& s2);

	void divide(Field<diagTensor3>& f, const UList<diagTensor3>& f1, const UList<sphericalTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const UList<diagTensor3>& f1, const UList<sphericalTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const UList<diagTensor3>& f1, const tmp<Field<sphericalTensor3>>& tf2);

	tmp<Field<diagTensor3>> operator /(const tmp<Field<diagTensor3>>& tf1, const UList<sphericalTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const tmp<Field<diagTensor3>>& tf1, const tmp<Field<sphericalTensor3>>& tf2);

	void divide(Field<diagTensor3>& f, const diagTensor3& s1, const UList<sphericalTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const diagTensor3& s1, const UList<sphericalTensor3>& f2);

	tmp<Field<diagTensor3>> operator /(const diagTensor3& s1, const tmp<Field<sphericalTensor3>>& tf2);

	void divide(Field<diagTensor3>& f, const UList<diagTensor3>& f1, const sphericalTensor3& s2);

	tmp<Field<diagTensor3>> operator /(const UList<diagTensor3>& f1, const sphericalTensor3& s2);

	tmp<Field<diagTensor3>> operator /(const tmp<Field<diagTensor3>>& tf1, const sphericalTensor3& s2);

	void add(Field<diagTensor3>& f, const UList<diagTensor3>& f1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator +(const UList<diagTensor3>& f1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator +(const UList<diagTensor3>& f1, const tmp<Field<diagTensor3>>& tf2);

	tmp<Field<diagTensor3>> operator +(const tmp<Field<diagTensor3>>& tf1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator +(const tmp<Field<diagTensor3>>& tf1, const tmp<Field<diagTensor3>>& tf2);

	void subtract(Field<diagTensor3>& f, const UList<diagTensor3>& f1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator -(const UList<diagTensor3>& f1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator -(const UList<diagTensor3>& f1, const tmp<Field<diagTensor3>>& tf2);

	tmp<Field<diagTensor3>> operator -(const tmp<Field<diagTensor3>>& tf1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator -(const tmp<Field<diagTensor3>>& tf1, const tmp<Field<diagTensor3>>& tf2);

	void add(Field<diagTensor3>& f, const diagTensor3& s1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator +(const diagTensor3& s1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator +(const diagTensor3& s1, const tmp<Field<diagTensor3>>& tf2);

	void add(Field<diagTensor3>& f, const UList<diagTensor3>& f1, const diagTensor3& s2);

	tmp<Field<diagTensor3>> operator +(const UList<diagTensor3>& f1, const diagTensor3& s2);

	tmp<Field<diagTensor3>> operator +(const tmp<Field<diagTensor3>>& tf1, const diagTensor3& s2);

	void subtract(Field<diagTensor3>& f, const diagTensor3& s1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator -(const diagTensor3& s1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator -(const diagTensor3& s1, const tmp<Field<diagTensor3>>& tf2);

	void subtract(Field<diagTensor3>& f, const UList<diagTensor3>& f1, const diagTensor3& s2);

	tmp<Field<diagTensor3>> operator -(const UList<diagTensor3>& f1, const diagTensor3& s2);

	tmp<Field<diagTensor3>> operator -(const tmp<Field<diagTensor3>>& tf1, const diagTensor3& s2);

	void add(Field<diagTensor3>& f, const UList<sphericalTensor3>& f1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator +(const UList<sphericalTensor3>& f1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator +(const UList<sphericalTensor3>& f1, const tmp<Field<diagTensor3>>& tf2);

	tmp<Field<diagTensor3>> operator +(const tmp<Field<sphericalTensor3>>& tf1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator +(const tmp<Field<sphericalTensor3>>& tf1, const tmp<Field<diagTensor3>>& tf2);

	void subtract(Field<diagTensor3>& f, const UList<sphericalTensor3>& f1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator -(const UList<sphericalTensor3>& f1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator -(const UList<sphericalTensor3>& f1, const tmp<Field<diagTensor3>>& tf2);

	tmp<Field<diagTensor3>> operator -(const tmp<Field<sphericalTensor3>>& tf1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator -(const tmp<Field<sphericalTensor3>>& tf1, const tmp<Field<diagTensor3>>& tf2);

	void add(Field<diagTensor3>& f, const sphericalTensor3& s1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator +(const sphericalTensor3& s1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator +(const sphericalTensor3& s1, const tmp<Field<diagTensor3>>& tf2);

	void add(Field<diagTensor3>& f, const UList<sphericalTensor3>& f1, const diagTensor3& s2);

	tmp<Field<diagTensor3>> operator +(const UList<sphericalTensor3>& f1, const diagTensor3& s2);

	tmp<Field<diagTensor3>> operator +(const tmp<Field<sphericalTensor3>>& tf1, const diagTensor3& s2);

	void subtract(Field<diagTensor3>& f, const sphericalTensor3& s1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator -(const sphericalTensor3& s1, const UList<diagTensor3>& f2);

	tmp<Field<diagTensor3>> operator -(const sphericalTensor3& s1, const tmp<Field<diagTensor3>>& tf2);

	void subtract(Field<diagTensor3>& f, const UList<sphericalTensor3>& f1, const diagTensor3& s2);

	tmp<Field<diagTensor3>> operator -(const UList<sphericalTensor3>& f1, const diagTensor3& s2);

	tmp<Field<diagTensor3>> operator -(const tmp<Field<sphericalTensor3>>& tf1, const diagTensor3& s2);

	void add(Field<diagTensor3>& f, const UList<diagTensor3>& f1, const UList<sphericalTensor3>& f2);

	tmp<Field<diagTensor3>> operator +(const UList<diagTensor3>& f1, const UList<sphericalTensor3>& f2);

	tmp<Field<diagTensor3>> operator +(const UList<diagTensor3>& f1, const tmp<Field<sphericalTensor3>>& tf2);

	tmp<Field<diagTensor3>> operator +(const tmp<Field<diagTensor3>>& tf1, const UList<sphericalTensor3>& f2);

	tmp<Field<diagTensor3>> operator +(const tmp<Field<diagTensor3>>& tf1, const tmp<Field<sphericalTensor3>>& tf2);

	void subtract(Field<diagTensor3>& f, const UList<diagTensor3>& f1, const UList<sphericalTensor3>& f2);

	tmp<Field<diagTensor3>> operator -(const UList<diagTensor3>& f1, const UList<sphericalTensor3>& f2);

	tmp<Field<diagTensor3>> operator -(const UList<diagTensor3>& f1, const tmp<Field<sphericalTensor3>>& tf2);

	tmp<Field<diagTensor3>> operator -(const tmp<Field<diagTensor3>>& tf1, const UList<sphericalTensor3>& f2);

	tmp<Field<diagTensor3>> operator -(const tmp<Field<diagTensor3>>& tf1, const tmp<Field<sphericalTensor3>>& tf2);

	void add(Field<diagTensor3>& f, const diagTensor3& s1, const UList<sphericalTensor3>& f2);

	tmp<Field<diagTensor3>> operator +(const diagTensor3& s1, const UList<sphericalTensor3>& f2);

	tmp<Field<diagTensor3>> operator +(const diagTensor3& s1, const tmp<Field<sphericalTensor3>>& tf2);

	void add(Field<diagTensor3>& f, const UList<diagTensor3>& f1, const sphericalTensor3& s2);

	tmp<Field<diagTensor3>> operator +(const UList<diagTensor3>& f1, const sphericalTensor3& s2);

	tmp<Field<diagTensor3>> operator +(const tmp<Field<diagTensor3>>& tf1, const sphericalTensor3& s2);

	void subtract(Field<diagTensor3>& f, const diagTensor3& s1, const UList<sphericalTensor3>& f2);

	tmp<Field<diagTensor3>> operator -(const diagTensor3& s1, const UList<sphericalTensor3>& f2);

	tmp<Field<diagTensor3>> operator -(const diagTensor3& s1, const tmp<Field<sphericalTensor3>>& tf2);

	void subtract(Field<diagTensor3>& f, const UList<diagTensor3>& f1, const sphericalTensor3& s2);

	tmp<Field<diagTensor3>> operator -(const UList<diagTensor3>& f1, const sphericalTensor3& s2);

	tmp<Field<diagTensor3>> operator -(const tmp<Field<diagTensor3>>& tf1, const sphericalTensor3& s2);

	 
	void inv(Field<diagTensor4>& res, const UList<diagTensor4>& f);

	tmp<Field<diagTensor4>> inv(const UList<diagTensor4>& f);

	tmp<Field<diagTensor4>> inv(const tmp<Field<diagTensor4>>& tf);

	void diag(Field<diagTensor4>& res, const UList<diagTensor4>& f);

	tmp<Field<diagTensor4>> diag(const UList<diagTensor4>& f);

	tmp<Field<diagTensor4>> diag(const tmp<Field<diagTensor4>>& tf);

	void divide(Field<diagTensor4>& f, const UList<scalar>& f1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const UList<scalar>& f1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const UList<scalar>& f1, const tmp<Field<diagTensor4>>& tf2);

	tmp<Field<diagTensor4>> operator /(const tmp<Field<scalar>>& tf1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const tmp<Field<scalar>>& tf1, const tmp<Field<diagTensor4>>& tf2);

	void divide(Field<diagTensor4>& f, const scalar& s1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const scalar& s1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const scalar& s1, const tmp<Field<diagTensor4>>& tf2);

	void divide(Field<diagTensor4>& f, const UList<scalar>& f1, const diagTensor4& s2);

	tmp<Field<diagTensor4>> operator /(const UList<scalar>& f1, const diagTensor4& s2);

	tmp<Field<diagTensor4>> operator /(const tmp<Field<scalar>>& tf1, const diagTensor4& s2);

	void divide(Field<vector4>& f, const UList<vector4>& f1, const UList<diagTensor4>& f2);

	tmp<Field<vector4>> operator /(const UList<vector4>& f1, const UList<diagTensor4>& f2);

	tmp<Field<vector4>> operator /(const UList<vector4>& f1, const tmp<Field<diagTensor4>>& tf2);

	tmp<Field<vector4>> operator /(const tmp<Field<vector4>>& tf1, const UList<diagTensor4>& f2);

	tmp<Field<vector4>> operator /(const tmp<Field<vector4>>& tf1, const tmp<Field<diagTensor4>>& tf2);

	void divide(Field<vector4>& f, const vector4& s1, const UList<diagTensor4>& f2);

	tmp<Field<vector4>> operator /(const vector4& s1, const UList<diagTensor4>& f2);

	tmp<Field<vector4>> operator /(const vector4& s1, const tmp<Field<diagTensor4>>& tf2);

	void divide(Field<vector4>& f, const UList<vector4>& f1, const diagTensor4& s2);

	tmp<Field<vector4>> operator /(const UList<vector4>& f1, const diagTensor4& s2);

	tmp<Field<vector4>> operator /(const tmp<Field<vector4>>& tf1, const diagTensor4& s2);

	void divide(Field<diagTensor4>& f, const UList<diagTensor4>& f1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const UList<diagTensor4>& f1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const UList<diagTensor4>& f1, const tmp<Field<diagTensor4>>& tf2);

	tmp<Field<diagTensor4>> operator /(const tmp<Field<diagTensor4>>& tf1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const tmp<Field<diagTensor4>>& tf1, const tmp<Field<diagTensor4>>& tf2);

	void divide(Field<diagTensor4>& f, const diagTensor4& s1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const diagTensor4& s1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const diagTensor4& s1, const tmp<Field<diagTensor4>>& tf2);

	void divide(Field<diagTensor4>& f, const UList<diagTensor4>& f1, const diagTensor4& s2);

	tmp<Field<diagTensor4>> operator /(const UList<diagTensor4>& f1, const diagTensor4& s2);

	tmp<Field<diagTensor4>> operator /(const tmp<Field<diagTensor4>>& tf1, const diagTensor4& s2);

	void divide(Field<diagTensor4>& f, const UList<sphericalTensor4>& f1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const UList<sphericalTensor4>& f1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const UList<sphericalTensor4>& f1, const tmp<Field<diagTensor4>>& tf2);

	tmp<Field<diagTensor4>> operator /(const tmp<Field<sphericalTensor4>>& tf1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const tmp<Field<sphericalTensor4>>& tf1, const tmp<Field<diagTensor4>>& tf2);

	void divide(Field<diagTensor4>& f, const sphericalTensor4& s1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const sphericalTensor4& s1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const sphericalTensor4& s1, const tmp<Field<diagTensor4>>& tf2);

	void divide(Field<diagTensor4>& f, const UList<sphericalTensor4>& f1, const diagTensor4& s2);

	tmp<Field<diagTensor4>> operator /(const UList<sphericalTensor4>& f1, const diagTensor4& s2);

	tmp<Field<diagTensor4>> operator /(const tmp<Field<sphericalTensor4>>& tf1, const diagTensor4& s2);

	void divide(Field<diagTensor4>& f, const UList<diagTensor4>& f1, const UList<sphericalTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const UList<diagTensor4>& f1, const UList<sphericalTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const UList<diagTensor4>& f1, const tmp<Field<sphericalTensor4>>& tf2);

	tmp<Field<diagTensor4>> operator /(const tmp<Field<diagTensor4>>& tf1, const UList<sphericalTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const tmp<Field<diagTensor4>>& tf1, const tmp<Field<sphericalTensor4>>& tf2);

	void divide(Field<diagTensor4>& f, const diagTensor4& s1, const UList<sphericalTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const diagTensor4& s1, const UList<sphericalTensor4>& f2);

	tmp<Field<diagTensor4>> operator /(const diagTensor4& s1, const tmp<Field<sphericalTensor4>>& tf2);

	void divide(Field<diagTensor4>& f, const UList<diagTensor4>& f1, const sphericalTensor4& s2);

	tmp<Field<diagTensor4>> operator /(const UList<diagTensor4>& f1, const sphericalTensor4& s2);

	tmp<Field<diagTensor4>> operator /(const tmp<Field<diagTensor4>>& tf1, const sphericalTensor4& s2);

	void add(Field<diagTensor4>& f, const UList<diagTensor4>& f1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator +(const UList<diagTensor4>& f1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator +(const UList<diagTensor4>& f1, const tmp<Field<diagTensor4>>& tf2);

	tmp<Field<diagTensor4>> operator +(const tmp<Field<diagTensor4>>& tf1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator +(const tmp<Field<diagTensor4>>& tf1, const tmp<Field<diagTensor4>>& tf2);

	void subtract(Field<diagTensor4>& f, const UList<diagTensor4>& f1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator -(const UList<diagTensor4>& f1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator -(const UList<diagTensor4>& f1, const tmp<Field<diagTensor4>>& tf2);

	tmp<Field<diagTensor4>> operator -(const tmp<Field<diagTensor4>>& tf1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator -(const tmp<Field<diagTensor4>>& tf1, const tmp<Field<diagTensor4>>& tf2);

	void add(Field<diagTensor4>& f, const diagTensor4& s1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator +(const diagTensor4& s1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator +(const diagTensor4& s1, const tmp<Field<diagTensor4>>& tf2);

	void add(Field<diagTensor4>& f, const UList<diagTensor4>& f1, const diagTensor4& s2);

	tmp<Field<diagTensor4>> operator +(const UList<diagTensor4>& f1, const diagTensor4& s2);

	tmp<Field<diagTensor4>> operator +(const tmp<Field<diagTensor4>>& tf1, const diagTensor4& s2);

	void subtract(Field<diagTensor4>& f, const diagTensor4& s1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator -(const diagTensor4& s1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator -(const diagTensor4& s1, const tmp<Field<diagTensor4>>& tf2);

	void subtract(Field<diagTensor4>& f, const UList<diagTensor4>& f1, const diagTensor4& s2);

	tmp<Field<diagTensor4>> operator -(const UList<diagTensor4>& f1, const diagTensor4& s2);

	tmp<Field<diagTensor4>> operator -(const tmp<Field<diagTensor4>>& tf1, const diagTensor4& s2);

	void add(Field<diagTensor4>& f, const UList<sphericalTensor4>& f1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator +(const UList<sphericalTensor4>& f1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator +(const UList<sphericalTensor4>& f1, const tmp<Field<diagTensor4>>& tf2);

	tmp<Field<diagTensor4>> operator +(const tmp<Field<sphericalTensor4>>& tf1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator +(const tmp<Field<sphericalTensor4>>& tf1, const tmp<Field<diagTensor4>>& tf2);

	void subtract(Field<diagTensor4>& f, const UList<sphericalTensor4>& f1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator -(const UList<sphericalTensor4>& f1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator -(const UList<sphericalTensor4>& f1, const tmp<Field<diagTensor4>>& tf2);

	tmp<Field<diagTensor4>> operator -(const tmp<Field<sphericalTensor4>>& tf1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator -(const tmp<Field<sphericalTensor4>>& tf1, const tmp<Field<diagTensor4>>& tf2);

	void add(Field<diagTensor4>& f, const sphericalTensor4& s1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator +(const sphericalTensor4& s1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator +(const sphericalTensor4& s1, const tmp<Field<diagTensor4>>& tf2);

	void add(Field<diagTensor4>& f, const UList<sphericalTensor4>& f1, const diagTensor4& s2);

	tmp<Field<diagTensor4>> operator +(const UList<sphericalTensor4>& f1, const diagTensor4& s2);

	tmp<Field<diagTensor4>> operator +(const tmp<Field<sphericalTensor4>>& tf1, const diagTensor4& s2);

	void subtract(Field<diagTensor4>& f, const sphericalTensor4& s1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator -(const sphericalTensor4& s1, const UList<diagTensor4>& f2);

	tmp<Field<diagTensor4>> operator -(const sphericalTensor4& s1, const tmp<Field<diagTensor4>>& tf2);

	void subtract(Field<diagTensor4>& f, const UList<sphericalTensor4>& f1, const diagTensor4& s2);

	tmp<Field<diagTensor4>> operator -(const UList<sphericalTensor4>& f1, const diagTensor4& s2);

	tmp<Field<diagTensor4>> operator -(const tmp<Field<sphericalTensor4>>& tf1, const diagTensor4& s2);

	void add(Field<diagTensor4>& f, const UList<diagTensor4>& f1, const UList<sphericalTensor4>& f2);

	tmp<Field<diagTensor4>> operator +(const UList<diagTensor4>& f1, const UList<sphericalTensor4>& f2);

	tmp<Field<diagTensor4>> operator +(const UList<diagTensor4>& f1, const tmp<Field<sphericalTensor4>>& tf2);

	tmp<Field<diagTensor4>> operator +(const tmp<Field<diagTensor4>>& tf1, const UList<sphericalTensor4>& f2);

	tmp<Field<diagTensor4>> operator +(const tmp<Field<diagTensor4>>& tf1, const tmp<Field<sphericalTensor4>>& tf2);

	void subtract(Field<diagTensor4>& f, const UList<diagTensor4>& f1, const UList<sphericalTensor4>& f2);

	tmp<Field<diagTensor4>> operator -(const UList<diagTensor4>& f1, const UList<sphericalTensor4>& f2);

	tmp<Field<diagTensor4>> operator -(const UList<diagTensor4>& f1, const tmp<Field<sphericalTensor4>>& tf2);

	tmp<Field<diagTensor4>> operator -(const tmp<Field<diagTensor4>>& tf1, const UList<sphericalTensor4>& f2);

	tmp<Field<diagTensor4>> operator -(const tmp<Field<diagTensor4>>& tf1, const tmp<Field<sphericalTensor4>>& tf2);

	void add(Field<diagTensor4>& f, const diagTensor4& s1, const UList<sphericalTensor4>& f2);

	tmp<Field<diagTensor4>> operator +(const diagTensor4& s1, const UList<sphericalTensor4>& f2);

	tmp<Field<diagTensor4>> operator +(const diagTensor4& s1, const tmp<Field<sphericalTensor4>>& tf2);

	void add(Field<diagTensor4>& f, const UList<diagTensor4>& f1, const sphericalTensor4& s2);

	tmp<Field<diagTensor4>> operator +(const UList<diagTensor4>& f1, const sphericalTensor4& s2);

	tmp<Field<diagTensor4>> operator +(const tmp<Field<diagTensor4>>& tf1, const sphericalTensor4& s2);

	void subtract(Field<diagTensor4>& f, const diagTensor4& s1, const UList<sphericalTensor4>& f2);

	tmp<Field<diagTensor4>> operator -(const diagTensor4& s1, const UList<sphericalTensor4>& f2);

	tmp<Field<diagTensor4>> operator -(const diagTensor4& s1, const tmp<Field<sphericalTensor4>>& tf2);

	void subtract(Field<diagTensor4>& f, const UList<diagTensor4>& f1, const sphericalTensor4& s2);

	tmp<Field<diagTensor4>> operator -(const UList<diagTensor4>& f1, const sphericalTensor4& s2);

	tmp<Field<diagTensor4>> operator -(const tmp<Field<diagTensor4>>& tf1, const sphericalTensor4& s2);

	 
	void inv(Field<diagTensor6>& res, const UList<diagTensor6>& f);

	tmp<Field<diagTensor6>> inv(const UList<diagTensor6>& f);

	tmp<Field<diagTensor6>> inv(const tmp<Field<diagTensor6>>& tf);

	void diag(Field<diagTensor6>& res, const UList<diagTensor6>& f);

	tmp<Field<diagTensor6>> diag(const UList<diagTensor6>& f);

	tmp<Field<diagTensor6>> diag(const tmp<Field<diagTensor6>>& tf);

	void divide(Field<diagTensor6>& f, const UList<scalar>& f1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const UList<scalar>& f1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const UList<scalar>& f1, const tmp<Field<diagTensor6>>& tf2);

	tmp<Field<diagTensor6>> operator /(const tmp<Field<scalar>>& tf1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const tmp<Field<scalar>>& tf1, const tmp<Field<diagTensor6>>& tf2);

	void divide(Field<diagTensor6>& f, const scalar& s1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const scalar& s1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const scalar& s1, const tmp<Field<diagTensor6>>& tf2);

	void divide(Field<diagTensor6>& f, const UList<scalar>& f1, const diagTensor6& s2);

	tmp<Field<diagTensor6>> operator /(const UList<scalar>& f1, const diagTensor6& s2);

	tmp<Field<diagTensor6>> operator /(const tmp<Field<scalar>>& tf1, const diagTensor6& s2);

	void divide(Field<vector6>& f, const UList<vector6>& f1, const UList<diagTensor6>& f2);

	tmp<Field<vector6>> operator /(const UList<vector6>& f1, const UList<diagTensor6>& f2);

	tmp<Field<vector6>> operator /(const UList<vector6>& f1, const tmp<Field<diagTensor6>>& tf2);

	tmp<Field<vector6>> operator /(const tmp<Field<vector6>>& tf1, const UList<diagTensor6>& f2);

	tmp<Field<vector6>> operator /(const tmp<Field<vector6>>& tf1, const tmp<Field<diagTensor6>>& tf2);

	void divide(Field<vector6>& f, const vector6& s1, const UList<diagTensor6>& f2);

	tmp<Field<vector6>> operator /(const vector6& s1, const UList<diagTensor6>& f2);

	tmp<Field<vector6>> operator /(const vector6& s1, const tmp<Field<diagTensor6>>& tf2);

	void divide(Field<vector6>& f, const UList<vector6>& f1, const diagTensor6& s2);

	tmp<Field<vector6>> operator /(const UList<vector6>& f1, const diagTensor6& s2);

	tmp<Field<vector6>> operator /(const tmp<Field<vector6>>& tf1, const diagTensor6& s2);

	void divide(Field<diagTensor6>& f, const UList<diagTensor6>& f1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const UList<diagTensor6>& f1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const UList<diagTensor6>& f1, const tmp<Field<diagTensor6>>& tf2);

	tmp<Field<diagTensor6>> operator /(const tmp<Field<diagTensor6>>& tf1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const tmp<Field<diagTensor6>>& tf1, const tmp<Field<diagTensor6>>& tf2);

	void divide(Field<diagTensor6>& f, const diagTensor6& s1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const diagTensor6& s1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const diagTensor6& s1, const tmp<Field<diagTensor6>>& tf2);

	void divide(Field<diagTensor6>& f, const UList<diagTensor6>& f1, const diagTensor6& s2);

	tmp<Field<diagTensor6>> operator /(const UList<diagTensor6>& f1, const diagTensor6& s2);

	tmp<Field<diagTensor6>> operator /(const tmp<Field<diagTensor6>>& tf1, const diagTensor6& s2);

	void divide(Field<diagTensor6>& f, const UList<sphericalTensor6>& f1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const UList<sphericalTensor6>& f1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const UList<sphericalTensor6>& f1, const tmp<Field<diagTensor6>>& tf2);

	tmp<Field<diagTensor6>> operator /(const tmp<Field<sphericalTensor6>>& tf1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const tmp<Field<sphericalTensor6>>& tf1, const tmp<Field<diagTensor6>>& tf2);

	void divide(Field<diagTensor6>& f, const sphericalTensor6& s1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const sphericalTensor6& s1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const sphericalTensor6& s1, const tmp<Field<diagTensor6>>& tf2);

	void divide(Field<diagTensor6>& f, const UList<sphericalTensor6>& f1, const diagTensor6& s2);

	tmp<Field<diagTensor6>> operator /(const UList<sphericalTensor6>& f1, const diagTensor6& s2);

	tmp<Field<diagTensor6>> operator /(const tmp<Field<sphericalTensor6>>& tf1, const diagTensor6& s2);

	void divide(Field<diagTensor6>& f, const UList<diagTensor6>& f1, const UList<sphericalTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const UList<diagTensor6>& f1, const UList<sphericalTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const UList<diagTensor6>& f1, const tmp<Field<sphericalTensor6>>& tf2);

	tmp<Field<diagTensor6>> operator /(const tmp<Field<diagTensor6>>& tf1, const UList<sphericalTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const tmp<Field<diagTensor6>>& tf1, const tmp<Field<sphericalTensor6>>& tf2);

	void divide(Field<diagTensor6>& f, const diagTensor6& s1, const UList<sphericalTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const diagTensor6& s1, const UList<sphericalTensor6>& f2);

	tmp<Field<diagTensor6>> operator /(const diagTensor6& s1, const tmp<Field<sphericalTensor6>>& tf2);

	void divide(Field<diagTensor6>& f, const UList<diagTensor6>& f1, const sphericalTensor6& s2);

	tmp<Field<diagTensor6>> operator /(const UList<diagTensor6>& f1, const sphericalTensor6& s2);

	tmp<Field<diagTensor6>> operator /(const tmp<Field<diagTensor6>>& tf1, const sphericalTensor6& s2);

	void add(Field<diagTensor6>& f, const UList<diagTensor6>& f1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator +(const UList<diagTensor6>& f1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator +(const UList<diagTensor6>& f1, const tmp<Field<diagTensor6>>& tf2);

	tmp<Field<diagTensor6>> operator +(const tmp<Field<diagTensor6>>& tf1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator +(const tmp<Field<diagTensor6>>& tf1, const tmp<Field<diagTensor6>>& tf2);

	void subtract(Field<diagTensor6>& f, const UList<diagTensor6>& f1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator -(const UList<diagTensor6>& f1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator -(const UList<diagTensor6>& f1, const tmp<Field<diagTensor6>>& tf2);

	tmp<Field<diagTensor6>> operator -(const tmp<Field<diagTensor6>>& tf1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator -(const tmp<Field<diagTensor6>>& tf1, const tmp<Field<diagTensor6>>& tf2);

	void add(Field<diagTensor6>& f, const diagTensor6& s1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator +(const diagTensor6& s1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator +(const diagTensor6& s1, const tmp<Field<diagTensor6>>& tf2);

	void add(Field<diagTensor6>& f, const UList<diagTensor6>& f1, const diagTensor6& s2);

	tmp<Field<diagTensor6>> operator +(const UList<diagTensor6>& f1, const diagTensor6& s2);

	tmp<Field<diagTensor6>> operator +(const tmp<Field<diagTensor6>>& tf1, const diagTensor6& s2);

	void subtract(Field<diagTensor6>& f, const diagTensor6& s1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator -(const diagTensor6& s1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator -(const diagTensor6& s1, const tmp<Field<diagTensor6>>& tf2);

	void subtract(Field<diagTensor6>& f, const UList<diagTensor6>& f1, const diagTensor6& s2);

	tmp<Field<diagTensor6>> operator -(const UList<diagTensor6>& f1, const diagTensor6& s2);

	tmp<Field<diagTensor6>> operator -(const tmp<Field<diagTensor6>>& tf1, const diagTensor6& s2);

	void add(Field<diagTensor6>& f, const UList<sphericalTensor6>& f1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator +(const UList<sphericalTensor6>& f1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator +(const UList<sphericalTensor6>& f1, const tmp<Field<diagTensor6>>& tf2);

	tmp<Field<diagTensor6>> operator +(const tmp<Field<sphericalTensor6>>& tf1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator +(const tmp<Field<sphericalTensor6>>& tf1, const tmp<Field<diagTensor6>>& tf2);

	void subtract(Field<diagTensor6>& f, const UList<sphericalTensor6>& f1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator -(const UList<sphericalTensor6>& f1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator -(const UList<sphericalTensor6>& f1, const tmp<Field<diagTensor6>>& tf2);

	tmp<Field<diagTensor6>> operator -(const tmp<Field<sphericalTensor6>>& tf1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator -(const tmp<Field<sphericalTensor6>>& tf1, const tmp<Field<diagTensor6>>& tf2);

	void add(Field<diagTensor6>& f, const sphericalTensor6& s1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator +(const sphericalTensor6& s1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator +(const sphericalTensor6& s1, const tmp<Field<diagTensor6>>& tf2);

	void add(Field<diagTensor6>& f, const UList<sphericalTensor6>& f1, const diagTensor6& s2);

	tmp<Field<diagTensor6>> operator +(const UList<sphericalTensor6>& f1, const diagTensor6& s2);

	tmp<Field<diagTensor6>> operator +(const tmp<Field<sphericalTensor6>>& tf1, const diagTensor6& s2);

	void subtract(Field<diagTensor6>& f, const sphericalTensor6& s1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator -(const sphericalTensor6& s1, const UList<diagTensor6>& f2);

	tmp<Field<diagTensor6>> operator -(const sphericalTensor6& s1, const tmp<Field<diagTensor6>>& tf2);

	void subtract(Field<diagTensor6>& f, const UList<sphericalTensor6>& f1, const diagTensor6& s2);

	tmp<Field<diagTensor6>> operator -(const UList<sphericalTensor6>& f1, const diagTensor6& s2);

	tmp<Field<diagTensor6>> operator -(const tmp<Field<sphericalTensor6>>& tf1, const diagTensor6& s2);

	void add(Field<diagTensor6>& f, const UList<diagTensor6>& f1, const UList<sphericalTensor6>& f2);

	tmp<Field<diagTensor6>> operator +(const UList<diagTensor6>& f1, const UList<sphericalTensor6>& f2);

	tmp<Field<diagTensor6>> operator +(const UList<diagTensor6>& f1, const tmp<Field<sphericalTensor6>>& tf2);

	tmp<Field<diagTensor6>> operator +(const tmp<Field<diagTensor6>>& tf1, const UList<sphericalTensor6>& f2);

	tmp<Field<diagTensor6>> operator +(const tmp<Field<diagTensor6>>& tf1, const tmp<Field<sphericalTensor6>>& tf2);

	void subtract(Field<diagTensor6>& f, const UList<diagTensor6>& f1, const UList<sphericalTensor6>& f2);

	tmp<Field<diagTensor6>> operator -(const UList<diagTensor6>& f1, const UList<sphericalTensor6>& f2);

	tmp<Field<diagTensor6>> operator -(const UList<diagTensor6>& f1, const tmp<Field<sphericalTensor6>>& tf2);

	tmp<Field<diagTensor6>> operator -(const tmp<Field<diagTensor6>>& tf1, const UList<sphericalTensor6>& f2);

	tmp<Field<diagTensor6>> operator -(const tmp<Field<diagTensor6>>& tf1, const tmp<Field<sphericalTensor6>>& tf2);

	void add(Field<diagTensor6>& f, const diagTensor6& s1, const UList<sphericalTensor6>& f2);

	tmp<Field<diagTensor6>> operator +(const diagTensor6& s1, const UList<sphericalTensor6>& f2);

	tmp<Field<diagTensor6>> operator +(const diagTensor6& s1, const tmp<Field<sphericalTensor6>>& tf2);

	void add(Field<diagTensor6>& f, const UList<diagTensor6>& f1, const sphericalTensor6& s2);

	tmp<Field<diagTensor6>> operator +(const UList<diagTensor6>& f1, const sphericalTensor6& s2);

	tmp<Field<diagTensor6>> operator +(const tmp<Field<diagTensor6>>& tf1, const sphericalTensor6& s2);

	void subtract(Field<diagTensor6>& f, const diagTensor6& s1, const UList<sphericalTensor6>& f2);

	tmp<Field<diagTensor6>> operator -(const diagTensor6& s1, const UList<sphericalTensor6>& f2);

	tmp<Field<diagTensor6>> operator -(const diagTensor6& s1, const tmp<Field<sphericalTensor6>>& tf2);

	void subtract(Field<diagTensor6>& f, const UList<diagTensor6>& f1, const sphericalTensor6& s2);

	tmp<Field<diagTensor6>> operator -(const UList<diagTensor6>& f1, const sphericalTensor6& s2);

	tmp<Field<diagTensor6>> operator -(const tmp<Field<diagTensor6>>& tf1, const sphericalTensor6& s2);

	 
	void inv(Field<diagTensor8>& res, const UList<diagTensor8>& f);

	tmp<Field<diagTensor8>> inv(const UList<diagTensor8>& f);

	tmp<Field<diagTensor8>> inv(const tmp<Field<diagTensor8>>& tf);

	void diag(Field<diagTensor8>& res, const UList<diagTensor8>& f);

	tmp<Field<diagTensor8>> diag(const UList<diagTensor8>& f);

	tmp<Field<diagTensor8>> diag(const tmp<Field<diagTensor8>>& tf);

	void divide(Field<diagTensor8>& f, const UList<scalar>& f1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const UList<scalar>& f1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const UList<scalar>& f1, const tmp<Field<diagTensor8>>& tf2);

	tmp<Field<diagTensor8>> operator /(const tmp<Field<scalar>>& tf1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const tmp<Field<scalar>>& tf1, const tmp<Field<diagTensor8>>& tf2);

	void divide(Field<diagTensor8>& f, const scalar& s1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const scalar& s1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const scalar& s1, const tmp<Field<diagTensor8>>& tf2);

	void divide(Field<diagTensor8>& f, const UList<scalar>& f1, const diagTensor8& s2);

	tmp<Field<diagTensor8>> operator /(const UList<scalar>& f1, const diagTensor8& s2);

	tmp<Field<diagTensor8>> operator /(const tmp<Field<scalar>>& tf1, const diagTensor8& s2);

	void divide(Field<vector8>& f, const UList<vector8>& f1, const UList<diagTensor8>& f2);

	tmp<Field<vector8>> operator /(const UList<vector8>& f1, const UList<diagTensor8>& f2);

	tmp<Field<vector8>> operator /(const UList<vector8>& f1, const tmp<Field<diagTensor8>>& tf2);

	tmp<Field<vector8>> operator /(const tmp<Field<vector8>>& tf1, const UList<diagTensor8>& f2);

	tmp<Field<vector8>> operator /(const tmp<Field<vector8>>& tf1, const tmp<Field<diagTensor8>>& tf2);

	void divide(Field<vector8>& f, const vector8& s1, const UList<diagTensor8>& f2);

	tmp<Field<vector8>> operator /(const vector8& s1, const UList<diagTensor8>& f2);

	tmp<Field<vector8>> operator /(const vector8& s1, const tmp<Field<diagTensor8>>& tf2);

	void divide(Field<vector8>& f, const UList<vector8>& f1, const diagTensor8& s2);

	tmp<Field<vector8>> operator /(const UList<vector8>& f1, const diagTensor8& s2);

	tmp<Field<vector8>> operator /(const tmp<Field<vector8>>& tf1, const diagTensor8& s2);

	void divide(Field<diagTensor8>& f, const UList<diagTensor8>& f1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const UList<diagTensor8>& f1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const UList<diagTensor8>& f1, const tmp<Field<diagTensor8>>& tf2);

	tmp<Field<diagTensor8>> operator /(const tmp<Field<diagTensor8>>& tf1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const tmp<Field<diagTensor8>>& tf1, const tmp<Field<diagTensor8>>& tf2);

	void divide(Field<diagTensor8>& f, const diagTensor8& s1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const diagTensor8& s1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const diagTensor8& s1, const tmp<Field<diagTensor8>>& tf2);

	void divide(Field<diagTensor8>& f, const UList<diagTensor8>& f1, const diagTensor8& s2);

	tmp<Field<diagTensor8>> operator /(const UList<diagTensor8>& f1, const diagTensor8& s2);

	tmp<Field<diagTensor8>> operator /(const tmp<Field<diagTensor8>>& tf1, const diagTensor8& s2);

	void divide(Field<diagTensor8>& f, const UList<sphericalTensor8>& f1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const UList<sphericalTensor8>& f1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const UList<sphericalTensor8>& f1, const tmp<Field<diagTensor8>>& tf2);

	tmp<Field<diagTensor8>> operator /(const tmp<Field<sphericalTensor8>>& tf1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const tmp<Field<sphericalTensor8>>& tf1, const tmp<Field<diagTensor8>>& tf2);

	void divide(Field<diagTensor8>& f, const sphericalTensor8& s1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const sphericalTensor8& s1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const sphericalTensor8& s1, const tmp<Field<diagTensor8>>& tf2);

	void divide(Field<diagTensor8>& f, const UList<sphericalTensor8>& f1, const diagTensor8& s2);

	tmp<Field<diagTensor8>> operator /(const UList<sphericalTensor8>& f1, const diagTensor8& s2);

	tmp<Field<diagTensor8>> operator /(const tmp<Field<sphericalTensor8>>& tf1, const diagTensor8& s2);

	void divide(Field<diagTensor8>& f, const UList<diagTensor8>& f1, const UList<sphericalTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const UList<diagTensor8>& f1, const UList<sphericalTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const UList<diagTensor8>& f1, const tmp<Field<sphericalTensor8>>& tf2);

	tmp<Field<diagTensor8>> operator /(const tmp<Field<diagTensor8>>& tf1, const UList<sphericalTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const tmp<Field<diagTensor8>>& tf1, const tmp<Field<sphericalTensor8>>& tf2);

	void divide(Field<diagTensor8>& f, const diagTensor8& s1, const UList<sphericalTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const diagTensor8& s1, const UList<sphericalTensor8>& f2);

	tmp<Field<diagTensor8>> operator /(const diagTensor8& s1, const tmp<Field<sphericalTensor8>>& tf2);

	void divide(Field<diagTensor8>& f, const UList<diagTensor8>& f1, const sphericalTensor8& s2);

	tmp<Field<diagTensor8>> operator /(const UList<diagTensor8>& f1, const sphericalTensor8& s2);

	tmp<Field<diagTensor8>> operator /(const tmp<Field<diagTensor8>>& tf1, const sphericalTensor8& s2);

	void add(Field<diagTensor8>& f, const UList<diagTensor8>& f1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator +(const UList<diagTensor8>& f1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator +(const UList<diagTensor8>& f1, const tmp<Field<diagTensor8>>& tf2);

	tmp<Field<diagTensor8>> operator +(const tmp<Field<diagTensor8>>& tf1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator +(const tmp<Field<diagTensor8>>& tf1, const tmp<Field<diagTensor8>>& tf2);

	void subtract(Field<diagTensor8>& f, const UList<diagTensor8>& f1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator -(const UList<diagTensor8>& f1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator -(const UList<diagTensor8>& f1, const tmp<Field<diagTensor8>>& tf2);

	tmp<Field<diagTensor8>> operator -(const tmp<Field<diagTensor8>>& tf1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator -(const tmp<Field<diagTensor8>>& tf1, const tmp<Field<diagTensor8>>& tf2);

	void add(Field<diagTensor8>& f, const diagTensor8& s1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator +(const diagTensor8& s1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator +(const diagTensor8& s1, const tmp<Field<diagTensor8>>& tf2);

	void add(Field<diagTensor8>& f, const UList<diagTensor8>& f1, const diagTensor8& s2);

	tmp<Field<diagTensor8>> operator +(const UList<diagTensor8>& f1, const diagTensor8& s2);

	tmp<Field<diagTensor8>> operator +(const tmp<Field<diagTensor8>>& tf1, const diagTensor8& s2);

	void subtract(Field<diagTensor8>& f, const diagTensor8& s1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator -(const diagTensor8& s1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator -(const diagTensor8& s1, const tmp<Field<diagTensor8>>& tf2);

	void subtract(Field<diagTensor8>& f, const UList<diagTensor8>& f1, const diagTensor8& s2);

	tmp<Field<diagTensor8>> operator -(const UList<diagTensor8>& f1, const diagTensor8& s2);

	tmp<Field<diagTensor8>> operator -(const tmp<Field<diagTensor8>>& tf1, const diagTensor8& s2);

	void add(Field<diagTensor8>& f, const UList<sphericalTensor8>& f1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator +(const UList<sphericalTensor8>& f1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator +(const UList<sphericalTensor8>& f1, const tmp<Field<diagTensor8>>& tf2);

	tmp<Field<diagTensor8>> operator +(const tmp<Field<sphericalTensor8>>& tf1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator +(const tmp<Field<sphericalTensor8>>& tf1, const tmp<Field<diagTensor8>>& tf2);

	void subtract(Field<diagTensor8>& f, const UList<sphericalTensor8>& f1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator -(const UList<sphericalTensor8>& f1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator -(const UList<sphericalTensor8>& f1, const tmp<Field<diagTensor8>>& tf2);

	tmp<Field<diagTensor8>> operator -(const tmp<Field<sphericalTensor8>>& tf1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator -(const tmp<Field<sphericalTensor8>>& tf1, const tmp<Field<diagTensor8>>& tf2);

	void add(Field<diagTensor8>& f, const sphericalTensor8& s1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator +(const sphericalTensor8& s1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator +(const sphericalTensor8& s1, const tmp<Field<diagTensor8>>& tf2);

	void add(Field<diagTensor8>& f, const UList<sphericalTensor8>& f1, const diagTensor8& s2);

	tmp<Field<diagTensor8>> operator +(const UList<sphericalTensor8>& f1, const diagTensor8& s2);

	tmp<Field<diagTensor8>> operator +(const tmp<Field<sphericalTensor8>>& tf1, const diagTensor8& s2);

	void subtract(Field<diagTensor8>& f, const sphericalTensor8& s1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator -(const sphericalTensor8& s1, const UList<diagTensor8>& f2);

	tmp<Field<diagTensor8>> operator -(const sphericalTensor8& s1, const tmp<Field<diagTensor8>>& tf2);

	void subtract(Field<diagTensor8>& f, const UList<sphericalTensor8>& f1, const diagTensor8& s2);

	tmp<Field<diagTensor8>> operator -(const UList<sphericalTensor8>& f1, const diagTensor8& s2);

	tmp<Field<diagTensor8>> operator -(const tmp<Field<sphericalTensor8>>& tf1, const diagTensor8& s2);

	void add(Field<diagTensor8>& f, const UList<diagTensor8>& f1, const UList<sphericalTensor8>& f2);

	tmp<Field<diagTensor8>> operator +(const UList<diagTensor8>& f1, const UList<sphericalTensor8>& f2);

	tmp<Field<diagTensor8>> operator +(const UList<diagTensor8>& f1, const tmp<Field<sphericalTensor8>>& tf2);

	tmp<Field<diagTensor8>> operator +(const tmp<Field<diagTensor8>>& tf1, const UList<sphericalTensor8>& f2);

	tmp<Field<diagTensor8>> operator +(const tmp<Field<diagTensor8>>& tf1, const tmp<Field<sphericalTensor8>>& tf2);

	void subtract(Field<diagTensor8>& f, const UList<diagTensor8>& f1, const UList<sphericalTensor8>& f2);

	tmp<Field<diagTensor8>> operator -(const UList<diagTensor8>& f1, const UList<sphericalTensor8>& f2);

	tmp<Field<diagTensor8>> operator -(const UList<diagTensor8>& f1, const tmp<Field<sphericalTensor8>>& tf2);

	tmp<Field<diagTensor8>> operator -(const tmp<Field<diagTensor8>>& tf1, const UList<sphericalTensor8>& f2);

	tmp<Field<diagTensor8>> operator -(const tmp<Field<diagTensor8>>& tf1, const tmp<Field<sphericalTensor8>>& tf2);

	void add(Field<diagTensor8>& f, const diagTensor8& s1, const UList<sphericalTensor8>& f2);

	tmp<Field<diagTensor8>> operator +(const diagTensor8& s1, const UList<sphericalTensor8>& f2);

	tmp<Field<diagTensor8>> operator +(const diagTensor8& s1, const tmp<Field<sphericalTensor8>>& tf2);

	void add(Field<diagTensor8>& f, const UList<diagTensor8>& f1, const sphericalTensor8& s2);

	tmp<Field<diagTensor8>> operator +(const UList<diagTensor8>& f1, const sphericalTensor8& s2);

	tmp<Field<diagTensor8>> operator +(const tmp<Field<diagTensor8>>& tf1, const sphericalTensor8& s2);

	void subtract(Field<diagTensor8>& f, const diagTensor8& s1, const UList<sphericalTensor8>& f2);

	tmp<Field<diagTensor8>> operator -(const diagTensor8& s1, const UList<sphericalTensor8>& f2);

	tmp<Field<diagTensor8>> operator -(const diagTensor8& s1, const tmp<Field<sphericalTensor8>>& tf2);

	void subtract(Field<diagTensor8>& f, const UList<diagTensor8>& f1, const sphericalTensor8& s2);

	tmp<Field<diagTensor8>> operator -(const UList<diagTensor8>& f1, const sphericalTensor8& s2);

	tmp<Field<diagTensor8>> operator -(const tmp<Field<diagTensor8>>& tf1, const sphericalTensor8& s2);
}

#undef DiagTensorN_FieldFunctions

#include <undefFieldFunctionsM.hxx>

#endif // !1
