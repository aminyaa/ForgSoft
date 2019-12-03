#pragma once
#ifndef _Mesh_SingularPatch_Header
#define _Mesh_SingularPatch_Header

#include <Mesh_ImpPatch.hxx>

namespace AutLib
{

	template<class SurfType, class SizeFun, class MetricFun>
	class Mesh_SingularPatch
		: public Mesh_ImpPatch<SurfType, SizeFun, MetricFun>
	{

		/*Private Data*/

	protected:


	};
}

#endif // !_Mesh_SingularPatch_Header
