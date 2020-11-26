#pragma once
#ifndef _FrgBase_Pnt3d_Header
#define _FrgBase_Pnt3d_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Pnt.hxx>

#include <FrgBase_Serialization_Global.hxx>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_Pnt3d
	: public FrgBase_Pnt<3>
{

public:

	FrgBase_Pnt3d(double x = 0.0, double y = 0.0, double z = 0.0);
	FrgBase_Pnt3d(const FrgBase_Pnt3d& pt);
	/*FrgBase_Pnt3d& operator=(const FrgBase_Pnt3d& pt);

	const double& Z() const { return theZ_; }
	double& Z() { return theZ_; }

	FrgBase_Pnt3d& operator+=(const FrgBase_Pnt3d& pt);
	FrgBase_Pnt3d& operator-=(const FrgBase_Pnt3d& pt);
	FrgBase_Pnt3d& operator*=(const FrgBase_Pnt3d& pt);
	FrgBase_Pnt3d& operator=(double value);
	FrgBase_Pnt3d& operator+=(double value);
	FrgBase_Pnt3d& operator-=(double value);
	FrgBase_Pnt3d& operator*=(double value);
	FrgBase_Pnt3d& operator/=(double value);
	FrgBase_Pnt3d& operator+();
	FrgBase_Pnt3d operator-();

	double SquareTwoNorm() const;
	double TwoNorm() const;
	FrgBase_Pnt3d UnitLength() const;
	double DotProduct(const FrgBase_Pnt3d& pt) const;
	FrgBase_Pnt3d CrossProduct(const FrgBase_Pnt3d& pt) const;

	double SquareDistance(const FrgBase_Pnt3d& pt) const;
	double Distance(const FrgBase_Pnt3d& pt) const;

	void Print(std::ostream& os = std::cout) const;

	void Translate(double dx, double dy, double dz);*/

private:

	DECLARE_SAVE_LOAD_HEADER( )

//protected:
//
//	double theZ_;
};

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_Pnt3d)

#include <FrgBase_Pnt3dI.hxx>

#endif // !_FrgBase_Pnt3d_Header
