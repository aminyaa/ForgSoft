#pragma once
namespace tnbLib
{

	inline Pnt2d 
		Pln_Curve::FirstCoord() const
	{
		auto p = Value(FirstParameter());
		return std::move(p);
	}

	inline Pnt2d 
		Pln_Curve::LastCoord() const
	{
		auto p = Value(LastParameter());
		return std::move(p);
	}
}