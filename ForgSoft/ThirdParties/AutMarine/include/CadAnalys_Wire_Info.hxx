#pragma once
#ifndef _CadAnalys_Wire_Info_Header
#define _CadAnalys_Wire_Info_Header

#include <Global_Verbose.hxx>
#include <Global_AccessMethod.hxx>

namespace AutLib
{

	class CadAnalys_Wire_Info
		: public Global_Verbose
	{

		/*Private Data*/

		Standard_Real thePrecision_;
		Standard_Real theSmallPrecision_;

	public:

		static const Standard_Real DEFAULT_PRECISION;
		static const Standard_Real DEFAULT_SMALL_PRECISION;

		CadAnalys_Wire_Info()
			: thePrecision_(DEFAULT_PRECISION)
			, theSmallPrecision_(DEFAULT_SMALL_PRECISION)
		{}

		//- Macros
		GLOBAL_ACCESS_SINGLE(Standard_Real, Precision)
			GLOBAL_ACCESS_SINGLE(Standard_Real, SmallPrecision)
	};
}

#endif // !_CadAnalys_Wire_Info_Header
