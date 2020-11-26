#pragma once
#ifndef _symmTensorFieldField_Header
#define _symmTensorFieldField_Header

#include <FieldField.hxx>
#include <symmTensor.hxx>
#include <sphericalTensor.hxx>
#include <tensor.hxx>

#define TEMPLATE template<template<class> class Field>
#include <FieldFieldFunctionsM.hxx>

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //



	template <template<class> class Field>
	void sqr(FieldField<Field, symmTensor>& res, const FieldField<Field, vector>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> sqr(const FieldField<Field, vector>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> sqr(const tmp<FieldField<Field, vector>>& tf);
		
	template <template<class> class Field>
	void innerSqr(FieldField<Field, symmTensor>& res, const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> innerSqr(const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> innerSqr(const tmp<FieldField<Field, symmTensor>>& tf);

	template <template<class> class Field>
	void tr(FieldField<Field, scalar>& res, const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> tr(const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> tr(const tmp<FieldField<Field, symmTensor>>& tf);
		
	template <template<class> class Field>
	void sph(FieldField<Field, sphericalTensor>& res, const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor>> sph(const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor>> sph(const tmp<FieldField<Field, symmTensor>>& tf);
		
	template <template<class> class Field>
	void symm(FieldField<Field, symmTensor>& res, const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> symm(const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> symm(const tmp<FieldField<Field, symmTensor>>& tf);
		
	template <template<class> class Field>
	void twoSymm(FieldField<Field, symmTensor>& res, const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> twoSymm(const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> twoSymm(const tmp<FieldField<Field, symmTensor>>& tf);
		
	template <template<class> class Field>
	void dev(FieldField<Field, symmTensor>& res, const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> dev(const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> dev(const tmp<FieldField<Field, symmTensor>>& tf);
		
	template <template<class> class Field>
	void dev2(FieldField<Field, symmTensor>& res, const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> dev2(const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> dev2(const tmp<FieldField<Field, symmTensor>>& tf);
		
	template <template<class> class Field>
	void det(FieldField<Field, scalar>& res, const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> det(const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> det(const tmp<FieldField<Field, symmTensor>>& tf);
		
	template <template<class> class Field>
	void cof(FieldField<Field, symmTensor>& res, const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> cof(const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> cof(const tmp<FieldField<Field, symmTensor>>& tf);
		
	template <template<class> class Field>
	void inv(FieldField<Field, symmTensor>& res, const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> inv(const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> inv(const tmp<FieldField<Field, symmTensor>>& tf);
		
	template <template<class> class Field>
	void hinv(FieldField<Field, symmTensor>& res, const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> hinv(const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> hinv(const tmp<FieldField<Field, symmTensor>>& tf);


		// * * * * * * * * * * * * * * * global operators  * * * * * * * * * * * * * //

		
	template <template<class> class Field>
	void hdual(FieldField<Field, vector>& res, const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, vector>> operator *(const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, vector>> operator *(const tmp<FieldField<Field, symmTensor>>& tf);

		
	template <template<class> class Field>
	void dot(FieldField<Field, tensor>& f, const FieldField<Field, symmTensor>& f1
	         , const FieldField<Field, symmTensor>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> operator &(const FieldField<Field, symmTensor>& f1
	                                          , const FieldField<Field, symmTensor>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> operator &(const FieldField<Field, symmTensor>& f1
	                                          , const tmp<FieldField<Field, symmTensor>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> operator &(const tmp<FieldField<Field, symmTensor>>& tf1
	                                          , const FieldField<Field, symmTensor>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> operator &(const tmp<FieldField<Field, symmTensor>>& tf1
	                                          , const tmp<FieldField<Field, symmTensor>>& tf2);
		
	template <template<class> class Field>
	void dot(FieldField<Field, tensor>& f, const symmTensor& s1, const FieldField<Field, symmTensor>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> operator &(const symmTensor& s1, const FieldField<Field, symmTensor>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> operator &(const symmTensor& s1, const tmp<FieldField<Field, symmTensor>>& tf2);

	template <template<class> class Field>
	void dot(FieldField<Field, tensor>& f, const FieldField<Field, symmTensor>& f1, const symmTensor& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> operator &(const FieldField<Field, symmTensor>& f1, const symmTensor& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> operator &(const tmp<FieldField<Field, symmTensor>>& tf1, const symmTensor& s2);


		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#include <undefFieldFunctionsM.hxx>

#ifdef NoRepository
#   include <symmTensorFieldField.cxx>
#endif

#endif // !_symmTensorFieldField_Header
