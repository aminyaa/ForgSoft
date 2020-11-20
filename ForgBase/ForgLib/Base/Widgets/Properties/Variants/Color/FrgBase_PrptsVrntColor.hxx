#pragma once
#ifndef _FrgBase_PrptsVrntColor_Header
#define _FrgBase_PrptsVrntColor_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <FrgBase_Serialization_Global.hxx>

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
		const QString& displayName = "",
		QColor value = QColor(),
		const QString& prefix = "",
		const QString& suffix = ""
	);

	typedef FrgBase_PrptsWdgColor VariantWidget;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

Q_SIGNALS:

	void DisplayNameChangedSignal(const QString&);
	void ValueChangedSignal(const QColor&);
	void PrefixChangedSignal(const QString&);
	void SuffixChangedSignal(const QString&);
};

Q_DECLARE_METATYPE(FrgBase_PrptsVrntColor*)

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_PrptsVrntColor)

#endif // !_FrgBase_PrptsVrntColor_Header
