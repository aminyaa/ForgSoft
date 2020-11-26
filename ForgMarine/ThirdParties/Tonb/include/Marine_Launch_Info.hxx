#pragma once
#ifndef _Marine_Launch_Info_Header
#define _Marine_Launch_Info_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

namespace tnbLib
{

	class Marine_Launch_Info
	{

		/*Private Data*/

		Standard_Real theMinTol_;
		Standard_Real theMaxTol_;

	public:

		Marine_Launch_Info();

		//- Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, MinTol)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, MaxTol)
	};
}

#endif // !_Marine_Launch_Info_Header
