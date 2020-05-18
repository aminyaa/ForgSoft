#pragma once
#ifndef _FrgBase_PrptsVrntPnt2d_Header
#define _FrgBase_PrptsVrntPnt2d_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>

#include <QtCore/QMetaType>
#include <QtCore/QObject>

BeginForgBaseLib

class FrgBase_Pnt2d;
class FrgBase_PrptsWdgPnt2d;

class FORGBASE_EXPORT FrgBase_PrptsVrntPnt2d
	: public QObject
	, public FrgBase_PrptsVrntOneValue<FrgBase_Pnt2d*, false>
{
	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntPnt2d
	(
		const char* displayName = "",
		FrgBase_Pnt2d* value = nullptr,
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
	void ValueChangedSignal(FrgBase_Pnt2d*);
	void PrefixChangedSignal(const char*);
	void SuffixChangedSignal(const char*);
};

Q_DECLARE_METATYPE(FrgBase_PrptsVrntPnt2d*)

EndForgBaseLib

#endif // !_FrgBase_PrptsVrntPnt2d_Header
