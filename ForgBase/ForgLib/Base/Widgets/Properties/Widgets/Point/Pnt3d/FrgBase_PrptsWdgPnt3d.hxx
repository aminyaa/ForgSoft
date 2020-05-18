#pragma once
#ifndef _FrgBase_PrptsWdgPnt3d_Header
#define _FrgBase_PrptsWdgPnt3d_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgOneValue.hxx>

class QLineEdit;
class QLabel;

BeginForgBaseLib

class FrgBase_Pnt3d;

class FORGBASE_EXPORT FrgBase_PrptsWdgPnt3d
	: public FrgBase_PrptsWdgOneValue<FrgBase_Pnt3d*, false>
{

	Q_OBJECT

public:

	FrgBase_PrptsWdgPnt3d
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgPnt3d();

	void SetValue(FrgBase_Pnt3d* const& value) override;

	void SetPrefix(const char* prefix) override;
	void SetSuffix(const char* suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<FrgBase_Pnt3d*, false>& variant) override;

	void FormWidget();

	bool eventFilter(QObject *watched, QEvent *event) override;

private slots:

	void DisplayNameChangedSlot(const char* displayName);
	void ValueChangedSlot(FrgBase_Pnt3d* value);
	void PrefixChangedSlot(const char* prefix);
	void SuffixChangedSlot(const char* suffix);

	void WdgXValueChangedSlot();
	void WdgYValueChangedSlot();
	void WdgZValueChangedSlot();

private:

	QLineEdit* theXLineEdit_ = nullptr;
	QLineEdit* theYLineEdit_ = nullptr;
	QLineEdit* theZLineEdit_ = nullptr;

	QLabel* thePrefixLabel_ = nullptr;
	QLabel* theSuffixLabel_ = nullptr;
};

EndForgBaseLib

#endif // !_FrgBase_PrptsWdgPnt3d_Header
