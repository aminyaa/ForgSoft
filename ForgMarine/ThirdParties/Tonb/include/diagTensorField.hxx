#pragma once
#ifndef _diagTensorField_Header
#define _diagTensorField_Header

#include <tensorField.hxx>
#include <diagTensor.hxx>

#define TEMPLATE
#include <FieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	typedef Field<diagTensor> diagTensorField;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	 
	void diag(Field<diagTensor>& res, const UList<tensor>& f);
	tmp<Field<diagTensor>> diag(const UList<tensor>& f);
	tmp<Field<diagTensor>> diag(const tmp<Field<tensor>>& tf);

	void tr(Field<scalar>& res, const UList<diagTensor>& f);
	tmp<Field<scalar>> tr(const UList<diagTensor>& f);
	tmp<Field<scalar>> tr(const tmp<Field<diagTensor>>& tf);

	void sph(Field<sphericalTensor>& res, const UList<diagTensor>& f);
	tmp<Field<sphericalTensor>> sph(const UList<diagTensor>& f);
	tmp<Field<sphericalTensor>> sph(const tmp<Field<diagTensor>>& tf);

	void det(Field<scalar>& res, const UList<diagTensor>& f);
	tmp<Field<scalar>> det(const UList<diagTensor>& f);
	tmp<Field<scalar>> det(const tmp<Field<diagTensor>>& tf);

	void inv(Field<diagTensor>& res, const UList<diagTensor>& f);
	tmp<Field<diagTensor>> inv(const UList<diagTensor>& f);
	tmp<Field<diagTensor>> inv(const tmp<Field<diagTensor>>& tf);



	void add(Field<tensor>& f, const UList<diagTensor>& f1, const UList<tensor>& f2);
	tmp<Field<tensor>> operator + (const UList<diagTensor>& f1, const UList<tensor>& f2);
	tmp<Field<tensor>> operator + (const UList<diagTensor>& f1, const tmp<Field<tensor>>& tf2);
	tmp<Field<tensor>> operator + (const tmp<Field<diagTensor>>& tf1, const UList<tensor>& f2);
	tmp<Field<tensor>> operator + (const tmp<Field<diagTensor>>& tf1, const tmp<Field<tensor>>& tf2);

	void subtract(Field<tensor>& f, const UList<diagTensor>& f1, const UList<tensor>& f2);
	tmp<Field<tensor>> operator - (const UList<diagTensor>& f1, const UList<tensor>& f2);
	tmp<Field<tensor>> operator - (const UList<diagTensor>& f1, const tmp<Field<tensor>>& tf2);
	tmp<Field<tensor>> operator - (const tmp<Field<diagTensor>>& tf1, const UList<tensor>& f2);
	tmp<Field<tensor>> operator - (const tmp<Field<diagTensor>>& tf1, const tmp<Field<tensor>>& tf2);


	void add(Field<tensor>& f, const diagTensor& s1, const UList<tensor>& f2);
	tmp<Field<tensor>> operator + (const diagTensor& s1, const UList<tensor>& f2);
	tmp<Field<tensor>> operator + (const diagTensor& s1, const tmp<Field<tensor>>& tf2);
	void add(Field<tensor>& f, const UList<diagTensor>& f1, const tensor& s2);
	tmp<Field<tensor>> operator + (const UList<diagTensor>& f1, const tensor& s2);
	tmp<Field<tensor>> operator + (const tmp<Field<diagTensor>>& tf1, const tensor& s2);

	void subtract(Field<tensor>& f, const diagTensor& s1, const UList<tensor>& f2);
	tmp<Field<tensor>> operator - (const diagTensor& s1, const UList<tensor>& f2);
	tmp<Field<tensor>> operator - (const diagTensor& s1, const tmp<Field<tensor>>& tf2);
	void subtract(Field<tensor>& f, const UList<diagTensor>& f1, const tensor& s2);
	tmp<Field<tensor>> operator - (const UList<diagTensor>& f1, const tensor& s2);
	tmp<Field<tensor>> operator - (const tmp<Field<diagTensor>>& tf1, const tensor& s2);


	void divide(Field<vector>& f, const UList<vector>& f1, const UList<diagTensor>& f2);
	tmp<Field<vector>> operator / (const UList<vector>& f1, const UList<diagTensor>& f2);
	tmp<Field<vector>> operator / (const UList<vector>& f1, const tmp<Field<diagTensor>>& tf2);
	tmp<Field<vector>> operator / (const tmp<Field<vector>>& tf1, const UList<diagTensor>& f2);
	tmp<Field<vector>> operator / (const tmp<Field<vector>>& tf1, const tmp<Field<diagTensor>>& tf2);

	void divide(Field<vector>& f, const vector& s1, const UList<diagTensor>& f2);
	tmp<Field<vector>> operator / (const vector& s1, const UList<diagTensor>& f2);
	tmp<Field<vector>> operator / (const vector& s1, const tmp<Field<diagTensor>>& tf2);
	void divide(Field<vector>& f, const UList<vector>& f1, const diagTensor& s2);
	tmp<Field<vector>> operator / (const UList<vector>& f1, const diagTensor& s2);
	tmp<Field<vector>> operator / (const tmp<Field<vector>>& tf1, const diagTensor& s2);


		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <undefFieldFunctionsM.hxx>

#endif // !1
