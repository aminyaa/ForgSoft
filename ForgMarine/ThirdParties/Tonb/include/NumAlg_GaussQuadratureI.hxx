#pragma once
#include <NumAlg_GaussQuadrature_Core.hxx>
namespace tnbLib
{
	template<class Function, int NbPts>
	void NumAlg_GaussQuadrature<Function, NbPts>::Perform()
	{
		auto h2 = 0.5*(Upper() - Lower());
		auto c = 0.5*(Upper() + Lower());

		theResult_ =
			h2 * numLib::gaussLib::Core<Function, NbPts>::_(*this, h2, c);

		Change_IsDone() = Standard_True;
	}
}