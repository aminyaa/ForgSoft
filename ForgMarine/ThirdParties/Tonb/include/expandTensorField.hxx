#pragma once
#ifndef _expandTensorField_Header
#define _expandTensorField_Header

#include <tensorField.hxx>

#define TEMPLATE
#include <FieldFunctionsM.hxx>

namespace tnbLib
{

	// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

	void contractScalar(Field<scalar>& res, const UList<tensor>& f);
	void contractLinear(Field<vector>& res, const UList<tensor>& f);

	void expandScalar(Field<vector>& res, const UList<scalar>& f);

	void expandScalar(Field<tensor>& res, const UList<scalar>& f);
	void expandLinear(Field<tensor>& res, const UList<vector>& f);

	void sumToDiag(Field<vector>& res, const UList<tensor>& f);
	void sumMagToDiag(Field<vector>& res, const UList<tensor>& f);

} // End namespace tnbLib

#include <undefFieldFunctionsM.hxx>

#endif // !_expandTensorField_Header
