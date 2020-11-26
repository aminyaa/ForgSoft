#pragma once
#ifndef _Cad2d_GeoSketch_Header
#define _Cad2d_GeoSketch_Header

#include <Cad_GeoSketch.hxx>
#include <OFstream.hxx>

#include <Standard_Handle.hxx>

class Geom2d_Curve;

namespace tnbLib
{

	class Cad2d_GeoSketch
		: public Cad_GeoSketch
	{

		/*Private Data*/

		Handle(Geom2d_Curve) theGeom_;

	protected:

		Cad2d_GeoSketch()
		{}

		Cad2d_GeoSketch(const Standard_Integer theIndex)
			: Cad_GeoSketch(theIndex)
		{}

		Cad2d_GeoSketch
		(
			const Standard_Integer theIndex,
			const word& theName
		)
			: Cad_GeoSketch(theIndex, theName)
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

#endif // !_Cad2d_GeoSketch_Header
