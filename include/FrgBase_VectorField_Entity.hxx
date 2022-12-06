#pragma once
#ifndef _FrgBase_VectorField_Entity_Header
#define _FrgBase_VectorField_Entity_Header

#include <FrgBase_Field.hxx>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_VectorField_Entity
	: public FrgBase_Field<std::vector<double>>
{

public:

	FrgBase_VectorField_Entity();

	~FrgBase_VectorField_Entity();

	bool IsVector() const override { return true; }

	std::string GetTypeAsString() const override;

	size_t GetSize() const { return theValue_.size(); }

	void CalcValue
	(
		const std::shared_ptr<FrgBase_FieldParser::Calculated>& calculated = nullptr
	) override;

	const auto& GetCalcValueFunction() const { return theCalcValueFunction_; }
	void SetCalcValueFunction(const std::function<std::vector<double>()>& f) { theCalcValueFunction_ = f; }

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

protected:

	std::function<std::vector<double>()> theCalcValueFunction_ = nullptr;
};

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_VectorField_Entity)

#endif // !_FrgBase_VectorField_Entity_Header
