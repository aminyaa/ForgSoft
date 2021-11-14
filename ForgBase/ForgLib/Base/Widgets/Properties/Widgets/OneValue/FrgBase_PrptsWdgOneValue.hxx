#pragma once
#ifndef _FrgBase_PrptsWdgOneValue_Header
#define _FrgBase_PrptsWdgOneValue_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Object.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>

#include <QtWidgets/QWidget>

BeginForgBaseLib

class FrgBase_PrptsVrnt;
class FrgBase_TreeItem;

class FrgBase_PrptsWdg
	: public QWidget
	, public FrgBase_Object
{

	Q_OBJECT

public:

	FrgBase_PrptsWdg
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	) 
		: QWidget(parent)
		, theVariant_(variant) {}

	FrgBase_PrptsVrnt* GetVariantBasePtr() const { return theVariant_; }
	FrgBase_PrptsVrnt*& GetVariantBasePtrRef() { return theVariant_; }

	virtual void FormWidget() {}

	FrgBase_TreeItem* GetParentTItem() const { return theParentTItem_; }
	void SetParentTItem(FrgBase_TreeItem* parentTItem) { theParentTItem_ = parentTItem; }

protected:

	FrgBase_PrptsVrnt* theVariant_ = nullptr;
	FrgBase_TreeItem* theParentTItem_ = nullptr;
};

template <typename Type, bool IsBounded = true>
class FrgBase_PrptsWdgOneValue
	: public FrgBase_PrptsWdg
{

public:

	FrgBase_PrptsWdgOneValue
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgOneValue();

	virtual const Type& GetValue() const;
	virtual void SetValue(const Type& value);

	virtual const QString& GetPrefix() const;
	virtual void SetPrefix(const QString& prefix);
	virtual const QString& GetSuffix() const;
	virtual void SetSuffix(const QString& suffix);

	virtual const FrgBase_PrptsVrntOneValue<Type, IsBounded>& GetVariant() const;
	virtual void SetVariant(const FrgBase_PrptsVrntOneValue<Type, IsBounded>& variant);
};

EndForgBaseLib

#include <FrgBase_PrptsWdgOneValueI.hxx>

#endif // !_FrgBase_PrptsWdgOneValue_Header
