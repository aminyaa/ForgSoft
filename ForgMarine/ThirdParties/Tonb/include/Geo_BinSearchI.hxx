#pragma once
namespace tnbLib
{

	template<class T>
	Standard_Integer Geo_BinSearch<T>::KeyX
	(
		const Standard_Real theX
	) const
	{
		return (Standard_Integer)((theX - Pmin().X()) / std::get<0>(D)) + 1;
	}

	template<class T>
	Standard_Integer Geo_BinSearch<T>::KeyY
	(
		const Standard_Real theX
	) const
	{
		return (Standard_Integer)((theX - Pmin().Y()) / std::get<1>(D)) + 1;
	}

}