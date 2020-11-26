#pragma once
#ifndef _symmTransformField_Header
#define _symmTransformField_Header

#include <symmTransform.hxx>
#include <symmTensorField.hxx>
#include <transformField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template<class Type>
	void transform(Field<Type>&, const symmTensorField&, const Field<Type>&);

	template<class Type>
	tmp<Field<Type> > transform(const symmTensorField&, const Field<Type>&);

	template<class Type>
	tmp<Field<Type> > transform(const symmTensorField&, const tmp<Field<Type> >&);

	template<class Type>
	tmp<Field<Type> > transform(const tmp<symmTensorField>&, const Field<Type>&);

	template<class Type>
	tmp<Field<Type> > transform(const tmp<symmTensorField>&, const tmp<Field<Type> >&);


	template<class Type>
	void transform(Field<Type>&, const tensor&, const Field<Type>&);

	template<class Type>
	tmp<Field<Type> > transform(const tensor&, const Field<Type>&);

	template<class Type>
	tmp<Field<Type> > transform(const tensor&, const tmp<Field<Type> >&);


	template<>
	tmp<Field<sphericalTensor> > transformFieldMask<sphericalTensor>
		(
			const symmTensorField&
			);

	template<>
	tmp<Field<sphericalTensor> > transformFieldMask<sphericalTensor>
		(
			const tmp<symmTensorField>&
			);


	template<>
	tmp<Field<symmTensor> > transformFieldMask<symmTensor>
		(
			const symmTensorField&
			);

	template<>
	tmp<Field<symmTensor> > transformFieldMask<symmTensor>
		(
			const tmp<symmTensorField>&
			);


	template<>
	tmp<Field<tensor> > transformFieldMask<tensor>
		(
			const symmTensorField&
			);

	template<>
	tmp<Field<tensor> > transformFieldMask<tensor>
		(
			const tmp<symmTensorField>&
			);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <symmTransformField.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !1
