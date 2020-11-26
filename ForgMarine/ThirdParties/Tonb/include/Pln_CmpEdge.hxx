#pragma once
#ifndef _Pln_CmpEdge_Header
#define _Pln_CmpEdge_Header

#include <Pln_Entity.hxx>
#include <OFstream.hxx>

class gp_Trsf2d;

#include <memory>
#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class Pln_Vertex;
	class Pln_Edge;
	class Pln_Wire;
	class Pln_Tools;

	class Pln_CmpEdge
		: public Pln_Entity
	{

		typedef std::vector<std::shared_ptr<Pln_Edge>> edgeList;

		friend class Pln_Edge;
		friend class Pln_Wire;
		friend class Pln_Tools;

		/*Private Data*/

		edgeList theEdges_;

	protected:


		auto& ChangeEdges()
		{
			return theEdges_;
		}

		void Insert
		(
			const std::shared_ptr<Pln_Edge>& theEdge
		)
		{
			theEdges_.push_back(theEdge);
		}

	public:


		Pln_CmpEdge()
		{}

		Pln_CmpEdge
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: Pln_Entity(theIndex, theName)
		{}

		Standard_Boolean IsValidForWire
		(
			const Standard_Real theTol
		) const;

		auto NbEdges() const
		{
			return (Standard_Integer)theEdges_.size();
		}

		const auto& Edges() const
		{
			return theEdges_;
		}

		std::shared_ptr<Pln_Entity>
			Copy() const override;

		std::vector<std::shared_ptr<Pln_Vertex>>
			RetrieveVertices() const;

		void Transform(const gp_Trsf2d& t);

		void RetrieveVerticesTo(std::vector<std::shared_ptr<Pln_Vertex>>& theVertices) const;

		void Reverse();

		void ExportToPlt
		(
			OFstream& File
		) const;

		static std::shared_ptr<Pln_Wire>
			MakeWire
			(
				const std::shared_ptr<Pln_CmpEdge>& theEdge,
				const Standard_Real theTol
			);
	};
}

#endif // !_Pln_CmpEdge_Header
