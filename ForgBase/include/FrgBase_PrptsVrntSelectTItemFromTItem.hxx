#pragma once
#ifndef _FrgBase_SelectTItemFromTItem_Header
#define _FrgBase_SelectTItemFromTItem_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntSelectTItemFromTItem_Base.hxx>

BeginForgBaseLib

template <typename Type>
class FrgBase_PrptsWdgSelectTItemFromTItem;

template <typename Type>
class FrgBase_PrptsVrntSelectTItemFromTItem
	: public FrgBase_PrptsVrntSelectTItemFromTItem_Base
{

public:

	explicit FrgBase_PrptsVrntSelectTItemFromTItem
	(
		const QString& displayName = "",
		Type* selectedItem = nullptr,
		std::function<std::vector<FrgBase_TreeItem*>()> parentItemsFunction = nullptr,
		const QString& prefix = "",
		const QString& suffix = ""
	);

	typedef FrgBase_PrptsWdgSelectTItemFromTItem<Type> VariantWidget;

	Type* GetValueByType() const;

private:

	friend class boost::serialization::access;
	template<class Archive>
	void save(Archive& ar, const unsigned int version) const
	{
		ar& boost::serialization::base_object<FrgBase_PrptsVrntSelectTItemFromTItem_Base>(*this);
	}

	template<class Archive>
	void load(Archive& ar, const unsigned int version)
	{
		ar& boost::serialization::base_object<FrgBase_PrptsVrntSelectTItemFromTItem_Base>(*this);
	}

	BOOST_SERIALIZATION_SPLIT_MEMBER()
};

EndForgBaseLib

#include <FrgBase_PrptsVrntSelectTItemFromTItemI.hxx>

#endif // !_FrgBase_SelectTItemFromTItem_Header
