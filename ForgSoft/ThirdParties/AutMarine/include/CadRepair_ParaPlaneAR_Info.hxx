#pragma once
#ifndef _CadRepair_ParaPlaneAR_Info_Header
#define _CadRepair_ParaPlaneAR_Info_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>
#include <Global_Verbose.hxx>

namespace AutLib
{

	class CadRepair_ParaPlaneAR_Info
		: public Global_Verbose
	{

		/*Private Data*/

		Standard_Real theAR_;

		Standard_Boolean toApply_;

	public:

		static const Standard_Real DEFAULT_AR;

		CadRepair_ParaPlaneAR_Info()
			: theAR_(DEFAULT_AR)
			, toApply_(Standard_False)
		{}

		Standard_Boolean ToApply() const
		{
			return toApply_;
		}

		void ToApply(const Standard_Boolean apply)
		{
			toApply_ = apply;
		}

		//- Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, AR)
	};
}

#endif // !_CadRepair_ParaPlaneAR_Info_Header
