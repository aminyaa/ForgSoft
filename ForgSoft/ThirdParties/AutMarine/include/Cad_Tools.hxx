#pragma once
#ifndef _Cad_Tools_Header
#define _Cad_Tools_Header

#include <Standard_Handle.hxx>
#include <Entity2d_BoxFwd.hxx>
#include <Entity3d_BoxFwd.hxx>
#include <Entity3d_Triangulation.hxx>
#include <Entity2d_TriangulationFwd.hxx>

class Bnd_Box2d;
class Bnd_Box;
class Geom_Curve;
class Geom_Surface;
class Geom2d_Curve;
class Poly_Triangulation;
class TopoDS_Face;
class TopoDS_Shape;
class Geom2dAPI_InterCurveCurve;

namespace AutLib
{

	// Forward Declaration
	class Numeric_AdaptIntegrationInfo;

	class Cad_Tools
	{

	public:

		//- an exception will be thrown if the curve is not bounded
		static std::shared_ptr<Geom2dAPI_InterCurveCurve> 
			Intersection
			(
				const Handle(Geom2d_Curve)& theCurve0, 
				const Handle(Geom2d_Curve)& theCurve1,
				const Standard_Real theTol = 1.0E-6
			);

		static Handle(Geom2d_Curve)
			ConvertToTrimmedCurve
			(
				const Handle(Geom2d_Curve)& theCurve,
				const Standard_Real theU0,
				const Standard_Real theU1);

		static std::shared_ptr<Entity2d_Triangulation> 
			ParametricTriangulation
			(
				const Pnt2d& theP0,
				const Pnt2d& theP1,
				const Standard_Integer theNx, 
				const Standard_Integer theNy
			);

		static std::shared_ptr<Entity3d_Triangulation>
			Triangulation
			(
				const Geom_Surface& theSurface, 
				const Entity2d_Triangulation& theParametric
			);

		static std::shared_ptr<Entity3d_Triangulation>
			Triangulation
			(
				const Handle(Geom_Surface)& theSurface,
				const Standard_Integer theNx,
				const Standard_Integer theNy
			);

		static Handle(Geom_Surface)
			ConvertToRectangularTrimmedSurface
			(
				const Handle(Geom_Surface)& theSurface,
				const Entity2d_Box& theBoundaries
			);

		//- an exception will be thrown if the surface is not bounded
		static Handle(Geom_Surface)
			ConvertToBSpline
			(
				const Handle(Geom_Surface)& theSurface
			);

		//- an exception will be thrown if the curve is not bounded
		static Handle(Geom2d_Curve) 
			ConvertToBSpline
			(
				const Handle(Geom2d_Curve)& theCurve
			);

		//- an exception will be thrown if the surface is not bspline
		static std::shared_ptr<Entity3d_Triangulation> 
			PreviewPatchCurves
			(
				const Handle(Geom_Surface)& theSurface,
				const Standard_Integer theNbSegments_U,
				const Standard_Integer theNbSegments_V
			);

		static std::vector<std::shared_ptr<Entity3d_Triangulation>>
			PreviewUnMergedPatchCurves
			(
				const Handle(Geom_Surface)& theSurface,
				const Standard_Integer theNbSegments_U,
				const Standard_Integer theNbSegments_V
			);

		static std::shared_ptr<Entity3d_Triangulation>
			PreviewPatchCurves
			(
				const TopoDS_Face& theFace,
				const Standard_Integer theNbSegments_U,
				const Standard_Integer theNbSegments_V
			);

		static std::vector<std::shared_ptr<Entity3d_Triangulation>>
			PreviewUnMergedPatchCurves
			(
				const TopoDS_Face& theFace,
				const Standard_Integer theNbSegments_U,
				const Standard_Integer theNbSegments_V
			);

		static std::vector<std::shared_ptr<Entity3d_Triangulation>>
			PreviewPatchCurves
			(
				const TopoDS_Shape& theShape,
				const Standard_Integer theNbSegments_U,
				const Standard_Integer theNbSegments_V
			);

		static std::vector<std::shared_ptr<Entity3d_Triangulation>>
			PreviewUnMergedPatchCurves
			(
				const TopoDS_Shape& theShape,
				const Standard_Integer theNbSegments_U,
				const Standard_Integer theNbSegments_V
			);

		static std::shared_ptr<Entity3d_Triangulation> 
			PreviewCurveOnSurface_U
			(
				const Handle(Geom_Surface)& theSurface, 
				const Standard_Real u, 
				const Standard_Integer theNbSegments
			);

		static std::shared_ptr<Entity3d_Triangulation> 
			PreviewCurveOnSurface_V
			(
				const Handle(Geom_Surface)& theSurface, 
				const Standard_Real v,
				const Standard_Integer theNbSegments
			);

		static std::shared_ptr<Entity3d_Triangulation> 
			PreviewCurve
			(
				const Handle(Geom_Curve)& theCurve,
				const Standard_Integer theNbSegments
			);

		static Entity2d_Box BoundingBox(const Bnd_Box2d& theBox);

		static Entity3d_Box BoundingBox(const Bnd_Box& theBox);

		static Handle(Poly_Triangulation) 
			RetrieveTriangulation
			(
				const TopoDS_Face& theFace
			);

		static std::vector<Handle(Poly_Triangulation)> 
			RetrieveTriangulation
			(
				const TopoDS_Shape& theShape
			);

		static Bnd_Box BoundingBox
		(
			const Handle(Geom_Surface)& theSurface,
			const Entity2d_Box& theParams
		);

		//- an exception will be thrown if the curve is not bounded
		static Bnd_Box2d BoundingBox
		(
			const Handle(Geom2d_Curve)& theCurve
		);

		static Bnd_Box2d BoundingBox
		(
			const Handle(Geom2d_Curve)& theCurve,
			const Standard_Real theU0, 
			const Standard_Real theU1
		);

		static std::shared_ptr<Entity3d_Triangulation> 
			Triangulation
			(
				const Poly_Triangulation& theTriangulation
			);

		//- an exception will be thrown if the curve is not bounded and the x exceeds the boundary
		static void SplitCurve
		(
			const Handle(Geom2d_Curve)& theCurve,
			const Standard_Real theX,
			Handle(Geom2d_Curve)& theC0, 
			Handle(Geom2d_Curve)& theC1
		);

		static void ExportToIGES
		(
			const word& unit,
			const TopoDS_Shape& theShape, 
			const fileName& name
		);

		Standard_Real CharLength(const Handle(Geom_Surface)& theSurface, const Pnt2d& theP0, const Pnt2d& theP1, Numeric_AdaptIntegrationInfo& theInfo);

		template<class SurfType>
		static std::shared_ptr<SurfType> ReParameterization(const SurfType& theSurface, const Standard_Real thsScale);

		template<class SurfType>
		static std::shared_ptr<SurfType> ReParameterization_uExpand(const SurfType& theSurface, const Standard_Real theMult);

		template<class SurfType>
		static std::shared_ptr<SurfType> ReParameterization_vExpand(const SurfType& theSurface, const Standard_Real theMult);
      
		static void ExportToSTEP
		(
			const TopoDS_Shape& theShape,
			const fileName& name
		);
	};
}

#endif // !_Cad_Tools_Header
