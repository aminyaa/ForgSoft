#pragma once
#ifndef _sphericalTensorField_Header
#define _sphericalTensorField_Header

#include <scalarField.hxx>
#include <sphericalTensor.hxx>

#define TEMPLATE
#include <FieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	typedef Field<sphericalTensor> sphericalTensorField;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
	 
	void tr(Field<scalar>& res, const UList<sphericalTensor>& f); 
	tmp<Field<scalar>> tr(const UList<sphericalTensor>& f); 
	tmp<Field<scalar>> tr(const tmp<Field<sphericalTensor>>& tf);
		
	void sph(Field<sphericalTensor>& res, const UList<sphericalTensor>& f); 
	tmp<Field<sphericalTensor>> sph(const UList<sphericalTensor>& f); 
	tmp<Field<sphericalTensor>> sph(const tmp<Field<sphericalTensor>>& tf);
		
	 
	void det(Field<scalar>& res, const UList<sphericalTensor>& f);
	tmp<Field<scalar>> det(const UList<sphericalTensor>& f);
	tmp<Field<scalar>> det(const tmp<Field<sphericalTensor>>& tf);		
	 
	void inv(Field<sphericalTensor>& res, const UList<sphericalTensor>& f); 
	tmp<Field<sphericalTensor>> inv(const UList<sphericalTensor>& f);
	tmp<Field<sphericalTensor>> inv(const tmp<Field<sphericalTensor>>& tf);		
	 
	void divide ( Field<sphericalTensor>& f, const UList<scalar>& f1, const UList<sphericalTensor>& f2 );  
	tmp<Field<sphericalTensor>> operator / ( const UList<scalar>& f1, const UList<sphericalTensor>& f2 ); 
	tmp<Field<sphericalTensor>> operator / ( const UList<scalar>& f1, const tmp<Field<sphericalTensor>>& tf2 );
	tmp<Field<sphericalTensor>> operator / ( const tmp<Field<scalar>>& tf1, const UList<sphericalTensor>& f2 );  
	tmp<Field<sphericalTensor>> operator / ( const tmp<Field<scalar>>& tf1, const tmp<Field<sphericalTensor>>& tf2 );
		
	 
	void divide ( Field<sphericalTensor>& f, const scalar& s1, const UList<sphericalTensor>& f2 );
	tmp<Field<sphericalTensor>> operator / ( const scalar& s1, const UList<sphericalTensor>& f2 );
	tmp<Field<sphericalTensor>> operator / ( const scalar& s1, const tmp<Field<sphericalTensor>>& tf2 );
	void divide ( Field<sphericalTensor>& f, const UList<scalar>& f1, const sphericalTensor& s2 );
	tmp<Field<sphericalTensor>> operator / ( const UList<scalar>& f1, const sphericalTensor& s2 ); 
	tmp<Field<sphericalTensor>> operator / ( const tmp<Field<scalar>>& tf1, const sphericalTensor& s2 );


		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <undefFieldFunctionsM.hxx>

#endif // !1
