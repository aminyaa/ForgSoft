#pragma once
#ifndef _transformFieldField_Header
#define _transformFieldField_Header

#include <transform.hxx>
#include <tensorFieldField.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template<template<class> class Field, class Type>
	void transform
	(
		FieldField<Field, Type>&,
		const FieldField<Field, tensor>&,
		const FieldField<Field, Type>&
	);

	template<template<class> class Field, class Type>
	tmp<FieldField<Field, Type> > transform
	(
		const FieldField<Field, tensor>&,
		const FieldField<Field, Type>&
	);

	template<template<class> class Field, class Type>
	tmp<FieldField<Field, Type> > transform
	(
		const FieldField<Field, tensor>&,
		const tmp<FieldField<Field, Type> >&
	);

	template<template<class> class Field, class Type>
	tmp<FieldField<Field, Type> > transform
	(
		const tmp<FieldField<Field, tensor> >&,
		const FieldField<Field, Type>&
	);

	template<template<class> class Field, class Type>
	tmp<FieldField<Field, Type> > transform
	(
		const tmp<FieldField<Field, tensor> >&,
		const tmp<FieldField<Field, Type> >&
	);


	template<template<class> class Field, class Type>
	void transform
	(
		FieldField<Field, Type>&,
		const tensor&,
		const FieldField<Field, Type>&
	);

	template<template<class> class Field, class Type>
	tmp<FieldField<Field, Type> > transform
	(
		const tensor&,
		const FieldField<Field, Type>&
	);

	template<template<class> class Field, class Type>
	tmp<FieldField<Field, Type> > transform
	(
		const tensor&,
		const tmp<FieldField<Field, Type> >&
	);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <transformFieldField.cxx>
#endif

#endif // !_transformFieldField_Header
