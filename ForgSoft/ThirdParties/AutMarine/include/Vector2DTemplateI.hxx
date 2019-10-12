#pragma once
template<class Cmpt>
inline AutLib::Vector2D<Cmpt>::Vector2D()
{}

template<class Cmpt>
inline AutLib::Vector2D<Cmpt>::Vector2D(const VectorSpace<Vector2D<Cmpt>, Cmpt, 2>& vs)
	: VectorSpace<Vector2D<Cmpt>, Cmpt, 2>(vs)
{}

template<class Cmpt>
inline AutLib::Vector2D<Cmpt>::Vector2D(const Cmpt & vx, const Cmpt & vy)
{
	this->v_[X] = vx;
	this->v_[Y] = vy;
}

template<class Cmpt>
inline AutLib::Vector2D<Cmpt>::Vector2D(Istream & is)
	: VectorSpace<Vector2D<Cmpt>, Cmpt, 2>(is)
{}

template<class Cmpt>
inline const Cmpt & AutLib::Vector2D<Cmpt>::x() const
{
	return this->v_[X];
}

template<class Cmpt>
inline const Cmpt & AutLib::Vector2D<Cmpt>::y() const
{
	return this->v_[Y];
}

template<class Cmpt>
inline Cmpt & AutLib::Vector2D<Cmpt>::x()
{
	return this->v_[X];
}

template<class Cmpt>
inline Cmpt & AutLib::Vector2D<Cmpt>::y()
{
	return this->v_[Y];
}

namespace AutLib
{
	template<class Cmpt>
	inline const Cmpt & Vector2D<Cmpt>::operator()(const direction i) const
	{
		return this->operator[](i);
	}

	template<class Cmpt>
	inline Cmpt & AutLib::Vector2D<Cmpt>::operator()(const direction i)
	{
		return this->operator[](i);
	}

	template <class Cmpt>
	inline typename innerProduct<Vector2D<Cmpt>, Vector2D<Cmpt> >::type operator&(const Vector2D<Cmpt>& v1, const Vector2D<Cmpt>& v2)
	{
		return Cmpt(v1.x()*v2.x() + v1.y()*v2.y());
	}
}

template<class Cmpt>
inline AutLib::scalar AutLib::Vector2D<Cmpt>::perp(const Vector2D<Cmpt>& b) const
{
	return x()*b.y() - y()*b.x();
}