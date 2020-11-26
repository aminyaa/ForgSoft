#pragma once
#ifndef _HsSection_WaterLine_Header
#define _HsSection_WaterLine_Header

#include <HsEntity_Section.hxx>

namespace tnbLib
{

	class HsSection_WaterLine
		: public HsEntity_Section
	{

		/*Private Data*/

	public:

		HsSection_WaterLine();

		HsSection_WaterLine(const Standard_Integer theIndex);

		HsSection_WaterLine(const Standard_Integer theIndex, const word& theName);
	};
}

#endif // !_HsSection_WaterLine_Header
