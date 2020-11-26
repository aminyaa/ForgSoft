#pragma once
#ifndef _symmTensor4thOrderFieldField_Header
#define _symmTensor4thOrderFieldField_Header

#include <symmTensor4thOrder.hxx>

#define TEMPLATE template<template<class> class Field>
#include <FieldFunctionsM.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


	// * * * * * * * * * * * * * * * global operators  * * * * * * * * * * * * * //



	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include <undefFieldFunctionsM.hxx>

#ifdef NoRepository
#   include <symmTensor4thOrderFieldField.cxx>
#endif

#endif // !_symmTensor4thOrderFieldField_Header
