#pragma once
#ifndef _Marine_DeckStation_Header
#define _Marine_DeckStation_Header

#include <Marine_SingleStation.hxx>

namespace AutLib
{

	class Marine_DeckStation
		: public Marine_SingleStation
	{

		/*Private Data*/

		Standard_Real theBreadth_;

	public:

		Marine_DeckStation
		(
			const std::shared_ptr<marineLib::cmpSectCurve>& theCurve,
			const Standard_Real theB
		)
			: Marine_SingleStation(theCurve)
			, theBreadth_(theB)
		{}

		Standard_Real Breadth() const
		{
			return theBreadth_;
		}
	};
}

#endif // !_Marine_DeckStation_Header
