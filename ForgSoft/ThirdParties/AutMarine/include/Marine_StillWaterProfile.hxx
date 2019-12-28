#pragma once
#ifndef _Marine_StillWaterProfile_Header
#define _Marine_StillWaterProfile_Header

#include <Marine_WaveProfile.hxx>
#include <Global_AccessMethod.hxx>

namespace AutLib
{

	class Marine_StillWaterProfile
		: public Marine_WaveProfile
	{

		/*Private Data*/

		Standard_Real theH0_;
		Standard_Real theH1_;

	public:

		Marine_StillWaterProfile
		(
			const Standard_Real theDraft
		)
			: theH0_(theDraft)
			, theH1_(theDraft)
		{}

		Marine_StillWaterProfile
		(
			const Standard_Real theH0, 
			const Standard_Real theH1
		)
			: theH0_(theH0)
			, theH1_(theH1)
		{}

		Standard_Real Value(const Standard_Real x) const override;


		//- Macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, H0)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, H1)
	};
}

#endif // !_Marine_StillWaterProfile_Header
