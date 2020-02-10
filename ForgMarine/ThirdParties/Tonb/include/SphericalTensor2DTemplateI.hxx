#pragma once
#include <Vector2DTemplate.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

	// Construct null
	template <class Cmpt>
	SphericalTensor2D<Cmpt>::SphericalTensor2D()
	{}


	// Construct given VectorSpace
	template <class Cmpt>
	SphericalTensor2D<Cmpt>::SphericalTensor2D
	(
		const VectorSpace<SphericalTensor2D<Cmpt>, Cmpt, 1>& vs
	)
		: VectorSpace<SphericalTensor2D<Cmpt>, Cmpt, 1>(vs)
	{}


	// Construct given three Cmpts
	template <class Cmpt>
	SphericalTensor2D<Cmpt>::SphericalTensor2D(const Cmpt& stii)
	{
		this->v_[II] = stii;
	}


	// Construct from Istream
	template <class Cmpt>
	SphericalTensor2D<Cmpt>::SphericalTensor2D(Istream& is)
		: VectorSpace<SphericalTensor2D<Cmpt>, Cmpt, 1>(is)
	{}


	// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

	template <class Cmpt>
	const Cmpt&  SphericalTensor2D<Cmpt>::ii() const
	{
		return this->v_[II];
	}


	template <class Cmpt>
	Cmpt& SphericalTensor2D<Cmpt>::ii()
	{
		return this->v_[II];
	}


	// * * * * * * * * * * * * * * * Global Operators  * * * * * * * * * * * * * //

	//- Inner-product between two spherical tensors
	template <class Cmpt>
	SphericalTensor2D<Cmpt>
		operator&
		(
			const SphericalTensor2D<Cmpt>& st1,
			const SphericalTensor2D<Cmpt>& st2
			)
	{
		return SphericalTensor2D<Cmpt>(st1.ii()*st2.ii());
	}


	//- Inner-product between a spherical tensor and a vector
	template <class Cmpt>
	Vector2D<Cmpt>
		operator&(const SphericalTensor2D<Cmpt>& st, const Vector2D<Cmpt>& v)
	{
		return Vector2D<Cmpt>
			(
				st.ii()*v.x(),
				st.ii()*v.y()
				);
	}


	//- Inner-product between a vector and a spherical tensor
	template <class Cmpt>
	Vector2D<Cmpt>
		operator&(const Vector2D<Cmpt>& v, const SphericalTensor2D<Cmpt>& st)
	{
		return Vector2D<Cmpt>
			(
				v.x()*st.ii(),
				v.y()*st.ii()
				);
	}


	//- Division of a scalar by a sphericalTensor2D
	template <class Cmpt>
	SphericalTensor2D<Cmpt>
		operator/(const scalar s, const SphericalTensor2D<Cmpt>& st)
	{
		return SphericalTensor2D<Cmpt>(s / st.ii());
	}


	//- Return the trace of a spherical tensor
	template <class Cmpt>
	Cmpt tr(const SphericalTensor2D<Cmpt>& st)
	{
		return 2 * st.ii();
	}


	//- Return the spherical part of a spherical tensor, i.e. itself
	template <class Cmpt>
	SphericalTensor2D<Cmpt> sph(const SphericalTensor2D<Cmpt>& st)
	{
		return st;
	}


	//- Return the determinant of a spherical tensor
	template <class Cmpt>
	Cmpt det(const SphericalTensor2D<Cmpt>& st)
	{
		return st.ii()*st.ii();
	}


	//- Return the inverse of a symmetric tensor
	template <class Cmpt>
	SphericalTensor2D<Cmpt> inv(const SphericalTensor2D<Cmpt>& st)
	{
		return SphericalTensor2D<Cmpt>(1.0 / st.ii());
	}


	template<class Cmpt>
	class outerProduct<SphericalTensor2D<Cmpt>, Cmpt>
	{
	public:

		typedef SphericalTensor2D<Cmpt> type;
	};

	template<class Cmpt>
	class outerProduct<Cmpt, SphericalTensor2D<Cmpt>>
	{
	public:

		typedef SphericalTensor2D<Cmpt> type;
	};


	template<class Cmpt>
	class innerProduct<SphericalTensor2D<Cmpt>, SphericalTensor2D<Cmpt>>
	{
	public:

		typedef SphericalTensor2D<Cmpt> type;
	};


	template<class Cmpt>
	class innerProduct<SphericalTensor2D<Cmpt>, Vector2D<Cmpt>>
	{
	public:

		typedef Vector2D<Cmpt> type;
	};

	template<class Cmpt>
	class innerProduct<Vector2D<Cmpt>, SphericalTensor2D<Cmpt>>
	{
	public:

		typedef Vector2D<Cmpt> type;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// ************************************************************************* //