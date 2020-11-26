#pragma once
#ifndef _scalarField_Header
#define _scalarField_Header

#include <Field.hxx>
#include <scalar.hxx>

#define TEMPLATE
#include <FieldFunctionsM.hxx>

namespace tnbLib
{
	typedef Field<scalar> scalarField;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template<>
	tmp<scalarField> scalarField::component(const direction) const;

	void component
	(
		scalarField& sf,
		const UList<scalar>& f,
		const direction
	);

	template<>
	void scalarField::replace(const direction, const UList<scalar>& sf);

	template<>
	void scalarField::replace(const direction, const scalar& s);


	void stabilise(scalarField& Res, const UList<scalar>& sf, const scalar s);
	tmp<scalarField> stabilise(const UList<scalar>&, const scalar s);
	tmp<scalarField> stabilise(const tmp<scalarField>&, const scalar s);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	 void add(Field<scalar>& f, const scalar& s1, const UList<scalar>& f2);

	tmp<Field<scalar>> operator +(const scalar& s1, const UList<scalar>& f2);

	tmp<Field<scalar>> operator +(const scalar& s1, const tmp<Field<scalar>>& tf2);

	void add(Field<scalar>& f, const UList<scalar>& f1, const scalar& s2);

	tmp<Field<scalar>> operator +(const UList<scalar>& f1, const scalar& s2);

	tmp<Field<scalar>> operator +(const tmp<Field<scalar>>& tf1, const scalar& s2);
		
	 void subtract(Field<scalar>& f, const scalar& s1, const UList<scalar>& f2);

	tmp<Field<scalar>> operator -(const scalar& s1, const UList<scalar>& f2);

	tmp<Field<scalar>> operator -(const scalar& s1, const tmp<Field<scalar>>& tf2);

	void subtract(Field<scalar>& f, const UList<scalar>& f1, const scalar& s2);

	tmp<Field<scalar>> operator -(const UList<scalar>& f1, const scalar& s2);

	tmp<Field<scalar>> operator -(const tmp<Field<scalar>>& tf1, const scalar& s2);

		
	 void multiply(Field<scalar>& f, const UList<scalar>& f1, const UList<scalar>& f2);

	tmp<Field<scalar>> operator *(const UList<scalar>& f1, const UList<scalar>& f2);

	tmp<Field<scalar>> operator *(const UList<scalar>& f1, const tmp<Field<scalar>>& tf2);

	tmp<Field<scalar>> operator *(const tmp<Field<scalar>>& tf1, const UList<scalar>& f2);

	tmp<Field<scalar>> operator *(const tmp<Field<scalar>>& tf1, const tmp<Field<scalar>>& tf2);
		
	 void divide(Field<scalar>& f, const UList<scalar>& f1, const UList<scalar>& f2);

	tmp<Field<scalar>> operator /(const UList<scalar>& f1, const UList<scalar>& f2);

	tmp<Field<scalar>> operator /(const UList<scalar>& f1, const tmp<Field<scalar>>& tf2);

	tmp<Field<scalar>> operator /(const tmp<Field<scalar>>& tf1, const UList<scalar>& f2);

	tmp<Field<scalar>> operator /(const tmp<Field<scalar>>& tf1, const tmp<Field<scalar>>& tf2);

		
	 void divide(Field<scalar>& f, const scalar& s1, const UList<scalar>& f2);

	tmp<Field<scalar>> operator /(const scalar& s1, const UList<scalar>& f2);

	tmp<Field<scalar>> operator /(const scalar& s1, const tmp<Field<scalar>>& tf2);

		
	 void pow(Field<scalar>& f, const UList<scalar>& f1, const UList<scalar>& f2);

	tmp<Field<scalar>> pow(const UList<scalar>& f1, const UList<scalar>& f2);

	tmp<Field<scalar>> pow(const UList<scalar>& f1, const tmp<Field<scalar>>& tf2);

	tmp<Field<scalar>> pow(const tmp<Field<scalar>>& tf1, const UList<scalar>& f2);

	tmp<Field<scalar>> pow(const tmp<Field<scalar>>& tf1, const tmp<Field<scalar>>& tf2);
		
	 void pow(Field<scalar>& f, const scalar& s1, const UList<scalar>& f2);

	tmp<Field<scalar>> pow(const scalar& s1, const UList<scalar>& f2);

	tmp<Field<scalar>> pow(const scalar& s1, const tmp<Field<scalar>>& tf2);

	void pow(Field<scalar>& f, const UList<scalar>& f1, const scalar& s2);

	tmp<Field<scalar>> pow(const UList<scalar>& f1, const scalar& s2);

	tmp<Field<scalar>> pow(const tmp<Field<scalar>>& tf1, const scalar& s2);

		
	 void atan2(Field<scalar>& f, const UList<scalar>& f1, const UList<scalar>& f2);

	tmp<Field<scalar>> atan2(const UList<scalar>& f1, const UList<scalar>& f2);

	tmp<Field<scalar>> atan2(const UList<scalar>& f1, const tmp<Field<scalar>>& tf2);

	tmp<Field<scalar>> atan2(const tmp<Field<scalar>>& tf1, const UList<scalar>& f2);

	tmp<Field<scalar>> atan2(const tmp<Field<scalar>>& tf1, const tmp<Field<scalar>>& tf2);
		
	 void atan2(Field<scalar>& f, const scalar& s1, const UList<scalar>& f2);

	tmp<Field<scalar>> atan2(const scalar& s1, const UList<scalar>& f2);

	tmp<Field<scalar>> atan2(const scalar& s1, const tmp<Field<scalar>>& tf2);

