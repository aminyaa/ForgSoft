#include <FrgBase_Pnt2d.hxx>

ForgBaseLib::FrgBase_Pnt2d::FrgBase_Pnt2d(double x, double y)
	: FrgBase_Pnt<2>(x, y)
{

}

ForgBaseLib::FrgBase_Pnt2d::FrgBase_Pnt2d(const FrgBase_Pnt2d & pt)
	: FrgBase_Pnt2d(pt.X(), pt.Y())
{
	//FrgBase_Pnt2d(pt.X(), pt.Y());
}

//ForgBaseLib::FrgBase_Pnt2d & ForgBaseLib::FrgBase_Pnt2d::operator=(const FrgBase_Pnt2d & pt)
//{
//	return std::move(FrgBase_Pnt2d(pt.X(), pt.Y()));
//}
//
//ForgBaseLib::FrgBase_Pnt2d& ForgBaseLib::FrgBase_Pnt2d::operator+=(const FrgBase_Pnt2d& pt)
//{
//	theX_ += pt.X();
//	theY_ += pt.Y();
//
//	return *this;
//}
//
//ForgBaseLib::FrgBase_Pnt2d& ForgBaseLib::FrgBase_Pnt2d::operator-=(const FrgBase_Pnt2d& pt)
//{
//	theX_ -= pt.X();
//	theY_ -= pt.Y();
//
//	return *this;
//}
//
//ForgBaseLib::FrgBase_Pnt2d& ForgBaseLib::FrgBase_Pnt2d::operator*=(const FrgBase_Pnt2d& pt)
//{
//	theX_ *= pt.X();
//	theY_ *= pt.Y();
//
//	return *this;
//}
//
//ForgBaseLib::FrgBase_Pnt2d& ForgBaseLib::FrgBase_Pnt2d::operator=(double value)
//{
//	theX_ = value;
//	theY_ = value;
//
//	return *this;
//}
//
//ForgBaseLib::FrgBase_Pnt2d& ForgBaseLib::FrgBase_Pnt2d::operator+=(double value)
//{
//	theX_ += value;
//	theY_ += value;
//
//	return *this;
//}
//
//ForgBaseLib::FrgBase_Pnt2d& ForgBaseLib::FrgBase_Pnt2d::operator-=(double value)
//{
//	theX_ -= value;
//	theY_ -= value;
//
//	return *this;
//}
//
//ForgBaseLib::FrgBase_Pnt2d& ForgBaseLib::FrgBase_Pnt2d::operator*=(double value)
//{
//	theX_ *= value;
//	theY_ *= value;
//
//	return *this;
//}
//
//ForgBaseLib::FrgBase_Pnt2d& ForgBaseLib::FrgBase_Pnt2d::operator/=(double value)
//{
//	theX_ /= value;
//	theY_ /= value;
//
//	return *this;
//}
//
//ForgBaseLib::FrgBase_Pnt2d& ForgBaseLib::FrgBase_Pnt2d::operator+()
//{
//	return *this;
//}
//
//ForgBaseLib::FrgBase_Pnt2d ForgBaseLib::FrgBase_Pnt2d::operator-()
//{
//	return FrgBase_Pnt2d() - (*this);
//}
//
//void ForgBaseLib::FrgBase_Pnt2d::Rotate90cw()
//{
//	double Temp = Y();
//	Y() = -X();
//	X() = Temp;
//}
//
//void ForgBaseLib::FrgBase_Pnt2d::Rotate90ccw()
//{
//	double Temp = X();
//	X() = -Y();
//	Y() = Temp;
//}
//
//double ForgBaseLib::FrgBase_Pnt2d::SquareTwoNorm() const
//{
//	return X() * X() + Y() * Y();
//}
//
//double ForgBaseLib::FrgBase_Pnt2d::TwoNorm() const
//{
//	return std::sqrt(SquareTwoNorm());
//}
//
//ForgBaseLib::FrgBase_Pnt2d ForgBaseLib::FrgBase_Pnt2d::UnitLength() const
//{
//	double S = 1.0 / TwoNorm();
//
//	return FrgBase_Pnt2d(X() * S, Y() * S);
//}
//
//double ForgBaseLib::FrgBase_Pnt2d::DotProduct(const FrgBase_Pnt2d& pt) const
//{
//	return X() * pt.X() + Y() * pt.Y();
//}
//
//ForgBaseLib::FrgBase_Pnt3d ForgBaseLib::FrgBase_Pnt2d::CrossProduct(const FrgBase_Pnt2d& pt) const
//{
//	return FrgBase_Pnt3d(0.0, 0.0, (X() * pt.Y(), pt.X() * Y()));
//}
//
//double ForgBaseLib::FrgBase_Pnt2d::SquareDistance(const FrgBase_Pnt2d& pt) const
//{
//	return std::pow(pt.X() - X(), 2.0) + std::pow(pt.Y() - Y(), 2.0);
//}
//
//double ForgBaseLib::FrgBase_Pnt2d::Distance(const FrgBase_Pnt2d& pt) const
//{
//	return std::sqrt(SquareDistance(pt));
//}
//
//ForgBaseLib::FrgBase_Pnt3d CrossProduct(const ForgBaseLib::FrgBase_Pnt2d& P1, const ForgBaseLib::FrgBase_Pnt2d& P2)
//{
//	return P1.CrossProduct(P2);
//}
//
//void ForgBaseLib::FrgBase_Pnt2d::Print(std::ostream& os) const
//{
//	/*os << *this;*/
//}
//
//void ForgBaseLib::FrgBase_Pnt2d::Translate(double dx, double dy)
//{
//	theX_ += dx;
//	theY_ += dy;
//}

DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_Pnt2d)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_Pnt<2>>(*this);
	/*ar & theX_;
	ar & theY_;*/
}

DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_Pnt2d)
{
	ar& boost::serialization::base_object<ForgBaseLib::FrgBase_Pnt<2>>(*this);
	/*ar & theX_;
	ar & theY_;*/
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_Pnt2d)