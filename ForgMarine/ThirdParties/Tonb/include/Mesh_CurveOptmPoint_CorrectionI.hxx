#pragma once
#include <Global_Macros.hxx>
namespace tnbLib
{

	template<class gCurveType, class MetricPrcsrType>
	void Mesh_CurveOptmPoint_Correction<gCurveType, MetricPrcsrType>::Perform()
	{
		const auto& map = Entity().SizeMap();
		const auto& curve = Entity().Curve();

		const auto nbLevels = Info().MaxLevel();
		const auto tol = Info().Tolerance();
		const auto underRelaxation = Info().UnderRelaxation();

		auto Correct = Guess();
		auto P0 = curve.Value(U0());

		auto Umin = U0();
		auto Umax = Entity().LastParameter();

		forThose(Iter, 1, nbLevels)
		{
			auto dis = map.CalcUnitDistance(P0, curve.Value(Correct));
			auto du = (Correct - Umin) / dis;
			//Correct = Umin + underRelaxation*du;
			Correct = Umin + du;

			if (Correct < Umin) Correct = Umin;
			if (Correct > Umax) Correct = Umax;

			if (ABS(1.0 - dis) < tol) break;
		}

		ChangeCorrected() = Correct;
		Change_IsDone() = Standard_True;
	}
}