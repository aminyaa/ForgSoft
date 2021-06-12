#pragma once

template<typename Type>
inline ForgBaseLib::FrgBase_PrptsVrntSelectTItemFromTItem<Type>::FrgBase_PrptsVrntSelectTItemFromTItem
(
	const QString& displayName,
	Type* selectedItem,
	std::function<std::vector<FrgBase_TreeItem*>()> parentItemsFunction,
	const QString& prefix,
	const QString& suffix
)
	: ForgBaseLib::FrgBase_PrptsVrntSelectTItemFromTItem_Base(displayName, selectedItem, prefix, suffix)
{
	//theParentTItems_ = parentItems;
	theParentTItemsFunction_ = parentItemsFunction;
}

template<typename Type>
inline Type* ForgBaseLib::FrgBase_PrptsVrntSelectTItemFromTItem<Type>::GetValueByType() const
{
	auto myValue = dynamic_cast<Type*>(GetValue());
	return myValue;
}