#pragma once
#ifndef _dimensionedVectorTensorN_Header
#define _dimensionedVectorTensorN_Header

#include <dimensionedType.hxx>
#include <VectorNFieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

#define doMakeTypedef(type, Type, args)      \
    typedef dimensioned<type> dimensioned##Type;

	typedef dimensioned<vector2> dimensionedVector2;
	typedef dimensioned<vector3> dimensionedVector3;
	typedef dimensioned<vector4> dimensionedVector4;
	typedef dimensioned<vector6> dimensionedVector6;
	typedef dimensioned<vector8> dimensionedVector8;

		
	typedef dimensioned<tensor2> dimensionedTensor2;
	typedef dimensioned<tensor3> dimensionedTensor3;
	typedef dimensioned<tensor4> dimensionedTensor4;
	typedef dimensioned<tensor6> dimensionedTensor6;
	typedef dimensioned<tensor8> dimensionedTensor8;

		
	typedef dimensioned<diagTensor2> dimensionedDiagTensor2;
	typedef dimensioned<diagTensor3> dimensionedDiagTensor3;
	typedef dimensioned<diagTensor4> dimensionedDiagTensor4;
	typedef dimensioned<diagTensor6> dimensionedDiagTensor6;
	typedef dimensioned<diagTensor8> dimensionedDiagTensor8;

		
	typedef dimensioned<sphericalTensor2> dimensionedSphericalTensor2;
	typedef dimensioned<sphericalTensor3> dimensionedSphericalTensor3;
	typedef dimensioned<sphericalTensor4> dimensionedSphericalTensor4;
	typedef dimensioned<sphericalTensor6> dimensionedSphericalTensor6;
	typedef dimensioned<sphericalTensor8> dimensionedSphericalTensor8;

#undef doMakeTypedef


		// friend functions

		
	dimensionSet diag(const dimensionSet& ds);
	dimensionSet cmptSum(const dimensionSet& ds);
	dimensionSet contractLinear(const dimensionSet& ds);
	dimensionSet contractScalar(const dimensionSet& ds);

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define UNARY_FUNCTION(returnType, type, fun, text)                                 \
inline dimensioned< returnType > fun(const dimensioned< type >& t);


#define BINARY_OPERATOR(returnType, type1, type2, op, text)                         \
dimensioned< returnType > op(const dimensioned< type1 >&,                           \
    const dimensioned< type2 >&);


#define dimensionedType_Funs(tensorType, diagTensorType,                            \
    sphericalTensorType, vectorType, cmptType, args)                             \
                                                                                    \
UNARY_FUNCTION(tensorType, tensorType, inv, inv)                                    \
UNARY_FUNCTION(diagTensorType, diagTensorType, inv, inv)                            \
UNARY_FUNCTION(sphericalTensorType, sphericalTensorType, inv, inv)                  \
                                                                                    \
UNARY_FUNCTION(diagTensorType, tensorType, diag, diag)                              \
UNARY_FUNCTION(diagTensorType, diagTensorType, diag, diag)                          \
UNARY_FUNCTION(sphericalTensorType, sphericalTensorType, diag, diag)                \
                                                                                    \
UNARY_FUNCTION(vectorType, vectorType, cmptSum, cmptSum)                            \
                                                                                    \
BINARY_OPERATOR(tensorType, tensorType, diagTensorType, operator+, +)               \
BINARY_OPERATOR(tensorType, diagTensorType, tensorType, operator+, +)               \
BINARY_OPERATOR(tensorType, tensorType, sphericalTensorType, operator+, +)          \
BINARY_OPERATOR(tensorType, sphericalTensorType, tensorType, operator+, +)          \
BINARY_OPERATOR(diagTensorType, diagTensorType, sphericalTensorType, operator+, +)  \
BINARY_OPERATOR(diagTensorType, sphericalTensorType, diagTensorType, operator+, +)  \
                                                                                    \
