#include <FrgBase_Pnt2d.hxx>

ForgBaseLib::FrgBase_Pnt2d::FrgBase_Pnt2d(double x, double y)
	: theX_(x)
	, theY_(y)
{

}

ForgBaseLib::FrgBase_Pnt2d::FrgBase_Pnt2d(const FrgBase_Pnt2d & pt)
{
	FrgBase_Pnt2d(pt.X(), pt.Y());
}

ForgBaseLib::FrgBase_Pnt2d & ForgBaseLib::FrgBase_Pnt2d::operator=(const FrgBase_Pnt2d & pt)
{
	return FrgBase_Pnt2d(pt.X(), pt.Y());
}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_Pnt2d)
{
	ar << theX_;
	ar << theY_;
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_Pnt2d)
{
	ar & theX_;
	ar & theY_;
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_Pnt2d)