#pragma once
#ifndef _Pln_CmpEdge_Header
#define _Pln_CmpEdge_Header

#include <Pln_Entity.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	class Pln_Edge;
	class Pln_Wire;

	class Pln_CmpEdge
		: public Pln_Entity
	{

		typedef std::vector<std::shared_ptr<Pln_Edge>> edgeList;

		friend class Pln_Edge;
		friend class Pln_Wire;

		/*Private Data*/

		edgeList theEdges_;

	protected:

		Pln_CmpEdge()
		{}

		Pln_CmpEdge
		(
			const Standard_Integer theIndex, 
			const word& theName
		)
			: Pln_Entity(theIndex, theName)
		{}

		void Insert(const std::shared_ptr<Pln_Edge>& theEdge)
		{
			theEdges_.push_back(theEdge);
		}

	public:


		Standard_Integer NbEdges() const
		{
			return (Standard_Integer)theEdges_.size();
		}

		const edgeList& Edges() const
		{
			return theEdges_;
		}


	};
}

#endif // !_Pln_CmpEdge_Header
