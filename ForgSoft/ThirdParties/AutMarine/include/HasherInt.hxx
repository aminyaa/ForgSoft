#pragma once
#ifndef _HasherInt_Header
#define _HasherInt_Header

#include <Hasher.hxx>
#include <stdint.h>

namespace AutLib
{

	//- An optimized version of Hasher
	//  @param[in] data - an array of uint32_t values
	//  @param[in] len  - the number of values (not bytes)
	//  @param[in] seed - the previous hash, or an arbitrary value
	unsigned HasherInt(const uint32_t*, size_t length, unsigned seed = 0);

	//- An optimized version of Hasher, returning dual hash values
	//  @param[in] data - an array of uint32_t values
	//  @param[in] len  - the number of values (not bytes)
	//  @param[in] hash1 - the previous hash, or an arbitrary value
	//    on output, the primary hash value
	//  @param[in] hash1 - the previous hash, or an arbitrary value
	//    on output, the secondary hash value
	unsigned HasherDual
	(
		const uint32_t*,
		size_t len,
		unsigned& hash1,
		unsigned& hash2
	);
}

#endif // !_HasherInt_Header
