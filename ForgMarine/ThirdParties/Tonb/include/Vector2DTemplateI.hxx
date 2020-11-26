#pragma once
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

	// Construct null
	template <class Cmpt>
	Vector2D<Cmpt>::Vector2D()
	{}


	// Construct given VectorSpace
	template <class Cmpt>
	Vector2D<Cmpt>::Vector2D(const VectorSpace<Vector2D<Cmpt>, Cmpt, 2>& vs)
		: VectorSpace<Vector2D<Cmpt>, Cmpt, 2>(vs)
	{}


	// Construct given three Cmpts
	template <class Cmpt>
	Vector2D<Cmpt>::Vector2D(const Cmpt& vx, const Cmpt& vy)
	{
		this->v_[X] = vx;
		this->v_[Y] = vy;
	}


	// Construct from Istream
	template <class Cmpt>
	Vector2D<Cmpt>::Vector2D(Istream& is)
		: VectorSpace<Vector2D<Cmpt>, Cmpt, 2>(is)
	{}


	// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

	template <class Cmpt>
	const Cmpt&  Vector2D<Cmpt>::x() const
	{
		return this->v_[X];
	}

	template <class Cmpt>
	const Cmpt&  Vector2D<Cmpt>::y() const
	{
		return this->v_[Y];
	}


	template <class Cmpt>
	Cmpt& Vector2D<Cmpt>::x()
	{
		return this->v_[X];
	}

	template <class Cmpt>
	Cmpt& Vector2D<Cmpt>::y()
	{
		return this->v_[Y];
	}


	template <class Cmpt>
	const Cmpt& Vector2D<Cmpt>::operator()
		(
			const direction i
			) const
	{
		return this->operator[](i);
	}


	template <class Cmpt>
	Cmpt& Vector2D<Cmpt>::operator()
		(
			const direction i
			)
	{
		return this->operator[](i);
	}


	// * * * * * * * * * * * * * * * Global Operators  * * * * * * * * * * * * * //

	template <class Cmpt>
	typename innerProduct<Vector2D<Cmpt>, Vector2D<Cmpt>>::type
		operator&(const Vector2D<Cmpt>& v1, const Vector2D<Cmpt>& v2)
	{
		return Cmpt(v1.x()*v2.x() + v1.y()*v2.y());
	}


	template <class Cmpt>
	scalar Vector2D<Cmpt>::perp(const Vector2D<Cmpt>& b) const
	{
		return x()*b.y() - y()*b.x();
	}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// ************************************************************************* //