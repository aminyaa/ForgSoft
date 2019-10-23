#pragma once
#ifndef _Vessel_UnderwaterStation_Header
#define _Vessel_UnderwaterStation_Header

#include <Vessel_SingleStation.hxx>

namespace AutLib
{

	class Vessel_UnderwaterStation
		: public Vessel_SingleStation
	{

		/*Private Data*/

	public:

		Vessel_UnderwaterStation
		(
			const std::shared_ptr<marineLib::cmpSectCurve>& theCurve
		)
			: Vessel_SingleStation(theCurve)
		{}

		Vessel_UnderwaterStation
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<marineLib::cmpSectCurve>& theCurve
		)
			: Vessel_SingleStation(theIndex, theName, theCurve)
		{}
	};
}

#endif // !_Vessel_UnderwaterStation_Header
