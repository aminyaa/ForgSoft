#pragma once
#ifndef _FrgBase_FrgBase_Pnt2dI_Header
#define _FrgBase_FrgBase_Pnt2dI_Header

//BeginForgBaseLib
//
//inline FrgBase_Pnt2d operator+(const FrgBase_Pnt2d& P1, const FrgBase_Pnt2d& P2)
//{
//	FrgBase_Pnt2d Temp = P1;
//	Temp += P2;
//	return std::move(Temp);
//}
//
//inline FrgBase_Pnt2d operator-(const FrgBase_Pnt2d& P1, const FrgBase_Pnt2d& P2)
//{
//	FrgBase_Pnt2d Temp = P1;
//	Temp -= P2;
//	return std::move(Temp);
//}
//
//inline FrgBase_Pnt2d operator+(const FrgBase_Pnt2d& P1, const double Scalar)
//{
//	FrgBase_Pnt2d Temp = P1;
//	Temp += Scalar;
//	return std::move(Temp);
//}
//
//inline FrgBase_Pnt2d operator+(const double Scalar, const FrgBase_Pnt2d& P1)
//{
//	FrgBase_Pnt2d Temp = P1;
//	Temp += Scalar;
//	return std::move(Temp);
//}
//
//inline FrgBase_Pnt2d operator-(const FrgBase_Pnt2d& P1, const double Scalar)
//{
//	FrgBase_Pnt2d Temp = P1;
//	Temp -= Scalar;
//	return std::move(Temp);
//}
//
//inline FrgBase_Pnt2d operator*(const FrgBase_Pnt2d& P1, const double Scalar)
//{
//	FrgBase_Pnt2d Temp = P1;
//	Temp *= Scalar;
//	return std::move(Temp);
//}
//
//inline FrgBase_Pnt2d operator*(const double Scalar, const FrgBase_Pnt2d& P1)
//{
//	FrgBase_Pnt2d Temp = P1;
//	Temp *= Scalar;
//	return std::move(Temp);
//}
//
//inline FrgBase_Pnt2d operator/(const FrgBase_Pnt2d& P1, const double Scalar)
//{
//	FrgBase_Pnt2d Temp = P1;
//	Temp /= Scalar;
//	return std::move(Temp);
//}
//
//inline double Distance(const FrgBase_Pnt2d& P1, const FrgBase_Pnt2d& P2)
//{
//	return P1.Distance(P2);
//}
//
//inline double SquareDistance(const FrgBase_Pnt2d& P1, const FrgBase_Pnt2d& P2)
//{
//	return P1.SquareDistance(P2);
//}
//
//inline double DotProduct(const FrgBase_Pnt2d& P1, const FrgBase_Pnt2d& P2)
//{
//	return P1.DotProduct(P2);
//}
//
//FrgBase_Pnt3d CrossProduct(const FrgBase_Pnt2d& P1, const FrgBase_Pnt2d& P2);

//std::ostream& operator<<(std::ostream& os, const FrgBase_Pnt2d& P)
//{
//	os << P.X() << ",  " << P.Y();
//	return os;
//}
//std::istream& operator>>(std::istream& is, FrgBase_Pnt2d& P)
//{
//	double x, y;
//	std::string comma;
//
//	is >> x;
//	if (!is.good())
//	{
//		std::exception myException("Error in reading a real parameter");
//
//		throw myException;
//	}
//
//	is >> comma;
//	if (!is.good())
//	{
//		std::exception myException("Error in reading a comma parameter");
//
//		throw myException;
//	}
//
//	is >> y;
//	if (!is.good())
//	{
//		std::exception myException("Error in reading a real parameter");
//
//		throw myException;
//	}
//
//	P.X() = x;
//	P.Y() = y;
//
//	return is;
//}

//EndForgBaseLib

#endif // !_FrgBase_FrgBase_Pnt2dI_Header
