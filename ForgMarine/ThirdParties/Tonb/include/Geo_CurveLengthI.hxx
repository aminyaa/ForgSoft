#pragma once
#include <NumAlg_AdaptiveInteg.hxx>
#include <Geo_CurveIntegrand_Function.hxx>
#include <error.hxx>
#include <OSstream.hxx>

namespace tnbLib
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
			NumAlg_AdaptiveInteg
				<
				Geo_CurveIntegrand_Function<gCurveType, MetricPrcsrType, true>
				>
				Integration(theIntegrand, theU0, theU1, theInfo);

			Integration.Perform();

			Debug_If_Condition_Message(NOT Integration.IsDone(), "Integration has not been performed!");

			if (NOT theInfo.IsConverged())
			{
				FatalConvErrorIn(FunctionSIG, theInfo.MaxNbIterations(), theInfo.Tolerance())
					<< "Algorithm is not converged!" << endl
					<< abort(FatalConvError);
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
			NumAlg_AdaptiveInteg
				<
				Geo_CurveIntegrand_Function<gCurveType, void, false>
				>
				Integration(theIntegrand, theU0, theU1, theInfo);

			Integration.Perform();

			Debug_If_Condition_Message(NOT Integration.IsDone(), "Integration has not been performed!");

			if (NOT theInfo.IsConverged())
			{
				FatalConvErrorIn(FunctionSIG, theInfo.MaxNbIterations(), theInfo.Tolerance())
					<< "Algorithm is not converged!" << endl
					<< abort(FatalConvError);
			}
			return theInfo.Result();
		}
	}
}