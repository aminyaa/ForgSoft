#pragma once
#ifndef _NamedEnum_Header
#define _NamedEnum_Header

#include <HashTable.hxx>
#include <StaticAssert.hxx>

namespace AutLib
{

	template<class Enum, int nEnum>
	class NamedEnum
		: public HashTable<int>
	{

		//- nEnum must be positive (non-zero)
		typedef StaticAssertionTest<sizeof(StaticAssertionFailed<((nEnum > 0) ? true : false)>)> StaticAssertionTest33;

		// Private Member Functions

		//- Disallow default bitwise copy construct
		NamedEnum(const NamedEnum&) = delete;

		//- Disallow default bitwise assignment
		void operator=(const NamedEnum&) = delete;

	public:

		// Static data members

		//- The set of names corresponding to the enumeration Enum
		static const char* names[nEnum];


		// Constructors

		//- Construct from names
		NamedEnum();


		// Member Functions

		//- Read a word from Istream and return the corresponding
		//  enumeration element
		Enum read(Istream&) const;

		//- Write the name representation of the enumeration to an Ostream
		void write(const Enum e, Ostream&) const;


		// Member Operators

		//- Return the enumeration element corresponding to the given name
		const Enum operator[](const char* name) const
		{
			return Enum(HashTable<int>::operator[](name));
		}

		//- Return the enumeration element corresponding to the given name
		const Enum operator[](const word& name) const
		{
			return Enum(HashTable<int>::operator[](name));
		}

		//- Return the name of the given enumeration element
		const char* operator[](const Enum e) const
		{
			return names[e];
		}

		//- Return the name of the given enumeration element
		//  where e is specified as a int
		const char* operator[](const int e) const
		{
			return names[e];
		}


		// Friend operators
		template<class Enum, int nEnum>
		friend Ostream& operator<<(Ostream&, const NamedEnum<Enum, nEnum>&);
	};
}

#include <NamedEnumI.hxx>

#endif // !_NamedEnum_Header
