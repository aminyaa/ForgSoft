#pragma once
#ifndef _Entity2d_TriangulationN_Header
#define _Entity2d_TriangulationN_Header

#include <Entity2d_Triangulation.hxx>

namespace AutLib
{

	typedef Entity_StaticData<Pnt2d, connectivity::triple, true>
		Entity2d_TriangulationN;

	template<>
	void Entity2d_TriangulationN::Swap
	(
		const Standard_Integer theElement,
		const Standard_Integer theEdge
	);

	struct SwapBox
	{
		Standard_Integer V0;
		Standard_Integer V1;
		Standard_Integer V2;
		Standard_Integer V3;

		connectivity::triple Swaped0() const
		{
			connectivity::triple t;
			t.Value(0) = V1;
			t.Value(1) = V2;
			t.Value(2) = V3;
			return std::move(t);
		}

		connectivity::triple Swaped1() const
		{
			connectivity::triple t;
			t.Value(0) = V3;
			t.Value(1) = V0;
			t.Value(2) = V1;
			return std::move(t);
		}

		static SwapBox GetSwapBox
		(
			const std::vector<connectivity::triple>& Vtx,
			const std::vector<connectivity::triple>& Neighb,
			const Standard_Integer E0,
			const Standard_Integer theIndex
		);
	};
}

#endif // !_Entity2d_TriangulationN_Header
