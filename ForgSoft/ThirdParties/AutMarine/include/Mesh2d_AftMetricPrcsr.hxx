#pragma once
#ifndef _Mesh2d_AftMetricPrcsr_Header
#define _Mesh2d_AftMetricPrcsr_Header

#include <Mesh_AftMetricPrcsrIso.hxx>
#include <Aft2d_Edge.hxx>

namespace AutLib
{

	template<class SizeFun>
	class Mesh_AftMetricPrcsr<Aft2d_Edge, SizeFun, void>
		: public Mesh_AftMetricPrcsrIso_Base<SizeFun, Aft2d_Edge>
	{

		/*Private Data*/

	public:

		Mesh_AftMetricPrcsr
		(
			const std::shared_ptr<SizeFun>& theSizeFunction
		)
			: Mesh_AftMetricPrcsrIso_Base<SizeFun, Aft2d_Edge>(theSizeFunction)
		{}


		Mesh_AftMetricPrcsr
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<SizeFun>& theSizeFunction
		)
			: Mesh_AftMetricPrcsrIso_Base<SizeFun, Aft2d_Edge>(theIndex, theName, theSizeFunction)
		{}

	};
}

#endif // !_Mesh2d_AftMetricPrcsr_Header
