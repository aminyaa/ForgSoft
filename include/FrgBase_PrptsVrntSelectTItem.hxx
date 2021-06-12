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
		const QString& displayName = "",
		FrgBase_TreeItem* tItem = nullptr,
		const QString& prefix = "",
		const QString& suffix = ""
	);

	typedef FrgBase_PrptsWdgSelectTItem<Type> VariantWidget;

private:

	friend class boost::serialization::access;
	template<class Archive>
	void save(Archive& ar, const unsigned int version) const
	{
		ar& boost::serialization::base_object<FrgBase_PrptsVrntSelectTItem_Base>(*this);
	}

	template<class Archive>
	void load(Archive& ar, const unsigned int version)
	{
		ar& boost::serialization::base_object<FrgBase_PrptsVrntSelectTItem_Base>(*this);
	}

	BOOST_SERIALIZATION_SPLIT_MEMBER()
};

EndForgBaseLib

#include <FrgBase_PrptsVrntSelectTItemI.hxx>

#endif // !_FrgBase_PrptsVrntSelectTItem_Header
