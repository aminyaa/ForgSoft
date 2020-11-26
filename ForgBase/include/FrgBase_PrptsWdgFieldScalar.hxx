#pragma once
#ifndef _FrgBase_PrptsWdgFieldScalar_Header
#define _FrgBase_PrptsWdgFieldScalar_Header

#include <FrgBase_PrptsWdgField.hxx>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsWdgFieldScalar
	: public FrgBase_PrptsWdgField
{
	Q_OBJECT

public:

	FrgBase_PrptsWdgFieldScalar
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgFieldScalar();
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgFieldScalar_Header
