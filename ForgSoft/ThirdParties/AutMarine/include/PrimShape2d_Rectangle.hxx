#pragma once
#ifndef _PrimShape2d_Rectangle_Header
#define _PrimShape2d_Rectangle_Header

#include <Geo2d_PrimShape.hxx>

namespace AutLib
{

	class PrimShape2d_Rectangle
		: public Geo2d_PrimShape
	{

		/*Private Data*/

		Pnt2d theP0_;

		Standard_Real theDx_;
		Standard_Real theDy_;

		void Make();

	public:

		PrimShape2d_Rectangle
		(
			const Pnt2d& theP0,
			const Standard_Real theDx, 
			const Standard_Real theDy
		)
			: theP0_(theP0)
			, theDx_(theDx)
			, theDy_(theDy)
		{}

		const Pnt2d& P0() const
		{
			return theP0_;
		}

		Standard_Real Dx() const
		{
			return theDx_;
		}

		Standard_Real Dy() const
		{
			return theDy_;
		}

		void Transform(const gp_Trsf2d& theTrasf);
	};
}

#endif // !_PrimShape2d_Rectangle_Header
