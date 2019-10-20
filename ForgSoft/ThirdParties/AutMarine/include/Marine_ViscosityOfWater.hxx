#pragma once
#ifndef _Marine_ViscosityOfWater_Header
#define _Marine_ViscosityOfWater_Header

#include <Marine_Viscosity.hxx>

namespace AutLib
{

	namespace marineLib
	{

		template<Marine_UnitsSys Sys = Marine_UnitsSys_SI>
		class Marine_ViscosityOfWater
			: public Marine_Viscosity<Sys>
		{

			/*Private Data*/

		public:

			Marine_ViscosityOfWater()
				: Marine_Viscosity<Sys>((Standard_Real)8.9E-4)
			{}

			explicit Marine_ViscosityOfWater
			(
				const Standard_Real theValue
			)
				: Marine_Viscosity<Sys>(theValue)
			{}

		};


		template<>
		class Marine_ViscosityOfWater<Marine_UnitsSys_Imperial>
			: public Marine_Viscosity<Marine_UnitsSys_Imperial>
		{

			/*Private Data*/

		public:

			Marine_ViscosityOfWater()
				: Marine_Viscosity<Marine_UnitsSys_Imperial>((Standard_Real)1.791E-5)
			{}

			explicit Marine_ViscosityOfWater
			(
				const Standard_Real theValue
			)
				: Marine_Viscosity<Marine_UnitsSys_Imperial>(theValue)
			{}

		};
	}
}

#endif // !_Marine_ViscosityOfWater_Header
