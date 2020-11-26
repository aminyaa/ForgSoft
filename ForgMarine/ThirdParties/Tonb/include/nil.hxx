#pragma once
#ifndef _nil_Header
#define _nil_Header

namespace tnbLib
{

	// Forward declaration of classes
	class Istream;
	class Ostream;

	// Forward declaration of friend functions and operators

	class nil;

	Istream& operator>>(Istream&, nil&);
	Ostream& operator<<(Ostream&, const nil&);

	//- A zero-sized class without any storage. Used, for example, in HashSet.
	//- A zero-sized class actually does still require at least 1 byte storage.
	class nil
	{

	public:

		// Constructors

		//- Construct null
		nil()
		{}

		//- Construct from Istream
		nil(Istream&)
		{}


		// IOstream Operators

		friend Istream& operator>>(Istream& is, nil&)
		{
			return is;
		}

		friend Ostream& operator<<(Ostream& os, const nil&)
		{
			return os;
		}
	};
}

#endif // !_nil_Header
