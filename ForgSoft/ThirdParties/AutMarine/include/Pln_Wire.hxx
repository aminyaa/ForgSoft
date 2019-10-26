#pragma once
#ifndef _Pln_Wire_Header
#define _Pln_Wire_Header

#include <Pln_Entity.hxx>
#include <Pln_CmpEdge.hxx>
#include <Pln_Orientation.hxx>
#include <Entity2d_BoxFwd.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <vector>

namespace AutLib
{

	// Forward Declarations
	class Pln_Edge;
	class Pln_Curve;
	class Pln_Vertex;
	class Pln_CmpEdge;

	class Pln_Wire
		: public Pln_Entity
	{

		typedef std::shared_ptr<Pln_Edge> edge_ptr;
		typedef std::vector<edge_ptr> edgeList;

		/*Private Data*/

		Pln_Orientation theOrientation_;

		std::shared_ptr<Pln_CmpEdge> theEdges_;

		std::shared_ptr<Entity2d_Box> theBoundingBox_;


		void CalcBoundingBox();

		void CheckWire(const edgeList& theEdges) const;

		void CreateWire(const std::shared_ptr<Pln_CmpEdge>& theEdges);

	public:

		Pln_Wire(const std::shared_ptr<Pln_CmpEdge>& theEdges)
			: theEdges_(theEdges)
		{
			CreateWire(theEdges);

			CalcBoundingBox();
		}

		Pln_Wire
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<Pln_CmpEdge>& theEdges
		)
			: theEdges_(theEdges)
			, Pln_Entity(theIndex)
		{
			CreateWire(theEdges);

			CalcBoundingBox();
		}

		Pln_Wire
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<Pln_CmpEdge>& theEdges
		)
			: theEdges_(theEdges)
			, Pln_Entity(theIndex, theName)
		{
			CreateWire(theEdges);

			CalcBoundingBox();
		}

		Standard_Integer NbEdges() const
		{
			Debug_Null_Pointer(theEdges_);
			return theEdges_->NbEdges();
		}

		const edgeList& Edges() const
		{
			return theEdges_->Edges();
		}

		const std::shared_ptr<Entity2d_Box>& BoundingBox() const
		{
			return theBoundingBox_;
		}

		Pln_Orientation Orientation() const
		{
			return theOrientation_;
		}

		void SetOrientation(const Pln_Orientation theOrient)
		{
			theOrientation_ = theOrient;
		}

		void Reverse();

		void RetrieveVerticesTo
		(
			std::vector<std::shared_ptr<Pln_Vertex>>& theVertices
		) const;

		//- Static functions and operators

		static std::shared_ptr<Pln_CmpEdge> 
			Cut
			(
				const std::shared_ptr<Pln_Wire>& theTarget, 
				const std::shared_ptr<Pln_Edge>& theCutter
			);

		static std::shared_ptr<Pln_CmpEdge> 
			Cut
			(
				const std::shared_ptr<Pln_Wire>& theTarget, 
				const std::shared_ptr<Pln_Curve>& theCutter
			);

		static std::vector<std::shared_ptr<Pln_Wire>>
			RetrieveWires
			(
				const std::vector<std::shared_ptr<Pln_Edge>>& theEdges
			);

		static Pln_Orientation RetrieveOrientation(const Pln_Wire& theWire);
	};
}

#endif // !_Pln_Wire_Header
