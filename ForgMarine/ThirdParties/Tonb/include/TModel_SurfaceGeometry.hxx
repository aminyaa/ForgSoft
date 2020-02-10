#pragma once
#ifndef _TModel_SurfaceGeometry_Header
#define _TModel_SurfaceGeometry_Header

#include <Standard_Handle.hxx>
#include <TopoDS_Face.hxx>
#include <Global_AccessMethod.hxx>
#include <OFstream.hxx>

class Geom_Surface;
class Poly_Triangulation;

namespace tnbLib
{

	class TModel_SurfaceGeometry
	{

		/*Private Data*/

		Handle(Geom_Surface) theGeometry_;

		TopoDS_Face theFace_;


		static void CheckGeometry(const Handle(Geom_Surface)& thePatch, const char* theName);

	protected:

		TModel_SurfaceGeometry
		(
			const Handle(Geom_Surface)& theGeometry
		)
			: theGeometry_(theGeometry)
		{
			//CheckGeometry(theGeometry, "TModel_SurfaceGeometry()");
		}

	public:

		const auto& Geometry() const
		{
			return theGeometry_;
		}

		Handle(Poly_Triangulation) RetrieveTriangulation() const;


		//- Io functions and operators

		void ExportPlaneCurvesToPlt(OFstream& File) const;

		void ExportToPlt(OFstream& File) const;

		void ExportMetricDetToPlt(OFstream& File) const;

		void ExportMetricDetPlaneToPlt(OFstream& File) const;

		//- Macros
		GLOBAL_ACCESS_SINGLE(TopoDS_Face, Face)
	};
}

#endif // !_TModel_SurfaceGeometry_Header
