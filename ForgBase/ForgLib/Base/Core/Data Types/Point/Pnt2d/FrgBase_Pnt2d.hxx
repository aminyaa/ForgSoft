#pragma once
#ifndef _FrgBase_Pnt2d_Header
#define _FrgBase_Pnt2d_Header

#include <FrgBase_Global.hxx>

#include <FrgBase_Serialization_Global.hxx>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_Pnt2d
{
	
public:

	FrgBase_Pnt2d(double x = 0.0, double y = 0.0);
	FrgBase_Pnt2d(const FrgBase_Pnt2d& pt);
	FrgBase_Pnt2d& operator=(const FrgBase_Pnt2d& pt);

	const double& X() const { return theX_; }
	double& X() { return theX_; }

	const double& Y() const { return theY_; }
	double& Y() { return theY_; }

private:

	DECLARE_SAVE_LOAD_HEADER

private:

	double theX_;
	double theY_;
};

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_Pnt2d)

#endif // !_FrgBase_Pnt2d_Header
