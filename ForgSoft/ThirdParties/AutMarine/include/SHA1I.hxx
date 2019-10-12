#pragma once
inline
uint32_t AutLib::SHA1::swapBytes(uint32_t n)
{
#ifdef __BYTE_ORDER
# if (__BYTE_ORDER == __BIG_ENDIAN)
	return n;
# else
	return (((n) << 24) | (((n) & 0xff00) << 8) | (((n) >> 8) & 0xff00) | ((n) >> 24));
# endif

#else

	const short x = 0x0100;

	// yields 0x01 for big endian
	if (*(reinterpret_cast<const char *>(&x)))
	{
		return n;
	}
	else
	{
		return (((n) << 24) | (((n) & 0xff00) << 8) | (((n) >> 8) & 0xff00) | ((n) >> 24));
	}
#endif
}

inline 
void AutLib::SHA1::set_uint32(unsigned char * cp, uint32_t v)
{
	memcpy(cp, &v, sizeof(uint32_t));
}

inline 
AutLib::SHA1::SHA1()
{
	clear();
}

inline 
AutLib::SHA1::SHA1(const std::string& str)
{
	clear();
	append(str);
}

inline 
AutLib::SHA1::SHA1(const char* str)
{
	clear();
	append(str);
}

inline 
AutLib::SHA1& AutLib::SHA1::append(const char* data, size_t len)
{
	processBytes(data, len);
	return *this;
}


inline 
AutLib::SHA1& AutLib::SHA1::append(const std::string& str)
{
	processBytes(str.data(), str.size());
	return *this;
}


inline 
AutLib::SHA1& AutLib::SHA1::append(const char* str)
{
	if (str)
	{
		processBytes(str, strlen(str));
	}
	return *this;
}

inline 
bool AutLib::SHA1::operator==(const SHA1Digest& rhs) const
{
	return this->digest() == rhs;
}


inline 
bool AutLib::SHA1::operator!=(const SHA1Digest& rhs) const
{
	return this->digest() != rhs;
}


inline 
bool AutLib::SHA1::operator==(const SHA1& rhs) const
{
	return digest() == rhs.digest();
}


inline 
bool AutLib::SHA1::operator!=(const SHA1& rhs) const
{
	return digest() != rhs.digest();
}

namespace AutLib
{
	inline SHA1::operator SHA1Digest() const
	{
		return digest();
	}
}