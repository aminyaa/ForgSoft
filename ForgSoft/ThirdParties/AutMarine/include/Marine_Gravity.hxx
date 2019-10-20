#pragma once
#ifndef _Marine_Gravity_Header
#define _Marine_Gravity_Header

#include <Marine_DimensionedParam.hxx>

namespace AutLib
{

	namespace marineLib
	{

		// gravity in SI units of systems
		template<Marine_UnitsSys Sys = Marine_UnitsSys_SI>
		class Gravity
			: public vecParam
		{

			/*Private Data*/

		public:

			Gravity()
				: vecParam
				(
					"gravity",
					dimAcceleration,
					Vec2d(0, -(Standard_Real)9.806)
				)
			{}

			explicit Gravity
			(
				const Vec2d& theValue
			)
				: vecParam
				(
					"gravity",
					dimAcceleration,
					theValue
				)
			{}
			
		};


		template<>
		class Gravity<Marine_UnitsSys_Imperial>
			: public vecParam
		{

			/*Private Data*/

		public:

			Gravity()
				: vecParam
				(
					"gravity",
					dimAcceleration,
					Vec2d(0, -(Standard_Real)32.2)
				)
			{}

			explicit Gravity
			(
				const Vec2d& theValue
			)
				: vecParam
				(
					"gravity",
					dimAcceleration,
					theValue
				)
			{}
		};
	}
}

#endif // !_Marine_Gravity_Header
