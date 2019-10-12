#pragma once
#ifndef _SHA1_Header
#define _SHA1_Header

#include <SHA1Digest.hxx>

#include <string>

namespace AutLib
{

	class SHA1
	{
		// Private data

		//- Track if the hashsum has been finalized (added count, etc)
		bool finalized_;

		//- The hash sums
		uint32_t hashsumA_;
		uint32_t hashsumB_;
		uint32_t hashsumC_;
		uint32_t hashsumD_;
		uint32_t hashsumE_;

		//- The total number processed, saved as 64-bit
		uint32_t bufTotal_[2];

		//- The number of elements pending in the buffer
		uint32_t bufLen_;

		//- The input processing buffer
		uint32_t buffer_[32];

		// Private Member Functions

		//- Swap bytes from internal to network (big-endian) order
		static uint32_t swapBytes(uint32_t);

		//- Copy the 4-byte value into the memory location pointed to by *dst.
		//  If the architecture allows unaligned access this is equivalent to
		//  *(uint32_t *) cp = val
		static void set_uint32(unsigned char *cp, uint32_t);

		//- Process data block-wise, LEN must be a multiple of 64!
		void processBlock(const void *data, size_t len);

		//- Process for the next LEN bytes, LEN need not be a multiple of 64.
		void processBytes(const void *data, size_t len);

		//- Calculate current digest from appended data.
		void calcDigest(SHA1Digest&) const;

	public:

		// Constructors

		//- Construct null
		SHA1();

		//- Construct and append initial std::string
		explicit SHA1(const std::string&);

		//- Construct and append initial string
		explicit SHA1(const char*);

		// Member Functions

		//- Reset the hashed data before appending more
		void clear();

		//- Append data for processing
		SHA1& append(const char* data, size_t len);

		//- Append string for processing
		SHA1& append(const std::string&);

		//- Append string for processing
		SHA1& append(const char* str);

		//- Finalized the calculations (normally not needed directly).
		//  Returns false if no bytes were passed for processing
		bool finalize();

		//- Calculate current digest from appended data.
		SHA1Digest digest() const;


		// Member Operators

		//- Equality operator
		bool operator==(const SHA1Digest&) const;

		//- Inequality operator
		bool operator!=(const SHA1Digest&) const;

		//- Equality operator
		bool operator==(const SHA1&) const;

		//- Inequality operator
		bool operator!=(const SHA1&) const;

		//- Convert to a digest, calculate current digest from appended data.
		operator SHA1Digest() const;

		// Friend Functions

		// Friend Operators

		friend Ostream& operator<<(Ostream&, const SHA1&);

	};
}

#include <SHA1I.hxx>

#endif // !_SHA1_Header
