#pragma once
namespace AutLib
{

	template<class SurfType>
	std::pair<Standard_Integer, Standard_Real> 
		CadRepair_DefectPatch_AR<SurfType>::CalcMaxAR
		(
			const SurfType& theSurface
		)
	{
		const auto& box = theSurface.BoundingBox();

		const auto& P0 = box.P0();
		const auto& P1 = box.P1();

		auto dx = P1.X() - P0.X();
		auto dy = P1.Y() - P0.Y();

		if (dy > dx)
		{
			auto p = std::make_pair(0, dy / dx);
			return std::move(p);
		}
		else
		{
			auto p = std::make_pair(1, dx / dy);
			return std::move(p);
		}
	}
}