#pragma once
#ifndef _vectorField_Header
#define _vectorField_Header

#include <scalarField.hxx>
#include <vector.hxx>

#define TEMPLATE
#include <FieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	typedef Field<vector> vectorField;


	// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

	 void scaleRow(Field<vector>& f, const UList<vector>& f1, const UList<scalar>& f2);

	tmp<Field<vector>> scaleRow(const UList<vector>& f1, const UList<scalar>& f2);

	tmp<Field<vector>> scaleRow(const UList<vector>& f1, const tmp<Field<scalar>>& tf2);

	tmp<Field<vector>> scaleRow(const tmp<Field<vector>>& tf1, const UList<scalar>& f2);

	tmp<Field<vector>> scaleRow(const tmp<Field<vector>>& tf1, const tmp<Field<scalar>>& tf2);
		
	 void scaleRow(Field<vector>& f, const vector& s1, const UList<scalar>& f2);

	tmp<Field<vector>> scaleRow(const vector& s1, const UList<scalar>& f2);

	tmp<Field<vector>> scaleRow(const vector& s1, const tmp<Field<scalar>>& tf2);

	void scaleRow(Field<vector>& f, const UList<vector>& f1, const scalar& s2);

	tmp<Field<vector>> scaleRow(const UList<vector>& f1, const scalar& s2);

	tmp<Field<vector>> scaleRow(const tmp<Field<vector>>& tf1, const scalar& s2);


		// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <undefFieldFunctionsM.hxx>

#endif // !1
