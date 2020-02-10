#pragma once
#ifndef _FrgBase_PrptsVrntString_Header
#define _FrgBase_PrptsVrntString_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <QtCore/QMetaType>
#include <QtCore/QObject>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsVrntString
	: public QObject
	, public FrgBase_PrptsVrntOneValue<QString, false>
{

	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntString
	(
		const char* displayName = "",
		const QString& value = "",
		const char* prefix = "",
		const char* suffix = ""
	);

protected:

	void DisplayNameChanged() override;
	void ValueChanged() override;
	void PrefixChanged() override;
	void SuffixChanged() override;

Q_SIGNALS:

	void DisplayNameChangedSignal(const char*);
	void ValueChangedSignal(const QString&);
	void PrefixChangedSignal(const char*);
	void SuffixChangedSignal(const char*);
};

//Q_DECLARE_METATYPE(FrgBase_PrptsVrntString)
Q_DECLARE_METATYPE(FrgBase_PrptsVrntString*)

EndForgBaseLib

//Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntString)
//Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntString*)

#endif // !_FrgBase_PrptsVrntString_Header
