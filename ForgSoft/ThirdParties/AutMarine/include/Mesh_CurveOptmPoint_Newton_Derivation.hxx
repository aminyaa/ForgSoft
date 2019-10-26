#pragma once
#ifndef _Mesh_CurveOptmPoint_Newton_Derivation_Header
#define _Mesh_CurveOptmPoint_Newton_Derivation_Header

#include <Numeric_NewtonSolver.hxx>
#include <Mesh_CurveEntity.hxx>

namespace AutLib
{

	template<class CurveType, class SizeMap>
	class Mesh_CurveOptmPoint_Newton_Derivation
		: public Numeric_NewtonSolver_Derivation<true>
	{

		typedef Mesh_CurveEntity<CurveType, SizeMap> entity;

		/*Private Data*/

		const entity& theCurve_;

	public:

		Mesh_CurveOptmPoint_Newton_Derivation
		(
			const entity& theCurve
		)
			: theCurve_(theCurve)
		{
			Lower() = theCurve.FirstParameter();
			Upper() = theCurve.LastParameter();
		}

		const entity& Curve() const
		{
			return theCurve_;
		}

		Standard_Real Value(const Standard_Real x) const override
		{
			return entity::Integrand(x, Curve());
		}
	};
}

#endif // !_Mesh_CurveOptmPoint_Newton_Derivation_Header