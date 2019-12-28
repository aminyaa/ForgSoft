#pragma once
#ifndef _Cad2d_Sketch_Engine_Header
#define _Cad2d_Sketch_Engine_Header

#include <Pnt2d.hxx>

#include <map>
#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Cad2d_Sketch;
	class Pln_Vertex;
	class Pln_Edge;
	class Pln_Wire;

	template<class T>
	class Geom_AdTree;

	class Cad2d_Sketch_Engine
	{

		friend class Cad2d_Sketch;

		/*Private Data*/

		std::shared_ptr<Geom_AdTree<std::shared_ptr<Pln_Vertex>>> theSearch_;

		std::map<Standard_Integer, std::shared_ptr<Pln_Vertex>> theVertices_;
		std::map<Standard_Integer, std::shared_ptr<Pln_Edge>> theEdges_;


		Standard_Real theResolution_;

		Standard_Real theResSQ_;

	protected:

		Cad2d_Sketch_Engine()
			: theResolution_(DEFAULT_RESOLUTION)
		{}

		const std::shared_ptr<Geom_AdTree<std::shared_ptr<Pln_Vertex>>>& Search() const
		{
			return theSearch_;
		}

	public:


		static const Standard_Real DEFAULT_RESOLUTION;


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

		const Standard_Real Resolution() const
		{
			return theResolution_;
		}

		void SetResolution(const Standard_Real theTol)
		{
			theResolution_ = theTol;
		}

		void InsertToVertices(const std::shared_ptr<Pln_Vertex>& theVertex);

		void InsertToEdges(const std::shared_ptr<Pln_Edge>& theEdge);

		void RemoveFromVertices(const std::shared_ptr<Pln_Vertex>& theVertex);

		void RemoveFromEdges(const std::shared_ptr<Pln_Edge>& theEdge);
	};
}

#endif // !_Cad2d_Sketch_Engine_Header
