#pragma once
#ifndef _GModel_Surface_Header
#define _GModel_Surface_Header

#include <GModel_Entity.hxx>
#include <Entity2d_Box.hxx>
#include <Pnt3d.hxx>

#include <Standard_Handle.hxx>
#include <TopoDS_Face.hxx>

class Geom_Surface;
class Poly_Triangulation;

namespace AutLib
{

	// Forward Declarations
	class GModel_Wire;
	class GModel_parCurve;
	class Cad3d_GModel;
	class Numeric_AdaptIntegrationInfo;
	class Entity2d_Metric1;

	class GModel_Surface
		: public GModel_Entity
	{

		typedef std::shared_ptr<GModel_Wire> wire_ptr;
		typedef wire_ptr outer;

		typedef std::shared_ptr<std::vector<wire_ptr>> inner;

		/*Private Data*/

		Handle(Geom_Surface) theGeom_;

		Handle(Poly_Triangulation) theTriangulation_;

		outer theOuter_;
		inner theInner_;

		Entity2d_Box theBoundingBox_;

		TopoDS_Face theFace_;

		Entity2d_Box CalcParametricBoundingBox() const;

	public:

		GModel_Surface
		(
			const Handle(Geom_Surface)& theGeom,
			const outer& theOuter,
			const inner& theInner
		)
			: theGeom_(theGeom)
			, theOuter_(theOuter)
			, theInner_(theInner)
		{
			theBoundingBox_ = CalcParametricBoundingBox();
		}

		GModel_Surface
		(
			const Standard_Integer theIndex,
			const Handle(Geom_Surface)& theGeom,
			const outer& theOuter,
			const inner& theInner
		)
			: theGeom_(theGeom)
			, theOuter_(theOuter)
			, theInner_(theInner)
			, GModel_Entity(theIndex)
		{
			theBoundingBox_ = CalcParametricBoundingBox();
		}

		GModel_Surface
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Handle(Geom_Surface)& theGeom,
			const outer& theOuter,
			const inner& theInner
		)
			: theGeom_(theGeom)
			, theOuter_(theOuter)
			, theInner_(theInner)
			, GModel_Entity(theIndex, theName)
		{
			theBoundingBox_ = CalcParametricBoundingBox();
		}

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

		const Handle(Poly_Triangulation)& Triangulation() const
		{
			return theTriangulation_;
		}

		const Entity2d_Box& BoundingBox() const
		{
			return theBoundingBox_;
		}

		const TopoDS_Face& Face() const
		{
			return theFace_;
		}

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


		//- IO functions and operators

		void ExportPlaneCurvesToPlt(OFstream& File) const;

		//void ExportCurvesFromPlaneToPlt(OFstream& File) const;

		void ExportToPlt(OFstream& File) const;

		void ExportMetricDetToPlt(OFstream& File) const;
	};
}

#endif // !_GModel_Surface_Header
