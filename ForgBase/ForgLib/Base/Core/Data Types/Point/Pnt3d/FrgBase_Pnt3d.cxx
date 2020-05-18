#include <FrgBase_Pnt3d.hxx>

ForgBaseLib::FrgBase_Pnt3d::FrgBase_Pnt3d(double x, double y, double z)
	: FrgBase_Pnt2d(x, y)
	, theZ_(z)
{

}

ForgBaseLib::FrgBase_Pnt3d::FrgBase_Pnt3d(const FrgBase_Pnt3d & pt)
{
	FrgBase_Pnt3d(pt.X(), pt.Y(), pt.Z());
}

ForgBaseLib::FrgBase_Pnt3d & ForgBaseLib::FrgBase_Pnt3d::operator=(const FrgBase_Pnt3d & pt)
{
	return FrgBase_Pnt3d(pt.X(), pt.Y(), pt.Z());
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_Pnt3d)
{
	ar & boost::serialization::base_object<ForgBaseLib::FrgBase_Pnt2d>(*this);
	//ar & BOOST_SERIALIZATION_NVP(theZ_);
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_Pnt3d)
{
	ar & boost::serialization::base_object<ForgBaseLib::FrgBase_Pnt2d>(*this);
	//ar & BOOST_SERIALIZATION_NVP(theZ_);
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_Pnt3d)