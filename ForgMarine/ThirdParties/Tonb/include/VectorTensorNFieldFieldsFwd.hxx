#pragma once
#ifndef _VectorTensorNFieldFieldsFwd_Header
#define _VectorTensorNFieldFieldsFwd_Header

#include <VectorNFieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<class Type>
	class Field;

	template<template<class> class Field, class Type>
	class FieldField;

#define makeTypedef(Type, args)                      \
    typedef FieldField<Field, Type > Type##FieldField;

	typedef FieldField<Field, vector2> vector2FieldField;
	typedef FieldField<Field, vector3> vector3FieldField;
	typedef FieldField<Field, vector4> vector4FieldField;
	typedef FieldField<Field, vector6> vector6FieldField;
	typedef FieldField<Field, vector8> vector8FieldField;

		
	typedef FieldField<Field, tensor2> tensor2FieldField;
	typedef FieldField<Field, tensor3> tensor3FieldField;
	typedef FieldField<Field, tensor4> tensor4FieldField;
	typedef FieldField<Field, tensor6> tensor6FieldField;
	typedef FieldField<Field, tensor8> tensor8FieldField;

		
	typedef FieldField<Field, diagTensor2> diagTensor2FieldField;
	typedef FieldField<Field, diagTensor3> diagTensor3FieldField;
	typedef FieldField<Field, diagTensor4> diagTensor4FieldField;
	typedef FieldField<Field, diagTensor6> diagTensor6FieldField;
	typedef FieldField<Field, diagTensor8> diagTensor8FieldField;

		
	typedef FieldField<Field, sphericalTensor2> sphericalTensor2FieldField;
	typedef FieldField<Field, sphericalTensor3> sphericalTensor3FieldField;
	typedef FieldField<Field, sphericalTensor4> sphericalTensor4FieldField;
	typedef FieldField<Field, sphericalTensor6> sphericalTensor6FieldField;
	typedef FieldField<Field, sphericalTensor8> sphericalTensor8FieldField;

#undef makeTypedef

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_VectorTensorNFieldFieldsFwd_Header
