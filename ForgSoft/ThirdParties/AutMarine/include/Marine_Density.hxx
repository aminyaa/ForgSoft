#pragma once
#ifndef _Marine_Density_Header
#define _Marine_Density_Header

#include <Marine_DimensionedParam.hxx>

namespace AutLib
{

	namespace marineLib
	{

		// density of water in SI units of systems
		template<Marine_UnitsSys Sys = Marine_UnitsSys_SI>
		class Density
			: public realParam
		{

			/*Private Data*/

		protected:

			explicit Density
			(
				const Standard_Real theValue
			)
				: realParam
				(
					"density",
					dimDensity,
					theValue
				)
			{}
		};


		// density of water in imperial units of systems
		template<>
		class Density<Marine_UnitsSys_Imperial>
			: public realParam
		{

			/*Private Data*/

		protected:

			explicit Density
			(
				const Standard_Real theValue
			)
				: realParam
				(
					"density",
					dimDensity,
					theValue
				)
			{}
		};
	}
}

#endif // !_Marine_Density_Header
