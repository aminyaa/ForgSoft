#include <FrgBase_Pnt.hxx>

template<int Dim>
ForgBaseLib::FrgBase_Pnt<Dim>::FrgBase_Pnt()
{
	for (int i = 0; i < Dim; i++)
		theCoords_[i] = 0.0;
}

template<int Dim>
ForgBaseLib::FrgBase_Pnt<Dim>::FrgBase_Pnt(const FrgBase_Pnt& pt)
{
	for (int i = 0; i < Dim; i++)
		theCoords_[i] = pt.Coord(i);
}

template<int Dim>
const double& ForgBaseLib::FrgBase_Pnt<Dim>::Coord(int i) const
{
	if constexpr (Dim > 3)
	{
		std::exception myException("Dimension is grater than the 3.");
		throw myException;
	}

	return theCoords_[i];
}

template<int Dim>
ForgBaseLib::FrgBase_Pnt<Dim>& ForgBaseLib::FrgBase_Pnt<Dim>::operator=(const FrgBase_Pnt& pt)
{
	if constexpr (Dim == 2)
	{
		X() = pt.X();
		Y() = pt.Y();
	}
	else if constexpr (Dim == 3)
	{
		X() = pt.X();
		Y() = pt.Y();
		Z() = pt.Z();
	}

	return *this;
}

template<int Dim>
const double& ForgBaseLib::FrgBase_Pnt<Dim>::X() const
{
	return theCoords_[0];
}

template<int Dim>
double& ForgBaseLib::FrgBase_Pnt<Dim>::X()
{
	return theCoords_[0];
}

template<int Dim>
const double& ForgBaseLib::FrgBase_Pnt<Dim>::Y() const
{
	return theCoords_[1];
}

template<int Dim>
double& ForgBaseLib::FrgBase_Pnt<Dim>::Y()
{
	return theCoords_[1];
}

template<>
template<>
const double& ForgBaseLib::FrgBase_Pnt<3>::Z() const
{
	return theCoords_[2];
}

template<>
template<>
double& ForgBaseLib::FrgBase_Pnt<3>::Z()
{
	return theCoords_[2];
}

template<int Dim>
ForgBaseLib::FrgBase_Pnt<Dim>& ForgBaseLib::FrgBase_Pnt<Dim>::operator+=(const FrgBase_Pnt& pt)
{
	if constexpr (Dim == 2)
	{
		theCoords_[0] += pt.X();
		theCoords_[1] += pt.Y();
	}
	else if constexpr (Dim == 3)
	{
		theCoords_[0] += pt.X();
		theCoords_[1] += pt.Y();
		theCoords_[2] += pt.Z();
	}

	return *this;
}

template<int Dim>
ForgBaseLib::FrgBase_Pnt<Dim>& ForgBaseLib::FrgBase_Pnt<Dim>::operator-=(const FrgBase_Pnt& pt)
{
	if constexpr (Dim == 2)
	{
		theCoords_[0] -= pt.X();
		theCoords_[1] -= pt.Y();
	}
	else if constexpr (Dim == 3)
	{
		theCoords_[0] -= pt.X();
		theCoords_[1] -= pt.Y();
		theCoords_[2] -= pt.Z();
	}

	return *this;
}

template<int Dim>
ForgBaseLib::FrgBase_Pnt<Dim>& ForgBaseLib::FrgBase_Pnt<Dim>::operator*=(const FrgBase_Pnt& pt)
{
	if constexpr (Dim == 2)
	{
		theCoords_[0] *= pt.X();
		theCoords_[1] *= pt.Y();
	}
	else if constexpr (Dim == 3)
	{
		theCoords_[0] *= pt.X();
		theCoords_[1] *= pt.Y();
		theCoords_[2] *= pt.Z();
	}

	return *this;
}

template<int Dim>
ForgBaseLib::FrgBase_Pnt<Dim>& ForgBaseLib::FrgBase_Pnt<Dim>::operator=(double value)
{
	if constexpr (Dim == 2)
	{
		theCoords_[0] = value;
		theCoords_[1] = value;
	}
	else if constexpr (Dim == 3)
	{
		theCoords_[0] = value;
		theCoords_[1] = value;
		theCoords_[2] = value;
	}

	return *this;
}

