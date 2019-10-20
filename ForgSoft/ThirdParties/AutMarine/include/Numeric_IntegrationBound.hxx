#pragma once
#ifndef _Numeric_IntegrationBound_Header
#define _Numeric_IntegrationBound_Header

#include <Global_Bound.hxx>

namespace AutLib
{

	class Numeric_IntegrationBound
		: public Global_Bound<Standard_Real>
	{

		/*Private Data*/

	protected:

		Numeric_IntegrationBound
		(
			const Standard_Real theLower,
			const Standard_Real theUpper
		)
			: Global_Bound<Standard_Real>(theLower, theUpper)
		{}
	};
}

#endif // !_Numeric_IntegrationBound_Header
