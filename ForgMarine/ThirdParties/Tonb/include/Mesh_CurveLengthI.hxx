#pragma once
#include <NumAlg_AdaptiveInteg.hxx>
#include <Mesh_CurveLength_Function.hxx>
#include <error.hxx>
namespace tnbLib
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
		NumAlg_AdaptiveInteg<Mesh_CurveLength_Function<gCurveType, MetricPrcsrType>>
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
			FatalConvErrorIn(FunctionSIG, theInfo.MaxNbIterations(), theInfo.Tolerance())
				<< "Algorithm is not converged!" << " nb. iterations = " << theInfo.MaxNbIterations() << endl
				<< abort(FatalConvError);
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
		return Length
		(
			theEntity, 
			theEntity.FirstParameter(), theEntity.LastParameter(), 
			theInfo);
	}
}