#pragma once
namespace AutLib
{

	inline Standard_Real
		AutLib::Geo_Interpolate::Linear
		(
			const Standard_Real theX,
			const Standard_Real theX0, 
			const Standard_Real theY0,
			const Standard_Real theX1,
			const Standard_Real theY1
		)
	{
		auto Dx = theX1 - theX0;
		auto Dy = theY1 - theY0;

		auto dx = theX - theX0;
		return theY0 + dx * (Dy / Dx);
	}
}