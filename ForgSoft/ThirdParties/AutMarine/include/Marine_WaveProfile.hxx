#pragma once
#ifndef _Marine_WaveProfile_Header
#define _Marine_WaveProfile_Header

#include <Global_Bound.hxx>
#include <Global_Indexed.hxx>
#include <Global_Named.hxx>

namespace AutLib
{

	class Marine_WaveProfile
		: public Global_Indexed
		, public Global_Named
		, public Global_Bound<Standard_Real>
	{

		/*Private Data*/

	protected:

		Marine_WaveProfile()
		{}


	public:

		virtual Standard_Real Value(const Standard_Real x) const = 0;

	};
}

#endif // !_Marine_WaveProfile_Header
