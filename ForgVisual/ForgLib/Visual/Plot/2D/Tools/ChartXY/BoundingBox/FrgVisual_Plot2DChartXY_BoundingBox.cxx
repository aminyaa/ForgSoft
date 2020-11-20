#include <FrgVisual_Plot2DChartXY_BoundingBox.hxx>

ForgVisualLib::FrgVisual_Plot2DChartXY_BoundingBox::FrgVisual_Plot2DChartXY_BoundingBox
(
	ForgBaseLib::FrgBase_Pnt<2> P0,
	ForgBaseLib::FrgBase_Pnt<2> P1
)
	: theP0_(P0)
	, theP1_(P1)
{

}

double ForgVisualLib::FrgVisual_Plot2DChartXY_BoundingBox::Diameter() const
{
	return theP0_.Distance(theP1_);
}

bool ForgVisualLib::FrgVisual_Plot2DChartXY_BoundingBox::IsInside(const ForgBaseLib::FrgBase_Pnt<2>& P)
{
	if (
		(P.Coord(0) >= theP0_.Coord(0) && P.Coord(0) <= theP1_.Coord(0))
		&&
		(P.Coord(1) >= theP0_.Coord(1) && P.Coord(1) <= theP1_.Coord(1))
		)
	{
		return true;
	}

	return false;
}

ForgVisualLib::FrgVisual_Plot2DChartXY_BoundingBox ForgVisualLib::FrgVisual_Plot2DChartXY_BoundingBox::OffSet(const double tol) const
{
	ForgBaseLib::FrgBase_Pnt<2> p0(P0().X() - tol, P0().Y() - tol);
	ForgBaseLib::FrgBase_Pnt<2> p1(P1().X() + tol, P1().Y() + tol);

	return FrgVisual_Plot2DChartXY_BoundingBox(p0, p1);
}

void ForgVisualLib::FrgVisual_Plot2DChartXY_BoundingBox::Expand(const double dx, const double dy)
{
	auto& p0 = P0();
	auto& p1 = P1();

	p0.X() -= dx;
	p0.Y() -= dy;

	p1.X() += dx;
	p1.Y() += dy;
}

ForgVisualLib::FrgVisual_Plot2DChartXY_BoundingBox ForgVisualLib::FrgVisual_Plot2DChartXY_BoundingBox::BoundingBoxOf
(
	const std::vector<ForgBaseLib::FrgBase_Pnt<2>>& thePts
)
{
	ForgBaseLib::FrgBase_Pnt<2> Pmin, Pmax;
	Pmin = 1.7976931348623158e+308;
	Pmax = -1.7976931348623158e+308;
	for (const auto& x : thePts)
	{
		Pmin.X() = std::min(Pmin.X(), x.X());
		Pmin.Y() = std::min(Pmin.Y(), x.Y());

		Pmax.X() = std::max(Pmax.X(), x.X());
		Pmax.Y() = std::max(Pmax.Y(), x.Y());
	}

	FrgVisual_Plot2DChartXY_BoundingBox box(Pmin, Pmax);
	return std::move(box);
}

ForgVisualLib::FrgVisual_Plot2DChartXY_BoundingBox ForgVisualLib::FrgVisual_Plot2DChartXY_BoundingBox::Union
(
	const FrgVisual_Plot2DChartXY_BoundingBox& theBox0,
	const FrgVisual_Plot2DChartXY_BoundingBox& theBox1
)
{
	std::vector<ForgBaseLib::FrgBase_Pnt<2>> list;
	list.push_back(theBox0.P0());
	list.push_back(theBox0.P1());

	list.push_back(theBox1.P0());
	list.push_back(theBox1.P1());

	auto box = BoundingBoxOf(list);
	return std::move(box);
}