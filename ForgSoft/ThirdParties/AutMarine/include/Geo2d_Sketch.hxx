#pragma once
#ifndef _Geo2d_Sketch_Header
#define _Geo2d_Sketch_Header

#include <Geo_Sketch.hxx>
#include <OFstream.hxx>

#include <Standard_Handle.hxx>

class Geom2d_Curve;

namespace AutLib
{

	class Geo2d_Sketch
		: public Geo_Sketch
	{

		/*Private Data*/

		Handle(Geom2d_Curve) theGeom_;

	protected:

		Geo2d_Sketch()
		{}


		Handle(Geom2d_Curve)& ChangeGeometry()
		{
			return theGeom_;
		}

	public:

		const Handle(Geom2d_Curve)& Geometry() const
		{
			return theGeom_;
		}

		void ExportToPlt(OFstream& File) const;
	};
}

#endif // !_Geo2d_Sketch_Header
