#pragma once
#ifndef _Marine_Froude_Header
#define _Marine_Froude_Header

#include <Marine_DimensionedParam.hxx>

namespace AutLib
{

	namespace marineLib
	{

		class Froude
			: public realParam
		{

			/*Private Data*/

		public:

			explicit Froude(const Standard_Real theValue)
				: realParam
				(
					"froude number",
					dimless,
					theValue
				)
			{}

		};
	};
}

#endif // !_Marine_Froude_Header
