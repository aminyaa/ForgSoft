#pragma once
#ifndef _Mesh_VariationRate_Header
#define _Mesh_VariationRate_Header

#include <Standard_Real.hxx>
#include <Global_AccessMethod.hxx>
#include <Mesh_VariationRateInfo.hxx>

namespace AutLib
{

	class Mesh_VariationRate
	{

		/*Private Data*/

		Standard_Real theCustom_;

	public:

		static const Standard_Real DEFAULT_VERYLOWRATE;
		static const Standard_Real DEFAULT_LOWRATE;
		static const Standard_Real DEFAULT_MODERATE;
		static const Standard_Real DEFAULT_FASTRATE;

		Mesh_VariationRate()
		{}

		Standard_Real Rate(const Mesh_VariationRateInfo Info);


		//- Static functions and operators

		static Standard_Real VeryLowrate()
		{
			return DEFAULT_VERYLOWRATE;
		}

		static Standard_Real Lowrate()
		{
			return DEFAULT_LOWRATE;
		}

		static Standard_Real Moderate()
		{
			return DEFAULT_MODERATE;
		}

		static Standard_Real Highrate()
		{
			return DEFAULT_FASTRATE;
		}


		//- Macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Custom)
	};
}

#endif // !_Mesh_VariationRate_Header
