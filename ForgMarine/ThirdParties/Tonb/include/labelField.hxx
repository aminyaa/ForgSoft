#pragma once
#ifndef _labelField_Header
#define _labelField_Header

#include <label.hxx>
#include <Field.hxx>

#define TEMPLATE
#include <FieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	typedef Field<label> labelField;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	 
	void add ( Field<label>& f, const label& s1, const UList<label>& f2 );
	tmp<Field<label>> operator + ( const label& s1, const UList<label>& f2 ); 
	tmp<Field<label>> operator + ( const label& s1, const tmp<Field<label>>& tf2 );

	void add ( Field<label>& f, const UList<label>& f1, const label& s2 );
	tmp<Field<label>> operator + ( const UList<label>& f1, const label& s2 );  
	tmp<Field<label>> operator + ( const tmp<Field<label>>& tf1, const label& s2 );
		
	void subtract ( Field<label>& f, const label& s1, const UList<label>& f2 );
	tmp<Field<label>> operator - ( const label& s1, const UList<label>& f2 ); 
	tmp<Field<label>> operator - ( const label& s1, const tmp<Field<label>>& tf2 );
	
	 
	void subtract ( Field<label>& f, const UList<label>& f1, const label& s2 );
	tmp<Field<label>> operator - ( const UList<label>& f1, const label& s2 ); 
	tmp<Field<label>> operator - ( const tmp<Field<label>>& tf1, const label& s2 );


		
	template<>
	tmp<labelField> labelField::component(const direction) const;

	template<>
	void component
	(
		labelField& lf,
		const UList<label>& f,
		const direction
	);

	template<>
	void labelField::replace(const direction, const UList<label>& lf);


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <undefFieldFunctionsM.hxx>

#endif // !1
