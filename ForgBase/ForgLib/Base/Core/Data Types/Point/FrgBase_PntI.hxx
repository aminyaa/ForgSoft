#pragma once
#ifndef _FrgBase_PntI_Header
#define _FrgBase_PntI_Header

template<int Dim>
template<typename>
inline ForgBaseLib::FrgBase_Pnt<Dim>::FrgBase_Pnt(double x, double y)
{
	theCoords_[0] = x;
	theCoords_[1] = y;
}

template<int Dim>
template<typename>
inline ForgBaseLib::FrgBase_Pnt<Dim>::FrgBase_Pnt(double x, double y, double z)
{
	theCoords_[0] = x;
	theCoords_[1] = y;
	theCoords_[2] = z;
}

template<int Dim>
inline ForgBaseLib::FrgBase_Pnt<Dim> operator+(const ForgBaseLib::FrgBase_Pnt<Dim>& P1, const ForgBaseLib::FrgBase_Pnt<Dim>& P2)
{
	ForgBaseLib::FrgBase_Pnt<Dim> Temp = P1;
	Temp += P2;
	return std::move(Temp);
}

template<int Dim>
inline ForgBaseLib::FrgBase_Pnt<Dim> operator-(const ForgBaseLib::FrgBase_Pnt<Dim>& P1, const ForgBaseLib::FrgBase_Pnt<Dim>& P2)
{
	ForgBaseLib::FrgBase_Pnt<Dim> Temp = P1;
	Temp -= P2;
	return std::move(Temp);
}

template<int Dim>
inline ForgBaseLib::FrgBase_Pnt<Dim> operator+(const ForgBaseLib::FrgBase_Pnt<Dim>& P1, const double Scalar)
{
	ForgBaseLib::FrgBase_Pnt<Dim> Temp = P1;
	Temp += Scalar;
	return std::move(Temp);
}

template<int Dim>
inline ForgBaseLib::FrgBase_Pnt<Dim> operator+(const double Scalar, const ForgBaseLib::FrgBase_Pnt<Dim>& P1)
{
	ForgBaseLib::FrgBase_Pnt<Dim> Temp = P1;
	Temp += Scalar;
	return std::move(Temp);
}

template<int Dim>
inline ForgBaseLib::FrgBase_Pnt<Dim> operator-(const ForgBaseLib::FrgBase_Pnt<Dim>& P1, const double Scalar)
{
	ForgBaseLib::FrgBase_Pnt<Dim> Temp = P1;
	Temp -= Scalar;
	return std::move(Temp);
}

template<int Dim>
inline ForgBaseLib::FrgBase_Pnt<Dim> operator*(const ForgBaseLib::FrgBase_Pnt<Dim>& P1, const double Scalar)
{
	ForgBaseLib::FrgBase_Pnt<Dim> Temp = P1;
	Temp *= Scalar;
	return std::move(Temp);
}

template<int Dim>
inline ForgBaseLib::FrgBase_Pnt<Dim> operator*(const double Scalar, const ForgBaseLib::FrgBase_Pnt<Dim>& P1)
{
	ForgBaseLib::FrgBase_Pnt<Dim> Temp = P1;
	Temp *= Scalar;
	return std::move(Temp);
}

template<int Dim>
inline ForgBaseLib::FrgBase_Pnt<Dim> operator/(const ForgBaseLib::FrgBase_Pnt<Dim>& P1, const double Scalar)
{
	ForgBaseLib::FrgBase_Pnt<Dim> Temp = P1;
	Temp /= Scalar;
	return std::move(Temp);
}

template<int Dim>
inline double Distance(const ForgBaseLib::FrgBase_Pnt<Dim>& P1, const ForgBaseLib::FrgBase_Pnt<Dim>& P2)
{
	return P1.Distance(P2);
}

template<int Dim>
inline double SquareDistance(const ForgBaseLib::FrgBase_Pnt<Dim>& P1, const ForgBaseLib::FrgBase_Pnt<Dim>& P2)
{
	return P1.SquareDistance(P2);
}

template<int Dim>
inline double DotProduct(const ForgBaseLib::FrgBase_Pnt<Dim>& P1, const ForgBaseLib::FrgBase_Pnt<Dim>& P2)
{
	return P1.DotProduct(P2);
}

template<int Dim>
ForgBaseLib::FrgBase_Pnt<3> CrossProduct(const ForgBaseLib::FrgBase_Pnt<Dim>& P1, const ForgBaseLib::FrgBase_Pnt<Dim>& P2)
{
	return P1.CrossProduct(P2);
}

#endif // !_FrgBase_PntI_Header
