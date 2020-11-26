#pragma once
#ifndef _FrgBase_PrptsVrntBool_Header
#define _FrgBase_PrptsVrntBool_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <FrgBase_Serialization_Global.hxx>

#include <QtCore/QMetaType>
#include <QtCore/QObject>

BeginForgBaseLib

class FrgBase_PrptsWdgBool;

class FORGBASE_EXPORT FrgBase_PrptsVrntBool
	: public QObject
	, public FrgBase_PrptsVrntOneValue<bool, false>
{

	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntBool
	(
		const QString& displayName = "",
		bool value = false,
		const QString& prefix = "",
		const QString& suffix = ""
	);

	typedef FrgBase_PrptsWdgBool VariantWidget;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

Q_SIGNALS:

	void DisplayNameChangedSignal(const QString&);
	void ValueChangedSignal(const bool&);
	void PrefixChangedSignal(const QString&);
	void SuffixChangedSignal(const QString&);

};

//Q_DECLARE_METATYPE(FrgBase_PrptsVrntBool)
Q_DECLARE_METATYPE(FrgBase_PrptsVrntBool*)

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_PrptsVrntBool)

//Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntBool)
//Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntBool*)

#endif // !_FrgBase_PrptsVrntBool_Header
