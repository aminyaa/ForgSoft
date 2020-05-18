#pragma once
#ifndef _FrgBase_PrptsVrntSelectTItem_Header
#define _FrgBase_PrptsVrntSelectTItem_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntSelectTItem_Base.hxx>

#include <QtCore/QObject>

BeginForgBaseLib

template <typename Type>
class FrgBase_PrptsWdgSelectTItem;

template <typename Type>
class FrgBase_PrptsVrntSelectTItem
	: public FrgBase_PrptsVrntSelectTItem_Base
{

public:

	explicit FrgBase_PrptsVrntSelectTItem
	(
		const char* displayName = "",
		FrgBase_TreeItem* tItem = nullptr,
		const char* prefix = "",
		const char* suffix = ""
	);

	typedef FrgBase_PrptsWdgSelectTItem<Type> VariantWidget;
};

EndForgBaseLib

#include <FrgBase_PrptsVrntSelectTItemI.hxx>

#endif // !_FrgBase_PrptsVrntSelectTItem_Header
