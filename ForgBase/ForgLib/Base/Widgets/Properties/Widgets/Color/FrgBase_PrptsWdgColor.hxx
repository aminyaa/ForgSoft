#pragma once
#ifndef _FrgBase_PrptsWdgColor_Header
#define _FrgBase_PrptsWdgColor_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgOneValue.hxx>

class QLabel;
class QToolButton;

BeginForgBaseLib

class FrgBase_PrptsVrntWdgColor_Label;

class FORGBASE_EXPORT FrgBase_PrptsWdgColor
	: public FrgBase_PrptsWdgOneValue<QColor, false>
{
	Q_OBJECT

public:

	FrgBase_PrptsWdgColor
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgColor();

	void SetValue(const QColor& value) override;

	void SetPrefix(const char* prefix) override;
	void SetSuffix(const char* suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<QColor, false>& variant) override;

	void FormWidget();

public slots:

	void OnColorButtonClickedSlot();

private slots:

	void DisplayNameChangedSlot(const char* displayName);
	void ValueChangedSlot(const QColor& value);
	void PrefixChangedSlot(const char* prefix);
	void SuffixChangedSlot(const char* suffix);

private:

	FrgBase_PrptsVrntWdgColor_Label* theColorLabel_ = nullptr;

	QLabel* thePrefixLabel_ = nullptr;
	QLabel* theSuffixLabel_ = nullptr;

	QToolButton* theColorButton_ = nullptr;

	void SetLabelWidgetColor(const QColor& color);
	void SetLabelWidgetColor(int red, int green, int blue);
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgColor_Header
