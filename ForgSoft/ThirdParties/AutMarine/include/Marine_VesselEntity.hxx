#pragma once
#ifndef _Marine_VesselEntity_Header
#define _Marine_VesselEntity_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>

namespace AutLib
{

	class Marine_VesselEntity
		: public Global_Indexed
		, public Global_Named
	{

		/*Private Data*/

	protected:

		Marine_VesselEntity()
		{}

		Marine_VesselEntity
		(
			const Standard_Integer theIndex, 
			const word& theName
		)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
		{}

	public:

		virtual ~Marine_VesselEntity()
		{}
	};
}

#endif // !_Marine_VesselEntity_Header
