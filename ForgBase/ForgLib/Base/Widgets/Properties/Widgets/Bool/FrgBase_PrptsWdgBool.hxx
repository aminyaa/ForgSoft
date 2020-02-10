#pragma once
#ifndef _FrgBase_PrptsWdgBool_Header
#define _FrgBase_PrptsWdgBool_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgOneValue.hxx>

class QCheckBox;
class QLabel;

BeginForgBaseLib

class FrgBase_PropertiesPanel;

class FORGBASE_EXPORT FrgBase_PrptsVrntBool;

class FrgBase_PrptsWdgBool
	: public FrgBase_PrptsWdgOneValue<bool, false>
{

	Q_OBJECT

public:

	FrgBase_PrptsWdgBool
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrntBool* variant = nullptr
	);

	void SetValue(const bool& value) override;

	void SetPrefix(const char* prefix) override;
	void SetSuffix(const char* suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<bool, false>& variant) override;

	QCheckBox* GetCheckBox() const { return theCheckBox_; }

	void FormWidget();

private slots:

	void DisplayNameChangedSlot(const char* displayName);
	void ValueChangedSlot(const bool& value);
	void PrefixChangedSlot(const char* prefix);
	void SuffixChangedSlot(const char* suffix);
	void WdgValueChangedSlot(bool checked);

protected:

	//void mouseReleaseEvent(QMouseEvent *event) override;
	//bool eventFilter(QObject *obj, QEvent *event) override;

private slots:

private:

	QCheckBox* theCheckBox_ = nullptr;
	QLabel* thePrefixLabel_ = nullptr;
	QLabel* theSuffixLabel_ = nullptr;
	
	FrgBase_PropertiesPanel* theParentPropertiesPanel_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgBool_Header
