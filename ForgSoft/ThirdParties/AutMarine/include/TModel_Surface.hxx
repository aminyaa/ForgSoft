#pragma once
#ifndef _TModel_Surface_Header
#define _TModel_Surface_Header

#include <TModel_Entity.hxx>
#include <Entity2d_Box.hxx>
#include <Entity3d_Box.hxx>
#include <TModel_FaceOrientation.hxx>

#include <Standard_Handle.hxx>
#include <TopoDS_Face.hxx>

class Geom_Surface;
class Poly_Triangulation;

#include <vector>

namespace AutLib
{

	// Forward Declarations
	class TModel_Edge;
	class TModel_Wire;
	class TModel_Plane;
	class TModel_parWire;
	class Entity2d_Metric1;
	class TModel_parCurve;

	class TModel_Surface
		: public TModel_Entity
	{

		typedef std::shared_ptr<TModel_Wire> wire_ptr;
		typedef wire_ptr outer;

		typedef std::shared_ptr<std::vector<wire_ptr>> inner;

		/*Private Data*/

		Handle(Geom_Surface) theGeom_;

		Handle(Poly_Triangulation) theTriangulation_;

		outer theOuter_;
		inner theInner_;

		Entity2d_Box theBoundingBox_;
		Entity3d_Box theBoundingBox3d_;

		TopoDS_Face theFace_;

		TModel_FaceOrientation theOrientation_;


		//- Private functions and operators

		void Check() const;

		Entity2d_Box CalcParametricBoundingBox() const;

		Entity3d_Box CalcBoundingBox() const;

	public:

		typedef TModel_parCurve parCurveType;
		typedef TModel_Plane planeType;
		typedef TModel_parWire parWireType;

		typedef TModel_Wire wireType;

		TModel_Surface
		(
			const Handle(Geom_Surface)& theGeom,
			const outer& theOuter,
			const inner& theInner
		);

		TModel_Surface
		(
			const Standard_Integer theIndex,
			const Handle(Geom_Surface)& theGeom,
			const outer& theOuter,
			const inner& theInner
		);

		TModel_Surface
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Handle(Geom_Surface)& theGeom,
			const outer& theOuter,
			const inner& theInner
		);

		Standard_Integer NbHoles() const
		{
			if (NOT theInner_) return 0;
			return (Standard_Integer)theInner_->size();
		}

		Standard_Boolean HasHole() const
		{
			return NbHoles();
		}

		Standard_Boolean IsBSpline() const;

		Standard_Boolean IsClamped() const;

		const outer& OuterWire() const
		{
			return theOuter_;
		}

		const inner& InnerWires() const
		{
			return theInner_;
		}

		const Handle(Geom_Surface)& Geometry() const
		{
			return theGeom_;
		}

		Handle(Poly_Triangulation) RetrieveTriangulation() const;

		const Handle(Poly_Triangulation)& Triangulation() const
		{
			return theTriangulation_;
		}

		const Entity2d_Box& BoundingBox() const
		{
			return theBoundingBox_;
		}

		const Entity3d_Box& BoundingBox3d() const
		{
			return theBoundingBox3d_;
		}

		const TopoDS_Face& Face() const
		{
			return theFace_;
		}

		std::vector<std::shared_ptr<TModel_Edge>> Edges() const;

		Entity2d_Metric1 MetricAt(const Pnt2d& theCoord) const;

		Pnt3d Value(const Pnt2d& theCoord) const;

		void GetParametricBouns
		(
			Standard_Real& theXmin,
			Standard_Real& theXmax,
			Standard_Real& theYmin,
			Standard_Real& theYmax
		) const;

		void SetFace(const TopoDS_Face& theFace)
		{
			theFace_ = theFace;
		}

		void SetTriangulation(const Handle(Poly_Triangulation)& theTriangulation)
		{
			theTriangulation_ = theTriangulation;
		}


		//- Io functions and operators

		void ExportPlaneCurvesToPlt(OFstream& File) const;

		//void ExportCurvesFromPlaneToPlt(OFstream& File) const;

		void ExportToPlt(OFstream& File) const;

		void ExportMetricDetToPlt(OFstream& File) const;

		void ExportMetricDetPlaneToPlt(OFstream& File) const;

		//- static functions and operators

		static Standard_Boolean
			IsLess
			(
				const std::shared_ptr<TModel_Surface>& theS0,
				const std::shared_ptr<TModel_Surface>& theS1
			)
		{
			Debug_Null_Pointer(theS0);
			Debug_Null_Pointer(theS1);

			return theS0->Index() < theS1->Index();
		}
	};
}

#endif // !_TModel_Surface_Header
