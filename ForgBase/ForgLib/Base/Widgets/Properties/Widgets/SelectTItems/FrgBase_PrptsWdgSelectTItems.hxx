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
	void SetPrefix(const char* prefix) override;
	void SetSuffix(const char* suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<FrgBase_TreeItem*, false>& variant) override;

	void FormWidget();

private slots:

	void DisplayNameChangedSlot(const char* displayName);
	void PrefixChangedSlot(const char* prefix);
	void SuffixChangedSlot(const char* suffix);

	void OnButtonClickedSlot();

private:

	QLabel* thePrefixLabel_ = nullptr;
	QLabel* theSuffixLabel_ = nullptr;
	QLabel* theListOfSelectedTItemsLabel_ = nullptr;
	QToolButton* theButton_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgSelectTItems_Header
