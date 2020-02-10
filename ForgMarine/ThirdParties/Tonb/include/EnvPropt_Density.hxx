#pragma once
#ifndef _EnvPropt_Density_Header
#define _EnvPropt_Density_Header

#include <Marine_DimensionedParam.hxx>

namespace tnbLib
{

	namespace marineLib
	{

		class Density
			: public realParam
		{

			/*Private Data*/

		public:

			Density(const word& theName, const Standard_Real theValue);

		public:


		};
	}
}

#endif // !_EnvPropt_Density_Header
