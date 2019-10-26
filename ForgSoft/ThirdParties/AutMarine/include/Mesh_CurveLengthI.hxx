#pragma once
#include <Numeric_AdaptIntegration.hxx>
#include <Mesh_CurveLength_Function.hxx>
#include <NonConvergency_Iteration_Failure.hxx>
namespace AutLib
{

	/*template<class CurveType, class SizeMap>
	Standard_Real Mesh_CurveLength::Length
	(
		const Mesh_CurveEntity<CurveType, SizeMap>& theCurve,
		const Standard_Real theLower,
		const Standard_Real theUpper,
		info& theInfo
	)
	{
		Numeric_AdaptIntegration<Mesh_CurveLength_Function<CurveType, SizeMap>>
			Integration(theCurve, theLower, theUpper, theInfo);

		Integration.Perform();

		if (NOT theInfo.IsDone())
		{
			FatalErrorIn("Standard_Real Mesh_CurveLength::Length()")
				<< "Integration has not been performed!" << endl
				<< abort(FatalError);
		}

		if (NOT theInfo.IsConverged())
		{
			cout << "nb iterations = " << theInfo.MaxNbIterations() << std::endl;
			IterFailedIn(FunctionSIG, theInfo.MaxNbIterations())
				<< "Algorithm is not converged!" << endl
				<< abort(IterFail);
		}

		return theInfo.Result();
	}*/
}