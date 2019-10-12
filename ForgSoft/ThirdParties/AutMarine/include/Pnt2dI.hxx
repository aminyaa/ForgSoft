#pragma once
#include <Global_Macros.hxx>
namespace AutLib
{

	inline Pnt2d operator+(const Pnt2d& P1, const Pnt2d& P2)
	{
		Pnt2d Temp = P1;
		Temp += P2;
		MOVE(Temp);
	}

	inline Pnt2d operator-(const Pnt2d& P1, const Pnt2d& P2)
	{
		Pnt2d Temp = P1;
		Temp -= P2;
		MOVE(Temp);
	}

	inline Pnt2d operator+(const Pnt2d& P1, const Standard_Real Scalar)
	{
		Pnt2d Temp = P1;
		Temp += Scalar;
		MOVE(Temp);
	}

	inline Pnt2d operator+(const Standard_Real Scalar, const Pnt2d& P1)
	{
		Pnt2d Temp = P1;
		Temp += Scalar;
		MOVE(Temp);
	}

	inline Pnt2d operator-(const Pnt2d& P1, const Standard_Real Scalar)
	{
		Pnt2d Temp = P1;
		Temp -= Scalar;
		MOVE(Temp);
	}

	inline Pnt2d operator*(const Pnt2d& P1, const Standard_Real Scalar)
	{
		Pnt2d Temp = P1;
		Temp *= Scalar;
		MOVE(Temp);
	}

	inline Pnt2d operator*(const Standard_Real Scalar, const Pnt2d& P1)
	{
		Pnt2d Temp = P1;
		Temp *= Scalar;
		MOVE(Temp);
	}

	inline Pnt2d operator/(const Pnt2d& P1, const Standard_Real Scalar)
	{
		Pnt2d Temp = P1;
		Temp /= Scalar;
		MOVE(Temp);
	}

	inline Standard_Real Distance(const Pnt2d& P1, const Pnt2d& P2)
	{
		return P1.Distance(P2);
	}

	inline Standard_Real SquareDistance(const Pnt2d& P1, const Pnt2d& P2)
	{
		return P1.SquareDistance(P2);
	}

	inline Standard_Real DotProduct(const Pnt2d & P1, const Pnt2d & P2)
	{
		return P1.X()*P2.X() + P1.Y()*P2.Y();
	}

	inline Standard_Real CrossProduct(const Pnt2d & P1, const Pnt2d & P2)
	{
		return P1.X()*P2.Y() - P2.X()*P1.Y();
	}
}