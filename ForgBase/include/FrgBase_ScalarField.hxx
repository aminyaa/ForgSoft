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

	std::string GetTypeAsString() const override { return "Scalar"; }

	void CalcValue
	(
		const std::shared_ptr<FrgBase_FieldParser::Calculated>& calculated = nullptr
	) override;

	const auto& GetCalcValueFunction() const { return theCalcValueFunction_; }
	void SetCalcValueFunction(const std::function<double()>& f) { theCalcValueFunction_ = f; }

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

protected:

	std::function<double()> theCalcValueFunction_ = nullptr;
};

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_ScalarField)

#endif // !_FrgBase_ScalarField_Header
