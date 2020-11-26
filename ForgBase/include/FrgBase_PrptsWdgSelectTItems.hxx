#pragma once
#ifndef _FrgBase_PrptsWdgSelectTItems_Header
#define _FrgBase_PrptsWdgSelectTItems_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgOneValue.hxx>

class QLabel;
class QToolButton;

BeginForgBaseLib

class FrgBase_TreeItem;
class FrgBase_PrptsVrnt;

class FORGBASE_EXPORT FrgBase_PrptsWdgSelectTItems
	: public FrgBase_PrptsWdgOneValue<FrgBase_TreeItem*, false>
{
	Q_OBJECT

public:

	FrgBase_PrptsWdgSelectTItems
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgSelectTItems();

	void SetValue(FrgBase_TreeItem*const & value) override;
	void SetPrefix(const QString& prefix) override;
	void SetSuffix(const QString& suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<FrgBase_TreeItem*, false>& variant) override;

	void FormWidget() override;

private slots:

	void DisplayNameChangedSlot(const QString& displayName);
	void PrefixChangedSlot(const QString& prefix);
	void SuffixChangedSlot(const QString& suffix);

	void OnButtonClickedSlot();

private:

	QLabel* thePrefixLabel_ = nullptr;
	QLabel* theSuffixLabel_ = nullptr;
	QLabel* theListOfSelectedTItemsLabel_ = nullptr;
	QToolButton* theButton_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgSelectTItems_Header
