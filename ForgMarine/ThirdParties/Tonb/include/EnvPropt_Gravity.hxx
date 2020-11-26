#pragma once
#ifndef _EnvPropt_Gravity_Header
#define _EnvPropt_Gravity_Header

#include <Marine_DimensionedParam.hxx>

namespace tnbLib
{

	namespace marineLib
	{

		class Gravity
			: public vec3Param
		{

			/*Private Data*/

		public:

			Gravity();

			explicit Gravity(const Vec3d& theValue);
		};
	}
}

#endif // !_EnvPropt_Gravity_Header
