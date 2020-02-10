#pragma once
#ifndef _transformField_Header
#define _transformField_Header

#include <transform.hxx>
#include <quaternion.hxx>
#include <septernion.hxx>
#include <vectorField.hxx>
#include <tensorField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template<class Type>
	void transform(Field<Type>&, const tensorField&, const Field<Type>&);

	template<class Type>
	tmp<Field<Type>> transform(const tensorField&, const Field<Type>&);

	template<class Type>
	tmp<Field<Type>> transform(const tensorField&, const tmp<Field<Type>>&);

	template<class Type>
	tmp<Field<Type>> transform(const tmp<tensorField>&, const Field<Type>&);

	template<class Type>
	tmp<Field<Type>> transform(const tmp<tensorField>&, const tmp<Field<Type>>&);


	template<class Type>
	void transform(Field<Type>&, const tensor&, const Field<Type>&);

	template<class Type>
	tmp<Field<Type>> transform(const tensor&, const Field<Type>&);

	template<class Type>
	tmp<Field<Type>> transform(const tensor&, const tmp<Field<Type>>&);


	template<class Type1, class Type2>
	tmp<Field<Type1>> transformFieldMask(const Field<Type2>&);

	template<class Type1, class Type2>
	tmp<Field<Type1>> transformFieldMask(const tmp<Field<Type2>>&);


	template<>
	tmp<Field<symmTensor>> transformFieldMask<symmTensor>
		(
			const tensorField&
			);

	template<>
	tmp<Field<symmTensor>> transformFieldMask<symmTensor>
		(
			const tmp<tensorField>&
			);


	template<>
	tmp<Field<sphericalTensor>> transformFieldMask<sphericalTensor>
		(
			const tensorField&
			);

	template<>
	tmp<Field<sphericalTensor>> transformFieldMask<sphericalTensor>
		(
			const tmp<tensorField>&
			);

	template<>
	tmp<Field<symmTensor4thOrder>> transformFieldMask<symmTensor4thOrder>
		(
			const tensorField&
			);

	template<>
	tmp<Field<symmTensor4thOrder>> transformFieldMask<symmTensor4thOrder>
		(
			const tmp<tensorField>&
			);

	template<>
	tmp<Field<symmTensor4thOrder>> transformFieldMask<symmTensor4thOrder>
		(
			const symmTensorField&
			);

	template<>
	tmp<Field<symmTensor4thOrder>> transformFieldMask<symmTensor4thOrder>
		(
			const tmp<symmTensorField>&
			);

	template<>
	tmp<Field<diagTensor>> transformFieldMask<diagTensor>
		(
			const tensorField&
			);

	template<>
	tmp<Field<diagTensor>> transformFieldMask<diagTensor>
		(
			const tmp<tensorField>&
			);

	template<>
	tmp<Field<diagTensor>> transformFieldMask<diagTensor>
		(
			const symmTensorField&
			);

	template<>
	tmp<Field<diagTensor>> transformFieldMask<diagTensor>
		(
			const tmp<symmTensorField>&
			);


	//- Rotate given vectorField with the given quaternion
	void transform(vectorField&, const quaternion&, const vectorField&);

	//- Rotate given vectorField with the given quaternion
	tmp<vectorField> transform(const quaternion&, const vectorField&);

	//- Rotate given tmp<vectorField> with the given quaternion
	tmp<vectorField> transform(const quaternion&, const tmp<vectorField>&);


	//- Transform given vectorField with the given septernion
	void transform(vectorField&, const septernion&, const vectorField&);

	//- Transform given vectorField with the given septernion
	tmp<vectorField> transform(const septernion&, const vectorField&);

	//- Transform given tmp<vectorField> with the given septernion
	tmp<vectorField> transform(const septernion&, const tmp<vectorField>&);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <transformFieldTemplates.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !1
