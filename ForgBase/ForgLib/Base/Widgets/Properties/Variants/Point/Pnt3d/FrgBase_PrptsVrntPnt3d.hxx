#pragma once
#ifndef _FrgBase_PrptsVrntPnt3d_Header
#define _FrgBase_PrptsVrntPnt3d_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>

#include <QtCore/QMetaType>
#include <QtCore/QObject>

BeginForgBaseLib

class FrgBase_Pnt3d;
class FrgBase_PrptsWdgPnt3d;

class FORGBASE_EXPORT FrgBase_PrptsVrntPnt3d
	: public QObject
	, public FrgBase_PrptsVrntOneValue<FrgBase_Pnt3d*, false>
{
	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntPnt3d
	(
		const char* displayName = "",
		FrgBase_Pnt3d* value = nullptr,
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
	void ValueChangedSignal(FrgBase_Pnt3d*);
	void PrefixChangedSignal(const char*);
	void SuffixChangedSignal(const char*);
};

Q_DECLARE_METATYPE(FrgBase_PrptsVrntPnt3d*)

EndForgBaseLib

#endif // !_FrgBase_PrptsVrntPnt3d_Header
