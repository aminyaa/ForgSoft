#pragma once
#ifndef _Vessel_DeckStation_Header
#define _Vessel_DeckStation_Header

#include <Vessel_SingleStation.hxx>

namespace AutLib
{

	class Vessel_DeckStation
		: public Vessel_SingleStation
	{

		/*Private Data*/

		Standard_Real theB_;

	public:

		Vessel_DeckStation
		(
			const std::shared_ptr<marineLib::cmpSectCurve>& theCurve,
			const Standard_Real theB
		)
			: Vessel_SingleStation(theCurve)
			, theB_(theB)
		{}

		Vessel_DeckStation
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<marineLib::cmpSectCurve>& theCurve,
			const Standard_Real theB
		)
			: Vessel_SingleStation(theIndex, theName, theCurve)
			, theB_(theB)
		{}


		Standard_Real Breadth() const
		{
			return theB_;
		}
	};
}

#endif // !_Vessel_DeckStation_Header
