#pragma once
namespace AutLib
{

	void Mesh2d_OptNodeAnIso_Analytical::Perform()
	{
		const auto& map = MetricMap();
		auto h = ElementSize();

		ChangeCoord() = CalcCoord(h, Front(), map);

		Change_IsDone() = Standard_True;
	}
}