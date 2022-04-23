#include <FrgBase_ScalarField.hxx>

ForgBaseLib::FrgBase_ScalarField::FrgBase_ScalarField()
	: FrgBase_Field<double>()
{
	theValue_ = 0.0;
}