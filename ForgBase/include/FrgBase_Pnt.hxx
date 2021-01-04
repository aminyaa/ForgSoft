#pragma once
#ifndef _FrgBase_Pnt_Header
#define _FrgBase_Pnt_Header

#include <FrgBase_Global.hxx>

#include <FrgBase_Serialization_Global.hxx>

BeginForgBaseLib

template <int Dim>
class FrgBase_Pnt
{

public:

	FORGBASE_EXPORT FrgBase_Pnt();

	template <typename = typename std::enable_if_t<Dim == 2>>
	FrgBase_Pnt(double x, double y);

	template <typename = typename std::enable_if_t<Dim == 3>>
	FrgBase_Pnt(double x, double y, double z);

	FORGBASE_EXPORT FrgBase_Pnt(const FrgBase_Pnt& pt);

	FORGBASE_EXPORT FrgBase_Pnt& operator=(const FrgBase_Pnt& pt);

	FORGBASE_EXPORT const double& X() const;
	FORGBASE_EXPORT double& X();

	FORGBASE_EXPORT const double& Y() const;
	FORGBASE_EXPORT double& Y();

	template <typename = typename std::enable_if_t<Dim == 3>>
	FORGBASE_EXPORT const double& Z() const;
	template <typename = typename std::enable_if_t<Dim == 3>>
	FORGBASE_EXPORT double& Z();

	FORGBASE_EXPORT const double& Coord(int i) const;

	FORGBASE_EXPORT FrgBase_Pnt& operator+=(const FrgBase_Pnt& pt);
	FORGBASE_EXPORT FrgBase_Pnt& operator-=(const FrgBase_Pnt& pt);
	FORGBASE_EXPORT FrgBase_Pnt& operator*=(const FrgBase_Pnt& pt);
	FORGBASE_EXPORT FrgBase_Pnt& operator=(double value);
	FORGBASE_EXPORT FrgBase_Pnt& operator+=(double value);
	FORGBASE_EXPORT FrgBase_Pnt& operator-=(double value);
	FORGBASE_EXPORT FrgBase_Pnt& operator*=(double value);
	FORGBASE_EXPORT FrgBase_Pnt& operator/=(double value);
	FORGBASE_EXPORT FrgBase_Pnt& operator+();
	FORGBASE_EXPORT FrgBase_Pnt operator-();

	FORGBASE_EXPORT bool operator==(const FrgBase_Pnt& pt);
	FORGBASE_EXPORT bool operator!=(const FrgBase_Pnt& pt);

	FORGBASE_EXPORT double SquareTwoNorm() const;
	FORGBASE_EXPORT double TwoNorm() const;
	FORGBASE_EXPORT FrgBase_Pnt UnitLength() const;
	double DotProduct(const FrgBase_Pnt& pt) const;
	FrgBase_Pnt<3> CrossProduct(const FrgBase_Pnt& pt) const;

	double SquareDistance(const FrgBase_Pnt& pt) const;
	FORGBASE_EXPORT double Distance(const FrgBase_Pnt& pt) const;

	FORGBASE_EXPORT void Print(std::ostream& os = std::cout) const;

	template <typename = typename std::enable_if_t<Dim == 2>>
	FORGBASE_EXPORT void Translate(double dx, double dy);
	template <typename = typename std::enable_if_t<Dim == 3>>
	FORGBASE_EXPORT void Translate(double dx, double dy, double dz);

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

private:

	double theCoords_[Dim];
};

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_Pnt<2>)
BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_Pnt<3>)

#include <FrgBase_PntI.hxx>

#endif // !_FrgBase_Pnt_Header
