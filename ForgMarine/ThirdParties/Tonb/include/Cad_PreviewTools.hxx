#pragma once
#ifndef _Cad_PreviewTools_Header
#define _Cad_PreviewTools_Header

#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <Entity3d_TriangulationFwd.hxx>
#include <Entity3d_PolygonFwd.hxx>
#include <Entity3d_ChainFwd.hxx>

class Geom_Curve;
class Geom_Surface;
class TopoDS_Face;
class TopoDS_Shape;

namespace tnbLib
{

	class Cad_PreviewTools
	{

	public:

		//- an exception will be thrown if the surface is not bspline
		static std::shared_ptr<Entity3d_Triangulation>
			PreviewPatchCurves
			(
				const Handle(Geom_Surface)& theSurface,
				const Standard_Integer theNbSegments_U,
				const Standard_Integer theNbSegments_V
			);

		static std::shared_ptr<Entity3d_Chain>
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

		static std::shared_ptr<Entity3d_Chain>
			PreviewUnMergedPatchCurves
			(
				const TopoDS_Face& theFace,
				const Standard_Integer theNbSegments_U,
				const Standard_Integer theNbSegments_V
			);

		static std::shared_ptr<Entity3d_Chain>
			PreviewUnMergedPatchCurves
			(
				const TopoDS_Shape& theShape,
				const Standard_Integer theNbSegments_U,
				const Standard_Integer theNbSegments_V
			);

		static std::shared_ptr<Entity3d_Polygon>
			PreviewCurveOnSurface_U
			(
				const Handle(Geom_Surface)& theSurface,
				const Standard_Real u,
				const Standard_Integer theNbSegments
			);

		static std::shared_ptr<Entity3d_Polygon>
			PreviewCurveOnSurface_V
			(
				const Handle(Geom_Surface)& theSurface,
				const Standard_Real v,
				const Standard_Integer theNbSegments
			);

		static std::shared_ptr<Entity3d_Polygon>
			PreviewCurve
			(
				const Handle(Geom_Curve)& theCurve,
				const Standard_Integer theNbSegments
			);
	};
}

#endif // !_Cad_PreviewTools_Header
