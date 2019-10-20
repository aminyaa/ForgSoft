#pragma once
#ifndef _Geo2d_Interpolation_Header
#define _Geo2d_Interpolation_Header

#include <Geo2d_Sketch.hxx>
#include <Pnt2d.hxx>

#include <vector>

namespace AutLib
{

	class Geo2d_Interpolation
		: public Geo2d_Sketch
	{

		/*Private Data*/

		std::vector<Pnt2d> thePts_;

	public:

		Geo2d_Interpolation()
		{}


		void InsertToList(const Pnt2d& theCoord)
		{
			thePts_.push_back(theCoord);
		}

		void Perform();
	};
}

#endif // !_Geo2d_Interpolation_Header
