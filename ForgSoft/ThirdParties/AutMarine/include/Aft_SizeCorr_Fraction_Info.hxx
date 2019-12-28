#pragma once
#ifndef _Aft_SizeCorr_Fraction_Info_Header
#define _Aft_SizeCorr_Fraction_Info_Header

#include <Global_AccessMethod.hxx>
#include <Standard_TypeDef.hxx>

namespace AutLib
{

	class Aft_SizeCorr_Fraction_Info
	{

		/*Private Data*/

		Standard_Real theDelta_;
		Standard_Real theCoeff_;

	public:

		static const Standard_Real DEFAULT_DELTA;
		static const Standard_Real DEFAULT_COEFF;

		Aft_SizeCorr_Fraction_Info()
			: theDelta_(DEFAULT_DELTA)
			, theCoeff_(DEFAULT_COEFF)
		{}

		//- Macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Delta)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Coeff)
	};
}

#endif // !_Aft_SizeCorr_Faction_Info_Header
