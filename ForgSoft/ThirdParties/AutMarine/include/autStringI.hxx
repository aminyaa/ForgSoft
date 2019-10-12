#pragma once

inline 
AutLib::string::string()
{}


inline 
AutLib::string::string(const std::string& str)
	: std::string(str)
{}


// Copy character array
inline 
AutLib::string::string(const char* str)
	: std::string(str)
{}


// Construct from a given number of characters in a character array
inline 
AutLib::string::string(const char* str, const size_type len)
	: std::string(str, len)
{}


// Construct from a single character
inline
AutLib::string::string(const char c)
	: std::string(1, c)
{}

template<class String>
inline bool AutLib::string::valid(const string& str)
{
	for (const_iterator iter = str.begin(); iter != str.end(); iter++)
	{
		if (!String::valid(*iter))
		{
			return false;
		}
	}
	return true;
}


template<class String>
inline bool AutLib::string::stripInvalid(string& str)
{
	if (!valid<String>(str))
	{
		register size_type nValid = 0;
		iterator iter2 = str.begin();

		for
			(
				const_iterator iter1 = iter2;
				iter1 != const_cast<const string&>(str).end();
				iter1++
				)
		{
			register char c = *iter1;

			if (String::valid(c))
			{
				*iter2 = c;
				++iter2;
				++nValid;
			}
		}

		str.resize(nValid);

		return true;
	}

	return false;
}


template<class String>
inline bool AutLib::string::meta(const string& str, const char quote)
{
	int escaped = 0;
	for (const_iterator iter = str.begin(); iter != str.end(); iter++)
	{
		if (quote && *iter == quote)
		{
			escaped ^= 1;  // toggle state
		}
		else if (escaped)
		{
			escaped = false;
		}
		else if (String::meta(*iter))
		{
			return true;
		}
	}
	return false;
}


template<class String>
inline AutLib::string
AutLib::string::quotemeta(const string& str, const char quote)
{
	if (!quote)
	{
		return str;
	}

	string sQuoted;
	sQuoted.reserve(2 * str.length());

	int escaped = 0;
	for (const_iterator iter = str.begin(); iter != str.end(); iter++)
	{
		if (*iter == quote)
		{
			escaped ^= 1;  // toggle state
		}
		else if (escaped)
		{
			escaped = 0;
		}
		else if (String::meta(*iter))
		{
			sQuoted += quote;
		}

		sQuoted += *iter;
	}

	sQuoted.resize(sQuoted.length());

	return sQuoted;
}


template<class String>
inline String AutLib::string::validate(const string& str)
{
	string ss = str;
	stripInvalid<String>(ss);
	return ss;
}

inline AutLib::string AutLib::string::operator()
(
	const size_type i,
	const size_type n
	) const
{
	return substr(i, n);
}


inline AutLib::string AutLib::string::operator()(const size_type n) const
{
	return substr(0, n);
}


inline unsigned AutLib::string::hash::operator()
(
	const string& key,
	unsigned seed
	) const
{
	return Hasher(key.data(), key.size(), seed);
}