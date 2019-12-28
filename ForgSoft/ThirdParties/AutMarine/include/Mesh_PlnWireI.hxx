#pragma once
namespace AutLib
{

	template<class PlnCurve>
	Entity2d_Box Mesh_PlnWire<PlnCurve>::CalcParametricBoundingBox() const
	{
		const auto& curves = Curves();

		auto box = curves[0]->BoundingBox();
		forThose(Index, 1, curves.size() - 1)
		{
			box = Entity2d_Box::Union(box, curves[Index]->BoundingBox());
		}
		return std::move(box);
	}

	template<class PlnCurve>
	std::vector<std::shared_ptr<PlnCurve>>
		Mesh_PlnWire<PlnCurve>::RetrieveCurvesFrom
		(
			const std::vector<std::shared_ptr<Mesh_PlnWire>>& theWires
		)
	{
		std::vector<std::shared_ptr<PlnCurve>> merged;
		Standard_Integer nbcurves = 0;
		for (const auto& x : theWires)
		{
			Debug_Null_Pointer(x);
			nbcurves += x->NbCurves();
		}

		for (const auto& x : theWires)
		{
			Debug_Null_Pointer(x);

			const auto curves = x->Curves();

			for (const auto& icurve : curves)
			{
				Debug_Null_Pointer(icurve);
				merged.push_back(icurve);
			}
		}
		return std::move(merged);
	}
}