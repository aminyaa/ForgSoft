#pragma once
#ifndef _EnvPropt_Froude_Header
#define _EnvPropt_Froude_Header

#include <Marine_DimensionedParam.hxx>

namespace tnbLib
{

	namespace marineLib
	{

		class Froude
			: public realParam
		{

			/*Private Data*/

		public:

			explicit Froude(const Standard_Real theValue);
		};
	}
}

#endif // !_EnvPropt_Froude_Header
