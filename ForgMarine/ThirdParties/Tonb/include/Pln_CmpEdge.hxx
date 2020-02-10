#pragma once
#ifndef _Pln_CmpEdge_Header
#define _Pln_CmpEdge_Header

#include <Pln_Entity.hxx>
#include <OFstream.hxx>

#include <memory>
#include <vector>

namespace tnbLib
{

	// Forward Declarations
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

		void Insert(const std::shared_ptr<Pln_Edge>& theEdge)
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

		Standard_Integer NbEdges() const
		{
			return (Standard_Integer)theEdges_.size();
		}

		const edgeList& Edges() const
		{
			return theEdges_;
		}

		void Reverse();

		void ExportToPlt(OFstream& File) const;
	};
}

#endif // !_Pln_CmpEdge_Header
