#pragma once
#ifndef _Mesh_CurveOptmPoint_Newton_Function_Header
#define _Mesh_CurveOptmPoint_Newton_Function_Header

#include <NumAlg_NewtonSolver.hxx>
#include <Geo_CurveLength.hxx>
#include <Mesh_CurveEntity.hxx>

#include <memory>

namespace tnbLib
{

	class Mesh_CurveOptmPoint_Newton_Function_Base
	{

		typedef NumAlg_AdaptiveInteg_Info info;

		/*Private Data*/

		Standard_Real theX0_;
		Standard_Real theStep_;

		const std::shared_ptr<info>& theInfo_;

	protected:

		Mesh_CurveOptmPoint_Newton_Function_Base
		(
			const Standard_Real theX0,
			const Standard_Real theStep,
			const std::shared_ptr<info>& theInfo
		)
			: theX0_(theX0)
			, theStep_(theStep)
			, theInfo_(theInfo)
		{}


	public:

		auto X0() const
		{
			return theX0_;
		}

		auto Step() const
		{
			return theStep_;
		}

		const auto& Info() const
		{
			return theInfo_;
		}
	};

	template<class gCurveType, class MetricPrcsrType>
	class Mesh_CurveOptmPoint_Newton_Function
		: public NumAlg_NewtonSolver_Function<true>
		, public Mesh_CurveOptmPoint_Newton_Function_Base
	{

		typedef Mesh_CurveEntity<gCurveType, MetricPrcsrType> entity;
		typedef NumAlg_AdaptiveInteg_Info info;

		/*Private Data*/

		const entity& theCurve_;

	public:

		Mesh_CurveOptmPoint_Newton_Function
		(
			const Standard_Real theX0,
			const Standard_Real theStep,
			const entity& theCurve,
			const std::shared_ptr<info>& theInfo
		);

		const auto& Entity() const
		{
			return theCurve_;
		}

		Standard_Real Value(const Standard_Real x) const override;
	};
}

#include <Mesh_CurveOptmPoint_Newton_FunctionI.hxx>

#endif // !_Mesh_CurveOptmPoint_Newton_Function_Header