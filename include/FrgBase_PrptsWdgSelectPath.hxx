#pragma once
#ifndef _FrgBase_PrptsWdgSelectPath_Header
#define _FrgBase_PrptsWdgSelectPath_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgOneValue.hxx>

class QLabel;
class QLineEdit;
class QToolButton;

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsWdgSelectPath
	: public FrgBase_PrptsWdgOneValue<QString, false>
{
	Q_OBJECT

public:

	FrgBase_PrptsWdgSelectPath
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgSelectPath();

	void SetValue(const QString& value) override;
	void SetPrefix(const QString& prefix) override;
	void SetSuffix(const QString& suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<QString, false>& variant) override;

	void FormWidget() override;

protected slots:

	void DisplayNameChangedSlot(const QString& displayName);
	void ValueChangedSlot(const QString&);
	void PrefixChangedSlot(const QString& prefix);
	void SuffixChangedSlot(const QString& suffix);

	void OnButtonClickedSlot();

protected:

	QLabel* thePrefixLabel_ = nullptr;
	QLabel* theSuffixLabel_ = nullptr;
	QLineEdit* theSelectedPathLabel_ = nullptr;
	QToolButton* theButton_ = nullptr;

	QWidget* theParent_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgSelectPath_Header
