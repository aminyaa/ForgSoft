#pragma once
#ifndef _FrgBase_PrptsVrntDouble_Header
#define _FrgBase_PrptsVrntDouble_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <QtCore/QMetaType>
#include <QtCore/QObject>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsVrntDouble
	: public QObject
	, public FrgBase_PrptsVrntOneValue<double>
{

	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntDouble
	(
		const char* displayName = "",
		double value = 0.0,
		double min = 0.0,
		double max = 1.0,
		double step = 0.01,
		const char* prefix = "",
		const char* suffix = ""
	);

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
	void ValueChangedSignal(const double&);
	void MinimumValueChangedSignal(const double&);
	void MaximumValueChangedSignal(const double&);
	void StepValueChangedSignal(const double&);
	void PrefixChangedSignal(const char*);
	void SuffixChangedSignal(const char*);
};

//Q_DECLARE_METATYPE(FrgBase_PrptsVrntDouble)
Q_DECLARE_METATYPE(FrgBase_PrptsVrntDouble*)

EndForgBaseLib

//Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntDouble)
//Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntDouble*)

#endif // !_FrgBase_PrptsVrntDouble_Header
