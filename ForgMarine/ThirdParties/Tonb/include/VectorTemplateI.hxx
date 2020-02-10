#pragma once
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

	// Construct null
	template <class Cmpt>
	Vector<Cmpt>::Vector()
	{}


	// Construct given VectorSpace
	template <class Cmpt>
	Vector<Cmpt>::Vector(const VectorSpace<Vector<Cmpt>, Cmpt, 3>& vs)
		: VectorSpace<Vector<Cmpt>, Cmpt, 3>(vs)
	{}


	// Construct given three Cmpts
	template <class Cmpt>
	Vector<Cmpt>::Vector(const Cmpt& vx, const Cmpt& vy, const Cmpt& vz)
	{
		this->v_[X] = vx;
		this->v_[Y] = vy;
		this->v_[Z] = vz;
	}


	// Construct from Istream
	template <class Cmpt>
	Vector<Cmpt>::Vector(Istream& is)
		: VectorSpace<Vector<Cmpt>, Cmpt, 3>(is)
	{}


	// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

	template <class Cmpt>
	const Cmpt& Vector<Cmpt>::x() const
	{
		return this->v_[X];
	}

	template <class Cmpt>
	const Cmpt& Vector<Cmpt>::y() const
	{
		return this->v_[Y];
	}

	template <class Cmpt>
	const Cmpt& Vector<Cmpt>::z() const
	{
		return this->v_[Z];
	}


	template <class Cmpt>
	Cmpt& Vector<Cmpt>::x()
	{
		return this->v_[X];
	}

	template <class Cmpt>
	Cmpt& Vector<Cmpt>::y()
	{
		return this->v_[Y];
	}

	template <class Cmpt>
	Cmpt& Vector<Cmpt>::z()
	{
		return this->v_[Z];
	}


	template <class Cmpt>
	const Cmpt& Vector<Cmpt>::operator()
		(
			const direction i
			) const
	{
		return this->operator[](i);
	}


	template <class Cmpt>
	Cmpt& Vector<Cmpt>::operator()
		(
			const direction i
			)
	{
		return this->operator[](i);
	}


	// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

	template <class Cmpt>
	const Vector<Cmpt>& Vector<Cmpt>::centre
	(
		const tnbLib::List<Vector<Cmpt>>&
	)const
	{
		return *this;
	}


	// * * * * * * * * * * * * * * * Global Operators  * * * * * * * * * * * * * //

	template <class Cmpt>
	typename innerProduct<Vector<Cmpt>, Vector<Cmpt>>::type
		operator&(const Vector<Cmpt>& v1, const Vector<Cmpt>& v2)
	{
		return Cmpt(v1.x()*v2.x() + v1.y()*v2.y() + v1.z()*v2.z());
	}


	template <class Cmpt>
	Vector<Cmpt> operator^(const Vector<Cmpt>& v1, const Vector<Cmpt>& v2)
	{
		return Vector<Cmpt>
			(
			(v1.y()*v2.z() - v1.z()*v2.y()),
				(v1.z()*v2.x() - v1.x()*v2.z()),
				(v1.x()*v2.y() - v1.y()*v2.x())
				);
	}


	template <class Cmpt>
	Vector<Cmpt> scaleRow(const Vector<Cmpt>& v, const Cmpt& c)
	{
		// Multiply by scalar
		return v * c;
	}


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib