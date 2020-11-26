#pragma once
#ifndef _EnvPropt_Viscosity_Header
#define _EnvPropt_Viscosity_Header

#include <Marine_DimensionedParam.hxx>

namespace tnbLib
{

	namespace marineLib
	{

		class Viscosity
			: public realParam
		{

			/*Private Data*/

		protected:

			Viscosity
			(
				const word& theName,
				const Standard_Real theValue
			);

		public:


		};
	}
}

#endif // !_EnvPropt_Viscosity_Header
