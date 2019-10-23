#pragma once
#ifndef _Vessel_DryStation_Header
#define _Vessel_DryStation_Header

#include <Vessel_SingleStation.hxx>

namespace AutLib
{

	class Vessel_DryStation
		: public Vessel_SingleStation
	{

		/*Private Data*/

	public:

		Vessel_DryStation
		(
			const std::shared_ptr<marineLib::cmpSectCurve>& theCurve
		)
			: Vessel_SingleStation(theCurve)
		{}

		Vessel_DryStation
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<marineLib::cmpSectCurve>& theCurve
		)
			: Vessel_SingleStation(theIndex, theName, theCurve)
		{}
	};
}

#endif // !_Vessel_DryStation_Header
