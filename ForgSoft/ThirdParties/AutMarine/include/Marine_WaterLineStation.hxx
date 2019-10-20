#pragma once
#ifndef _Marine_WaterLineStation_Header
#define _Marine_WaterLineStation_Header

#include <Marine_SingleStation.hxx>

namespace AutLib
{

	class Marine_WaterLineStation
		: public Marine_SingleStation
	{

		/*Private Data*/

		Standard_Real theBWL_;

	public:

		Marine_WaterLineStation
		(
			const std::shared_ptr<marineLib::cmpSectCurve>& theCurve,
			const Standard_Real theBWL
		)
			: Marine_SingleStation(theCurve)
			, theBWL_(theBWL)
		{}
	};
}

#endif // !_Marine_WaterLineStation_Header
