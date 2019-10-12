#pragma once
#ifndef _nil_Header
#define _nil_Header

namespace AutLib
{

	// Forward declaration of classes
	class Istream;
	class Ostream;

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
