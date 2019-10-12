#pragma once
#ifndef _Hasher_Header
#define _Hasher_Header

#include <cstddef>

namespace AutLib
{

	//- Bob Jenkins's 96-bit mixer hashing function (lookup3)
	//  @param[in] data - a character stream
	//  @param[in] len  - the number of bytes
	//  @param[in] seed - the previous hash, or an arbitrary value
	unsigned Hasher(const void* data, size_t len, unsigned seed = 0);
}

#endif // !_Hasher_Header
