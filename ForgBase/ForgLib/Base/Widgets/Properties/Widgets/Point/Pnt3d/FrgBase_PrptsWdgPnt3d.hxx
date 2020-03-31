#pragma once
#ifndef _FrgBase_PrptsWdgPnt3d_Header
#define _FrgBase_PrptsWdgPnt3d_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsWdgOneValue.hxx>

class QLineEdit;
class QLabel;

BeginForgBaseLib

struct Pnt3d_Data;

class FORGBASE_EXPORT FrgBase_PrptsWdgPnt3d
	: public FrgBase_PrptsWdgOneValue<Pnt3d_Data*, false>
{

	Q_OBJECT

public:

	FrgBase_PrptsWdgPnt3d
	(
		QWidget* parent = nullptr,
		FrgBase_PrptsVrnt* variant = nullptr
	);

	~FrgBase_PrptsWdgPnt3d();

	void SetValue(Pnt3d_Data* const& value) override;

	void SetPrefix(const char* prefix) override;
	void SetSuffix(const char* suffix) override;

	void SetVariant(const FrgBase_PrptsVrntOneValue<Pnt3d_Data*, false>& variant) override;

	void FormWidget();

private slots:

	void DisplayNameChangedSlot(const char* displayName);
	void ValueChangedSlot(Pnt3d_Data* value);
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
