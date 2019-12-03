#pragma once
#ifndef _Mesh_SingularDetection_Info_Header
#define _Mesh_SingularDetection_Info_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

namespace AutLib
{

	class Mesh_SingularDetection_Info
	{

		/*Private Data*/

		Standard_Integer theNbIters_;
		Standard_Real theOmega_;

	public:

		static const Standard_Integer DEFAULT_NB_ITERS;
		static const Standard_Real DEFAULT_OMEGA;

		Mesh_SingularDetection_Info()
			: theOmega_(DEFAULT_OMEGA)
			, theNbIters_(DEFAULT_NB_ITERS)
		{}

		//- Macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Integer, NbIters)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Omega)
	};
}

#endif // !_Mesh_SingularDetection_Info_Header
