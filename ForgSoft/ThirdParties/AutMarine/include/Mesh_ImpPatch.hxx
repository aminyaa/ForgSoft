#pragma once
#ifndef _Mesh_ImpPatch_Header
#define _Mesh_ImpPatch_Header

#include <Mesh_PatchTemplate.hxx>

namespace AutLib
{

	template<class SurfType, class SizeFun, class MetricFun>
	class Mesh_ImpPatch
		: public Mesh_PatchTemplate<SurfType, SizeFun, MetricFun>
	{

		/*Private Data*/

	protected:

		Mesh_ImpPatch(const SurfType& theSurface)
			: Mesh_PatchTemplate<SurfType>(theSurface)
		{}

	public:

		typedef Mesh_PatchTemplate<SurfType> base;
	};
}

#endif // !_Mesh_ImpPatch_Header