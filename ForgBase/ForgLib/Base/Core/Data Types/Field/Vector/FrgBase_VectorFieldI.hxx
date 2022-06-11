#pragma once

template<int Dim>
inline ForgBaseLib::FrgBase_VectorField<Dim>::FrgBase_VectorField()
	: FrgBase_VectorField_Entity()
{
	theValue_.reserve(Dim);

	for (int i = 0; i < Dim; i++)
		theValue_.push_back(0.0);
}

template<int Dim>
inline ForgBaseLib::FrgBase_VectorField<Dim>::~FrgBase_VectorField()
{

}

//template<int Dim>
//inline void ForgBaseLib::FrgBase_VectorField<Dim>::CalcValue(const std::shared_ptr<FrgBase_FieldParser::Calculated>& calculated)
//{
//	FrgBase_Field_Entity::CalcValue(calculated);
//
//	theIsCalculating_ = true;
//
//	auto value = FrgBase_FieldParser::CalcValueVector(this, calculated);
//	theValue_ = value;
//
//	theIsCalculating_ = false;
//}