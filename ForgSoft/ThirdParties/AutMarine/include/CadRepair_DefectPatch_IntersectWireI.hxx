#pragma once
#include <Global_Macros.hxx>
#include <error.hxx>
#include <OSstream.hxx>
namespace AutLib
{

	template<class SurfType>
	Standard_Boolean CadRepair_DefectPatch_IntersectWire<SurfType>::Check
	(
		const SurfType& theSurface, 
		std::shared_ptr<wireType>& theOuter, 
		std::shared_ptr<wireType>& theInner, 
		const Standard_Real theTol
	)
	{
		if (NOT theSurface.HasHole())
		{
			return Standard_False;
		}

		theWire1_ = theSurface.OuterWire();

		const auto& outer = theSurface.OuterWire();
		const auto& inners = *theSurface.InnerWires();

		auto oBox = outer->CalcParametricBoundingBox();

		for (const auto& x : inners)
		{
			Debug_Null_Pointer(x);
			auto iBox = x->CalcParametricBoundingBox();

			auto offset = iBox.OffSet(theTol);

			if (NOT Entity2d_Box::IsInside(offset, oBox))
			{
				theWire2_ = x;
				return Standard_True;
			}
		}

		return Standard_False;
	}
}