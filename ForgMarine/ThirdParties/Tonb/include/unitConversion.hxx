#pragma once
#ifndef _unitConversion_Header
#define _unitConversion_Header

#include <mathematicalConstants.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

	//- Conversion from degrees to radians
	inline scalar degToRad(const scalar deg)
	{
		return (deg*mathematicalConstant::pi / 180.0);
	}

	//- Conversion from radians to degrees
	inline scalar radToDeg(const scalar rad)
	{
		return (rad*180.0 / mathematicalConstant::pi);
	}

	//- Conversion from atm to Pa
	inline scalar atmToPa(const scalar atm)
	{
		return (atm*101325.0);
	}

	//- Conversion from atm to Pa
	inline scalar paToAtm(const scalar pa)
	{
		return (pa / 101325.0);
	}

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_unitConversion_Header
