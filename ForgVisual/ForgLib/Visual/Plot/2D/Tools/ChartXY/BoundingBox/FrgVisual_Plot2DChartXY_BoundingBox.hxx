#pragma once
#ifndef _FrgVisual_Plot2DChartXY_BoundingBox_Header
#define _FrgVisual_Plot2DChartXY_BoundingBox_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_Pnt.hxx>

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_Plot2DChartXY_BoundingBox
{

public:

	FrgVisual_Plot2DChartXY_BoundingBox
	(
		ForgBaseLib::FrgBase_Pnt<2> P0 = ForgBaseLib::FrgBase_Pnt<2>(0.0, 0.0),
		ForgBaseLib::FrgBase_Pnt<2> P1 = ForgBaseLib::FrgBase_Pnt<2>(1.0, 1.0)
	);

	double Diameter() const;

	bool IsInside(const ForgBaseLib::FrgBase_Pnt<2>& P);

	const auto& P0() const { return theP0_; }
	auto& P0() { return theP0_; }
	const auto& P1() const { return theP1_; }
	auto& P1() { return theP1_; }

	FrgVisual_Plot2DChartXY_BoundingBox OffSet(const double tol) const;

	void Expand(const double dx, const double dy);

	static FrgVisual_Plot2DChartXY_BoundingBox BoundingBoxOf(const std::vector<ForgBaseLib::FrgBase_Pnt<2>>& thePts);
	
	static FrgVisual_Plot2DChartXY_BoundingBox Union
	(
		const FrgVisual_Plot2DChartXY_BoundingBox& theBox0,
		const FrgVisual_Plot2DChartXY_BoundingBox& theBox1
	);

private:

	ForgBaseLib::FrgBase_Pnt<2> theP0_;
	ForgBaseLib::FrgBase_Pnt<2> theP1_;
};

EndForgVisualLib

#endif // !_FrgVisual_Plot2DChartXY_BoundingBox_Header
