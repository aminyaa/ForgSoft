#pragma once
#ifndef _Marine_StillWaterProfile_Header
#define _Marine_StillWaterProfile_Header

#include <Marine_WaveProfile.hxx>

namespace AutLib
{

	class Marine_StillWaterProfile
		: public Marine_WaveProfile
	{

		/*Private Data*/

	public:

		Marine_StillWaterProfile
		(
			const Standard_Real theDraft
		)
			: Marine_WaveProfile(theDraft, theDraft, theDraft)
		{}

		Marine_StillWaterProfile
		(
			const Standard_Real theTa, 
			const Standard_Real theTf
		)
			: Marine_WaveProfile(theTa, theTf)
		{}

		Standard_Real Value(const Standard_Real x) const override;
	};
}

#endif // !_Marine_StillWaterProfile_Header
