#pragma once
#ifndef _Marine_VesselParam_Header
#define _Marine_VesselParam_Header

#include <Marine_DimensionedParam.hxx>

namespace AutLib
{

	class Marine_VesselParam
		: public Marine_DimensionedParam<Standard_Real>
	{

		/*Private Data*/

	protected:

		Marine_VesselParam
		(
			const word& theName,
			const Marine_DimensionSet& theDim, 
			const Standard_Real theValue
		)
			: Marine_DimensionedParam<Standard_Real>(theName, theDim, theValue)
		{}

	public:

	};
}

#endif // !_Marine_VesselParam_Header
