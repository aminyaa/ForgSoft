#pragma once
#ifndef _GModel_Wire_Header
#define _GModel_Wire_Header

#include <GModel_Entity.hxx>
#include <Entity2d_BoxFwd.hxx>
#include <OFstream.hxx>

#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class GModel_Edge;
	class GModel_ParaWire;
	class GModel_ParaCurve;

	class GModel_Wire
		: public GModel_Entity
	{

		typedef std::vector<std::shared_ptr<GModel_Edge>> edgeList;

		/*Private Data*/

		std::shared_ptr<edgeList> theEdges_;

	public:

		GModel_Wire
		(
			const std::shared_ptr<edgeList>& theEdges
		);

		GModel_Wire
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<edgeList>& theEdges
		);

		GModel_Wire
		(
			const Standard_Integer theIndex,
			const word& theName, 
			const std::shared_ptr<edgeList>& theEdges
		);


		Standard_Integer NbEdges() const;

		const auto& Edges() const
		{
			return theEdges_;
		}

		Entity2d_Box CalcParametricBoundingBox() const;


		//- Io functions and operators

		void ExportPlaneCurvesToPlt
		(
			OFstream& File
		) const;


		//- Static functions and operators

		static std::shared_ptr<std::vector<std::shared_ptr<GModel_ParaCurve>>>
			RetrievePlaneCurves
			(
				const GModel_Wire& theWire
			);

		static std::shared_ptr<GModel_ParaWire> 
			RetrieveParWire
			(
				const GModel_Wire& theWire
			);
	};
}

#endif // !_GModel_Wire_Header
