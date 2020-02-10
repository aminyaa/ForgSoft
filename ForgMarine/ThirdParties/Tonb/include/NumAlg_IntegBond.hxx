#pragma once
#ifndef _NumAlg_IntegBond_Header
#define _NumAlg_IntegBond_Header

#include <Global_Bound.hxx>

namespace tnbLib
{

	class NumAlg_IntegBond
		: public Global_Bound<Standard_Real>
	{

		/*Private Data*/

	protected:

		NumAlg_IntegBond
		(
			const Standard_Real theLower, 
			const Standard_Real theUpper
		)
			: Global_Bound<Standard_Real>(theLower, theUpper)
		{}

	};
}

#endif // !_NumAlg_IntegBond_Header
