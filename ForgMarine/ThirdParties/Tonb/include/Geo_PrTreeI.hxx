#pragma once

namespace tnbLib
{

	/*Geo_Quadrant CalcQuadrant
	(
		const Pnt2d & theCoord,
		const Pnt2d & theCentre
	)
	{
		if (theCoord.X() <= theCentre.X())
			if (theCoord.Y() <= theCentre.Y())
				return Geo_Quadrant_SW;
			else
				return Geo_Quadrant_NW;
		else
		{
			if (theCoord.Y() <= theCentre.Y())
				return Geo_Quadrant_SE;
			else
				return Geo_Quadrant_NE;
		}
	}

	Geo_Octant CalcOctant
	(
		const Pnt3d & theCoord,
		const Pnt3d & theCentre
	)
	{
		if (theCoord.X() <= theCentre.X())
		{
			if (theCoord.Y() <= theCentre.Y())
			{
				if (theCoord.Z() <= theCentre.Z())
				{
					return Geo_Octant_Bwd_SW;
				}
				else
				{
					return Geo_Octant_Fwd_SW;
				}
			}
			else
			{
				if (theCoord.Z() <= theCentre.Z())
				{
					return Geo_Octant_Bwd_NW;
				}
				else
				{
					return Geo_Octant_Fwd_NW;
				}
			}
		}
		else
		{
			if (theCoord.Y() <= theCentre.Y())
			{
				if (theCoord.Z() <= theCentre.Z())
				{
					return Geo_Octant_Bwd_SE;
				}
				else
				{
					return Geo_Octant_Fwd_SE;
				}
			}
			else
			{
				if (theCoord.Z() <= theCentre.Z())
				{
					return Geo_Octant_Bwd_NE;
				}
				else
				{
					return Geo_Octant_Fwd_NE;
				}
			}
		}
	}*/

}