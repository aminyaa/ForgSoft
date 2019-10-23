#pragma once
#ifndef _Vessel_WaterlineStation_Header
#define _Vessel_WaterlineStation_Header

#include <Vessel_SingleStation.hxx>

namespace AutLib
{

	class Vessel_WaterlineStation
		: public Vessel_SingleStation
	{

		/*private Data*/

	public:

		Vessel_WaterlineStation
		(
			const std::shared_ptr<marineLib::cmpSectCurve>& theCurve
		)
			: Vessel_SingleStation(theCurve)
		{}

		Vessel_WaterlineStation
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<marineLib::cmpSectCurve>& theCurve
		)
			: Vessel_SingleStation(theIndex, theName, theCurve)
		{}
	};
}

#endif // !_Vessel_WaterlineStation_Header
