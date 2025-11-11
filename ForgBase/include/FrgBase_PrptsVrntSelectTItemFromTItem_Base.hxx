#pragma once
#ifndef _FrgBase_PrptsVrntSelectTItemFromTItem_Base_Header
#define _FrgBase_PrptsVrntSelectTItemFromTItem_Base_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>

#include <QtCore/QObject>

BeginForgBaseLib

class FrgBase_TreeItem;

class FORGBASE_EXPORT FrgBase_PrptsVrntSelectTItemFromTItem_Base
	: public QObject
	, public FrgBase_PrptsVrntOneValue<FrgBase_TreeItem*, false>
{

	Q_OBJECT

public:

	FrgBase_PrptsVrntSelectTItemFromTItem_Base
	(
		const QString& displayName = "",
		FrgBase_TreeItem* tItem = nullptr,
		const QString& prefix = "",
		const QString& suffix = ""
	);

	std::vector<FrgBase_TreeItem*> GetParentTItems() const;

	const std::function<std::vector<FrgBase_TreeItem*>()>& GetParentItemsFunction() const { return theParentTItemsFunction_; }
	void SetParentItemsFunction(const std::function<std::vector<FrgBase_TreeItem*>()>& func) { theParentTItemsFunction_ = func; }

	const std::function<FrgBase_TreeItem* ()>& GetSelectTItemFunction() const { return theSelectTItemFunction_; }
	void SetSelectTItemFunction(const std::function<FrgBase_TreeItem*()>& function) { theSelectTItemFunction_ = function; }

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

protected:

	std::function<std::vector<FrgBase_TreeItem*>()> theParentTItemsFunction_;
	//std::vector<FrgBase_TreeItem*> theParentTItems_;

	std::function<FrgBase_TreeItem*()> theSelectTItemFunction_ = nullptr;

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

Q_SIGNALS:

	void DisplayNameChangedSignal(const QString&);
	void ValueChangedSignal(FrgBase_TreeItem*);
	void PrefixChangedSignal(const QString&);
	void SuffixChangedSignal(const QString&);
};

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_PrptsVrntSelectTItemFromTItem_Base)

#endif // !_FrgBase_PrptsVrntSelectTItemFromTItem_Base_Header
