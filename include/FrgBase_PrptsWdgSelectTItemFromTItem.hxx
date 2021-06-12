#pragma once
#ifndef _FrgBase_PrptsWdgSelectTItemFromTItem_Header
#define _FrgBase_PrptsWdgSelectTItemFromTItem_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgSelectTItemFromTItem_Base.hxx>

BeginForgBaseLib

template <typename Type>
class FrgBase_PrptsWdgSelectTItemFromTItem
	: public FrgBase_PrptsWdgSelectTItemFromTItem_Base
{

public:

	FrgBase_PrptsWdgSelectTItemFromTItem
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgSelectTItemFromTItem();

public:

	void OnButtonClicked() override;
};

EndForgBaseLib

#include <FrgBase_PrptsWdgSelectTItemFromTItemI.hxx>

#endif // !_FrgBase_PrptsWdgSelectTItemFromTItem_Header
