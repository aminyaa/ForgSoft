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

	class Mesh_CurveOptmPoint_Newton_Base
	{

		/*Private Data*/

		Standard_Real theU0_;
		Standard_Real theStep_;

		Standard_Real theCorrected_;

	protected:

		Mesh_CurveOptmPoint_Newton_Base
		(
			const Standard_Real theU0,
			const Standard_Real theStep
		)
			: theU0_(theU0)
			, theStep_(theStep)
			, theCorrected_(0)
		{}


		Standard_Real& ChangeCorrected()
		{
			return theCorrected_;
		}

	public:

		Standard_Real Corrected() const
		{
			return theCorrected_;
		}

		//- Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, U0)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Step)
	};

	template<class gCurveType, class MetricPrcsrType>
	class Mesh_CurveOptmPoint_Newton
		: public Global_Done
		, public Mesh_CurveOptmPoint_Newton_Base
	{

		typedef Mesh_CurveEntity<gCurveType, MetricPrcsrType> entity;
		typedef Numeric_NewtonSolverInfo iterInfo;
		typedef Numeric_AdaptIntegrationInfo intgInfo;

		/*Private Data*/

		const entity& theEntity_;

	public:

		Mesh_CurveOptmPoint_Newton
		(
			const Standard_Real theU0, 
			const Standard_Real theStep,
			const entity& theEntity
		)
			: Mesh_CurveOptmPoint_Newton_Base(theU0, theStep)
			, theEntity_(theEntity)
		{}


		const entity& Entity() const
		{
			return theEntity_;
		}

		void Perform
		(
			const Standard_Real theGuess, 
			const std::shared_ptr<iterInfo>& theIter,
			const std::shared_ptr<intgInfo>& theInteg
		);
	};
}

#include <Mesh_CurveOptmPoint_NewtonI.hxx>

#endif // !_Mesh_CurveOptmPoint_Newton_Header
