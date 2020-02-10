#pragma once
#ifndef _PlnOpert_SplitVertex_Header
#define _PlnOpert_SplitVertex_Header

#include <Pln_Vertex.hxx>

namespace tnbLib
{

	// Forward Declarations
	class PlnOpert_IntsctPoint;

	class PlnOpert_SplitVertex
		: public Pln_Vertex
	{

		/*Private Data*/

		std::shared_ptr<PlnOpert_IntsctPoint> theIntEntity_;

	public:

		PlnOpert_SplitVertex()
		{}

		PlnOpert_SplitVertex(const )
	};
}

#endif // !_PlnOpert_SplitVertex_Header
