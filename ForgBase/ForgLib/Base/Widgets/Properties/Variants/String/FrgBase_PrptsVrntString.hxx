#pragma once
#ifndef _FrgBase_PrptsVrntString_Header
#define _FrgBase_PrptsVrntString_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <FrgBase_Serialization_Global.hxx>

#include <QtCore/QMetaType>
#include <QtCore/QObject>

BeginForgBaseLib

class FrgBase_PrptsWdgString;

class FORGBASE_EXPORT FrgBase_PrptsVrntString
	: public QObject
	, public FrgBase_PrptsVrntOneValue<QString, false>
{

	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntString
	(
		const QString& displayName = "",
		const QString& value = "",
		const QString& prefix = "",
		const QString& suffix = ""
	);

	typedef FrgBase_PrptsWdgString VariantWidget;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

Q_SIGNALS:

	void DisplayNameChangedSignal(const QString&);
	void ValueChangedSignal(const QString&);
	void PrefixChangedSignal(const QString&);
	void SuffixChangedSignal(const QString&);
};

//Q_DECLARE_METATYPE(FrgBase_PrptsVrntString)
Q_DECLARE_METATYPE(FrgBase_PrptsVrntString*)

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_PrptsVrntString)

//Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntString)
//Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntString*)

#endif // !_FrgBase_PrptsVrntString_Header
