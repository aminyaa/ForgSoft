#pragma once
inline
AutLib::Pnt2d 
AutLib::Mesh2d_OptNode_Analytical_Base::CalcCoord
(
	const Standard_Real theSize,
	const Aft2d_Edge & theEdge
)
{
	const auto& middle = theEdge.Centre();
	auto vec = (theEdge.Node1()->Coord() - middle).UnitLength();
	vec.Rotate90ccw();

	auto P = middle + theSize * vec;
	return std::move(P);
}

namespace AutLib
{

	void Mesh2d_OptNode_Analytical::Perform()
	{
		ChangeCoord() = CalcCoord(ElementSize(), Front());

		Change_IsDone() = Standard_True;
	}
}