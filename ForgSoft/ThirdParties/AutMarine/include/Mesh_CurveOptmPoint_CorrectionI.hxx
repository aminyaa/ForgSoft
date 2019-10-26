#pragma once
#include <Global_Macros.hxx>
#include <iostream>
namespace AutLib
{

	template<class CurveType, class SizeMap>
	void Mesh_CurveOptmPoint_Correction<CurveType, SizeMap>::Perform()
	{
		const auto& map = Curve().SizeMap();
		const auto& curve = Curve().Curve();

		const auto nbLevels = Info().MaxLevel();
		const auto tol = Info().Tolerance();
		const auto underRelaxation = Info().UnderRelaxation();

		auto Correct = Guess();
		auto P0 = curve.Value(U0());

		auto Umin = U0();
		auto Umax = Curve().LastParameter();

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

		theCorrected_ = Correct;
		Change_IsDone() = Standard_True;
	}
}