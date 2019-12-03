#pragma once
#ifndef _Pln_IntsctEdgeEdgeInfo_Header
#define _Pln_IntsctEdgeEdgeInfo_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

namespace AutLib
{

	class Pln_IntsctEdgeEdgeInfo
	{

		/*Private Data*/

		Standard_Real theTolerance_;

	public:

		static const Standard_Real DEFAULT_TOLERANCE;

		Pln_IntsctEdgeEdgeInfo()
			: theTolerance_(DEFAULT_TOLERANCE)
		{}

		//- Macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Tolerance)
	};
}

#endif // !_Pln_IntsctEdgeEdgeInfo_Header
