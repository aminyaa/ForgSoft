#pragma once
#ifndef _EnvPropt_WaterDensity_Header
#define _EnvPropt_WaterDensity_Header

#include <EnvPropt_Density.hxx>

namespace tnbLib
{

	namespace marineLib
	{

		class WaterDensity
			: public Density
		{

			/*Private Data*/

		public:

			WaterDensity();

			explicit WaterDensity(const Standard_Real theValue);

		};
	}
}

#endif // !_EnvPropt_WaterDensity_Header
