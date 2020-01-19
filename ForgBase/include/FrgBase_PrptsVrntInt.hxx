#pragma once
#ifndef _FrgBase_PrptsVrntInt_Header
#define _FrgBase_PrptsVrntInt_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <QtCore/QMetaType>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsVrntInt
	: public FrgBase_PrptsVrntOneValue<int>
{

public:

	explicit FrgBase_PrptsVrntInt
	(
		int value = 0,
		int min = 0,
		int max = 100,
		int step = 1,
		const char* prefix = "",
		const char* suffix = ""
	);

};

EndForgBaseLib

Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntInt)
Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntInt*)

#endif // !_FrgBase_PrptsVrntInt_Header
