#pragma once
#ifndef _FrgBase_PrptsVrntDouble_Header
#define _FrgBase_PrptsVrntDouble_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_PrptsVrntOneValue.hxx>
#include <QtCore/QMetaType>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_PrptsVrntDouble
	: public FrgBase_PrptsVrntOneValue<double>
{
public:

	explicit FrgBase_PrptsVrntDouble
	(
		double value = 0.0,
		double min = 0.0,
		double max = 1.0,
		double step = 0.01,
		const char* prefix = "",
		const char* suffix = ""
	);
};

EndForgBaseLib

Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntDouble)
Q_DECLARE_METATYPE(ForgBaseLib::FrgBase_PrptsVrntDouble*)

#endif // !_FrgBase_PrptsVrntDouble_Header
