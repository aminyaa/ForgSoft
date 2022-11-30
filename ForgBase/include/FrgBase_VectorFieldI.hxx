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