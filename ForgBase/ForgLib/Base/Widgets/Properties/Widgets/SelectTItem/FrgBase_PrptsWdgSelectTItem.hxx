#pragma once
#ifndef _FrgBase_PrptsWdgSelectTItem_Header
#define _FrgBase_PrptsWdgSelectTItem_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgSelectTItem_Base.hxx>

BeginForgBaseLib

template <typename Type>
class FrgBase_PrptsWdgSelectTItem
	: public FrgBase_PrptsWdgSelectTItem_Base
{

public:

	FrgBase_PrptsWdgSelectTItem
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgSelectTItem();

protected:

	void OnButtonClicked() override;
};

EndForgBaseLib

#include <FrgBase_PrptsWdgSelectTItemI.hxx>

#endif // !_FrgBase_PrptsWdgSelectTItem_Header
