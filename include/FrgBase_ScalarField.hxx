#pragma once
#ifndef _FrgBase_ScalarField_Header
#define _FrgBase_ScalarField_Header

#include <FrgBase_Field.hxx>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_ScalarField
	: public FrgBase_Field<double>
{

public:

	FrgBase_ScalarField();

	bool IsScalar() const override { return true; }
};

EndForgBaseLib

#endif // !_FrgBase_ScalarField_Header
