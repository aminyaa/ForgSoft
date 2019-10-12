#pragma once
namespace AutLib
{

	template<class CurveType, class SizeMap>
	void Mesh_CurveOptmPoint_Newton<CurveType, SizeMap>::Perform
	(
		const Standard_Real theGuess,
		IterInfo & theIterInfo,
		IntgInfo & theIntgInfo
	)
	{
		Mesh_CurveOptmPoint_Newton_Function<CurveType, SizeMap> fun(U0(), Step(), Curve(), theIntgInfo);
		Mesh_CurveOptmPoint_Newton_Derivation<CurveType, SizeMap> der(Curve());

		Numeric_NewtonSolver
			<
			Mesh_CurveOptmPoint_Newton_Function<CurveType, SizeMap>,
			Mesh_CurveOptmPoint_Newton_Derivation<CurveType, SizeMap>,
			true
			>
			Iterator(fun, der, theIterInfo);

		Iterator.Perform(theGuess);

		Debug_If_Condition_Message(NOT theIterInfo.IsDone(), "Newton's Algorithm is not performed");

		if (theIterInfo.Condition() IS_EQUAL NewtonIter_ZERODIVIDE)
		{
			FatalErrorIn("Standard_Real Mesh_CurveIteration::Iteration()")
				<< "divide zero in Iterative function" << endl
				<< abort(FatalError);
		}

		if (theIterInfo.Condition() IS_EQUAL NewtonIter_LEVEL_EXCEEDED)
		{
			IterFailedIn("Standard_Real Mesh_CurveIteration::Iteration()", theIterInfo.NbIterations())
				<< "LEVEL EXCEEDED encountered in Iterative function" << endl
				<< abort(IterFail);
		}

		theCorrected_ = theIterInfo.Result();
		Change_IsDone() = Standard_True;
	}
}