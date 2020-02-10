#pragma once
#include <pTraits.hxx>
#include <dictionary.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

	template <class Type>
	dimensioned<Type> dimensioned<Type>::lookupOrDefault
	(
		const word& name,
		const dictionary& dict,
		const Type& defaultValue,
		const dimensionSet& dims
	)
	{
		Type value = dict.lookupOrDefault<Type>(name, defaultValue);
		return dimensioned<Type>(name, dims, value);
	}


	template <class Type>
	dimensioned<Type> dimensioned<Type>::lookupOrAddToDict
	(
		const word& name,
		dictionary& dict,
		const Type& defaultValue,
		const dimensionSet& dims
	)
	{
		Type value = dict.lookupOrAddDefault<Type>(name, defaultValue);
		return dimensioned<Type>(name, dims, value);
	}


	// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

	template <class Type>
	dimensioned<Type>::dimensioned
	(
		const word& name,
		const dimensionSet& dimSet,
		const Type t
	)
		:
		name_(name),
		dimensions_(dimSet),
		value_(t)
	{}


	template <class Type>
	dimensioned<Type>::dimensioned
	(
		const word& name,
		const dimensioned<Type>& dt
	)
		:
		name_(name),
		dimensions_(dt.dimensions_),
		value_(dt.value_)
	{}


	template <class Type>
	dimensioned<Type>::dimensioned
	(
		Istream& is
	)
		:
		name_(is),
		dimensions_(is),
		value_(pTraits<Type>(is))
	{}


	template <class Type>
	dimensioned<Type>::dimensioned
	(
		const word& name,
		Istream& is
	)
		:
		name_(name),
		dimensions_(is),
		value_(pTraits<Type>(is))
	{}


	template <class Type>
	dimensioned<Type>::dimensioned
	(
		const word& name,
		const dimensionSet& dimSet,
		Istream& is
	)
		:
		name_(name),
		dimensions_(dimSet),
		value_(pTraits<Type>(is))
	{}


	// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

	template <class Type>
	const word& dimensioned<Type>::name() const
	{
		return name_;
	}

	template <class Type>
	word& dimensioned<Type>::name()
	{
		return name_;
	}


	template <class Type>
	const dimensionSet& dimensioned<Type>::dimensions() const
	{
		return dimensions_;
	}

	template <class Type>
	dimensionSet& dimensioned<Type>::dimensions()
	{
		return dimensions_;
	}


	template <class Type>
	const Type& dimensioned<Type>::value() const
	{
		return value_;
	}

	template <class Type>
	Type& dimensioned<Type>::value()
	{
		return value_;
	}


	template <class Type>
	dimensioned<typename dimensioned<Type>::cmptType> dimensioned<Type>::component
	(
		const direction d
	) const
	{
		return dimensioned<cmptType>
			(
				name_ + ".component(" + tnbLib::name(d) + ')',
				dimensions_,
				value_.component(d)
				);
	}


	template <class Type>
	void dimensioned<Type>::replace
	(
		const direction d,
		const dimensioned<typename dimensioned<Type>::cmptType>& dc
	)
	{
		dimensions_ = dc.dimensions();
		value_.replace(d, dc.value());
	}


	template <class Type>
	bool dimensioned<Type>::readIfPresent(const dictionary& dict)
	{
		return dict.readIfPresent(name_, value_);
	}


	// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

	template <class Type>
	dimensioned<typename dimensioned<Type>::cmptType> dimensioned<Type>::operator[]
	(
		const direction d
		) const
	{
		return component(d);
	}


	template <class Type>
	void dimensioned<Type>::operator+=
		(
			const dimensioned<Type>& dt
			)
	{
		dimensions_ += dt.dimensions_;
		value_ += dt.value_;
	}


	template <class Type>
	void dimensioned<Type>::operator-=
		(
			const dimensioned<Type>& dt
			)
	{
		dimensions_ -= dt.dimensions_;
		value_ -= dt.value_;
	}


	template <class Type>
	void dimensioned<Type>::operator*=
		(
			const scalar s
			)
	{
		value_ *= s;
	}


	template <class Type>
	void dimensioned<Type>::operator/=
		(
			const scalar s
			)
	{
		value_ /= s;
	}


	// * * * * * * * * * * * * * * * Friend Functions  * * * * * * * * * * * * * //

	template<class Type, int r>
	dimensioned<typename powProduct<Type, r>::type>
		pow(const dimensioned<Type>& dt, typename powProduct<Type, r>::type)
	{
		return dimensioned<typename powProduct<Type, r>::type>
			(
				"pow(" + dt.name() + ',' + name(r) + ')',
				pow(dt.dimensions(), r),
				pow(dt.value(), 2)
				);
	}

	template<class Type>
	dimensioned<typename outerProduct<Type, Type>::type>
		sqr(const dimensioned<Type>& dt)
	{
		return dimensioned<typename outerProduct<Type, Type>::type>
			(
				"sqr(" + dt.name() + ')',
				sqr(dt.dimensions()),
				sqr(dt.value())
				);
	}

	template<class Type>
	dimensioned<scalar> magSqr(const dimensioned<Type>& dt)
	{
		return dimensioned<scalar>
			(
				"magSqr(" + dt.name() + ')',
				magSqr(dt.dimensions()),
				magSqr(dt.value())
				);
	}

	template<class Type>
	dimensioned<scalar> mag(const dimensioned<Type>& dt)
	{
		return dimensioned<scalar>
			(
				"mag(" + dt.name() + ')',
				dt.dimensions(),
				mag(dt.value())
				);
	}


	template <class Type>
	dimensioned<Type> max
	(
		const dimensioned<Type>& dt1,
		const dimensioned<Type>& dt2
	)
	{
		if (dt1.dimensions() != dt2.dimensions())
		{
			FatalErrorIn("max(const dimensioned<Type>&, const dimensioned<Type>&)")
				<< "dimensions of arguments are not equal"
				<< abort(FatalError);
		}

		return dimensioned<Type>
			(
				"max(" + dt1.name() + ',' + dt2.name() + ')',
				dt1.dimensions(),
				max(dt1.value(), dt2.value())
				);
	}


	template <class Type>
	dimensioned<Type> min
	(
		const dimensioned<Type>& dt1,
		const dimensioned<Type>& dt2
	)
	{
		if (dt1.dimensions() != dt2.dimensions())
		{
			FatalErrorIn("min(const dimensioned<Type>&, const dimensioned<Type>&)")
				<< "dimensions of arguments are not equal"
				<< abort(FatalError);
		}

		return dimensioned<Type>
			(
				"min(" + dt1.name() + ',' + dt2.name() + ')',
				dt1.dimensions(),
				min(dt1.value(), dt2.value())
				);
	}


	// * * * * * * * * * * * * * * * IOstream Operators  * * * * * * * * * * * * //

	template <class Type>
	Istream& operator>>(Istream& is, dimensioned<Type>& dt)
	{
		// do a stream read op for a Type and a dimensions()et
		is >> dt.name_ >> dt.dimensions_ >> dt.value_;

		// Check state of Istream
		is.check("Istream& operator>>(Istream&, dimensioned<Type>&)");

		return is;
	}


	template <class Type>
	Ostream& operator<<(Ostream& os, const dimensioned<Type>& dt)
	{
		// do a stream write op for a dimensions()et
		os << dt.name() << token::SPACE
			<< dt.dimensions() << token::SPACE
			<< dt.value();

		// Check state of Ostream
		os.check("Ostream& operator<<(Ostream&, const dimensioned<Type>&)");

		return os;
	}


	// * * * * * * * * * * * * * * * Global Operators  * * * * * * * * * * * * * //

	template <class Type>
	bool operator>
		(
			const dimensioned<Type>& dt1,
			const dimensioned<Type>& dt2
			)
	{
		return dt1.value() > dt2.value();
	}


	template <class Type>
	bool operator<
		(
			const dimensioned<Type>& dt1,
			const dimensioned<Type>& dt2
			)
	{
		return dt1.value() < dt2.value();
	}


	template <class Type>
	dimensioned<Type> operator+
		(
			const dimensioned<Type>& dt1,
			const dimensioned<Type>& dt2
			)
	{
		return dimensioned<Type>
			(
				'(' + dt1.name() + '+' + dt2.name() + ')',
				dt1.dimensions() + dt2.dimensions(),
				dt1.value() + dt2.value()
				);
	}


	template <class Type>
	dimensioned<Type> operator-(const dimensioned<Type>& dt)
	{
		return dimensioned<Type>
			(
				'-' + dt.name(),
				dt.dimensions(),
				-dt.value()
				);
	}


	template <class Type>
	dimensioned<Type> operator-
		(
			const dimensioned<Type>& dt1,
			const dimensioned<Type>& dt2
			)
	{
		return dimensioned<Type>
			(
				'(' + dt1.name() + '-' + dt2.name() + ')',
				dt1.dimensions() - dt2.dimensions(),
				dt1.value() - dt2.value()
				);
	}


	template <class Type>
	dimensioned<Type> operator*
		(
			const dimensioned<scalar>& ds,
			const dimensioned<Type>& dt
			)
	{
		return dimensioned<Type>
			(
				'(' + ds.name() + '*' + dt.name() + ')',
				ds.dimensions() * dt.dimensions(),
				ds.value() * dt.value()
				);
	}


	template <class Type>
	dimensioned<Type> operator/
		(
			const dimensioned<Type>& dt,
			const dimensioned<scalar>& ds
			)
	{
		return dimensioned<Type>
			(
				'(' + dt.name() + '|' + ds.name() + ')',
				dt.dimensions() / ds.dimensions(),
				dt.value() / ds.value()
				);
	}


	// Products
	// ~~~~~~~~


	template <class Type1, class Type2>
	dimensioned<typename outerProduct<Type1, Type2>::type> operator
		*(const dimensioned<Type1>& dt1, const dimensioned<Type2>& dt2)
	{
		return dimensioned<typename outerProduct<Type1, Type2>::type>('(' + dt1.name() + "*" + dt2.name() + ')'
			, dt1.dimensions() * dt2.dimensions()
			, dt1.value() * dt2.value());
	}

	template <class Type, class Form, class Cmpt, int nCmpt>
	dimensioned<typename outerProduct<Type, Form>::type> operator
		*(const dimensioned<Type>& dt1, const VectorSpace<Form, Cmpt, nCmpt>& t2)
	{
		return dimensioned<typename outerProduct<Type, Form>::type>('(' + dt1.name() + "*" + name(t2) + ')', dt1.dimensions()
			, dt1.value() * static_cast<const Form&>(t2));
	}

	template <class Type, class Form, class Cmpt, int nCmpt>
	dimensioned<typename outerProduct<Form, Type>::type> operator
		*(const VectorSpace<Form, Cmpt, nCmpt>& t1, const dimensioned<Type>& dt2)
	{
		return dimensioned<typename outerProduct<Form, Type>::type>('(' + name(t1) + "*" + dt2.name() + ')', dt2.dimensions()
			, static_cast<const Form&>(t1) * dt2.value());
	}

	template <class Type1, class Type2>
	dimensioned<typename crossProduct<Type1, Type2>::type> operator
		^(const dimensioned<Type1>& dt1, const dimensioned<Type2>& dt2)
	{
		return dimensioned<typename crossProduct<Type1, Type2>::type>('(' + dt1.name() + "^" + dt2.name() + ')'
			, dt1.dimensions() ^ dt2.dimensions()
			, dt1.value() ^ dt2.value());
	}

	template <class Type, class Form, class Cmpt, int nCmpt>
	dimensioned<typename crossProduct<Type, Form>::type> operator
		^(const dimensioned<Type>& dt1, const VectorSpace<Form, Cmpt, nCmpt>& t2)
	{
		return dimensioned<typename crossProduct<Type, Form>::type>('(' + dt1.name() + "^" + name(t2) + ')', dt1.dimensions()
			, dt1.value() ^ static_cast<const Form&>(t2));
	}

	template <class Type, class Form, class Cmpt, int nCmpt>
	dimensioned<typename crossProduct<Form, Type>::type> operator
		^(const VectorSpace<Form, Cmpt, nCmpt>& t1, const dimensioned<Type>& dt2)
	{
		return dimensioned<typename crossProduct<Form, Type>::type>('(' + name(t1) + "^" + dt2.name() + ')', dt2.dimensions()
			, static_cast<const Form&>(t1) ^ dt2.value());
	}

	template <class Type1, class Type2>
	dimensioned<typename innerProduct<Type1, Type2>::type> operator
		&(const dimensioned<Type1>& dt1, const dimensioned<Type2>& dt2)
	{
		return dimensioned<typename innerProduct<Type1, Type2>::type>('(' + dt1.name() + "&" + dt2.name() + ')'
			, dt1.dimensions() & dt2.dimensions()
			, dt1.value() & dt2.value());
	}

	template <class Type, class Form, class Cmpt, int nCmpt>
	dimensioned<typename innerProduct<Type, Form>::type> operator
		&(const dimensioned<Type>& dt1, const VectorSpace<Form, Cmpt, nCmpt>& t2)
	{
		return dimensioned<typename innerProduct<Type, Form>::type>('(' + dt1.name() + "&" + name(t2) + ')', dt1.dimensions()
			, dt1.value() & static_cast<const Form&>(t2));
	}

	template <class Type, class Form, class Cmpt, int nCmpt>
	dimensioned<typename innerProduct<Form, Type>::type> operator
		&(const VectorSpace<Form, Cmpt, nCmpt>& t1, const dimensioned<Type>& dt2)
	{
		return dimensioned<typename innerProduct<Form, Type>::type>('(' + name(t1) + "&" + dt2.name() + ')', dt2.dimensions()
			, static_cast<const Form&>(t1) & dt2.value());
	}

	template <class Type1, class Type2>
	dimensioned<typename scalarProduct<Type1, Type2>::type> operator
		&&(const dimensioned<Type1>& dt1, const dimensioned<Type2>& dt2)
	{
		return dimensioned<typename scalarProduct<Type1, Type2>::type>('(' + dt1.name() + "&&" + dt2.name() + ')'
			, dt1.dimensions() && dt2.dimensions()
			, dt1.value() && dt2.value());
	}

	template <class Type, class Form, class Cmpt, int nCmpt>
	dimensioned<typename scalarProduct<Type, Form>::type> operator
		&&(const dimensioned<Type>& dt1, const VectorSpace<Form, Cmpt, nCmpt>& t2)
	{
		return dimensioned<typename scalarProduct<Type, Form>::type>('(' + dt1.name() + "&&" + name(t2) + ')'
			, dt1.dimensions()
			, dt1.value() && static_cast<const Form&>(t2));
	}

	template <class Type, class Form, class Cmpt, int nCmpt>
	dimensioned<typename scalarProduct<Form, Type>::type> operator
		&&(const VectorSpace<Form, Cmpt, nCmpt>& t1, const dimensioned<Type>& dt2)
	{
		return dimensioned<typename scalarProduct<Form, Type>::type>('(' + name(t1) + "&&" + dt2.name() + ')'
			, dt2.dimensions()
			, static_cast<const Form&>(t1) && dt2.value());
	}



	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// ************************************************************************* //