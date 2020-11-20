#pragma once

template<typename Type>
inline ForgBaseLib::FrgBase_PrptsVrntSelectTItem<Type>::FrgBase_PrptsVrntSelectTItem
(
	const QString& displayName,
	FrgBase_TreeItem * tItem,
	const QString& prefix,
	const QString& suffix
)
	: FrgBase_PrptsVrntSelectTItem_Base(displayName, tItem, prefix, suffix)
{

}