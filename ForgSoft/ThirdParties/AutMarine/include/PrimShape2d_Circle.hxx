#pragma once
#ifndef _PrimShape2d_Circle_Header
#define _PrimShape2d_Circle_Header

#include <Geo2d_PrimShape.hxx>

namespace AutLib
{

	class PrimShape2d_Circle
		: public Geo2d_PrimShape
	{

		/*Private Data*/

		Standard_Integer theNbPoints_;

		Pnt2d theCentre_;

		Standard_Real theRadius_;

		void Make();

	public:

		static const Standard_Integer DEFAULT_NB_POINTS;

		PrimShape2d_Circle
		(
			const Standard_Real theRadius,
			const Pnt2d& theCoord
		)
			: theNbPoints_(DEFAULT_NB_POINTS)
			, theRadius_(theRadius)
			, theCentre_(theCoord)
		{
			Make();
		}

		PrimShape2d_Circle
		(
			const Standard_Real theRadius, 
			const Pnt2d& theCoord,
			const Standard_Integer theNbPoints
		)
			: theNbPoints_(theNbPoints)
			, theRadius_(theRadius)
			, theCentre_(theCoord)
		{
			Make();
		}

		Standard_Real Radius() const
		{
			return theRadius_;
		}

		const Pnt2d& Centre() const
		{
			return theCentre_;
		}

		void Transform(const gp_Trsf2d& theTrasf);

	};
}

#endif // !_PrimShape2d_Circle_Header
