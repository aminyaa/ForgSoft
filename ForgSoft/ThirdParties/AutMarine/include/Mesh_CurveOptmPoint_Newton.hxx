#pragma once
#ifndef _Mesh_CurveOptmPoint_Newton_Header
#define _Mesh_CurveOptmPoint_Newton_Header

#include <Global_Done.hxx>
#include <Mesh_CurveOptmPoint_Newton_Function.hxx>
#include <Mesh_CurveOptmPoint_Newton_Derivation.hxx>

namespace AutLib
{

	// Forward Declarations
	class Numeric_NewtonSolverInfo;

	template<class CurveType, class SizeMap>
	class Mesh_CurveOptmPoint_Newton
		: public Global_Done
	{

		typedef Mesh_CurveEntity<CurveType, SizeMap> entity;
		typedef Numeric_NewtonSolverInfo IterInfo;
		typedef Numeric_AdaptIntegrationInfo IntgInfo;

		/*Private Data*/

		Standard_Real theU0_;
		Standard_Real theStep_;

		const entity& theCurve_;

		Standard_Real theCorrected_;

	public:

		Mesh_CurveOptmPoint_Newton
		(
			const Standard_Real theU0,
			const Standard_Real theStep,
			const entity& theCurve
		)
			: theU0_(theU0)
			, theStep_(theStep)
			, theCurve_(theCurve)
		{}

		Standard_Real U0() const
		{
			return theU0_;
		}

		Standard_Real Step() const
		{
			return theStep_;
		}

		const entity& Curve() const
		{
			return theCurve_;
		}

		Standard_Real Corrected() const
		{
			return theCorrected_;
		}

		void Perform
		(
			const Standard_Real theGuess,
			IterInfo& theIterInfo,
			IntgInfo& theIntgInfo
		);
	};
}

#include <Mesh_CurveOptmPoint_NewtonI.hxx>

#endif // !_Mesh_CurveOptmPoint_Newton_Header