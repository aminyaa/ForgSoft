#pragma once
#ifndef _FrgBase_PrptsVrntBool_Header
#define _FrgBase_PrptsVrntBool_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <QtCore/QMetaType>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsVrntBool
	: public FrgBase_PrptsVrntOneValue<bool, false>
{

public:

	explicit FrgBase_PrptsVrntBool
	(
		const char* displayName = "",
		bool value = false,
		const char* prefix = "",
		const char* suffix = ""
	);

};

EndForgBaseLib

Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntBool)
Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntBool*)

#endif // !_FrgBase_PrptsVrntBool_Header
