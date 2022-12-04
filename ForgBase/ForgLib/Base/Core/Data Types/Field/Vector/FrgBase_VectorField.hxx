#pragma once
#ifndef _FrgBase_VectorField_Header
#define _FrgBase_VectorField_Header

#include <FrgBase_VectorField_Entity.hxx>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_VectorField
	: public FrgBase_VectorField_Entity
{

public:

	FrgBase_VectorField
	(
		const int size = 3
	);

	~FrgBase_VectorField() {}

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)
};

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_VectorField)

#include <FrgBase_VectorFieldI.hxx>

#endif // !_FrgBase_VectorField_Header
