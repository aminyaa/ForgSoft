#pragma once
#ifndef _FrgBase_PrptsVrntColor_Header
#define _FrgBase_PrptsVrntColor_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <QtCore/QMetaType>
#include <QtCore/QObject>
#include <QtGui/QColor>

BeginForgBaseLib

class FrgBase_PrptsWdgColor;

class FORGBASE_EXPORT FrgBase_PrptsVrntColor
	: public QObject
	, public FrgBase_PrptsVrntOneValue<QColor, false>
{
	Q_OBJECT

public:

	FrgBase_PrptsVrntColor
	(
		const char* displayName = "",
		QColor value = QColor(),
		const char* prefix = "",
		const char* suffix = ""
	);

	typedef FrgBase_PrptsWdgColor VariantWidget;

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

Q_SIGNALS:

	void DisplayNameChangedSignal(const char*);
	void ValueChangedSignal(const QColor&);
	void PrefixChangedSignal(const char*);
	void SuffixChangedSignal(const char*);
};

Q_DECLARE_METATYPE(FrgBase_PrptsVrntColor*)

EndForgBaseLib

#endif // !_FrgBase_PrptsVrntColor_Header
