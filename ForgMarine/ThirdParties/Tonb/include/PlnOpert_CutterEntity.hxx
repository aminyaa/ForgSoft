#pragma once
#ifndef _PlnOpert_CutterEntity_Header
#define _PlnOpert_CutterEntity_Header

#include <Global_Indexed.hxx>
#include <Global_AccessMethod.hxx>

#include <memory>

namespace tnbLib
{

	// Forward Declarations
	class Pln_Vertex;
	class Pln_Edge;

	class PlnOpert_CutterEntity
		: public Global_Indexed
	{

		/*Private Data*/

		std::shared_ptr<Pln_Vertex> theForwardVtx_;
		std::shared_ptr<Pln_Vertex> theBackwardVtx_;

		std::shared_ptr<Pln_Vertex> theForwardCutter_;
		std::shared_ptr<Pln_Vertex> theBackwardCutter_;

	public:

		PlnOpert_CutterEntity()
		{}

		PlnOpert_CutterEntity
		(
			const Standard_Integer theIndex
		)
			: Global_Indexed(theIndex)
		{}

		//- Macros
		GLOBAL_ACCESS_SINGLE(std::shared_ptr<Pln_Vertex>, ForwardVtx)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<Pln_Vertex>, BackwardVtx)

			GLOBAL_ACCESS_SINGLE(std::shared_ptr<Pln_Vertex>, ForwardCutter)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<Pln_Vertex>, BackwardCutter)
	};
}

#endif // !_PlnOpert_CutterEntity_Header
