#pragma once
namespace AutLib
{

	inline Pnt3d operator+(const Pnt3d& P1, const Pnt3d& P2)
	{
		Pnt3d Temp = P1;
		Temp += P2;
		MOVE(Temp);
	}

	inline Pnt3d operator-(const Pnt3d& P1, const Pnt3d& P2)
	{
		Pnt3d Temp = P1;
		Temp -= P2;
		MOVE(Temp);
	}

	inline Pnt3d operator+(const Pnt3d& P1, const Standard_Real Scalar)
	{
		Pnt3d Temp = P1;
		Temp += Scalar;
		MOVE(Temp);
	}

	inline Pnt3d operator+(const Standard_Real Scalar, const Pnt3d& P1)
	{
		Pnt3d Temp = P1;
		Temp += Scalar;
		MOVE(Temp);
	}

	inline Pnt3d operator-(const Pnt3d& P1, const Standard_Real Scalar)
	{
		Pnt3d Temp = P1;
		Temp -= Scalar;
		MOVE(Temp);
	}

	inline Pnt3d operator*(const Pnt3d& P1, const Standard_Real Scalar)
	{
		Pnt3d Temp = P1;
		Temp *= Scalar;
		MOVE(Temp);
	}

	inline Pnt3d operator*(const Standard_Real Scalar, const Pnt3d& P1)
	{
		Pnt3d Temp = P1;
		Temp *= Scalar;
		MOVE(Temp);
	}

	inline Pnt3d operator/(const Pnt3d& P1, const Standard_Real Scalar)
	{
		Pnt3d Temp = P1;
		Temp /= Scalar;
		MOVE(Temp);
	}

	inline Pnt3d CrossProduct(const Pnt3d & v1, const Pnt3d & v2)
	{
		Pnt3d a(v1.Y()*v2.Z() - v2.Y()*v1.Z(), v1.Z()*v2.X() - v1.X()*v2.Z(), v1.X()*v2.Y() - v2.X()*v1.Y());
		return std::move(a);
	}

	inline Standard_Real DotProduct(const Pnt3d & P1, const Pnt3d & P2)
	{
		return P1.X()*P2.X() + P1.Y()*P2.Y() + P1.Z()*P2.Z();
	}

	inline Standard_Real Distance(const Pnt3d& P1, const Pnt3d& P2)
	{
		return P1.Distance(P2);
	}

	inline Standard_Real SquareDistance(const Pnt3d& P1, const Pnt3d& P2)
	{
		return P1.SquareDistance(P2);
	}
}