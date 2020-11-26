#pragma once
#ifndef _FrgBase_PrptsWdgSelectTItem_Base_Header
#define _FrgBase_PrptsWdgSelectTItem_Base_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgOneValue.hxx>

class QLabel;
class QToolButton;

BeginForgBaseLib

class FrgBase_TreeItem;

class FORGBASE_EXPORT FrgBase_PrptsWdgSelectTItem_Base
	: public FrgBase_PrptsWdgOneValue<FrgBase_TreeItem*, false>
{
	Q_OBJECT

public:

	FrgBase_PrptsWdgSelectTItem_Base
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgSelectTItem_Base();

	void SetValue(FrgBase_TreeItem*const & value) override;
	void SetPrefix(const QString& prefix) override;
	void SetSuffix(const QString& suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<FrgBase_TreeItem*, false>& variant) override;

	void FormWidget() override;

protected slots:

	void DisplayNameChangedSlot(const QString& displayName);
	void ValueChangedSlot(FrgBase_TreeItem*);
	void PrefixChangedSlot(const QString& prefix);
	void SuffixChangedSlot(const QString& suffix);

	void OnButtonClickedSlot();

protected:

	QLabel* thePrefixLabel_ = nullptr;
	QLabel* theSuffixLabel_ = nullptr;
	QLabel* theSelectedTItemLabel_ = nullptr;
	QToolButton* theButton_ = nullptr;

	QWidget* theParent_ = nullptr;

	virtual void OnButtonClicked() {}
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgSelectTItem_Base_Header
