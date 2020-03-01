#pragma once
#ifndef _FrgBase_PrptsVrntInt_Header
#define _FrgBase_PrptsVrntInt_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <QtCore/QMetaType>
#include <QtCore/QObject>

BeginForgBaseLib

class FrgBase_PrptsWdgInt;

class FORGBASE_EXPORT FrgBase_PrptsVrntInt
	: public QObject
	, public FrgBase_PrptsVrntOneValue<int>
{

	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntInt
	(
		const char* displayName = "",
		int value = 0,
		int min = 0,
		int max = 100,
		int step = 1,
		const char* prefix = "",
		const char* suffix = ""
	);

	typedef FrgBase_PrptsWdgInt VariantWidget;

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void MinimumValueChanged() override;
	void MaximumValueChanged() override;
	void StepValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

Q_SIGNALS:

	void DisplayNameChangedSignal(const char*);
	void ValueChangedSignal(const int&);
	void MinimumValueChangedSignal(const int&);
	void MaximumValueChangedSignal(const int&);
	void StepValueChangedSignal(const int&);
	void PrefixChangedSignal(const char*);
	void SuffixChangedSignal(const char*);

};

//Q_DECLARE_METATYPE(FrgBase_PrptsVrntInt)
Q_DECLARE_METATYPE(FrgBase_PrptsVrntInt*)

EndForgBaseLib

//Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntInt)
//Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntInt*)

#endif // !_FrgBase_PrptsVrntInt_Header
