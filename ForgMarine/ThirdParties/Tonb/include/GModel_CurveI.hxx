#pragma once
#include <Pnt3d.hxx>
namespace tnbLib
{

	inline 
		Pnt3d tnbLib::GModel_Curve::FirstCoord() const
	{
		auto p = Value(FirstParameter());
		return std::move(p);
	}

	inline 
		Pnt3d tnbLib::GModel_Curve::LastCoord() const
	{
		auto p = Value(LastParameter());
		return std::move(p);
	}
}