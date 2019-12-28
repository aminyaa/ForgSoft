#pragma once
#ifndef _Pln_Vertex_Header
#define _Pln_Vertex_Header

#include <Cad_EntityPrecision.hxx>
#include <Pln_Entity.hxx>
#include <Pnt2d.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	class Pln_Edge;

	class Pln_Vertex
		: public Pln_Entity
		, public Cad_EntityPrecision
	{

		/*Private Data*/

		Pnt2d theCoord_;

		std::map<Standard_Integer, std::weak_ptr<Pln_Edge>> theEdges_;

	public:

		static const std::shared_ptr<Pln_Vertex> null;

		typedef Pnt2d ptType;

		Pln_Vertex()
		{}

		Pln_Vertex(const Standard_Integer theIndex)
			: Pln_Entity(theIndex)
		{}

		Pln_Vertex
		(
			const Standard_Integer theIndex,
			const Pnt2d& theCoord
		)
			: Pln_Entity(theIndex)
			, theCoord_(theCoord)
		{}

		Pln_Vertex
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Pnt2d& theCoord
		)
			: Pln_Entity(theIndex, theName)
			, theCoord_(theCoord)
		{}

		const Pnt2d& Coord() const
		{
			return theCoord_;
		}

		Pnt2d& Coord()
		{
			return theCoord_;
		}

		const std::map<Standard_Integer, std::weak_ptr<Pln_Edge>>&
			Edges() const
		{
			return theEdges_;
		}

		Standard_Integer NbEdges() const
		{
			return (Standard_Integer)theEdges_.size();
		}

		Standard_Boolean IsFree() const;

		Standard_Boolean IsOrphan() const;

		Standard_Boolean IsRingPoint() const;

		Standard_Boolean IsManifold() const;

		Standard_Boolean IsSharp(const Standard_Real theRadianAngle) const;

		void SetCoord(const Pnt2d& theCoord)
		{
			theCoord_ = theCoord;
		}

		void InsertToEdges(const std::shared_ptr<Pln_Edge>& theEdge);

		void InsertToEdges_dup(const std::shared_ptr<Pln_Edge>& theEdge);

		void RemoveFromEdges(const std::shared_ptr<Pln_Edge>& theEdge);

		void RetrieveEdgesTo(std::vector<std::weak_ptr<Pln_Edge>>& theEdges) const;

		void Mirror(const gp_Pnt2d& P);

		void Mirror(const gp_Ax2d& A);

		void Rotate(const gp_Pnt2d& P, const Standard_Real Ang);

		void Scale(const gp_Pnt2d& P, const Standard_Real S);

		void Translate(const gp_Vec2d& V);

		void Translate(const gp_Pnt2d& P1, const gp_Pnt2d& P2);

		void Transform(const gp_Trsf2d& T);

		static Standard_Boolean IsLess
		(
			const std::shared_ptr<Pln_Vertex>& theVtx0,
			const std::shared_ptr<Pln_Vertex>& theVtx1
		)
		{
			Debug_Null_Pointer(theVtx0);
			Debug_Null_Pointer(theVtx1);

			return theVtx0->Index() < theVtx1->Index();
		}

		static const Pnt2d& GetCoord
		(
			const std::shared_ptr<Pln_Vertex>& theVtx
		)
		{
			Debug_Null_Pointer(theVtx);
			return theVtx->Coord();
		}

		static std::vector<Pnt2d> GetCoord
		(
			const std::vector<std::shared_ptr<Pln_Vertex>>& theVertices
		);
	};
}

#endif // !_Pln_Vertex_Header
