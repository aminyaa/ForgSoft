#pragma once
namespace AutLib
{

	template<class gCurveType, class MetricPrcsrType>
	void Mesh_CurveOptmPoint_Newton<gCurveType, MetricPrcsrType>::Perform
	(
		const Standard_Real theGuess,
		const std::shared_ptr<iterInfo>& theIter, 
		const std::shared_ptr<intgInfo>& theInteg
	)
	{
		Mesh_CurveOptmPoint_Newton_Function<gCurveType, MetricPrcsrType> fun(U0(), Step(), Entity(), theInteg);
		Mesh_CurveOptmPoint_Newton_Derivation<gCurveType, MetricPrcsrType> der(Entity());

		Numeric_NewtonSolver
			<
			Mesh_CurveOptmPoint_Newton_Function<gCurveType, MetricPrcsrType>,
			Mesh_CurveOptmPoint_Newton_Derivation<gCurveType, MetricPrcsrType>,
			true
			>
			Iterator(fun, der, *theIter);

		Iterator.Perform(theGuess);

		Debug_If_Condition_Message(NOT Iterator.IsDone(), "Newton's Algorithm is not performed");

		if (theIter->Condition() IS_EQUAL NewtonIter_ZERODIVIDE)
		{
			FatalErrorIn("Standard_Real Mesh_CurveIteration::Iteration()")
				<< "divide zero in Iterative function" << endl
				<< abort(FatalError);
		}

		if (theIter->Condition() IS_EQUAL NewtonIter_LEVEL_EXCEEDED)
		{
			IterFailedIn("Standard_Real Mesh_CurveIteration::Iteration()", theIter->NbIterations())
				<< "LEVEL EXCEEDED encountered in Iterative function" << endl
				<< abort(IterFail);
		}

		ChangeCorrected() = theIter->Result();
		Change_IsDone() = Standard_True;
	}
}