template<int Dim>
ForgBaseLib::FrgBase_Pnt<Dim>& ForgBaseLib::FrgBase_Pnt<Dim>::operator+=(double value)
{
	if constexpr (Dim == 2)
	{
		theCoords_[0] += value;
		theCoords_[1] += value;
	}
	else if constexpr (Dim == 3)
	{
		theCoords_[0] += value;
		theCoords_[1] += value;
		theCoords_[2] += value;
	}

	return *this;
}

template<int Dim>
ForgBaseLib::FrgBase_Pnt<Dim>& ForgBaseLib::FrgBase_Pnt<Dim>::operator-=(double value)
{
	if constexpr (Dim == 2)
	{
		theCoords_[0] -= value;
		theCoords_[1] -= value;
	}
	else if constexpr (Dim == 3)
	{
		theCoords_[0] -= value;
		theCoords_[1] -= value;
		theCoords_[2] -= value;
	}

	return *this;
}

template<int Dim>
ForgBaseLib::FrgBase_Pnt<Dim>& ForgBaseLib::FrgBase_Pnt<Dim>::operator*=(double value)
{
	if constexpr (Dim == 2)
	{
		theCoords_[0] *= value;
		theCoords_[1] *= value;
	}
	else if constexpr (Dim == 3)
	{
		theCoords_[0] *= value;
		theCoords_[1] *= value;
		theCoords_[2] *= value;
	}

	return *this;
}

template<int Dim>
ForgBaseLib::FrgBase_Pnt<Dim>& ForgBaseLib::FrgBase_Pnt<Dim>::operator/=(double value)
{
	if constexpr (Dim == 2)
	{
		theCoords_[0] /= value;
		theCoords_[1] /= value;
	}
	else if constexpr (Dim == 3)
	{
		theCoords_[0] /= value;
		theCoords_[1] /= value;
		theCoords_[2] /= value;
	}

	return *this;
}

template<int Dim>
ForgBaseLib::FrgBase_Pnt<Dim>& ForgBaseLib::FrgBase_Pnt<Dim>::operator+()
{
	return *this;
}

template<int Dim>
ForgBaseLib::FrgBase_Pnt<Dim> ForgBaseLib::FrgBase_Pnt<Dim>::operator-()
{
	if constexpr (Dim == 2)
		return FrgBase_Pnt<Dim>(-X(), -Y());
	else if constexpr (Dim == 3)
		return FrgBase_Pnt<Dim>(-X(), -Y(), -Z());
}

template<int Dim>
bool ForgBaseLib::FrgBase_Pnt<Dim>::IsEqual(const FrgBase_Pnt& pt) const
{
	for (int i = 0; i < Dim; i++)
	{
		if (Coord(i) != pt.Coord(i))
			return false;
	}

	return true;
}

template<int Dim>
bool ForgBaseLib::FrgBase_Pnt<Dim>::operator==(const FrgBase_Pnt& pt)
{
	return IsEqual(pt);
}

template<int Dim>
bool ForgBaseLib::FrgBase_Pnt<Dim>::operator!=(const FrgBase_Pnt& pt)
{
	return !(*this == pt);
}

template<int Dim>
double ForgBaseLib::FrgBase_Pnt<Dim>::SquareTwoNorm() const
{
	if constexpr (Dim == 2)
		return X() * X() + Y() * Y();
	else if constexpr (Dim == 3)
		return X() * X() + Y() * Y() + Z() * Z();
}

template<int Dim>
double ForgBaseLib::FrgBase_Pnt<Dim>::TwoNorm() const
{
	return std::sqrt(SquareTwoNorm());
}

template<int Dim>
ForgBaseLib::FrgBase_Pnt<Dim> ForgBaseLib::FrgBase_Pnt<Dim>::UnitLength() const
{
	double S = 1.0 / TwoNorm();

	if constexpr (Dim == 2)
		return FrgBase_Pnt<2>(X() * S, Y() * S);
	else if constexpr (Dim == 3)
		return FrgBase_Pnt<3>(X() * S, Y() * S, Z() * S);
}