	void atan2(Field<scalar>& f, const UList<scalar>& f1, const scalar& s2);

	tmp<Field<scalar>> atan2(const UList<scalar>& f1, const scalar& s2);

	tmp<Field<scalar>> atan2(const tmp<Field<scalar>>& tf1, const scalar& s2);


		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

		
	void pow3(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> pow3(const UList<scalar>& f);

	tmp<Field<scalar>> pow3(const tmp<Field<scalar>>& tf);
		
	void pow4(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> pow4(const UList<scalar>& f);

	tmp<Field<scalar>> pow4(const tmp<Field<scalar>>& tf);
		
	void pow5(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> pow5(const UList<scalar>& f);

	tmp<Field<scalar>> pow5(const tmp<Field<scalar>>& tf);
		
	 void pow6(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> pow6(const UList<scalar>& f);

	tmp<Field<scalar>> pow6(const tmp<Field<scalar>>& tf);
		
	void sqrt(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> sqrt(const UList<scalar>& f);

	tmp<Field<scalar>> sqrt(const tmp<Field<scalar>>& tf);
		
	void sign(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> sign(const UList<scalar>& f);

	tmp<Field<scalar>> sign(const tmp<Field<scalar>>& tf);
		
	void pos(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> pos(const UList<scalar>& f);

	tmp<Field<scalar>> pos(const tmp<Field<scalar>>& tf);
		
	void neg(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> neg(const UList<scalar>& f);

	tmp<Field<scalar>> neg(const tmp<Field<scalar>>& tf);
		
	void exp(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> exp(const UList<scalar>& f);

	tmp<Field<scalar>> exp(const tmp<Field<scalar>>& tf);
		
	void log(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> log(const UList<scalar>& f);

	tmp<Field<scalar>> log(const tmp<Field<scalar>>& tf);
		
	void log10(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> log10(const UList<scalar>& f);

	tmp<Field<scalar>> log10(const tmp<Field<scalar>>& tf);
		
	void sin(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> sin(const UList<scalar>& f);

	tmp<Field<scalar>> sin(const tmp<Field<scalar>>& tf);
		
	void cos(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> cos(const UList<scalar>& f);

	tmp<Field<scalar>> cos(const tmp<Field<scalar>>& tf);
		
	void tan(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> tan(const UList<scalar>& f);

	tmp<Field<scalar>> tan(const tmp<Field<scalar>>& tf);
		
	void asin(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> asin(const UList<scalar>& f);

	tmp<Field<scalar>> asin(const tmp<Field<scalar>>& tf);
		
	void acos(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> acos(const UList<scalar>& f);

	tmp<Field<scalar>> acos(const tmp<Field<scalar>>& tf);
		
	void atan(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> atan(const UList<scalar>& f);

	tmp<Field<scalar>> atan(const tmp<Field<scalar>>& tf);
		
	void sinh(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> sinh(const UList<scalar>& f);

	tmp<Field<scalar>> sinh(const tmp<Field<scalar>>& tf);
		
	void cosh(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> cosh(const UList<scalar>& f);

	tmp<Field<scalar>> cosh(const tmp<Field<scalar>>& tf);
		
	void tanh(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> tanh(const UList<scalar>& f);

	tmp<Field<scalar>> tanh(const tmp<Field<scalar>>& tf);
		
	void asinh(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> asinh(const UList<scalar>& f);

	tmp<Field<scalar>> asinh(const tmp<Field<scalar>>& tf);
		
	void acosh(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> acosh(const UList<scalar>& f);

	tmp<Field<scalar>> acosh(const tmp<Field<scalar>>& tf);
		
	void atanh(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> atanh(const UList<scalar>& f);

	tmp<Field<scalar>> atanh(const tmp<Field<scalar>>& tf);
		
	void erf(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> erf(const UList<scalar>& f);

	tmp<Field<scalar>> erf(const tmp<Field<scalar>>& tf);
		
	void erfc(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> erfc(const UList<scalar>& f);

	tmp<Field<scalar>> erfc(const tmp<Field<scalar>>& tf);
		
	void lgamma(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> lgamma(const UList<scalar>& f);

	tmp<Field<scalar>> lgamma(const tmp<Field<scalar>>& tf);
		
	void j0(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> j0(const UList<scalar>& f);

	tmp<Field<scalar>> j0(const tmp<Field<scalar>>& tf);
		
	void j1(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> j1(const UList<scalar>& f);

	tmp<Field<scalar>> j1(const tmp<Field<scalar>>& tf);
		
	void y0(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> y0(const UList<scalar>& f);

	tmp<Field<scalar>> y0(const tmp<Field<scalar>>& tf);
		
	void y1(Field<scalar>& res, const UList<scalar>& f);

	tmp<Field<scalar>> y1(const UList<scalar>& f);

	tmp<Field<scalar>> y1(const tmp<Field<scalar>>& tf);
	

#define BesselFunc(func)                                            \
void func(scalarField& Res, const int n, const UList<scalar>& sf);  \
tmp<scalarField> func(const int n, const UList<scalar>&);           \
tmp<scalarField> func(const int n, const tmp<scalarField>&);

	void jn(scalarField& Res, const int n, const UList<scalar>& sf);
	tmp<scalarField> jn(const int n, const UList<scalar>&); 
	tmp<scalarField> jn(const int n, const tmp<scalarField>&);
		
	void yn(scalarField& Res, const int n, const UList<scalar>& sf);
	tmp<scalarField> yn(const int n, const UList<scalar>&); 
	tmp<scalarField> yn(const int n, const tmp<scalarField>&);

#undef BesselFunc
}

#include <undefFieldFunctionsM.hxx>

#endif // !1

