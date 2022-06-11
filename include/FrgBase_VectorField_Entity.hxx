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

	auto GetSize() const { return theValue_.size(); }

	void CalcValue(const std::shared_ptr<FrgBase_FieldParser::Calculated>& calculated = false) override;
};

EndForgBaseLib

#endif // !_FrgBase_VectorField_Entity_Header
