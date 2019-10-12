#pragma once
#ifndef _dimensionedConstants_Header
#define _dimensionedConstants_Header

#include <dictionary.hxx>

namespace AutLib
{

	dictionary& dimensionedConstants();

	template<class T>
	T dimensionedConstant
	(
		const char* switchName,
		const T defaultValue
	)
	{
		if (dimensionedConstants().found(switchName))
		{
			return pTraits<T>(dimensionedConstants().lookup(switchName));
		}
		else
		{
			dimensionedConstants().add(switchName, defaultValue);

			return defaultValue;
		}
	}
}

#endif // !_dimensionedConstants_Header
