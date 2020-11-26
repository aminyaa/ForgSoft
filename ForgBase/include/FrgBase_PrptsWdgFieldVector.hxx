#pragma once
#ifndef _FrgBase_PrptsWdgFieldVector_Header
#define _FrgBase_PrptsWdgFieldVector_Header

#include <FrgBase_PrptsWdgField.hxx>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsWdgFieldVector
	: public FrgBase_PrptsWdgField
{

	Q_OBJECT

public:

	FrgBase_PrptsWdgFieldVector
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgFieldVector();

public slots:
	
	void ValueChangedSlot(const std::vector<double>& values);
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgFieldVector_Header
