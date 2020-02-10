#pragma once
#ifndef _DimensionedDiagTensorField_Header
#define _DimensionedDiagTensorField_Header

#include <diagTensor.hxx>

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
#   include <DimensionedDiagTensorField.cxx>
#endif

#endif // !_DimensionedDiagTensorField_Header
