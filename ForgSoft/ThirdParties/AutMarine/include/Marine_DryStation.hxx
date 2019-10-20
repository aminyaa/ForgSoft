#pragma once
#ifndef _Marine_DryStation_Header
#define _Marine_DryStation_Header

#include <Marine_SingleStation.hxx>

namespace AutLib
{

	class Marine_DryStation
		: public Marine_SingleStation
	{

		/*Private Data*/

	public:

		Marine_DryStation
		(
			const std::shared_ptr<marineLib::cmpSectCurve>& theCurve
		)
			: Marine_SingleStation(theCurve)
		{}
	};
}

#endif // !_Marine_DryStation_Header
