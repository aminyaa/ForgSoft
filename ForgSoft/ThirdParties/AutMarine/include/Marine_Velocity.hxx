#pragma once
#ifndef _Marine_Velocity_Header
#define _Marine_Velocity_Header

#include <Marine_DimensionedParam.hxx>

namespace AutLib
{

	namespace marineLib
	{

		template<Marine_UnitsSys Sys = Marine_UnitsSys_SI>
		class Marine_Velocity
			: public vecParam
		{

			/*Private Data*/

		public:

			Marine_Velocity()
				: vecParam
				(
					"velocity",
					dimVelocity,
					Vec2d(1.0, 0)
				)
			{}

			explicit Marine_Velocity
			(
				const Vec2d& theValue
			)
				: vecParam
				(
					"velocity",
					dimVelocity,
					theValue
				)
			{}


		};


		template<>
		class Marine_Velocity<Marine_UnitsSys_Imperial>
			: public vecParam
		{

			/*private Data*/

		public:

			Marine_Velocity()
				: vecParam
				(
					"velocity",
					dimVelocity,
					Vec2d(1.0, 0)
				)
			{}

			explicit Marine_Velocity
			(
				const Vec2d& theValue
			)
				: vecParam
				(
					"velocity",
					dimVelocity,
					theValue
				)
			{}

		};
	}
}

#endif // !_Marine_Velocity_Header
