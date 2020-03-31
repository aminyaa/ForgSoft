#pragma once
#ifndef _FrgBase_PrptsVrntPnt3d_Header
#define _FrgBase_PrptsVrntPnt3d_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>

#include <QtCore/QMetaType>
#include <QtCore/QObject>

BeginForgBaseLib

struct Pnt3d_Data
{
	Pnt3d_Data(double x = 0.0, double y = 0.0, double z = 0.0)
		: theX_(x), theY_(y), theZ_(z)
	{

	}

	double theX_;
	double theY_;
	double theZ_;
};

class FrgBase_PrptsWdgPnt3d;

class FORGBASE_EXPORT FrgBase_PrptsVrntPnt3d
	: public QObject
	, public FrgBase_PrptsVrntOneValue<Pnt3d_Data*, false>
{
	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntPnt3d
	(
		const char* displayName = "",
		Pnt3d_Data* value = nullptr,
		const char* prefix = "",
		const char* suffix = ""
	);

	void SetXValue(double x);
	void SetYValue(double y);
	void SetZValue(double z);

	typedef FrgBase_PrptsWdgPnt3d VariantWidget;

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

Q_SIGNALS:

	void DisplayNameChangedSignal(const char*);
	void ValueChangedSignal(Pnt3d_Data*);
	void PrefixChangedSignal(const char*);
	void SuffixChangedSignal(const char*);
};

Q_DECLARE_METATYPE(FrgBase_PrptsVrntPnt3d*)

EndForgBaseLib

#endif // !_FrgBase_PrptsVrntPnt3d_Header
