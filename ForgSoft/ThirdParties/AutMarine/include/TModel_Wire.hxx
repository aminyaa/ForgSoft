#pragma once
#ifndef _TModel_Wire_Header
#define _TModel_Wire_Header

#include <TModel_Entity.hxx>
#include <Entity2d_BoxFwd.hxx>
#include <OFstream.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	class TModel_Edge;

	class TModel_Wire
		: public TModel_Entity
	{

		typedef std::shared_ptr<TModel_Edge> edge_ptr;

		typedef std::vector<edge_ptr> edgeList;
		typedef std::shared_ptr<edgeList> edgeList_ptr;

		/*Private Data*/

		edgeList_ptr theEdges_;

	public:

		TModel_Wire
		(
			const Standard_Integer theIndex,
			const edgeList_ptr& theEdges
		)
			: theEdges_(theEdges)
			, TModel_Entity(theIndex)
		{}

		TModel_Wire
		(
			const Standard_Integer theIndex,
			const word& theName,
			const edgeList_ptr& theEdges
		)
			: theEdges_(theEdges)
			, TModel_Entity(theIndex, theName)
		{}

		TModel_Wire(const edgeList_ptr& theEdges)
			: theEdges_(theEdges)
		{}

		const edgeList_ptr& Edges() const
		{
			return theEdges_;
		}

		Standard_Integer NbEdges() const
		{
			Debug_Null_Pointer(theEdges_);
			return (Standard_Integer)theEdges_->size();
		}

		Entity2d_Box CalcParametricBoundingBox() const;


		//- IO functions and operators

		void ExportPlaneCurvesToPlt(OFstream& File) const;
	};
}

#endif // !_TModel_Wire_Header
