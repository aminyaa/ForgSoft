#pragma once
#ifndef _Cad_Tools_Header
#define _Cad_Tools_Header

#include <Standard_Handle.hxx>
#include <Entity2d_BoxFwd.hxx>
#include <Entity3d_BoxFwd.hxx>
#include <Entity3d_Triangulation.hxx>

class Bnd_Box2d;
class Bnd_Box;
class Geom_Curve;
class Geom_Surface;
class Poly_Triangulation;
class TopoDS_Face;
class TopoDS_Shape;

namespace AutLib
{

	class Cad_Tools
	{

	public:

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

		//- an exception will be thrown if the surface is not bspline
		static std::shared_ptr<Entity3d_Triangulation> 
			PreviewPatchCurves
			(
				const Handle(Geom_Surface)& theSurface,
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

		static std::shared_ptr<Entity3d_Triangulation> 
			Triangulation
			(
				const Poly_Triangulation& theTriangulation
			);

		static void ExportToIGES
		(
			const word& unit,
			const TopoDS_Shape& theShape, 
			const fileName& name
		);
	};
}

#endif // !_Cad_Tools_Header
