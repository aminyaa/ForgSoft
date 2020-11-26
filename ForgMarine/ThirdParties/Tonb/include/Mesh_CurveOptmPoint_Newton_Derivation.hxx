#pragma once
#ifndef _Mesh_CurveOptmPoint_Newton_Derivation_Header
#define _Mesh_CurveOptmPoint_Newton_Derivation_Header

#include <NumAlg_NewtonSolver.hxx>
#include <Mesh_CurveEntity.hxx>

namespace tnbLib
{

	template<class gCurveType, class MetricPrcsrType>
	class Mesh_CurveOptmPoint_Newton_Derivation
		: public NumAlg_NewtonSolver_Derivation<true>
	{

		typedef Mesh_CurveEntity<gCurveType, MetricPrcsrType> entity;

		/*Private Data*/

		const entity& theEntity_;

	public:

		Mesh_CurveOptmPoint_Newton_Derivation(const entity& theEntity);

		const entity& Entity() const
		{
			return theEntity_;
		}

		Standard_Real Value(const Standard_Real x) const override
		{
			return entity::Integrand(x, Entity());
		}
	};
}

#include <Mesh_CurveOptmPoint_Newton_DerivationI.hxx>

#endif // !_Mesh_CurveOptmPoint_Newton_Derivation_Header