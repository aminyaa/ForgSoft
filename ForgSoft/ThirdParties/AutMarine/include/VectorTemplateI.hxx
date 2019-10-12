#pragma once
template<class Cmpt>
inline AutLib::Vector<Cmpt>::Vector()
{}

template<class Cmpt>
inline AutLib::Vector<Cmpt>::Vector(const VectorSpace<Vector<Cmpt>, Cmpt, 3>& vs)
	: VectorSpace<Vector<Cmpt>, Cmpt, 3>(vs)
{}

template<class Cmpt>
inline AutLib::Vector<Cmpt>::Vector(const Cmpt & vx, const Cmpt & vy, const Cmpt & vz)
{
	this->v_[X] = vx;
	this->v_[Y] = vy;
	this->v_[Z] = vz;
}

template<class Cmpt>
inline AutLib::Vector<Cmpt>::Vector(Istream & is)
	: VectorSpace<Vector<Cmpt>, Cmpt, 3>(is)
{}

template<class Cmpt>
inline const Cmpt & AutLib::Vector<Cmpt>::x() const
{
	return this->v_[X];
}

template<class Cmpt>
inline const Cmpt & AutLib::Vector<Cmpt>::y() const
{
	return this->v_[Y];
}

template<class Cmpt>
inline const Cmpt & AutLib::Vector<Cmpt>::z() const
{
	return this->v_[Z];
}

template<class Cmpt>
inline Cmpt & AutLib::Vector<Cmpt>::x()
{
	return this->v_[X];
}

template<class Cmpt>
inline Cmpt & AutLib::Vector<Cmpt>::y()
{
	return this->v_[Y];
}

template<class Cmpt>
inline Cmpt & AutLib::Vector<Cmpt>::z()
{
	return this->v_[Z];
}

namespace AutLib
{
	template<class Cmpt>
	inline const Cmpt &Vector<Cmpt>::operator()(const direction i) const
	{
		return this->operator[](i);
	}

	template<class Cmpt>
	inline Cmpt & Vector<Cmpt>::operator()(const direction i)
	{
		return this->operator[](i);
	}
}

template<class Cmpt>
inline const AutLib::Vector<Cmpt>& AutLib::Vector<Cmpt>::centre(const List<Vector<Cmpt>>&) const
{
	return *this;
}

// * * * * * * * * * * * * * * * Global Operators  * * * * * * * * * * * * * //

namespace AutLib
{
	template <class Cmpt>
	inline typename innerProduct<Vector<Cmpt>, Vector<Cmpt> >::type operator&(const Vector<Cmpt>& v1, const Vector<Cmpt>& v2)
	{
		return Cmpt(v1.x()*v2.x() + v1.y()*v2.y() + v1.z()*v2.z());
	}

	template <class Cmpt>
	inline Vector<Cmpt> operator^(const Vector<Cmpt>& v1, const Vector<Cmpt>& v2)
	{
		return Vector<Cmpt>((v1.y()*v2.z() - v1.z()*v2.y()), (v1.z()*v2.x() - v1.x()*v2.z()), (v1.x()*v2.y() - v1.y()*v2.x()));
	}


	template <class Cmpt>
	inline Vector<Cmpt> scaleRow(const Vector<Cmpt>& v, const Cmpt& c)
	{
		// Multiply by scalar
		return v * c;
	}
}