#pragma once
#ifndef _Pln_VertexAdaptor_Header
#define _Pln_VertexAdaptor_Header

#include <Standard_TypeDef.hxx>
#include <Global_Macros.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <map>
#include <memory>

namespace tnbLib
{

	// Forward Declarations
	class Pln_Edge;

	class Pln_VertexAdaptor
	{

		/*Private Data*/

		std::map<Standard_Integer, std::weak_ptr<Pln_Edge>> theEdges_;

	protected:

		Pln_VertexAdaptor()
		{}

	public:

		auto NbEdges() const
		{
			return (Standard_Integer)theEdges_.size();
		}

		const auto& Edges() const
		{
			return theEdges_;
		}

		void InsertToEdges
		(
			const Standard_Integer theIndex, 
			const std::weak_ptr<Pln_Edge>& theEdge
		)
		{
#ifdef FULLDEBUG
			auto iter = theEdges_.find(theIndex);
			if (iter NOT_EQUAL theEdges_.end())
			{
				FatalErrorIn("void InsertToEdges(const Standard_Integer theIndex, const std::weak_ptr<Pln_Edge>& theEdge)")
					<< "Duplicate data!" << endl
					<< abort(FatalError);
			}
#endif
			theEdges_.insert(std::make_pair(theIndex, theEdge));
		}

		void RemoveFromEdges
		(
			const Standard_Integer theIndex
		)
		{
			auto iter = theEdges_.find(theIndex);
			if (iter NOT_EQUAL theEdges_.end())
			{
				FatalErrorIn("void RemoveFromEdges(const Standard_Integer theIndex)")
					<< "the item is not in the tree: " << theIndex << endl
					<< abort(FatalError);
			}

			theEdges_.erase(iter);
		}
	};
}

#endif // !_Pln_VertexAdaptor_Header
