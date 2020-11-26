#pragma once
#ifndef _HsSection_UnderWater_Header
#define _HsSection_UnderWater_Header

#include <HsEntity_Section.hxx>

namespace tnbLib
{

	class HsSection_UnderWater
		: public HsEntity_Section
	{

		/*Private Data*/

	public:

		HsSection_UnderWater();

		HsSection_UnderWater(const Standard_Integer theIndex);

		HsSection_UnderWater(const Standard_Integer theIndex, const word &theName);
	};
}

#endif // !_HsSection_UnderWater_Header
