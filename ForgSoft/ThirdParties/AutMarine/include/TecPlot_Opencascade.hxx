#pragma once
#ifndef _TecPlot_Opencascade_Header
#define _TecPlot_Opencascade_Header

#include <TecPlot.hxx>
#include <OFstream.hxx>

#include <TColgp_Array1OfPnt.hxx>
#include <Poly_Array1OfTriangle.hxx>

class TopoDS_Shape;
class TopoDS_Edge;
class Geom_Curve;
class Geom2d_Curve;
class Poly_Triangulation;

namespace AutLib
{

	namespace Io
	{

		void ExportMesh
		(
			const TColgp_Array1OfPnt & Points,
			const Poly_Array1OfTriangle & Triangles,
			OFstream& File
		);

		void ExportMesh
		(
			const Poly_Triangulation & Triangulation,
			OFstream& File
		);

		void ExportCurve
		(
			const Geom_Curve& Curve,
			const Standard_Real First,
			const Standard_Real Last,
			const Standard_Integer NbSegmets,
			OFstream& File
		);

		void ExportCurve
		(
			const Geom2d_Curve& Curve,
			const Standard_Real First,
			const Standard_Real Last,
			const Standard_Integer NbSegmets,
			OFstream& File
		);

		void ExportCurve
		(
			const TopoDS_Edge& Curve,
			const Standard_Integer NbSegmets,
			OFstream& File
		);

		void ExportCurvesOf
		(
			const TopoDS_Shape& theShape,
			const Standard_Integer nbSegments,
			OFstream& File
		);
	}
}

#endif // !_TecPlot_Opencascade_Header
