#pragma once
#ifndef _Cad2d_SketchEngine_Header
#define _Cad2d_SketchEngine_Header

#include <Pnt2d.hxx>
#include <Geom_AdTree.hxx>

#include <map>
#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Cad2d_Sketch;
	class Pln_Vertex;
	class Pln_Edge;
	class Pln_Wire;

	class Cad2d_SketchEngine
	{

		friend class Cad2d_Sketch;

		/*Private Data*/

		Geom_AdTree<std::shared_ptr<Pln_Vertex>> theSearch_;

		std::map<Standard_Integer, std::shared_ptr<Pln_Vertex>> theVertices_;
		std::map<Standard_Integer, std::shared_ptr<Pln_Edge>> theEdges_;


		Standard_Real theTolerance_;

	protected:

		Cad2d_SketchEngine()
			: theTolerance_(DEFAULT_TOLERANCE)
		{}

	public:

		static const Standard_Real DEFAULT_TOLERANCE;


		std::shared_ptr<Pln_Vertex> PickUpVertex(const Pnt2d& theCoord) const;

		std::shared_ptr<Pln_Vertex> PickUpVertex(const Pnt2d& theCoord, const Standard_Real thePrec) const;

		std::shared_ptr<Pln_Edge> PickUpEdge(const std::shared_ptr<Pln_Vertex>& theVtx0, const std::shared_ptr<Pln_Vertex>& theVtx1) const;


		Standard_Integer NbVertices() const
		{
			return (Standard_Integer)theVertices_.size();
		}

		Standard_Integer NbEdges() const
		{
			return (Standard_Integer)theEdges_.size();
		}

		const Standard_Real Tolerance() const
		{
			return theTolerance_;
		}

		void SetTolerance(const Standard_Real theTol)
		{
			theTolerance_ = theTol;
		}

		void InsertToVertices(const Standard_Integer theIndex, const std::shared_ptr<Pln_Vertex>& theVertex);

		void InsertToEdges(const Standard_Integer theIndex, const std::shared_ptr<Pln_Edge>& theEdge);

		void RemoveFromVertices(const Standard_Integer theIndex);

		void RemoveFromEdges(const Standard_Integer theIndex);
	};
}

#endif // !_Cad2d_SketchEngine_Header
