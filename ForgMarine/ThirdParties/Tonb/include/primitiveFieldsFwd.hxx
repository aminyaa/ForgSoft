#pragma once
#ifndef _primitiveFieldsFwd_Header
#define _primitiveFieldsFwd_Header

#include <fieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	template<class Type> class Field;

	typedef Field<label> labelField;
	typedef Field<scalar> scalarField;
	typedef Field<vector> vectorField;
	typedef Field<sphericalTensor> sphericalTensorField;
	typedef Field<symmTensor> symmTensorField;
	typedef Field<symmTensor4thOrder> symmTensor4thOrderField;
	typedef Field<diagTensor> diagTensorField;
	typedef Field<tensor> tensorField;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !1
