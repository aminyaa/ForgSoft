#pragma once
#ifndef _symmTensorField_Header
#define _symmTensorField_Header

#include <scalarField.hxx>
#include <vectorField.hxx>
#include <sphericalTensor.hxx>
#include <symmTensor.hxx>
#include <tensor.hxx>

#define TEMPLATE
#include <FieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	typedef Field<symmTensor> symmTensorField;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	 
	void sqr(Field<symmTensor>& res, const UList<vector>& f); 
	tmp<Field<symmTensor>> sqr(const UList<vector>& f); 
	tmp<Field<symmTensor>> sqr(const tmp<Field<vector>>& tf);		
	 
	void innerSqr(Field<symmTensor>& res, const UList<symmTensor>& f);
	tmp<Field<symmTensor>> innerSqr(const UList<symmTensor>& f); 
	tmp<Field<symmTensor>> innerSqr(const tmp<Field<symmTensor>>& tf);
 
	void tr(Field<scalar>& res, const UList<symmTensor>& f);
	tmp<Field<scalar>> tr(const UList<symmTensor>& f);
	tmp<Field<scalar>> tr(const tmp<Field<symmTensor>>& tf);
		 
	void sph(Field<sphericalTensor>& res, const UList<symmTensor>& f);
	tmp<Field<sphericalTensor>> sph(const UList<symmTensor>& f); 
	tmp<Field<sphericalTensor>> sph(const tmp<Field<symmTensor>>& tf);
		 
	void symm(Field<symmTensor>& res, const UList<symmTensor>& f); 
	tmp<Field<symmTensor>> symm(const UList<symmTensor>& f);
	tmp<Field<symmTensor>> symm(const tmp<Field<symmTensor>>& tf);
		 
	void twoSymm(Field<symmTensor>& res, const UList<symmTensor>& f);
	tmp<Field<symmTensor>> twoSymm(const UList<symmTensor>& f); 
	tmp<Field<symmTensor>> twoSymm(const tmp<Field<symmTensor>>& tf);
		 
	void dev(Field<symmTensor>& res, const UList<symmTensor>& f); 
	tmp<Field<symmTensor>> dev(const UList<symmTensor>& f); 
	tmp<Field<symmTensor>> dev(const tmp<Field<symmTensor>>& tf);
		 
	void dev2(Field<symmTensor>& res, const UList<symmTensor>& f); 
	tmp<Field<symmTensor>> dev2(const UList<symmTensor>& f); 
	tmp<Field<symmTensor>> dev2(const tmp<Field<symmTensor>>& tf);
		 
	void det(Field<scalar>& res, const UList<symmTensor>& f); 
	tmp<Field<scalar>> det(const UList<symmTensor>& f);  
	tmp<Field<scalar>> det(const tmp<Field<symmTensor>>& tf);
		 
	void cof(Field<symmTensor>& res, const UList<symmTensor>& f); 
	tmp<Field<symmTensor>> cof(const UList<symmTensor>& f); 
	tmp<Field<symmTensor>> cof(const tmp<Field<symmTensor>>& tf);
		 
	void inv(Field<symmTensor>& res, const UList<symmTensor>& f); 
	tmp<Field<symmTensor>> inv(const UList<symmTensor>& f); 
	tmp<Field<symmTensor>> inv(const tmp<Field<symmTensor>>& tf);
		 
	void hinv(Field<symmTensor>& res, const UList<symmTensor>& f);
	tmp<Field<symmTensor>> hinv(const UList<symmTensor>& f);
	tmp<Field<symmTensor>> hinv(const tmp<Field<symmTensor>>& tf);


		// * * * * * * * * * * * * * * * global operators  * * * * * * * * * * * * * //

		 
	void hdual(Field<vector>& res, const UList<symmTensor>& f);
	tmp<Field<vector>> operator *(const UList<symmTensor>& f); 
	tmp<Field<vector>> operator *(const tmp<Field<symmTensor>>& tf);

		 
	void dot ( Field<tensor>& f, const UList<symmTensor>& f1, const UList<symmTensor>& f2 );
	tmp<Field<tensor>> operator & ( const UList<symmTensor>& f1, const UList<symmTensor>& f2 ); 
	tmp<Field<tensor>> operator & ( const UList<symmTensor>& f1, const tmp<Field<symmTensor>>& tf2 );
	tmp<Field<tensor>> operator & ( const tmp<Field<symmTensor>>& tf1, const UList<symmTensor>& f2 ); 
	tmp<Field<tensor>> operator & ( const tmp<Field<symmTensor>>& tf1, const tmp<Field<symmTensor>>& tf2 );
		 
	void dot ( Field<tensor>& f, const symmTensor& s1, const UList<symmTensor>& f2 ); 
	tmp<Field<tensor>> operator & ( const symmTensor& s1, const UList<symmTensor>& f2 ); 
	tmp<Field<tensor>> operator & ( const symmTensor& s1, const tmp<Field<symmTensor>>& tf2 ); 
	void dot ( Field<tensor>& f, const UList<symmTensor>& f1, const symmTensor& s2 );
	tmp<Field<tensor>> operator & ( const UList<symmTensor>& f1, const symmTensor& s2 ); 
	tmp<Field<tensor>> operator & ( const tmp<Field<symmTensor>>& tf1, const symmTensor& s2 );


		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <undefFieldFunctionsM.hxx>

#endif // !1
