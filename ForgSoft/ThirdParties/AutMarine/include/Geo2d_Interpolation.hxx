#pragma once
#ifndef _Geo2d_Interpolation_Header
#define _Geo2d_Interpolation_Header

#include <Global_Done.hxx>
#include <Geo2d_Sketch.hxx>
#include <Pnt2d.hxx>
#include <Vec2d.hxx>

#include <vector>
#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Geo2d_InterpolationInfo;

	class Geo2d_Interpolation
		: public Geo2d_Sketch
		, public Global_Done
	{

		/*Private Data*/

		std::vector<Pnt2d> thePts_;

	public:

		Geo2d_Interpolation()
		{}


		void LoadPoint(const Pnt2d& theCoord)
		{
			thePts_.push_back(theCoord);
		}

		void Perform
		(
			const std::shared_ptr<Geo2d_InterpolationInfo>& theInfo
		);

		void Perform
		(
			const std::shared_ptr<Geo2d_InterpolationInfo>& theInfo,
			const Vec2d& theFirst, 
			const Vec2d& theLast, 
			const Standard_Boolean Scale = Standard_True
		);
	};
}

#endif // !_Geo2d_Interpolation_Header
