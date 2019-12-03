#pragma once
#ifndef _CadRepair_ParaPlaneAR_Info_Header
#define _CadRepair_ParaPlaneAR_Info_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

namespace AutLib
{

	class CadRepair_ParaPlaneAR_Info
	{

		/*Private Data*/

		Standard_Real theAR_;

	public:

		static const Standard_Real DEFAULT_AR;

		CadRepair_ParaPlaneAR_Info()
			: theAR_(DEFAULT_AR)
		{}

		//- Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, AR)
	};
}

#endif // !_CadRepair_ParaPlaneAR_Info_Header
