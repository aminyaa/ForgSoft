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

	void CalcValue
	(
		const std::shared_ptr<FrgBase_FieldParser::Calculated>& calculated = nullptr
	) override;
};

EndForgBaseLib

#endif // !_FrgBase_ScalarField_Header
