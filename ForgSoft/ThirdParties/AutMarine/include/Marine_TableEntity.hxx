#pragma once
#ifndef _Marine_TableEntity_Header
#define _Marine_TableEntity_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>

namespace AutLib
{

	class Marine_TableEntity
		: public Global_Indexed
		, public Global_Named
	{

		/*Private Data*/

	protected:

		Marine_TableEntity()
		{}

		Marine_TableEntity
		(
			const Standard_Integer theIndex, 
			const word& theName
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
		{}

	public:

		virtual ~Marine_TableEntity()
		{}
	};
}

#endif // !_Marine_TableEntity_Header

