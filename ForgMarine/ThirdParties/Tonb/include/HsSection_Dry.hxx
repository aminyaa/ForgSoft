#pragma once
#ifndef _HsSection_Dry_Header
#define _HsSection_Dry_Header

#include <HsEntity_Section.hxx>

namespace tnbLib
{

	class HsSection_Dry
		: public HsEntity_Section
	{

		/*Private Data*/

	public:

		HsSection_Dry();

		HsSection_Dry(const Standard_Integer theIndex);

		HsSection_Dry(const Standard_Integer theIndex, const word& theName);
	};
}

#endif // !_HsSection_Dry_Header
