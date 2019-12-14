#pragma once
#ifndef _CadSingularity_Detection_Info_Header
#define _CadSingularity_Detection_Info_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>
#include <Global_Verbose.hxx>

namespace AutLib
{

	class CadSingularity_Detection_Info
		: public Global_Verbose
	{

		/*Private Data*/

		Standard_Integer theNbIters_;
		Standard_Real theOmega_;

	public:

		static const Standard_Integer DEFAULT_NB_ITERS;
		static const Standard_Real DEFAULT_OMEGA;

		CadSingularity_Detection_Info()
			: theOmega_(DEFAULT_OMEGA)
			, theNbIters_(DEFAULT_NB_ITERS)
		{}

		//- Macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbIters)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Omega)
	};
}

#endif // !_CadSingularity_Detection_Info_Header