BINARY_OPERATOR(tensorType, tensorType, diagTensorType, operator-, -)               \
BINARY_OPERATOR(tensorType, diagTensorType, tensorType, operator-, -)               \
BINARY_OPERATOR(tensorType, tensorType, sphericalTensorType, operator-, -)          \
BINARY_OPERATOR(tensorType, sphericalTensorType, tensorType, operator-, -)          \
BINARY_OPERATOR(diagTensorType, diagTensorType, sphericalTensorType, operator-, -)  \
BINARY_OPERATOR(diagTensorType, sphericalTensorType, diagTensorType, operator-, -)


	inline dimensioned<tensor2> inv(const dimensioned<tensor2>& t);

	inline dimensioned<diagTensor2> inv(const dimensioned<diagTensor2>& t);

	inline dimensioned<sphericalTensor2> inv(const dimensioned<sphericalTensor2>& t);

	inline dimensioned<diagTensor2> diag(const dimensioned<tensor2>& t);

	inline dimensioned<diagTensor2> diag(const dimensioned<diagTensor2>& t);

	inline dimensioned<sphericalTensor2> diag(const dimensioned<sphericalTensor2>& t);

	inline dimensioned<vector2> cmptSum(const dimensioned<vector2>& t);

	dimensioned<tensor2> operator+(const dimensioned<tensor2>&, const dimensioned<diagTensor2>&);

	dimensioned<tensor2> operator+(const dimensioned<diagTensor2>&, const dimensioned<tensor2>&);

	dimensioned<tensor2> operator+(const dimensioned<tensor2>&, const dimensioned<sphericalTensor2>&);

	dimensioned<tensor2> operator+(const dimensioned<sphericalTensor2>&, const dimensioned<tensor2>&);

	dimensioned<diagTensor2> operator+(const dimensioned<diagTensor2>&, const dimensioned<sphericalTensor2>&);

	dimensioned<diagTensor2> operator+(const dimensioned<sphericalTensor2>&, const dimensioned<diagTensor2>&);

	dimensioned<tensor2> operator-(const dimensioned<tensor2>&, const dimensioned<diagTensor2>&);

	dimensioned<tensor2> operator-(const dimensioned<diagTensor2>&, const dimensioned<tensor2>&);

	dimensioned<tensor2> operator-(const dimensioned<tensor2>&, const dimensioned<sphericalTensor2>&);

	dimensioned<tensor2> operator-(const dimensioned<sphericalTensor2>&, const dimensioned<tensor2>&);

	dimensioned<diagTensor2> operator-(const dimensioned<diagTensor2>&, const dimensioned<sphericalTensor2>&);

	dimensioned<diagTensor2> operator-(const dimensioned<sphericalTensor2>&, const dimensioned<diagTensor2>&);

	inline dimensioned<tensor3> inv(const dimensioned<tensor3>& t);

	inline dimensioned<diagTensor3> inv(const dimensioned<diagTensor3>& t);

	inline dimensioned<sphericalTensor3> inv(const dimensioned<sphericalTensor3>& t);

	inline dimensioned<diagTensor3> diag(const dimensioned<tensor3>& t);

	inline dimensioned<diagTensor3> diag(const dimensioned<diagTensor3>& t);

	inline dimensioned<sphericalTensor3> diag(const dimensioned<sphericalTensor3>& t);

	inline dimensioned<vector3> cmptSum(const dimensioned<vector3>& t);

	dimensioned<tensor3> operator+(const dimensioned<tensor3>&, const dimensioned<diagTensor3>&);

	dimensioned<tensor3> operator+(const dimensioned<diagTensor3>&, const dimensioned<tensor3>&);

	dimensioned<tensor3> operator+(const dimensioned<tensor3>&, const dimensioned<sphericalTensor3>&);

	dimensioned<tensor3> operator+(const dimensioned<sphericalTensor3>&, const dimensioned<tensor3>&);

	dimensioned<diagTensor3> operator+(const dimensioned<diagTensor3>&, const dimensioned<sphericalTensor3>&);

	dimensioned<diagTensor3> operator+(const dimensioned<sphericalTensor3>&, const dimensioned<diagTensor3>&);

	dimensioned<tensor3> operator-(const dimensioned<tensor3>&, const dimensioned<diagTensor3>&);

	dimensioned<tensor3> operator-(const dimensioned<diagTensor3>&, const dimensioned<tensor3>&);

	dimensioned<tensor3> operator-(const dimensioned<tensor3>&, const dimensioned<sphericalTensor3>&);

	dimensioned<tensor3> operator-(const dimensioned<sphericalTensor3>&, const dimensioned<tensor3>&);

	dimensioned<diagTensor3> operator-(const dimensioned<diagTensor3>&, const dimensioned<sphericalTensor3>&);

	dimensioned<diagTensor3> operator-(const dimensioned<sphericalTensor3>&, const dimensioned<diagTensor3>&);

	inline dimensioned<tensor4> inv(const dimensioned<tensor4>& t);

	inline dimensioned<diagTensor4> inv(const dimensioned<diagTensor4>& t);

	inline dimensioned<sphericalTensor4> inv(const dimensioned<sphericalTensor4>& t);

	inline dimensioned<diagTensor4> diag(const dimensioned<tensor4>& t);

	inline dimensioned<diagTensor4> diag(const dimensioned<diagTensor4>& t);

	inline dimensioned<sphericalTensor4> diag(const dimensioned<sphericalTensor4>& t);

	inline dimensioned<vector4> cmptSum(const dimensioned<vector4>& t);

	dimensioned<tensor4> operator+(const dimensioned<tensor4>&, const dimensioned<diagTensor4>&);

	dimensioned<tensor4> operator+(const dimensioned<diagTensor4>&, const dimensioned<tensor4>&);

	dimensioned<tensor4> operator+(const dimensioned<tensor4>&, const dimensioned<sphericalTensor4>&);

	dimensioned<tensor4> operator+(const dimensioned<sphericalTensor4>&, const dimensioned<tensor4>&);

	dimensioned<diagTensor4> operator+(const dimensioned<diagTensor4>&, const dimensioned<sphericalTensor4>&);

	dimensioned<diagTensor4> operator+(const dimensioned<sphericalTensor4>&, const dimensioned<diagTensor4>&);

	dimensioned<tensor4> operator-(const dimensioned<tensor4>&, const dimensioned<diagTensor4>&);

	dimensioned<tensor4> operator-(const dimensioned<diagTensor4>&, const dimensioned<tensor4>&);

	dimensioned<tensor4> operator-(const dimensioned<tensor4>&, const dimensioned<sphericalTensor4>&);

	dimensioned<tensor4> operator-(const dimensioned<sphericalTensor4>&, const dimensioned<tensor4>&);

	dimensioned<diagTensor4> operator-(const dimensioned<diagTensor4>&, const dimensioned<sphericalTensor4>&);

	dimensioned<diagTensor4> operator-(const dimensioned<sphericalTensor4>&, const dimensioned<diagTensor4>&);

	inline dimensioned<tensor6> inv(const dimensioned<tensor6>& t);

	inline dimensioned<diagTensor6> inv(const dimensioned<diagTensor6>& t);

	inline dimensioned<sphericalTensor6> inv(const dimensioned<sphericalTensor6>& t);

	inline dimensioned<diagTensor6> diag(const dimensioned<tensor6>& t);

	inline dimensioned<diagTensor6> diag(const dimensioned<diagTensor6>& t);

	inline dimensioned<sphericalTensor6> diag(const dimensioned<sphericalTensor6>& t);

	inline dimensioned<vector6> cmptSum(const dimensioned<vector6>& t);

	dimensioned<tensor6> operator+(const dimensioned<tensor6>&, const dimensioned<diagTensor6>&);

	dimensioned<tensor6> operator+(const dimensioned<diagTensor6>&, const dimensioned<tensor6>&);

	dimensioned<tensor6> operator+(const dimensioned<tensor6>&, const dimensioned<sphericalTensor6>&);

	dimensioned<tensor6> operator+(const dimensioned<sphericalTensor6>&, const dimensioned<tensor6>&);

	dimensioned<diagTensor6> operator+(const dimensioned<diagTensor6>&, const dimensioned<sphericalTensor6>&);

	dimensioned<diagTensor6> operator+(const dimensioned<sphericalTensor6>&, const dimensioned<diagTensor6>&);

	dimensioned<tensor6> operator-(const dimensioned<tensor6>&, const dimensioned<diagTensor6>&);

	dimensioned<tensor6> operator-(const dimensioned<diagTensor6>&, const dimensioned<tensor6>&);

	dimensioned<tensor6> operator-(const dimensioned<tensor6>&, const dimensioned<sphericalTensor6>&);

	dimensioned<tensor6> operator-(const dimensioned<sphericalTensor6>&, const dimensioned<tensor6>&);

	dimensioned<diagTensor6> operator-(const dimensioned<diagTensor6>&, const dimensioned<sphericalTensor6>&);

	dimensioned<diagTensor6> operator-(const dimensioned<sphericalTensor6>&, const dimensioned<diagTensor6>&);

	inline dimensioned<tensor8> inv(const dimensioned<tensor8>& t);

	inline dimensioned<diagTensor8> inv(const dimensioned<diagTensor8>& t);

	inline dimensioned<sphericalTensor8> inv(const dimensioned<sphericalTensor8>& t);

	inline dimensioned<diagTensor8> diag(const dimensioned<tensor8>& t);

	inline dimensioned<diagTensor8> diag(const dimensioned<diagTensor8>& t);

	inline dimensioned<sphericalTensor8> diag(const dimensioned<sphericalTensor8>& t);

	inline dimensioned<vector8> cmptSum(const dimensioned<vector8>& t);

	dimensioned<tensor8> operator+(const dimensioned<tensor8>&, const dimensioned<diagTensor8>&);

	dimensioned<tensor8> operator+(const dimensioned<diagTensor8>&, const dimensioned<tensor8>&);

	dimensioned<tensor8> operator+(const dimensioned<tensor8>&, const dimensioned<sphericalTensor8>&);

	dimensioned<tensor8> operator+(const dimensioned<sphericalTensor8>&, const dimensioned<tensor8>&);

	dimensioned<diagTensor8> operator+(const dimensioned<diagTensor8>&, const dimensioned<sphericalTensor8>&);

	dimensioned<diagTensor8> operator+(const dimensioned<sphericalTensor8>&, const dimensioned<diagTensor8>&);

	dimensioned<tensor8> operator-(const dimensioned<tensor8>&, const dimensioned<diagTensor8>&);

	dimensioned<tensor8> operator-(const dimensioned<diagTensor8>&, const dimensioned<tensor8>&);

	dimensioned<tensor8> operator-(const dimensioned<tensor8>&, const dimensioned<sphericalTensor8>&);

	dimensioned<tensor8> operator-(const dimensioned<sphericalTensor8>&, const dimensioned<tensor8>&);

	dimensioned<diagTensor8> operator-(const dimensioned<diagTensor8>&, const dimensioned<sphericalTensor8>&);

	dimensioned<diagTensor8> operator-(const dimensioned<sphericalTensor8>&, const dimensioned<diagTensor8>&);

#undef dimensionedType_Funs
#undef UNARY_FUNCTION
#undef BINARY_OPERATOR

		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <dimensionedVectorTensorNI.hxx>

#endif // !_dimensionedVectorTensorN_Header
