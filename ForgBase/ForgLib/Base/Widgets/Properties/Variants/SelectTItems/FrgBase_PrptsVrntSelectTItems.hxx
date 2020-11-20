#pragma once
#ifndef _FrgBase_PrptsVrntSelectTItems_Header
#define _FrgBase_PrptsVrntSelectTItems_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>

#include <QtCore/QObject>

class QTreeWidgetItem;

BeginForgBaseLib

class FrgBase_TreeItem;
class FrgBase_PrptsWdgSelectTItems;

class FORGBASE_EXPORT FrgBase_PrptsVrntSelectTItems
	: public QObject
	, public FrgBase_PrptsVrntOneValue<FrgBase_TreeItem*, false>
{
	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntSelectTItems
	(
		const QString& displayName = "",
		FrgBase_TreeItem* parentOfTItems = NullPtr,
		const QString& prefix = "",
		const QString& suffix = ""
	);

	typedef FrgBase_PrptsWdgSelectTItems VariantWidget;

	std::vector<QTreeWidgetItem*> GetSelectedTItems() const { return theListOfTItems_; }
	void SetSelectedTItems(std::vector<QTreeWidgetItem*> selectedTItems);

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

public:

	void SelectedTItemsChanged();

Q_SIGNALS:

	void DisplayNameChangedSignal(const QString&);
	void ValueChangedSignal(FrgBase_TreeItem*);
	void PrefixChangedSignal(const QString&);
	void SuffixChangedSignal(const QString&);
	void SelectedTItemsChangedSignal(std::vector<QTreeWidgetItem*>);

private:

	std::vector<QTreeWidgetItem*> theListOfTItems_;
};

Q_DECLARE_METATYPE(FrgBase_PrptsVrntSelectTItems*)

EndForgBaseLib

#endif // !_FrgBase_PrptsVrntSelectTItems_Header
