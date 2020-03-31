#pragma once
#ifndef _FrgBase_PrptsVrntPnt2d_Header
#define _FrgBase_PrptsVrntPnt2d_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>

#include <QtCore/QMetaType>
#include <QtCore/QObject>

BeginForgBaseLib

struct Pnt2d_Data
{
	Pnt2d_Data(double x = 0.0, double y = 0.0)
		: theX_(x), theY_(y)
	{

	}

	double theX_;
	double theY_;
};

class FrgBase_PrptsWdgPnt2d;

class FORGBASE_EXPORT FrgBase_PrptsVrntPnt2d
	: public QObject
	, public FrgBase_PrptsVrntOneValue<Pnt2d_Data*, false>
{
	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntPnt2d
	(
		const char* displayName = "",
		Pnt2d_Data* value = nullptr,
		const char* prefix = "",
		const char* suffix = ""
	);

	void SetXValue(double x);
	void SetYValue(double y);

	typedef FrgBase_PrptsWdgPnt2d VariantWidget;

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

Q_SIGNALS:

	void DisplayNameChangedSignal(const char*);
	void ValueChangedSignal(Pnt2d_Data*);
	void PrefixChangedSignal(const char*);
	void SuffixChangedSignal(const char*);
};

Q_DECLARE_METATYPE(FrgBase_PrptsVrntPnt2d*)

EndForgBaseLib

#endif // !_FrgBase_PrptsVrntPnt2d_Header
