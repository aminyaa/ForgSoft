#pragma once
#ifndef _Cad2d_VertexEdgeIntersection_Header
#define _Cad2d_VertexEdgeIntersection_Header

#include <Cad2d_EntityEntityIntersection.hxx>
#include <Global_AccessMethod.hxx>

#include <memory>

namespace tnbLib
{

	// Forward Declarations
	class Pln_Vertex;
	class Pln_Edge;
	class Cad2d_IntsctEntity_Point;
	class Cad2d_IntsctEntity_Segment;

	class Cad2d_VertexEdgeIntersection
		: public Cad2d_EntityEntityIntersection
	{

		/*Private Data*/

		std::shared_ptr<Pln_Vertex> theVtx_;
		std::shared_ptr<Pln_Edge> theEdge_;

	public:

		Cad2d_VertexEdgeIntersection();

		const auto& Vtx() const
		{
			return theVtx_;
		}

		const auto& Edge() const
		{
			return theEdge_;
		}

		Standard_Boolean IsVertexEdge() const override
		{
			return Standard_True;
		}

		void LoadVertex(const std::shared_ptr<Pln_Vertex>& theVtx)
		{
			theVtx_ = theVtx;
		}

		void LoadEdge(const std::shared_ptr<Pln_Edge>& theEdge)
		{
			theEdge_ = theEdge;
		}

		void Perform();

		//- Macros
	};
}

#endif // !_Cad2d_VertexEdgeIntersection_Header
