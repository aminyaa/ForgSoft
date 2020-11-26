#pragma once
#ifndef _SHA1Digest_Header
#define _SHA1Digest_Header

namespace tnbLib
{

	// Forward declaration of classes
	class Ostream;

	// Forward declaration of friend functions and operators
	class SHA1;
	class SHA1Digest;
	Ostream& operator<<(Ostream&, const SHA1Digest&);


	/*---------------------------------------------------------------------------*\
							Class SHA1Digest Declaration
	\*---------------------------------------------------------------------------*/

	class SHA1Digest
	{
	public:
		friend class SHA1;

		//- The length of the digest contents
		static const unsigned length = 20;

		//- Construct a zero digest
		SHA1Digest();

		//- Reset the digest to zero
		void clear();

		//- Equality operator
		bool operator==(const SHA1Digest&) const;

		//- Inequality operator
		bool operator!=(const SHA1Digest&) const;

		friend Ostream& operator<<(Ostream&, const SHA1Digest&);

	private:

		//- The digest contents
		unsigned char v_[length];
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_SHA1Digest_Header
