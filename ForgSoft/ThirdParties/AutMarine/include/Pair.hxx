#pragma once
#ifndef _Pair_Header
#define _Pair_Header

#include <FixedList.hxx>
#include <Istream.hxx>

namespace AutLib
{

	template<class Type>
	class Pair
		: public FixedList<Type, 2>
	{

	public:

		// Constructors

		//- Null constructor
		Pair()
		{}

		//- Construct from components
		Pair(const Type& f, const Type& s)
		{
			first() = f;
			second() = s;
		}

		//- Construct from Istream
		Pair(Istream& is)
			: FixedList<Type, 2>(is)
		{}


		// Member Functions

		//- Return first
		const Type& first() const
		{
			return this->operator[](0);
		}

		//- Return first
		Type& first()
		{
			return this->operator[](0);
		}

		//- Return second
		const Type& second() const
		{
			return this->operator[](1);
		}

		//- Return second
		Type& second()
		{
			return this->operator[](1);
		}

		//- Return reverse pair
		Pair<Type> reversePair() const
		{
			return Pair<Type>(second(), first());
		}

		//- Return other
		const Type& other(const Type& a) const
		{
			if (first() == second())
			{
				FatalErrorIn("Pair<Type>::other(const Type&) const")
					<< "Call to other only valid for Pair with differing"
					<< " elements:" << *this << abort(FatalError);
			}
			else if (first() == a)
			{
				return second();
			}
			else
			{
				if (second() != a)
				{
					FatalErrorIn("Pair<Type>::other(const Type&) const")
						<< "Pair " << *this
						<< " does not contain " << a << abort(FatalError);
				}
				return first();
			}
		}


		//- compare Pairs
		//  -  0: different
		//  - +1: identical
		//  - -1: same pair, but reversed order
		static int compare(const Pair<Type>& a, const Pair<Type>& b)
		{
			if (a[0] == b[0] && a[1] == b[1])
			{
				return 1;
			}
			else if (a[0] == b[1] && a[1] == b[0])
			{
				return -1;
			}
			else
			{
				return 0;
			}
		}


		// Friend Operators

		friend bool operator==(const Pair<Type>& a, const Pair<Type>& b)
		{
			return
				(
				(a.first() == b.first()) && (a.second() == b.second())
					);
		}

		friend bool operator!=(const Pair<Type>& a, const Pair<Type>& b)
		{
			return !(a == b);
		}
	};
}

#endif // !_Pair_Header
