#pragma once
#ifndef _CadSingularity_Detection_Base_Header
#define _CadSingularity_Detection_Base_Header

#include <Entity2d_Box.hxx>
#include <Entity2d_Polygon.hxx>

class Geom_Surface;

#include <memory>
#include <vector>

namespace AutLib
{

	template<class CurveType>
	class CadSingularity_Detection_Base
	{

	protected:


		static std::shared_ptr<CurveType> ParametricCurve_Pole(const Pnt2d& theP0, const Pnt2d& theP1);

		static std::shared_ptr<CurveType> ParametricCurve_Line(const Pnt2d& theP0, const Pnt2d& theP1);

		static std::vector<std::shared_ptr<CurveType>>
			LineHorizonCurves_Dangle
			(
				const Entity2d_Box& theBox,
				const Standard_Integer s0
			);

		static std::vector<std::shared_ptr<CurveType>>
			LineHorizonCurves_Corner
			(
				const Entity2d_Box& theBox,
				const Standard_Integer s0,
				const Geom_Surface& theSurface,
				const Standard_Real theTol
			);

		static std::vector<std::shared_ptr<CurveType>>
			LineHorizonCurves_WholeSide
			(
				const Entity2d_Box& theBox,
				const Standard_Integer s0
			);

		static std::vector<std::shared_ptr<CurveType>>
			LineHorizonCurves_Loop
			(
				const Entity2d_Box& theBox
			);

		static std::vector<std::shared_ptr<CurveType>>
			LineHorizonCurves_TwoSided
			(
				const Entity2d_Box& theBox,
				const Standard_Integer s0
			);
	};
}

#include <CadSingularity_Detection_BaseI.hxx>

#endif // !_CadSingularity_Detection_Base_Header
