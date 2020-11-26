#pragma once
#ifndef _FrgBase_Pnt_Header
#define _FrgBase_Pnt_Header

#include <FrgBase_Global.hxx>

#include <FrgBase_Serialization_Global.hxx>

BeginForgBaseLib

template <int Dim>
class FORGBASE_EXPORT FrgBase_Pnt
{

public:

	FrgBase_Pnt();

	template <typename = typename std::enable_if_t<Dim == 2>>
	FrgBase_Pnt(double x, double y);

	template <typename = typename std::enable_if_t<Dim == 3>>
	FrgBase_Pnt(double x, double y, double z);

	FrgBase_Pnt(const FrgBase_Pnt& pt);

	FrgBase_Pnt& operator=(const FrgBase_Pnt& pt);

	const double& X() const;
	double& X();

	const double& Y() const;
	double& Y();

	template <typename = typename std::enable_if_t<Dim == 3>>
	const double& Z() const;
	template <typename = typename std::enable_if_t<Dim == 3>>
	double& Z();

	const double& Coord(int i) const;

	FrgBase_Pnt& operator+=(const FrgBase_Pnt& pt);
	FrgBase_Pnt& operator-=(const FrgBase_Pnt& pt);
	FrgBase_Pnt& operator*=(const FrgBase_Pnt& pt);
	FrgBase_Pnt& operator=(double value);
	FrgBase_Pnt& operator+=(double value);
	FrgBase_Pnt& operator-=(double value);
	FrgBase_Pnt& operator*=(double value);
	FrgBase_Pnt& operator/=(double value);
	FrgBase_Pnt& operator+();
	FrgBase_Pnt operator-();

	bool operator==(const FrgBase_Pnt& pt);
	bool operator!=(const FrgBase_Pnt& pt);

	double SquareTwoNorm() const;
	double TwoNorm() const;
	FrgBase_Pnt UnitLength() const;
	double DotProduct(const FrgBase_Pnt& pt) const;
	FrgBase_Pnt<3> CrossProduct(const FrgBase_Pnt& pt) const;

	double SquareDistance(const FrgBase_Pnt& pt) const;
	double Distance(const FrgBase_Pnt& pt) const;

	void Print(std::ostream& os = std::cout) const;

	template <typename = typename std::enable_if_t<Dim == 2>>
	void Translate(double dx, double dy);
	template <typename = typename std::enable_if_t<Dim == 3>>
	void Translate(double dx, double dy, double dz);

private:

	DECLARE_SAVE_LOAD_HEADER( )

private:

	double theCoords_[Dim];
};

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_Pnt<2>)
BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_Pnt<3>)

#include <FrgBase_PntI.hxx>

#endif // !_FrgBase_Pnt_Header
