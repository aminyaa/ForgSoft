#pragma once
#ifndef _Tuple2_Header
#define _Tuple2_Header

#include <IOstream.hxx>
#include <ISstream.hxx>

namespace AutLib
{

	template<class Type1, class Type2>
	class Tuple2
	{
		// Private data

		Type1 f_;
		Type2 s_;


	public:

		// Constructors

		//- Null constructor for lists
		Tuple2()
		{}

		//- Construct from components
		Tuple2(const Type1& f, const Type2& s)
			: f_(f)
			, s_(s)
		{}

		//- Construct from Istream
		Tuple2(Istream& is)
		{
			is >> *this;
		}


		// Member Functions

		//- Return first
		const Type1& first() const
		{
			return f_;
		}

		//- Return first
		Type1& first()
		{
			return f_;
		}

		//- Return second
		const Type2& second() const
		{
			return s_;
		}

		//- Return second
		Type2& second()
		{
			return s_;
		}

		//- Return reverse pair
		Tuple2<Type2, Type1> reverseTuple2() const
		{
			return Tuple2<Type2, Type1>(second(), first());
		}


		// Friend Operators
		template<class Type1, class Type2>
		friend bool operator==(const Tuple2<Type1, Type2>& a, const Tuple2<Type1, Type2>& b);

		template<class Type1, class Type2>
		friend bool operator!=(const Tuple2<Type1, Type2>& a, const Tuple2<Type1, Type2>& b);


		// IOstream operators

		//- Read Tuple2 from Istream, discarding contents of existing Tuple2.
		template<class Type1, class Type2>
		friend Istream& operator>>(Istream& is, Tuple2<Type1, Type2>& t2);

		// Write Tuple2 to Ostream.
		template<class Type1, class Type2>
		friend Ostream& operator<<(Ostream& os, const Tuple2<Type1, Type2>& t2);
	};


	template<class Type1, class Type2>
	bool operator==(const Tuple2<Type1, Type2>& a, const Tuple2<Type1, Type2>& b)
	{
		return ((a.first() == b.first()) && (a.second() == b.second()));
	}


	template<class Type1, class Type2>
	bool operator!=(const Tuple2<Type1, Type2>& a, const Tuple2<Type1, Type2>& b)
	{
		return !(a == b);
	}


	template<class Type1, class Type2>
	Istream& operator>>(Istream& is, Tuple2<Type1, Type2>& t2)
	{
		is.readBegin("Tuple2");
		is >> t2.f_ >> t2.s_;
		is.readEnd("Tuple2");

		// Check state of Istream
		is.check("operator>>(Istream&, Tuple2<Type1, Type2>&)");

		return is;
	}


	template<class Type1, class Type2>
	Ostream& operator<<(Ostream& os, const Tuple2<Type1, Type2>& t2)
	{
		os << token::BEGIN_LIST
			<< t2.f_ << token::SPACE << t2.s_
			<< token::END_LIST;

		return os;
	}
}

#endif // !_Tuple2_Header
