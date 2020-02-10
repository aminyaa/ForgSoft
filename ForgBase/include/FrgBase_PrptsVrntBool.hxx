#pragma once
#ifndef _FrgBase_PrptsVrntBool_Header
#define _FrgBase_PrptsVrntBool_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <QtCore/QMetaType>
#include <QtCore/QObject>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsVrntBool
	: public QObject
	, public FrgBase_PrptsVrntOneValue<bool, false>
{

	Q_OBJECT

public:

	explicit FrgBase_PrptsVrntBool
	(
		const char* displayName = "",
		bool value = false,
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
	void ValueChangedSignal(const bool&);
	void PrefixChangedSignal(const char*);
	void SuffixChangedSignal(const char*);

};

//Q_DECLARE_METATYPE(FrgBase_PrptsVrntBool)
Q_DECLARE_METATYPE(FrgBase_PrptsVrntBool*)

EndForgBaseLib

//Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntBool)
//Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntBool*)

#endif // !_FrgBase_PrptsVrntBool_Header
