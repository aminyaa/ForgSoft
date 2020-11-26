#pragma once
#ifndef _Pln_Wire_Header
#define _Pln_Wire_Header

#include <Pln_Entity.hxx>
#include <Pln_Orientation.hxx>
#include <Entity2d_PolygonFwd.hxx>
#include <Entity2d_BoxFwd.hxx>
#include <OFstream.hxx>

class gp_Trsf2d;

#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class Pln_Edge;
	class Pln_Curve;
	class Pln_Vertex;
	class Pln_CmpEdge;
	class Geo_ApprxCurve_Info;

	class Pln_Wire
		: public Pln_Entity
	{

		/*Private Data*/

		Pln_Orientation theOrientation_;

		std::shared_ptr<Pln_CmpEdge> theEdges_;

		std::shared_ptr<Entity2d_Box> theBoundingBox_;


		//- private functions

		void CalcBoundingBox(const std::vector<std::shared_ptr<Pln_Edge>>& theEdges);

		void CheckWire(const std::vector<std::shared_ptr<Pln_Edge>>& theEdges);

		void CreateWire(const std::shared_ptr<Pln_CmpEdge>& theEdge);

	public:

		Pln_Wire
		(
			const std::shared_ptr<Pln_CmpEdge>& theEdge
		);

		Pln_Wire
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<Pln_CmpEdge>& theEdge
		);

		Pln_Wire
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<Pln_CmpEdge>& theEdge
		);

		Standard_Integer NbEdges() const;

		std::tuple<Standard_Real, Standard_Real> 
			BoundTolerance() const;

		std::shared_ptr<Entity2d_Polygon>
			Polygon() const;

		const std::vector<std::shared_ptr<Pln_Edge>>& Edges() const;

		const std::shared_ptr<Pln_CmpEdge>& CmpEdge() const
		{
			return theEdges_;
		}

		const std::shared_ptr<Entity2d_Box>& BoundingBox() const
		{
			return theBoundingBox_;
		}

		Pln_Orientation Orientation() const
		{
			return theOrientation_;
		}

		std::vector<std::shared_ptr<Pln_Vertex>>
			RetrieveVertices() const;

		std::vector<std::shared_ptr<Pln_Curve>>
			RetrieveCurves() const;

		std::shared_ptr<Pln_Entity>
			Copy() const override;

		void Transform(const gp_Trsf2d& t);

		void ApplyOrientation(const Pln_Orientation theOrient);

		void Reverse();

		void RetrieveVerticesTo
		(
			std::vector<std::shared_ptr<Pln_Vertex>>& theVertices
		) const;

		void RetrieveCurvesTo
		(
			std::vector<std::shared_ptr<Pln_Curve>>& theCurves
		) const;

		void Approx
		(
			const std::shared_ptr<Geo_ApprxCurve_Info>& theInfo
		) const;

		void ExportToPlt(OFstream& File) const;

		//- Static functions and operators

		/*static std::vector<std::shared_ptr<Pln_Wire>>
			RetrieveWires
			(
				const std::vector<std::shared_ptr<Pln_Edge>>& theEdges
			);*/

		//static Pln_Orientation RetrieveOrientation(const Pln_Wire& theWire);
	};
}

#endif // !_Pln_Wire_Header
