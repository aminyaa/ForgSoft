#pragma once
// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

inline tnbLib::keyType::keyType()
	: word()
	, isPattern_(false)
{}


inline tnbLib::keyType::keyType(const keyType& s)
	: word(s, false)
	, isPattern_(s.isPattern())
{}


inline tnbLib::keyType::keyType(const word& s)
	: word(s, false)
	, isPattern_(false)
{}


// Construct as copy of string. Expect it to be regular expression
inline tnbLib::keyType::keyType(const string& s)
	: word(s, false)
	, isPattern_(true)
{}


// Construct as copy of character array
inline tnbLib::keyType::keyType(const char* s)
	: word(s, false)
	, isPattern_(false)
{}


//- Construct as copy of std::string
inline tnbLib::keyType::keyType
(
	const std::string& s,
	const bool isPattern
)
	: word(s, false)
	, isPattern_(isPattern)
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

inline bool tnbLib::keyType::isPattern() const
{
	return isPattern_;
}


// * * * * * * * * * * * * * * * Member Operators  * * * * * * * * * * * * * //

inline const tnbLib::keyType& tnbLib::keyType::operator=(const keyType& s)
{
	// Bypass checking
	string::operator=(s);
	isPattern_ = s.isPattern_;
	return *this;
}


inline const tnbLib::keyType& tnbLib::keyType::operator=(const word& s)
{
	word::operator=(s);
	isPattern_ = false;
	return *this;
}


inline const tnbLib::keyType& tnbLib::keyType::operator=(const string& s)
{
	// Bypass checking
	string::operator=(s);
	isPattern_ = true;
	return *this;
}


inline const tnbLib::keyType& tnbLib::keyType::operator=(const char* s)
{
	// Bypass checking
	string::operator=(s);
	isPattern_ = false;
	return *this;
}