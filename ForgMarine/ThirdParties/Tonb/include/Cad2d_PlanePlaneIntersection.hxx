#pragma once
#ifndef _Cad2d_PlanePlaneIntersection_Header
#define _Cad2d_PlanePlaneIntersection_Header

#include <Global_Done.hxx>
#include <Global_AccessMethod.hxx>

#include <memory>
#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class Cad2d_Plane;
	class Cad2d_EntityEntityIntersection;

	class Cad2d_PlanePlaneIntersection
		: public Global_Done
	{

		/*Private Data*/

		std::vector<std::shared_ptr<Cad2d_EntityEntityIntersection>>
			theEntities_;

		std::shared_ptr<Cad2d_Plane> thePlane0_;
		std::shared_ptr<Cad2d_Plane> thePlane1_;

		Standard_Real theTolerance_;


		auto& ChangeEntities()
		{
			return theEntities_;
		}

	public:

		static const Standard_Real DEFAULT_TOLERANCE;

		Cad2d_PlanePlaneIntersection();

		auto NbEntities() const
		{
			return(Standard_Integer)theEntities_.size();
		}

		const auto& Plane0() const
		{
			return thePlane0_;
		}

		const auto& Plane1() const
		{
			return thePlane1_;
		}

		const auto& Entities() const
		{
			return theEntities_;
		}

		void LoadPlane0
		(
			const std::shared_ptr<Cad2d_Plane>& thePlane
		)
		{
			thePlane0_ = thePlane;
		}

		void LoadPlane1
		(
			const std::shared_ptr<Cad2d_Plane>& thePlane
		)
		{
			thePlane1_ = thePlane;
		}

		void Perform();


		//- Macros
		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Tolerance)
	};
}

#endif // !_Cad2d_PlanePlaneIntersection_Header
