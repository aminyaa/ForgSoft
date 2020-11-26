#pragma once
#ifndef _Marine_GraphTitle_Header
#define _Marine_GraphTitle_Header

#include <Marine_GraphEntity.hxx>

namespace tnbLib
{

	class Marine_GraphTitle
		: public Marine_GraphEntity
	{

		/*Private Data*/

	public:

		Marine_GraphTitle();

		Marine_GraphTitle(const word& theName);
	};
}

#endif // !_Marine_GraphTitle_Header
