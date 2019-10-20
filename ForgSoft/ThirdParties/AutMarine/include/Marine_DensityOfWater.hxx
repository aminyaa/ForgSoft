#pragma once
#ifndef _Marine_DensityOfWater_Header
#define _Marine_DensityOfWater_Header

#include <Marine_Density.hxx>

namespace AutLib
{

	namespace marineLib
	{


		// density of water in SI units of systems
		template<Marine_UnitsSys Sys = Marine_UnitsSys_SI>
		class DensityOfWater
			: public Density<Sys>
		{

			/*Private Data*/

		public:

			DensityOfWater()
				: Density<Sys>(1025.0)
			{}

			explicit DensityOfWater
			(
				const Standard_Real theValue
			)
				: Density<Sys>(theValue)
			{}
		};


		// density of water in imperial units of systems
		template<>
		class DensityOfWater<Marine_UnitsSys_Imperial>
			: public Density<Marine_UnitsSys_Imperial>
		{

			/*Private Data*/

		public:

			DensityOfWater()
				: Density<Marine_UnitsSys_Imperial>(1.989)
			{}

			explicit DensityOfWater
			(
				const Standard_Real theValue
			)
				: Density<Marine_UnitsSys_Imperial>(theValue)
			{}
		};
	}
}

#endif // !_Marine_DensityOfWater_Header
