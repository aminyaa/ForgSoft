#pragma once
#ifndef _Cad2d_IntsctEntity_TangSegment_Header
#define _Cad2d_IntsctEntity_TangSegment_Header

#include <Cad2d_IntsctEntity_Segment.hxx>
#include <Pnt2d.hxx>

namespace tnbLib
{

	class Cad2d_IntsctEntity_TangSegment
		: public Cad2d_IntsctEntity_Segment
	{

		/*Private Data*/

		Standard_Real theParameter0_;
		Standard_Real theParameter1_;

		Pnt2d theCoord0_;
		Pnt2d theCoord1_;

	public:

		Cad2d_IntsctEntity_TangSegment();

		explicit Cad2d_IntsctEntity_TangSegment(const Standard_Integer theIndex);

		Cad2d_IntsctEntity_TangSegment(const Standard_Integer theIndex, const word& theName);

		Standard_Real CharParameter() const override;

		//- Macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Parameter0)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Parameter1)

			GLOBAL_ACCESS_SINGLE(Pnt2d, Coord0)
			GLOBAL_ACCESS_SINGLE(Pnt2d, Coord1)
	};
}

#endif // !_Cad2d_IntsctEntity_TangSegment_Header
