#pragma once
#ifndef _FrgBase_PrptsVrntTextEdit_Header
#define _FrgBase_PrptsVrntTextEdit_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <FrgBase_Serialization_Global.hxx>

#include <QtCore/QMetaType>
#include <QtCore/QObject>

BeginForgBaseLib

class FrgBase_PrptsWdgTextEdit;

class FORGBASE_EXPORT FrgBase_PrptsVrntTextEdit
	: public QObject
	, public FrgBase_PrptsVrntOneValue<QString, false>
{

	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntTextEdit
	(
		const QString& displayName = "",
		const QString& value = false,
		const QString& prefix = "",
		const QString& suffix = ""
	);

	typedef FrgBase_PrptsWdgTextEdit VariantWidget;

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

//Q_DECLARE_METATYPE(FrgBase_PrptsVrntBool)
Q_DECLARE_METATYPE(FrgBase_PrptsVrntTextEdit*)

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_PrptsVrntTextEdit)

#endif // !_FrgBase_PrptsVrntTextEdit_Header