template<int Dim>
double ForgBaseLib::FrgBase_Pnt<Dim>::DotProduct(const FrgBase_Pnt& pt) const
{
	if constexpr (Dim == 2)
		return X() * pt.X() + Y() * pt.Y();
	else if constexpr (Dim == 3)
		return X() * pt.X() + Y() * pt.Y() + Z() * pt.Z();
}

template<int Dim>
ForgBaseLib::FrgBase_Pnt<3> ForgBaseLib::FrgBase_Pnt<Dim>::CrossProduct(const FrgBase_Pnt& pt) const
{
	if constexpr (Dim == 2)
		return FrgBase_Pnt<3>(0.0, 0.0, (X() * pt.Y(), pt.X() * Y()));
	else if constexpr (Dim == 3)
	{
		double x = Y() * pt.Z() - pt.Y() * Z();
		double y = -(X() * pt.Z() - pt.X() * Z());
		double z = X() * pt.Y() - pt.X() * Y();
		return FrgBase_Pnt<3>(x, y, z);
	}
}

template<int Dim>
double ForgBaseLib::FrgBase_Pnt<Dim>::SquareDistance(const FrgBase_Pnt& pt) const
{
	if constexpr (Dim == 2)
		return std::pow(pt.X() - X(), 2.0) + std::pow(pt.Y() - Y(), 2.0);
	else if constexpr (Dim == 3)
		return std::pow(pt.X() - X(), 2.0) + std::pow(pt.Y() - Y(), 2.0) + std::pow(pt.Z() - Z(), 2.0);
}

template<int Dim>
double ForgBaseLib::FrgBase_Pnt<Dim>::Distance(const FrgBase_Pnt& pt) const
{
	return std::sqrt(SquareDistance(pt));
}

template<int Dim>
void ForgBaseLib::FrgBase_Pnt<Dim>::Print(std::ostream& os) const
{
	if constexpr (Dim == 2)
		std::cout << theCoords_[0] << ", " << theCoords_[1] << std::endl;
	else if constexpr (Dim == 3)
		std::cout << theCoords_[0] << ", " << theCoords_[1] << ", " << theCoords_[2] << std::endl;
}

template<int Dim>
template<typename>
void ForgBaseLib::FrgBase_Pnt<Dim>::Translate(double dx, double dy)
{
	theCoords_[0] += dx;
	theCoords_[1] += dy;
}

template<int Dim>
template<typename>
void ForgBaseLib::FrgBase_Pnt<Dim>::Translate(double dx, double dy, double dz)
{
	theCoords_[0] += dx;
	theCoords_[1] += dy;
	theCoords_[2] += dz;
}

template<int Dim>
DECLARE_SAVE_IMP(ForgBaseLib::FrgBase_Pnt<Dim>)
{
	ar& boost::serialization::base_object<FrgBase_Object>(*this);

	ar& theCoords_;
}

template<int Dim>
DECLARE_LOAD_IMP(ForgBaseLib::FrgBase_Pnt<Dim>)
{
	ar& boost::serialization::base_object<FrgBase_Object>(*this);

	ar& theCoords_;
}

BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_Pnt<2>)
BOOST_CLASS_EXPORT_CXX(ForgBaseLib::FrgBase_Pnt<3>)

template FORGBASE_EXPORT class ForgBaseLib::FrgBase_Pnt<2>;
template FORGBASE_EXPORT class ForgBaseLib::FrgBase_Pnt<3>;

template FORGBASE_EXPORT ForgBaseLib::FrgBase_Pnt<2>::FrgBase_Pnt(double x, double y);
template FORGBASE_EXPORT ForgBaseLib::FrgBase_Pnt<3>::FrgBase_Pnt(double x, double y, double z);

template FORGBASE_EXPORT void ForgBaseLib::FrgBase_Pnt<2>::Translate(double dx, double dy);
template FORGBASE_EXPORT void ForgBaseLib::FrgBase_Pnt<3>::Translate(double dx, double dy, double z);

template FORGBASE_EXPORT const double& ForgBaseLib::FrgBase_Pnt<3>::Z() const;
template FORGBASE_EXPORT double& ForgBaseLib::FrgBase_Pnt<3>::Z();