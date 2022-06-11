#pragma once
#ifndef _FrgBase_VectorField_Header
#define _FrgBase_VectorField_Header

#include <FrgBase_VectorField_Entity.hxx>

BeginForgBaseLib

template <int Dim>
class FrgBase_VectorField
	: public FrgBase_VectorField_Entity
{

public:

	FrgBase_VectorField();

	~FrgBase_VectorField();

	//auto GetSize() const { return theValue_.size(); }

	//void CalcValue(const std::shared_ptr<FrgBase_FieldParser::Calculated>& calculated = false) override;
};

EndForgBaseLib

#include <FrgBase_VectorFieldI.hxx>

#endif // !_FrgBase_VectorField_Header
