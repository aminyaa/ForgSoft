#include <FrgBase_Pnt3d.hxx>

ForgBaseLib::FrgBase_Pnt3d::FrgBase_Pnt3d(double x, double y, double z)
	: FrgBase_Pnt<3>(x, y, z)
{

}

ForgBaseLib::FrgBase_Pnt3d::FrgBase_Pnt3d(const FrgBase_Pnt3d & pt)
	: FrgBase_Pnt3d(pt.X(), pt.Y(), pt.Z())
{
	//FrgBase_Pnt3d(pt.X(), pt.Y(), pt.Z());
}

//ForgBaseLib::FrgBase_Pnt3d & ForgBaseLib::FrgBase_Pnt3d::operator=(const FrgBase_Pnt3d & pt)
//{
//	return std::move(FrgBase_Pnt3d(pt.X(), pt.Y(), pt.Z()));
//}
//
//ForgBaseLib::FrgBase_Pnt3d& ForgBaseLib::FrgBase_Pnt3d::operator+=(const FrgBase_Pnt3d& pt)
//{
//	theX_ += pt.X();
//	theY_ += pt.Y();
//	theZ_ += pt.Z();
//
//	return *this;
//}
//
//ForgBaseLib::FrgBase_Pnt3d& ForgBaseLib::FrgBase_Pnt3d::operator-=(const FrgBase_Pnt3d& pt)
//{
//	theX_ -= pt.X();
//	theY_ -= pt.Y();
//	theZ_ -= pt.Z();
//
//	return *this;
//}
//
//ForgBaseLib::FrgBase_Pnt3d& ForgBaseLib::FrgBase_Pnt3d::operator*=(const FrgBase_Pnt3d& pt)
//{
//	theX_ *= pt.X();
//	theY_ *= pt.Y();
//	theZ_ *= pt.Z();
//
//	return *this;
//}
//
//ForgBaseLib::FrgBase_Pnt3d& ForgBaseLib::FrgBase_Pnt3d::operator=(double value)
//{
//	theX_ = value;
//	theY_ = value;
//	theZ_ = value;
//
//	return *this;
//}
//
//ForgBaseLib::FrgBase_Pnt3d& ForgBaseLib::FrgBase_Pnt3d::operator+=(double value)
//{
//	theX_ += value;
//	theY_ += value;
//	theZ_ += value;
//
//	return *this;
//}
//
//ForgBaseLib::FrgBase_Pnt3d& ForgBaseLib::FrgBase_Pnt3d::operator-=(double value)
//{
//	theX_ -= value;
//	theY_ -= value;
//	theZ_ -= value;
//
//	return *this;
//}
//
//ForgBaseLib::FrgBase_Pnt3d& ForgBaseLib::FrgBase_Pnt3d::operator*=(double value)
//{
//	theX_ *= value;
//	theY_ *= value;
//	theZ_ *= value;
//
//	return *this;
//}
//
//ForgBaseLib::FrgBase_Pnt3d& ForgBaseLib::FrgBase_Pnt3d::operator/=(double value)
//{
//	theX_ /= value;
//	theY_ /= value;
//	theZ_ /= value;
//
//	return *this;
//}
//
//ForgBaseLib::FrgBase_Pnt3d& ForgBaseLib::FrgBase_Pnt3d::operator+()
//{
//	return *this;
//}
//
//ForgBaseLib::FrgBase_Pnt3d ForgBaseLib::FrgBase_Pnt3d::operator-()
//{
//	return FrgBase_Pnt3d() - (*this);
//}
//
//double ForgBaseLib::FrgBase_Pnt3d::SquareTwoNorm() const
//{
//	return X() * X() + Y() * Y() + Z() * Z();
//}
//
//double ForgBaseLib::FrgBase_Pnt3d::TwoNorm() const
//{
//	return std::sqrt(SquareTwoNorm());
//}
//
//ForgBaseLib::FrgBase_Pnt3d ForgBaseLib::FrgBase_Pnt3d::UnitLength() const
//{
//	double S = 1.0 / TwoNorm();
//
//	return FrgBase_Pnt3d(X() * S, Y() * S, Z() * S);
//}
//
//double ForgBaseLib::FrgBase_Pnt3d::DotProduct(const FrgBase_Pnt3d& pt) const
//{
//	return X() * pt.X() + Y() * pt.Y() + Z() * pt.Z();
//}
//
//ForgBaseLib::FrgBase_Pnt3d ForgBaseLib::FrgBase_Pnt3d::CrossProduct(const FrgBase_Pnt3d& pt) const
//{
//	double x = Y() * pt.Z() - pt.Y() * Z();
//	double y = -(X() * pt.Z() - pt.X() * Z());
//	double z = X() * pt.Y() - pt.X() * Y();
//	return FrgBase_Pnt3d(x, y, z);
//}
//
//double ForgBaseLib::FrgBase_Pnt3d::SquareDistance(const FrgBase_Pnt3d& pt) const
//{
//	return std::pow(pt.X() - X(), 2.0) + std::pow(pt.Y() - Y(), 2.0) + std::pow(pt.Z() - Z(), 2.0);
//}
//
//double ForgBaseLib::FrgBase_Pnt3d::Distance(const FrgBase_Pnt3d& pt) const
//{
//	return std::sqrt(SquareDistance(pt));
//}
//
//void ForgBaseLib::FrgBase_Pnt3d::Print(std::ostream& os) const
//{
//	//os << *this;
//}
//
//void ForgBaseLib::FrgBase_Pnt3d::Translate(double dx, double dy, double dz)
//{
//	theX_ += dx;
//	theY_ += dy;
//	theZ_ += dz;
//}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_Pnt3d)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_Pnt<3>>(*this);
	/*ar & boost::serialization::base_object<ForgBaseLib::FrgBase_Pnt2d>(*this);

	ar& theZ_;*/
	//ar & BOOST_SERIALIZATION_NVP(theZ_);
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_Pnt3d)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_Pnt<3>>(*this);
	/*ar & boost::serialization::base_object<ForgBaseLib::FrgBase_Pnt2d>(*this);

	ar& theZ_;*/
	//ar & BOOST_SERIALIZATION_NVP(theZ_);
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_Pnt3d)