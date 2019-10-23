#pragma once
#include <Numeric_AdaptIntegration.hxx>
#include <Mesh_CurveLength_Function.hxx>
#include <NonConvergency_Iteration_Failure.hxx>
namespace AutLib
{

	template<class gCurveType, class MetricPrcsrType>
	Standard_Real Mesh_CurveLength::Length
	(
		const Mesh_CurveEntity<gCurveType, MetricPrcsrType>& theEntity,
		const Standard_Real theLower,
		const Standard_Real theUpper, 
		info & theInfo
	)
	{
		Numeric_AdaptIntegration<Mesh_CurveLength_Function<gCurveType, MetricPrcsrType>>
			Integration(theEntity, theLower, theUpper, theInfo);

		Integration.Perform();

		if (NOT Integration.IsDone())
		{
			FatalErrorIn("Standard_Real Mesh_CurveLength::Length()")
				<< "Integration has not been performed!" << endl
				<< abort(FatalError);
		}

		if (NOT theInfo.IsConverged())
		{
			IterFailedIn(FunctionSIG, theInfo.MaxNbIterations())
				<< "Algorithm is not converged!" << " nb iterations = " << theInfo.MaxNbIterations() << endl
				<< abort(IterFail);
		}

		return theInfo.Result();
	}

	template<class gCurveType, class MetricPrcsrType>
	Standard_Real Mesh_CurveLength::Length
	(
		const Mesh_CurveEntity<gCurveType, MetricPrcsrType>& theEntity,
		info & theInfo
	)
	{
		return Length(theEntity, theEntity.FirstParameter(), theEntity.LastParameter(), theInfo);
	}
}