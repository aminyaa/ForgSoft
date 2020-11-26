#pragma once
#ifndef _EnvPropt_AirViscosity_Header
#define _EnvPropt_AirViscosity_Header

#include <EnvPropt_Viscosity.hxx>

namespace tnbLib
{

	namespace marineLib
	{

		class AirViscosity
			: public Viscosity
		{

			/*Private Data*/

		public:

			AirViscosity();

			explicit AirViscosity(const Standard_Real theValue);
		};
	}
}

#endif // !_EnvPropt_AirViscosity_Header
