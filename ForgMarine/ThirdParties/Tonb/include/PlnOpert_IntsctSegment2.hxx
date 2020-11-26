#pragma once
#ifndef _PlnOpert_IntsctSegment2_Header
#define _PlnOpert_IntsctSegment2_Header

#include <PlnOpert_IntsctSegment.hxx>

namespace tnbLib
{

	class PlnOpert_IntsctSegment2
		: public PlnOpert_IntsctSegment
	{

		/*Private Data*/

		std::shared_ptr<PlnOpert_IntsctPoint> theStart_;
		std::shared_ptr<PlnOpert_IntsctPoint> theEnd_;

	public:

		PlnOpert_IntsctSegment2(const Standard_Integer theIndex)
			: PlnOpert_IntsctSegment(theIndex)
		{}

		PlnOpert_IntsctSegment2
		(
			const Standard_Integer theIndex,
			const Pnt2d& theCoord0,
			const Pnt2d& theCoord1,
			const Standard_Real theParam0,
			const Standard_Real theParam1
		)
			: PlnOpert_IntsctSegment(theIndex, theCoord0, theCoord1, theParam0, theParam1)
		{}


		Standard_Boolean IsType2() const override
		{
			return Standard_True;
		}

		//- Macros
		GLOBAL_ACCESS_SINGLE(std::shared_ptr<PlnOpert_IntsctPoint>, Start)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<PlnOpert_IntsctPoint>, End)
	};
}

#endif // !_PlnOpert_IntsctSegment2_Header
