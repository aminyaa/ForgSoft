#pragma once
#include <Numeric_AdaptIntegration.hxx>
#include <Geo_CurveIntegrand_Function.hxx>
#include <NonConvergency_Iteration_Failure.hxx>

namespace AutLib
{

	namespace GeoLib
	{

		template<class gCurveType, class MetricPrcsrType>
		Standard_Real CalcCurveLength<gCurveType, MetricPrcsrType>::_
		(
			const Geo_CurveIntegrand<gCurveType, MetricPrcsrType>& theIntegrand,
			const Standard_Real theU0, 
			const Standard_Real theU1,
			info & theInfo
		)
		{
			Numeric_AdaptIntegration
				<
				Geo_CurveIntegrand_Function<gCurveType, MetricPrcsrType, true>
				>
				Integration(theIntegrand, theU0, theU1, theInfo);

			Integration.Perform();

			Debug_If_Condition_Message(NOT Integration.IsDone(), "Integration has not been performed!");

			if (NOT theInfo.IsConverged())
			{
				IterFailedIn(FunctionSIG, theInfo.MaxNbIterations())
					<< "Algorithm is not converged!" << endl
					<< abort(IterFail);
			}
			return theInfo.Result();
		}

		template<class gCurveType>
		Standard_Real CalcCurveLength<gCurveType, void>::_
		(
			const Geo_CurveIntegrand<gCurveType>& theIntegrand,
			const Standard_Real theU0, 
			const Standard_Real theU1,
			info & theInfo
		)
		{
			Numeric_AdaptIntegration
				<
				Geo_CurveIntegrand_Function<gCurveType, void, false>
				>
				Integration(theIntegrand, theU0, theU1, theInfo);

			Integration.Perform();

			Debug_If_Condition_Message(NOT Integration.IsDone(), "Integration has not been performed!");

			if (NOT theInfo.IsConverged())
			{
				IterFailedIn(FunctionSIG, theInfo.MaxNbIterations())
					<< "Algorithm is not converged!" << endl
					<< abort(IterFail);
			}
			return theInfo.Result();
		}
	}
}