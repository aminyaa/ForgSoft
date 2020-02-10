#pragma once
#ifndef _DimensionedSymmTensor4thOrderField_Header
#define _DimensionedSymmTensor4thOrderField_Header

#include <DimensionedField.hxx>
#include <symmTensor4thOrder.hxx>

#define TEMPLATE template<class GeoMesh>
#include <DimensionedFieldFunctionsM.hxx>

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
#   include <DimensionedSymmTensor4thOrderField.cxx>
#endif

#endif // !_DimensionedSymmTensor4thOrderField_Header
