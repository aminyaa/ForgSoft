#pragma once
#ifndef _EnvPropt_WaterViscosity_Header
#define _EnvPropt_WaterViscosity_Header

#include <EnvPropt_Viscosity.hxx>

namespace tnbLib
{

	namespace marineLib
	{

		class WaterViscosity
			: public Viscosity
		{

			/*Private Data*/

		public:

			WaterViscosity();

			explicit WaterViscosity(const Standard_Real theValue);
		};
	}
}

#endif // !_EnvPropt_WaterViscosity_Header
