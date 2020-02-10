#pragma once
#ifndef _VectorNFieldsFwd_Header
#define _VectorNFieldsFwd_Header

#include <VectorNFieldTypes.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	template<class Type> class Field;

#define makeTypedef(Type, args)      \
    typedef Field<Type > Type##Field;

	forAllVectorNTypes(makeTypedef)

		forAllTensorNTypes(makeTypedef)

		forAllDiagTensorNTypes(makeTypedef)

		forAllSphericalTensorNTypes(makeTypedef)

#undef makeTypedef

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_VectorNFieldsFwd_Header
