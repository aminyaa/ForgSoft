#pragma once
#ifndef _PlnOpert_IntsctSegment_Header
#define _PlnOpert_IntsctSegment_Header

#include <PlnOpert_IntsctEntity.hxx>
#include <Pnt2d.hxx>

#include <array>

namespace tnbLib
{

	// Forward Declarations
	class PlnOpert_IntsctPoint;

	class PlnOpert_IntsctSegment
		: public PlnOpert_IntsctEntity
	{

		/*Private Data*/

		Pnt2d theCoord0_;
		Pnt2d theCoord1_;

		Standard_Real theParameter0_;
		Standard_Real theParameter1_;

	public:

		PlnOpert_IntsctSegment(const Standard_Integer theIndex)
			: PlnOpert_IntsctEntity(theIndex)
		{}

		PlnOpert_IntsctSegment
		(
			const Standard_Integer theIndex,
			const Pnt2d& theCoord0,
			const Pnt2d& theCoord1,
			const Standard_Real theParam0,
			const Standard_Real theParam1
		)
			: PlnOpert_IntsctEntity(theIndex)
			, theCoord0_(theCoord0)
			, theCoord1_(theCoord1)
			, theParameter0_(theParam0)
			, theParameter1_(theParam1)
		{}

		virtual Standard_Boolean IsType2() const
		{
			return Standard_False;
		}

		static std::array<std::shared_ptr<PlnOpert_IntsctPoint>, 2>
			ConvertToPoints(const PlnOpert_IntsctSegment& theEntity);

		//- override functions

		Standard_Boolean IsSegment() const override
		{
			return Standard_True;
		}

		Standard_Real CharParameter() const override
		{
			return MEAN(Parameter0(), Parameter1());
		}

		//- Macros
		GLOBAL_ACCESS_SINGLE(Pnt2d, Coord0)
			GLOBAL_ACCESS_SINGLE(Pnt2d, Coord1)

			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Parameter0)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Parameter1)
	};
}

#endif // !_PlnOpert_IntsctSegment_Header
