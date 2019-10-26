#pragma once
#ifndef _Mesh_CurveOptmPoint_Newton_Function_Header
#define _Mesh_CurveOptmPoint_Newton_Function_Header

#include <Numeric_NewtonSolver.hxx>
#include <Mesh_CurveLength.hxx>
#include <Mesh_CurveEntity.hxx>

namespace AutLib
{

	// Forward Declarations
	class Numeric_AdaptIntegrationInfo;

	template<class CurveType, class SizeMap>
	class Mesh_CurveOptmPoint_Newton_Function
		: public Numeric_NewtonSolver_Function<true>
	{

		typedef Mesh_CurveEntity<CurveType, SizeMap> entity;
		typedef Numeric_AdaptIntegrationInfo info;

		/*Private Data*/

		const entity& theCurve_;

		Standard_Real theX0_;
		Standard_Real theStep_;

		info& theInfo_;

	public:

		Mesh_CurveOptmPoint_Newton_Function
		(
			const Standard_Real theX0,
			const Standard_Real theStep,
			const entity& theCurve,
			info& theInfo
		)
			: theX0_(theX0)
			, theStep_(theStep)
			, theCurve_(theCurve)
			, theInfo_(theInfo)
		{
			Lower() = theCurve_.FirstParameter();
			Upper() = theCurve_.LastParameter();
		}

		const entity& Curve() const
		{
			return theCurve_;
		}

		Standard_Real X0() const
		{
			return theX0_;
		}

		Standard_Real Step() const
		{
			return theStep_;
		}

		Standard_Real Value(const Standard_Real x) const override;
	};


}

#include <Mesh_CurveOptmPoint_Newton_FunctionI.hxx>

#endif // !_Mesh_CurveOptmPoint_Newton_Function_Header