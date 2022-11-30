#pragma once
#ifndef _FrgBase_Field_Header
#define _FrgBase_Field_Header

#include <FrgBase_Field_Entity.hxx>

BeginForgBaseLib

template <typename T>
class FrgBase_Field
	: public FrgBase_Field_Entity
{

public:
	
	FrgBase_Field()
		: FrgBase_Field_Entity()
	{

	}

	~FrgBase_Field()
	{

	}

	T GetValue() const { return theValue_; }

	T& GetValueRef() { return theValue_; }

protected:

	T theValue_;
};

EndForgBaseLib

#include <FrgBase_FieldI.hxx>

#endif // !_FrgBase_Field_Header
