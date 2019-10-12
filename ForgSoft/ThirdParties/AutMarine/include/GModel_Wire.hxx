#pragma once
#ifndef _GModel_Wire_Header
#define _GModel_Wire_Header

#include <GModel_Entity.hxx>
#include <Entity2d_Box.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	class GModel_Edge;
	class GModel_parWire;
	class GModel_parCurve;

	class GModel_Wire
		: public GModel_Entity
	{

		typedef std::shared_ptr<GModel_Edge> edge_ptr;
		typedef std::vector<edge_ptr> edgeList;
		typedef std::shared_ptr<edgeList> edgeList_ptr;

		/*Private Data*/

		edgeList_ptr theEdges_;

	public:

		GModel_Wire
		(
			const Standard_Integer theIndex,
			const edgeList_ptr& theEdges
		)
			: theEdges_(theEdges)
			, GModel_Entity(theIndex)
		{}

		GModel_Wire
		(
			const Standard_Integer theIndex,
			const word& theName,
			const edgeList_ptr& theEdges
		)
			: theEdges_(theEdges)
			, GModel_Entity(theIndex, theName)
		{}

		GModel_Wire(const edgeList_ptr& theEdges)
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


		//- Io functions and operators

		void ExportPlaneCurvesToPlt(OFstream& File) const;


		//- Static functions and operators

		static std::shared_ptr<std::vector<std::shared_ptr<GModel_parCurve>>> 
			RetrievePlaneCurves
			(
				const GModel_Wire& theWire
			);
		
		static std::shared_ptr<GModel_parWire> RetrieveParWire(const GModel_Wire& theWire);
	};
}

#endif // !_GModel_Wire_Header
