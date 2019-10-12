#pragma once
inline 
AutLib::keyType::keyType()
	: word()
	, isPattern_(false)
{}

inline 
AutLib::keyType::keyType(const keyType& s)
	: word(s, false)
	, isPattern_(s.isPattern())
{}

inline 
AutLib::keyType::keyType(const word& s)
	: word(s, false)
	, isPattern_(false)
{}

// Construct as copy of string. Expect it to be regular expression
inline 
AutLib::keyType::keyType(const string& s)
	: word(s, false)
	, isPattern_(true)
{}

// Construct as copy of character array
inline 
AutLib::keyType::keyType(const char* s)
	: word(s, false)
	, isPattern_(false)
{}

//- Construct as copy of std::string
inline 
AutLib::keyType::keyType
(
	const std::string& s,
	const bool isPattern
)
	: word(s, false)
	, isPattern_(isPattern)
{}

inline 
bool AutLib::keyType::isPattern() const
{
	return isPattern_;
}

inline 
const AutLib::keyType& AutLib::keyType::operator=(const keyType& s)
{
	// Bypass checking
	string::operator=(s);
	isPattern_ = s.isPattern_;
	return *this;
}


inline 
const AutLib::keyType& AutLib::keyType::operator=(const word& s)
{
	word::operator=(s);
	isPattern_ = false;
	return *this;
}


inline 
const AutLib::keyType& AutLib::keyType::operator=(const string& s)
{
	// Bypass checking
	string::operator=(s);
	isPattern_ = true;
	return *this;
}


inline 
const AutLib::keyType& AutLib::keyType::operator=(const char* s)
{
	// Bypass checking
	string::operator=(s);
	isPattern_ = false;
	return *this;
}