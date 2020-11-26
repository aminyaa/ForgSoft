#pragma once
#ifndef _TModel_CmpEdge_Header
#define _TModel_CmpEdge_Header

#include <TModel_Entity.hxx>

#include <memory>
#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class TModel_Edge;
	class TModel_Wire;
	class Cad_Tools;

	class TModel_CmpEdge
		: public TModel_Entity
	{

		typedef std::vector<std::shared_ptr<TModel_Edge>> edgeList;

		friend class TModel_Edge;
		friend class TModel_Wire;
		friend class Cad_Tools;

		/*Private Data*/

		edgeList theEdges_;

	protected:

		void Insert(const std::shared_ptr<TModel_Edge>& theEdge)
		{
			theEdges_.push_back(theEdge);
		}

		edgeList& ChangeEdges()
		{
			return theEdges_;
		}

	public:

		TModel_CmpEdge()
		{}

		TModel_CmpEdge
		(
			const Standard_Integer theIndex
		)
			: TModel_Entity(theIndex)
		{}

		TModel_CmpEdge
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: TModel_Entity(theIndex, theName)
		{}


		auto NbEdges() const
		{
			return (Standard_Integer)theEdges_.size();
		}

		const auto& Edges() const
		{
			return theEdges_;
		}

		//void Reverse();

		
	};
}

#endif // !_TModel_CmpEdge_Header
