#pragma once
#ifndef _FrgBase_PrptsVrntString_Header
#define _FrgBase_PrptsVrntString_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <QtCore/QMetaType>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsVrntString
	: public FrgBase_PrptsVrntOneValue<QString, false>
{

public:

	explicit FrgBase_PrptsVrntString
	(
		const char* displayName = "",
		const QString& value = "",
		const char* prefix = "",
		const char* suffix = ""
	);
};

EndForgBaseLib

Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntString)
Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntString*)

#endif // !_FrgBase_PrptsVrntString_Header
