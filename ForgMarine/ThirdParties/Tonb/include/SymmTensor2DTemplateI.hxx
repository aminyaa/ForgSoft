#pragma once
#include <Vector2DTemplate.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

	template<class Cmpt>
	SymmTensor2D<Cmpt>::SymmTensor2D()
	{}


	template<class Cmpt>
	SymmTensor2D<Cmpt>::SymmTensor2D
	(
		const VectorSpace<SymmTensor2D<Cmpt>, Cmpt, 3>& vs
	)
		: VectorSpace<SymmTensor2D<Cmpt>, Cmpt, 3>(vs)
	{}


	template<class Cmpt>
	SymmTensor2D<Cmpt>::SymmTensor2D(const SphericalTensor2D<Cmpt>& st)
	{
		this->v_[XX] = st.ii(); this->v_[XY] = 0;
		this->v_[YY] = st.ii();
	}


	template<class Cmpt>
	SymmTensor2D<Cmpt>::SymmTensor2D
	(
		const Cmpt txx, const Cmpt txy,
		const Cmpt tyy
	)
	{
		this->v_[XX] = txx; this->v_[XY] = txy;
		this->v_[YY] = tyy;
	}


	template<class Cmpt>
	SymmTensor2D<Cmpt>::SymmTensor2D(Istream& is)
		: VectorSpace<SymmTensor2D<Cmpt>, Cmpt, 3>(is)
	{}


	// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

	template<class Cmpt>
	const Cmpt& SymmTensor2D<Cmpt>::xx() const
	{
		return this->v_[XX];
	}

	template<class Cmpt>
	const Cmpt& SymmTensor2D<Cmpt>::xy() const
	{
		return this->v_[XY];
	}

	template<class Cmpt>
	const Cmpt& SymmTensor2D<Cmpt>::yy() const
	{
		return this->v_[YY];
	}


	template<class Cmpt>
	Cmpt& SymmTensor2D<Cmpt>::xx()
	{
		return this->v_[XX];
	}

	template<class Cmpt>
	Cmpt& SymmTensor2D<Cmpt>::xy()
	{
		return this->v_[XY];
	}

	template<class Cmpt>
	Cmpt& SymmTensor2D<Cmpt>::yy()
	{
		return this->v_[YY];
	}


	template<class Cmpt>
	const SymmTensor2D<Cmpt>& SymmTensor2D<Cmpt>::T() const
	{
		return *this;
	}


	// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

	template<class Cmpt>
	void SymmTensor2D<Cmpt>::operator=(const SphericalTensor2D<Cmpt>& st)
	{
		this->v_[XX] = st.ii(); this->v_[XY] = 0;
		this->v_[YY] = st.ii();
	}


	// * * * * * * * * * * * * * * * Global Operators  * * * * * * * * * * * * * //

	//- Inner-product between two symmetric tensors
	template<class Cmpt>
	Tensor2D<Cmpt>
		operator&(const SymmTensor2D<Cmpt>& st1, const SymmTensor2D<Cmpt>& st2)
	{
		return Tensor2D<Cmpt>
			(
				st1.xx()*st2.xx() + st1.xy()*st2.xy(),
				st1.xx()*st2.xy() + st1.xy()*st2.yy(),

				st1.xy()*st2.xx() + st1.yy()*st2.xy(),
				st1.xy()*st2.xy() + st1.yy()*st2.yy()
				);
	}


	//- Double-dot-product between a symmetric tensor and a symmetric tensor
	template<class Cmpt>
	Cmpt
		operator&&(const SymmTensor2D<Cmpt>& st1, const SymmTensor2D<Cmpt>& st2)
	{
		return
			(
				st1.xx()*st2.xx() + 2 * st1.xy()*st2.xy()
				+ st1.yy()*st2.yy()
				);
	}


	//- Inner-product between a symmetric tensor and a vector
	template<class Cmpt>
	Vector2D<Cmpt>
		operator&(const SymmTensor2D<Cmpt>& st, const Vector2D<Cmpt>& v)
	{
		return Vector2D<Cmpt>
			(
				st.xx()*v.x() + st.xy()*v.y(),
				st.xy()*v.x() + st.yy()*v.y()
				);
	}


	//- Inner-product between a vector and a symmetric tensor
	template<class Cmpt>
	Vector2D<Cmpt>
		operator&(const Vector2D<Cmpt>& v, const SymmTensor2D<Cmpt>& st)
	{
		return Vector2D<Cmpt>
			(
				v.x()*st.xx() + v.y()*st.xy(),
				v.x()*st.xy() + v.y()*st.yy()
				);
	}


	//- Inner-sqr of a symmetric tensor
	template<class Cmpt>
	SymmTensor2D<Cmpt>
		innerSqr(const SymmTensor2D<Cmpt>& st)
	{
		return SymmTensor2D<Cmpt>
			(
				st.xx()*st.xx() + st.xy()*st.xy(),
				st.xx()*st.xy() + st.xy()*st.yy(),
				st.xy()*st.xy() + st.yy()*st.yy()
				);
	}


	template<class Cmpt>
	Cmpt magSqr(const SymmTensor2D<Cmpt>& st)
	{
		return
			(
				magSqr(st.xx()) + 2 * magSqr(st.xy())
				+ magSqr(st.yy())
				);
	}


	//- Return the trace of a symmetric tensor
	template<class Cmpt>
	Cmpt tr(const SymmTensor2D<Cmpt>& st)
	{
		return st.xx() + st.yy();
	}


	//- Return the spherical part of a symmetric tensor
	template<class Cmpt>
	SphericalTensor2D<Cmpt> sph(const SymmTensor2D<Cmpt>& st)
	{
		return (1.0 / 2.0)*tr(st);
	}


	//- Return the symmetric part of a symmetric tensor, i.e. itself
	template<class Cmpt>
	const SymmTensor2D<Cmpt>& symm(const SymmTensor2D<Cmpt>& st)
	{
		return st;
	}


	//- Return twice the symmetric part of a symmetric tensor
	template<class Cmpt>
	SymmTensor2D<Cmpt> twoSymm(const SymmTensor2D<Cmpt>& st)
	{
		return 2 * st;
	}


	//- Return the deviatoric part of a symmetric tensor
	template<class Cmpt>
	SymmTensor2D<Cmpt> dev(const SymmTensor2D<Cmpt>& st)
	{
		return st - SphericalTensor2D<Cmpt>::oneThirdI*tr(st);
	}


	//- Return the deviatoric part of a symmetric tensor
	template<class Cmpt>
	SymmTensor2D<Cmpt> dev2(const SymmTensor2D<Cmpt>& st)
	{
		return st - SphericalTensor2D<Cmpt>::twoThirdsI*tr(st);
	}


	//- Return the determinant of a symmetric tensor
	template<class Cmpt>
	Cmpt det(const SymmTensor2D<Cmpt>& st)
	{
		return
			(
				st.xx()*st.yy() - st.xy()*st.xy()
				);
	}


	//- Return the cofactor symmetric tensor of a symmetric tensor
	template<class Cmpt>
	SymmTensor2D<Cmpt> cof(const SymmTensor2D<Cmpt>& st)
	{
		return SymmTensor2D<Cmpt>
			(
				st.yy(), -st.xy(),
				st.xx()
				);
	}


	//- Return the inverse of a symmetric tensor give the determinant
	template<class Cmpt>
	SymmTensor2D<Cmpt> inv(const SymmTensor2D<Cmpt>& st, const Cmpt detst)
	{
		return cof(st) / detst;
	}


	//- Return the inverse of a symmetric tensor
	template<class Cmpt>
	SymmTensor2D<Cmpt> inv(const SymmTensor2D<Cmpt>& st)
	{
		return inv(st, det(st));
	}


	//- Return the 1st invariant of a symmetric tensor
	template<class Cmpt>
	Cmpt invariantI(const SymmTensor2D<Cmpt>& st)
	{
		return tr(st);
	}


	//- Return the 2nd invariant of a symmetric tensor
	template<class Cmpt>
	Cmpt invariantII(const SymmTensor2D<Cmpt>& st)
	{
		return
			(
				0.5*sqr(tr(st))
				- 0.5*
				(
					st.xx()*st.xx() + st.xy()*st.xy()
					+ st.xy()*st.xy() + st.yy()*st.yy()
					)
				);
	}


	//- Return the 3rd invariant of a symmetric tensor
	template<class Cmpt>
	Cmpt invariantIII(const SymmTensor2D<Cmpt>& st)
	{
		return det(st);
	}


	template<class Cmpt>
	SymmTensor2D<Cmpt>
		operator+(const SphericalTensor2D<Cmpt>& spt1, const SymmTensor2D<Cmpt>& st2)
	{
		return SymmTensor2D<Cmpt>
			(
				spt1.ii() + st2.xx(), st2.xy(),
				spt1.ii() + st2.yy()
				);
	}


	template<class Cmpt>
	SymmTensor2D<Cmpt>
		operator+(const SymmTensor2D<Cmpt>& st1, const SphericalTensor2D<Cmpt>& spt2)
	{
		return SymmTensor2D<Cmpt>
			(
				st1.xx() + spt2.ii(), st1.xy(),
				st1.yy() + spt2.ii()
				);
	}


	template<class Cmpt>
	SymmTensor2D<Cmpt>
		operator-(const SphericalTensor2D<Cmpt>& spt1, const SymmTensor2D<Cmpt>& st2)
	{
		return SymmTensor2D<Cmpt>
			(
				spt1.ii() - st2.xx(), -st2.xy(),
				spt1.ii() - st2.yy()
				);
	}


	template<class Cmpt>
	SymmTensor2D<Cmpt>
		operator-(const SymmTensor2D<Cmpt>& st1, const SphericalTensor2D<Cmpt>& spt2)
	{
		return SymmTensor2D<Cmpt>
			(
				st1.xx() - spt2.ii(), st1.xy(),
				st1.yy() - spt2.ii()
				);
	}


	//- Inner-product between a spherical symmetric tensor and a symmetric tensor
	template<class Cmpt>
	SymmTensor2D<Cmpt>
		operator&(const SphericalTensor2D<Cmpt>& spt1, const SymmTensor2D<Cmpt>& st2)
	{
		return SymmTensor2D<Cmpt>
			(
				spt1.ii()*st2.xx(), spt1.ii()*st2.xy(),
				spt1.ii()*st2.yy()
				);
	}


	//- Inner-product between a tensor and a spherical tensor
	template<class Cmpt>
	SymmTensor2D<Cmpt>
		operator&(const SymmTensor2D<Cmpt>& st1, const SphericalTensor2D<Cmpt>& spt2)
	{
		return SymmTensor2D<Cmpt>
			(
				st1.xx()*spt2.ii(), st1.xy()*spt2.ii(),
				st1.yy()*spt2.ii()
				);
	}


	//- Double-dot-product between a spherical tensor and a symmetric tensor
	template<class Cmpt>
	Cmpt
		operator&&(const SphericalTensor2D<Cmpt>& spt1, const SymmTensor2D<Cmpt>& st2)
	{
		return(spt1.ii()*st2.xx() + spt1.ii()*st2.yy());
	}


	//- Double-dot-product between a tensor and a spherical tensor
	template<class Cmpt>
	Cmpt
		operator&&(const SymmTensor2D<Cmpt>& st1, const SphericalTensor2D<Cmpt>& spt2)
	{
		return(st1.xx()*spt2.ii() + st1.yy()*spt2.ii());
	}


	template<class Cmpt>
	SymmTensor2D<Cmpt> sqr(const Vector2D<Cmpt>& v)
	{
		return SymmTensor2D<Cmpt>
			(
				v.x()*v.x(), v.x()*v.y(),
				v.y()*v.y()
				);
	}


	template<class Cmpt>
	class outerProduct<SymmTensor2D<Cmpt>, Cmpt>
	{
	public:

		typedef SymmTensor2D<Cmpt> type;
	};

	template<class Cmpt>
	class outerProduct<Cmpt, SymmTensor2D<Cmpt>>
	{
	public:

		typedef SymmTensor2D<Cmpt> type;
	};

	template<class Cmpt>
	class innerProduct<SymmTensor2D<Cmpt>, SymmTensor2D<Cmpt>>
	{
	public:

		typedef Tensor2D<Cmpt> type;
	};

	template<class Cmpt>
	class innerProduct<SymmTensor2D<Cmpt>, Vector2D<Cmpt>>
	{
	public:

		typedef Vector2D<Cmpt> type;
	};

	template<class Cmpt>
	class innerProduct<Vector2D<Cmpt>, SymmTensor2D<Cmpt>>
	{
	public:

		typedef Vector2D<Cmpt> type;
	};


	template<class Cmpt>
	class typeOfSum<SphericalTensor2D<Cmpt>, SymmTensor2D<Cmpt>>
	{
	public:

		typedef SymmTensor2D<Cmpt> type;
	};

	template<class Cmpt>
	class typeOfSum<SymmTensor2D<Cmpt>, SphericalTensor2D<Cmpt>>
	{
	public:

		typedef SymmTensor2D<Cmpt> type;
	};

	template<class Cmpt>
	class innerProduct<SphericalTensor2D<Cmpt>, SymmTensor2D<Cmpt>>
	{
	public:

		typedef SymmTensor2D<Cmpt> type;
	};

	template<class Cmpt>
	class innerProduct<SymmTensor2D<Cmpt>, SphericalTensor2D<Cmpt>>
	{
	public:

		typedef SymmTensor2D<Cmpt> type;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// ************************************************************************* //