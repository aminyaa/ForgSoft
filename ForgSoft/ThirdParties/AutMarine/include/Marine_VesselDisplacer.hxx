#pragma once
#ifndef _Marine_VesselDisplacer_Header
#define _Marine_VesselDisplacer_Header

#include <Marine_VesselEntity.hxx>

namespace AutLib
{

	class Marine_VesselDisplacer
		: public Marine_VesselEntity
	{

		/*Private Data*/

	protected:

		Marine_VesselDisplacer()
		{}

		Marine_VesselDisplacer
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: Marine_VesselEntity(theIndex, theName)
		{}
	};
}

#endif // !_Marine_VesselDisplacer_Header
