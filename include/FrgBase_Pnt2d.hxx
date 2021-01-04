#pragma once
#ifndef _FrgBase_Pnt2d_Header
#define _FrgBase_Pnt2d_Header

#include <FrgBase_Global.hxx>

#include <FrgBase_Serialization_Global.hxx>
#include <FrgBase_Pnt.hxx>

BeginForgBaseLib

//class FrgBase_Pnt3d;

class FrgBase_Pnt2d
	: public FrgBase_Pnt<2>
{
	
public:

	FORGBASE_EXPORT FrgBase_Pnt2d(double x = 0.0, double y = 0.0);
	FORGBASE_EXPORT FrgBase_Pnt2d(const FrgBase_Pnt2d& pt);
	/*FrgBase_Pnt2d& operator=(const FrgBase_Pnt2d& pt);

	const double& X() const { return theX_; }
	double& X() { return theX_; }

	const double& Y() const { return theY_; }
	double& Y() { return theY_; }

	FrgBase_Pnt2d& operator+=(const FrgBase_Pnt2d& pt);
	FrgBase_Pnt2d& operator-=(const FrgBase_Pnt2d& pt);
	FrgBase_Pnt2d& operator*=(const FrgBase_Pnt2d& pt);
	FrgBase_Pnt2d& operator=(double value);
	FrgBase_Pnt2d& operator+=(double value);
	FrgBase_Pnt2d& operator-=(double value);
	FrgBase_Pnt2d& operator*=(double value);
	FrgBase_Pnt2d& operator/=(double value);
	FrgBase_Pnt2d& operator+();
	FrgBase_Pnt2d operator-();

	void Rotate90cw();
	void Rotate90ccw();

	double SquareTwoNorm() const;
	double TwoNorm() const;
	FrgBase_Pnt2d UnitLength() const;
	double DotProduct(const FrgBase_Pnt2d& pt) const;
	FrgBase_Pnt3d CrossProduct(const FrgBase_Pnt2d& pt) const;

	double SquareDistance(const FrgBase_Pnt2d& pt) const;
	double Distance(const FrgBase_Pnt2d& pt) const;

	void Print(std::ostream& os = std::cout) const;

	void Translate(double dx, double dy);*/

private:

	DECLARE_SAVE_LOAD_HEADER(FORGBASE_EXPORT)

//protected:
//
//	double theX_;
//	double theY_;
};

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_Pnt2d)

#include <FrgBase_Pnt2dI.hxx>

#endif // !_FrgBase_Pnt2d_Header
