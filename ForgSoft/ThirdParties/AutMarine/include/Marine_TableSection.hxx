#pragma once
#ifndef _Marine_TableSection_Header
#define _Marine_TableSection_Header

#include <Marine_TableEntity.hxx>

namespace AutLib
{

	class Marine_TableSection
		: public Marine_TableEntity
	{

		/*Private Data*/

	protected:

		Marine_TableSection()
			: Marine_TableEntity(0, "section")
		{}

		Marine_TableSection
		(
			const Standard_Integer theIndex, 
			const word& theName
		)
		{}

	public:

	};
}

#endif // !_Marine_TableSection_Header
