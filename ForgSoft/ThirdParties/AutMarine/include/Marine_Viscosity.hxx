#pragma once
#ifndef _Marine_Viscosity_Header
#define _Marine_Viscosity_Header

#include <Marine_DimensionedParam.hxx>

namespace AutLib
{

	namespace marineLib
	{

		template<Marine_UnitsSys Sys = Marine_UnitsSys_SI>
		class Marine_Viscosity
			: public realParam
		{

			/*Private Data*/

		protected:

			explicit Marine_Viscosity
			(
				const Standard_Real theValue
			)
				: realParam
				(
					"viscosity",
					dimPressure* dimTime,
					theValue
				)
			{}
		};


		template<>
		class Marine_Viscosity<Marine_UnitsSys_Imperial>
			: public realParam
		{

			/*private Data*/

		protected:

			explicit Marine_Viscosity
			(
				const Standard_Real theValue
			)
				: realParam
				(
					"viscosity",
					dimPressure* dimTime,
					theValue
				)
			{}
		};
	}
}

#endif // !_Marine_Viscosity_Header
