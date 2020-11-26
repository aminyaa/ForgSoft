#pragma once
#ifndef _Cad2d_Subdivide_Header
#define _Cad2d_Subdivide_Header

#include <Global_Done.hxx>

#include <memory>
#include <vector>
#include <tuple>

namespace tnbLib
{

	// Forward Declarations
	class Pln_CmpEdge;
	class Cad2d_Plane;
	class Cad2d_PlanePlaneIntersection;
	class Cad2d_IntsctEntity_Pair;

	class Cad2d_Subdivide
		: public Global_Done
	{

		/*Private Data*/

		std::shared_ptr<Cad2d_PlanePlaneIntersection> theAlgorithm_;


		std::shared_ptr<Cad2d_Plane> thePlane0_;
		std::shared_ptr<Cad2d_Plane> thePlane1_;



		auto& ChangePlane0()
		{
			return thePlane0_;
		}

		auto& ChangePlane1()
		{
			return thePlane1_;
		}

	public:

		Cad2d_Subdivide();

		const auto& IntersectionAlgorithm() const
		{
			return theAlgorithm_;
		}

		const auto& ModifiedPlane0() const
		{
			return thePlane0_;
		}

		const auto& ModifiedPlane1() const
		{
			return thePlane1_;
		}

		void Perform();

		void LoadIntersectionAlgorithm
		(
			const std::shared_ptr<Cad2d_PlanePlaneIntersection>& theAlgorithm
		)
		{
			theAlgorithm_ = theAlgorithm;
		}


		static std::tuple<std::shared_ptr<Pln_CmpEdge>, std::shared_ptr<Pln_CmpEdge>>
			RetrieveSubEdges
			(
				const std::vector<std::shared_ptr<Cad2d_IntsctEntity_Pair>>& theEntities
			);
	};
}

#endif // !_Cad2d_Subdivide_Header
