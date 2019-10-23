#pragma once
#ifndef _Vessel_FormCoeff_Info_Header
#define _Vessel_FormCoeff_Info_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

namespace AutLib
{

	class Vessel_FormCoeff_Info
	{

		/*Private Data*/

		Standard_Real theTolerance_;

	public:

		static const Standard_Real DEFAULT_TOLERANCE;

		Vessel_FormCoeff_Info()
			: theTolerance_(DEFAULT_TOLERANCE)
		{}

		//- Macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Tolerance)
	};
}

#endif // !_Vessel_FormCoeff_Info_Header
