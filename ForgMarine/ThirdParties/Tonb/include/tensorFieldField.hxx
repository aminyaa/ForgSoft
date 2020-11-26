#pragma once
#ifndef _tensorFieldField_Header
#define _tensorFieldField_Header

#include <sphericalTensorFieldField.hxx>
#include <symmTensorFieldField.hxx>
#include <tensor.hxx>

#define TEMPLATE template<template<class> class Field>
#include <FieldFieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template <template<class> class Field>
	void tr(FieldField<Field, scalar>& res, const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> tr(const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> tr(const tmp<FieldField<Field, tensor>>& tf);
		
	template <template<class> class Field>
	void sph(FieldField<Field, sphericalTensor>& res, const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor>> sph(const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, sphericalTensor>> sph(const tmp<FieldField<Field, tensor>>& tf);
		
	template <template<class> class Field>
	void symm(FieldField<Field, symmTensor>& res, const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> symm(const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> symm(const tmp<FieldField<Field, tensor>>& tf);
		
	template <template<class> class Field>
	void twoSymm(FieldField<Field, symmTensor>& res, const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> twoSymm(const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> twoSymm(const tmp<FieldField<Field, tensor>>& tf);
		
	template <template<class> class Field>
	void skew(FieldField<Field, tensor>& res, const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> skew(const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> skew(const tmp<FieldField<Field, tensor>>& tf);
		
	template <template<class> class Field>
	void dev(FieldField<Field, tensor>& res, const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> dev(const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> dev(const tmp<FieldField<Field, tensor>>& tf);
		
	template <template<class> class Field>
	void dev2(FieldField<Field, tensor>& res, const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> dev2(const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> dev2(const tmp<FieldField<Field, tensor>>& tf);
		
	template <template<class> class Field>
	void det(FieldField<Field, scalar>& res, const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> det(const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, scalar>> det(const tmp<FieldField<Field, tensor>>& tf);
		
	template <template<class> class Field>
	void cof(FieldField<Field, tensor>& res, const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> cof(const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> cof(const tmp<FieldField<Field, tensor>>& tf);
		
	template <template<class> class Field>
	void inv(FieldField<Field, tensor>& res, const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> inv(const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> inv(const tmp<FieldField<Field, tensor>>& tf);
		
	template <template<class> class Field>
	void hinv(FieldField<Field, tensor>& res, const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> hinv(const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> hinv(const tmp<FieldField<Field, tensor>>& tf);
		
	template <template<class> class Field>
	void eigenValues(FieldField<Field, vector>& res, const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, vector>> eigenValues(const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, vector>> eigenValues(const tmp<FieldField<Field, tensor>>& tf);
		
	template <template<class> class Field>
	void eigenVectors(FieldField<Field, tensor>& res, const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> eigenVectors(const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> eigenVectors(const tmp<FieldField<Field, tensor>>& tf);

		
	template <template<class> class Field>
	void eigenValues(FieldField<Field, vector>& res, const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, vector>> eigenValues(const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, vector>> eigenValues(const tmp<FieldField<Field, symmTensor>>& tf);
		
	template <template<class> class Field>
	void eigenVectors(FieldField<Field, symmTensor>& res, const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> eigenVectors(const FieldField<Field, symmTensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, symmTensor>> eigenVectors(const tmp<FieldField<Field, symmTensor>>& tf);

		// * * * * * * * * * * * * * * * global operators  * * * * * * * * * * * * * //

		
	template <template<class> class Field>
	void hdual(FieldField<Field, vector>& res, const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, vector>> operator *(const FieldField<Field, tensor>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, vector>> operator *(const tmp<FieldField<Field, tensor>>& tf);
		
	template <template<class> class Field>
	void hdual(FieldField<Field, tensor>& res, const FieldField<Field, vector>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> operator *(const FieldField<Field, vector>& f);

	template <template<class> class Field>
	tmp<FieldField<Field, tensor>> operator *(const tmp<FieldField<Field, vector>>& tf);

		
	template <template<class> class Field>
	void divide(FieldField<Field, vector>& f, const FieldField<Field, vector>& f1, const FieldField<Field, tensor>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector>> operator /(const FieldField<Field, vector>& f1, const FieldField<Field, tensor>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector>> operator /(const FieldField<Field, vector>& f1
	                                          , const tmp<FieldField<Field, tensor>>& tf2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector>> operator /(const tmp<FieldField<Field, vector>>& tf1
	                                          , const FieldField<Field, tensor>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector>> operator /(const tmp<FieldField<Field, vector>>& tf1
	                                          , const tmp<FieldField<Field, tensor>>& tf2);
		
	template <template<class> class Field>
	void divide(FieldField<Field, vector>& f, const vector& s1, const FieldField<Field, tensor>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector>> operator /(const vector& s1, const FieldField<Field, tensor>& f2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector>> operator /(const vector& s1, const tmp<FieldField<Field, tensor>>& tf2);

	template <template<class> class Field>
	void divide(FieldField<Field, vector>& f, const FieldField<Field, vector>& f1, const tensor& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector>> operator /(const FieldField<Field, vector>& f1, const tensor& s2);

	template <template<class> class Field>
	tmp<FieldField<Field, vector>> operator /(const tmp<FieldField<Field, vector>>& tf1, const tensor& s2);


		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <undefFieldFunctionsM.hxx>

#ifdef NoRepository
#   include <tensorFieldField.cxx>
#endif

#endif // !1
