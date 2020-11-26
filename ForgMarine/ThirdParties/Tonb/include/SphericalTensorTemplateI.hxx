#pragma once
#include <VectorTemplate.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

	// Construct null
	template<class Cmpt>
	SphericalTensor<Cmpt>::SphericalTensor()
	{}


	// Construct given VectorSpace
	template<class Cmpt>
	SphericalTensor<Cmpt>::SphericalTensor
	(
		const VectorSpace<SphericalTensor<Cmpt>, Cmpt, 1>& vs
	)
		: VectorSpace<SphericalTensor<Cmpt>, Cmpt, 1>(vs)
	{}


	// Construct given three Cmpts
	template<class Cmpt>
	SphericalTensor<Cmpt>::SphericalTensor(const Cmpt& stii)
	{
		this->v_[II] = stii;
	}


	// Construct from Istream
	template<class Cmpt>
	SphericalTensor<Cmpt>::SphericalTensor(Istream& is)
		: VectorSpace<SphericalTensor<Cmpt>, Cmpt, 1>(is)
	{}


	// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

	template<class Cmpt>
	const Cmpt&  SphericalTensor<Cmpt>::ii() const
	{
		return this->v_[II];
	}


	template<class Cmpt>
	Cmpt& SphericalTensor<Cmpt>::ii()
	{
		return this->v_[II];
	}


	template<class Cmpt>
	const SphericalTensor<Cmpt>& SphericalTensor<Cmpt>::T() const
	{
		return *this;
	}


	// * * * * * * * * * * * * * * * Global Operators  * * * * * * * * * * * * * //

	//- Inner-product between two spherical tensors
	template<class Cmpt>
	SphericalTensor<Cmpt>
		operator&(const SphericalTensor<Cmpt>& st1, const SphericalTensor<Cmpt>& st2)
	{
		return SphericalTensor<Cmpt>(st1.ii()*st2.ii());
	}


	//- Inner-product between a spherical tensor and a vector
	template<class Cmpt>
	Vector<Cmpt>
		operator&(const SphericalTensor<Cmpt>& st, const Vector<Cmpt>& v)
	{
		return Vector<Cmpt>
			(
				st.ii()*v.x(),
				st.ii()*v.y(),
				st.ii()*v.z()
				);
	}


	//- Inner-product between a vector and a spherical tensor
	template<class Cmpt>
	Vector<Cmpt>
		operator&(const Vector<Cmpt>& v, const SphericalTensor<Cmpt>& st)
	{
		return Vector<Cmpt>
			(
				v.x()*st.ii(),
				v.y()*st.ii(),
				v.z()*st.ii()
				);
	}


	//- Double-dot-product between a spherical tensor and a spherical tensor
	template<class Cmpt>
	Cmpt
		operator&&(const SphericalTensor<Cmpt>& st1, const SphericalTensor<Cmpt>& st2)
	{
		return 3 * st1.ii()*st2.ii();
	}


	//- Division of a scalar by a sphericalTensor
	template<class Cmpt>
	SphericalTensor<Cmpt>
		operator/(const scalar s, const SphericalTensor<Cmpt>& st)
	{
		return SphericalTensor<Cmpt>(s / st.ii());
	}


	template<class Cmpt>
	Cmpt magSqr(const SphericalTensor<Cmpt>& st)
	{
		return 3 * magSqr(st.ii());
	}


	//- Return the trace of a spherical tensor
	template<class Cmpt>
	Cmpt tr(const SphericalTensor<Cmpt>& st)
	{
		return 3 * st.ii();
	}


	//- Return the spherical part of a spherical tensor, i.e. itself
	template<class Cmpt>
	SphericalTensor<Cmpt> sph(const SphericalTensor<Cmpt>& st)
	{
		return st;
	}


	//- Return the determinant of a spherical tensor
	template<class Cmpt>
	Cmpt det(const SphericalTensor<Cmpt>& st)
	{
		return st.ii()*st.ii()*st.ii();
	}


	//- Return the inverse of a spherical tensor
	template<class Cmpt>
	SphericalTensor<Cmpt> inv(const SphericalTensor<Cmpt>& st)
	{
		return SphericalTensor<Cmpt>(1.0 / st.ii());
	}


	template<class Cmpt>
	class outerProduct<SphericalTensor<Cmpt>, Cmpt>
	{
	public:

		typedef SphericalTensor<Cmpt> type;
	};

	template<class Cmpt>
	class outerProduct<Cmpt, SphericalTensor<Cmpt>>
	{
	public:

		typedef SphericalTensor<Cmpt> type;
	};


	template<class Cmpt>
	class innerProduct<SphericalTensor<Cmpt>, SphericalTensor<Cmpt>>
	{
	public:

		typedef SphericalTensor<Cmpt> type;
	};


	template<class Cmpt>
	class innerProduct<SphericalTensor<Cmpt>, Vector<Cmpt>>
	{
	public:

		typedef Vector<Cmpt> type;
	};

	template<class Cmpt>
	class innerProduct<Vector<Cmpt>, SphericalTensor<Cmpt>>
	{
	public:

		typedef Vector<Cmpt> type;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// ************************************************************************* //