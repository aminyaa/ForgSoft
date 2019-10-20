#pragma once
#ifndef _Marine_UnderwaterStation_Header
#define _Marine_UnderwaterStation_Header

#include <Marine_SingleStation.hxx>

namespace AutLib
{

	class Marine_UnderwaterStation
		: public Marine_SingleStation
	{

		/*Private Data*/

	public:

		Marine_UnderwaterStation
		(
			const std::shared_ptr<marineLib::cmpSectCurve>& theCurve
		)
			: Marine_SingleStation(theCurve)
		{}
	};
}

#endif // !_Marine_UnderwaterStation_Header
