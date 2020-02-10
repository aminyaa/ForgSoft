#pragma once
#ifndef _symmTensor4thOrderField_Header
#define _symmTensor4thOrderField_Header

#include <scalarField.hxx>
#include <vectorField.hxx>
#include <sphericalTensor.hxx>
#include <symmTensor4thOrder.hxx>

#define TEMPLATE
#include <FieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	typedef Field<symmTensor4thOrder> symmTensor4thOrderField;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


	// * * * * * * * * * * * * * * * global operators  * * * * * * * * * * * * * //


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <undefFieldFunctionsM.hxx>

#endif // !1
