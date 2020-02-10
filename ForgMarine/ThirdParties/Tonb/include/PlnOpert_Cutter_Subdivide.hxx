#pragma once
#ifndef _PlnOpert_Cutter_Subdivide_Header
#define _PlnOpert_Cutter_Subdivide_Header

#include <Global_Done.hxx>

#include <memory>
#include <vector>
#include <map>

namespace tnbLib
{

	// Forward Declarations
	class PlnOpert_IntsctPair;
	class PlnOpert_Cutter_Intersection;
	class Pln_Edge;

	class PlnOpert_Cutter_Subdivide
	{

		/*Private Data*/

		const std::shared_ptr<PlnOpert_Cutter_Intersection>& theIntersection_;

		std::vector<std::shared_ptr<Pln_Edge>> theEdges_;
	

		auto& ChangeEdges()
		{
			return theEdges_;
		}


	public:

		PlnOpert_Cutter_Subdivide
		(
			const std::shared_ptr<PlnOpert_Cutter_Intersection>& theIntersection
		)
			: theIntersection_(theIntersection)
		{}

		const auto& Intersection() const
		{
			return theIntersection_;
		}

		const auto& Edges() const
		{
			return theEdges_;
		}

		void Perform(const Standard_Real theTol);

	};
}

#endif // !_PlnOpert_Cutter_Subdivide_Header
