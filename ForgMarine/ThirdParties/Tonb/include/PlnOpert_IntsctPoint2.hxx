#pragma once
#ifndef _PlnOpert_IntsctPoint2_Header
#define _PlnOpert_IntsctPoint2_Header

#include <PlnOpert_IntsctPoint.hxx>

namespace tnbLib
{

	// Forward Declarations
	class PlnOpert_IntsctSegment;

	class PlnOpert_IntsctPoint2
		: public PlnOpert_IntsctPoint
	{

		/*Private Data*/

		std::weak_ptr<PlnOpert_IntsctSegment> theSegment_;

	public:

		PlnOpert_IntsctPoint2(const Standard_Integer theIndex)
			: PlnOpert_IntsctPoint(theIndex)
		{}

		PlnOpert_IntsctPoint2
		(
			const Standard_Integer theIndex,
			const Pnt2d& theCoord,
			const Standard_Real theParameter
		)
			: PlnOpert_IntsctPoint(theIndex, theCoord, theParameter)
		{}

		Standard_Boolean IsType2() const override
		{
			return Standard_True;
		}

		//- Macros
		GLOBAL_ACCESS_SINGLE(std::weak_ptr<PlnOpert_IntsctSegment>, Segment)
	};
}

#endif // !_PlnOpert_IntsctPoint2_Header
