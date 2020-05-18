#pragma once
#ifndef _FrgBase_Pnt3d_Header
#define _FrgBase_Pnt3d_Header

#include <FrgBase_Global.hxx>
#include <FrgBase_Pnt2d.hxx>

#include <FrgBase_Serialization_Global.hxx>

BeginForgBaseLib

class FORGBASE_EXPORT FrgBase_Pnt3d
	: public FrgBase_Pnt2d
{

public:

	FrgBase_Pnt3d(double x = 0.0, double y = 0.0, double z = 0.0);
	FrgBase_Pnt3d(const FrgBase_Pnt3d& pt);
	FrgBase_Pnt3d& operator=(const FrgBase_Pnt3d& pt);

	const double& Z() const { return theZ_; }
	double& Z() { return theZ_; }

private:

	DECLARE_SAVE_LOAD_HEADER

private:

	double theZ_;
};

EndForgBaseLib

BOOST_CLASS_EXPORT_KEY(ForgBaseLib::FrgBase_Pnt3d)

#endif // !_FrgBase_Pnt3d_Header
