#pragma once
#ifndef _PlnOpert_IntsctPoint_Header
#define _PlnOpert_IntsctPoint_Header

#include <PlnOpert_IntsctEntity.hxx>
#include <Pnt2d.hxx>

namespace tnbLib
{

	class PlnOpert_IntsctPoint
		: public PlnOpert_IntsctEntity
	{

		/*Private Data*/

		Pnt2d theCoord_;

		Standard_Real theParameter_;

	public:

		PlnOpert_IntsctPoint(const Standard_Integer theIndex)
			: PlnOpert_IntsctEntity(theIndex)
		{}

		PlnOpert_IntsctPoint
		(
			const Standard_Integer theIndex,
			const Pnt2d& theCoord,
			const Standard_Real theParameter
		)
			: PlnOpert_IntsctEntity(theIndex)
			, theCoord_(theCoord)
			, theParameter_(theParameter)
		{}


		virtual Standard_Boolean IsType2() const
		{
			return Standard_False;
		}

		//- override functions

		Standard_Boolean IsPoint() const override
		{
			return Standard_True;
		}

		Standard_Real CharParameter() const override
		{
			return theParameter_;
		}

		//- Macros
		GLOBAL_ACCESS_SINGLE(Pnt2d, Coord)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Parameter)
	};
}

#endif // !_PlnOpert_IntsctPoint_Header
