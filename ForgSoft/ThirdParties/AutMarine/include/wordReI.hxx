#pragma once
inline 
bool AutLib::wordRe::meta(char c)
{
	return regExp::meta(c);
}


inline 
bool AutLib::wordRe::isPattern(const string& str)
{
	return string::meta<regExp>(str);
}

inline AutLib::wordRe::wordRe()
	: word()
	, re_()
{}


inline AutLib::wordRe::wordRe(const wordRe& str)
	: word(str)
	, re_()
{
	if (str.isPattern())
	{
		compile();
	}
}


inline 
AutLib::wordRe::wordRe(const word& str)
	: word(str)
	, re_()
{}


inline 
AutLib::wordRe::wordRe(const char* str, const compOption opt)
	: word(str, false)
	, re_()
{
	compile(opt);
}


inline
AutLib::wordRe::wordRe(const string& str, const compOption opt)
	: word(str, false)
	, re_()
{
	compile(opt);
}


inline 
AutLib::wordRe::wordRe(const std::string& str, const compOption opt)
	: word(str, false)
	, re_()
{
	compile(opt);
}

inline 
bool AutLib::wordRe::isPattern() const
{
	return re_.exists();
}


inline 
bool AutLib::wordRe::compile(const compOption opt) const
{
	bool doCompile = false;

	if (opt & wordRe::REGEXP)
	{
		doCompile = true;
	}
	else if (opt & wordRe::DETECT)
	{
		if (string::meta<regExp>(*this) || !string::valid<word>(*this))
		{
			doCompile = true;
		}
	}
	else if (opt & wordRe::NOCASE)
	{
		doCompile = true;
	}


	if (doCompile)
	{
		re_.set(*this, (opt & wordRe::NOCASE));
	}
	else
	{
		re_.clear();
	}

	return re_.exists();
}


inline
bool AutLib::wordRe::compile() const
{
	re_ = *this;
	return re_.exists();
}


inline 
bool AutLib::wordRe::recompile() const
{
	if (re_.exists())
	{
		re_ = *this;
	}

	return re_.exists();
}


inline 
void AutLib::wordRe::uncompile(const bool doStripInvalid) const
{
	if (re_.clear())
	{
		// skip stripping unless debug is active to avoid costly operations
		if (word::debug && doStripInvalid)
		{
			string::stripInvalid<word>
				(
					const_cast<word&>(static_cast<const word&>(*this))
					);
		}
	}
}


inline 
void AutLib::wordRe::clear()
{
	word::clear();
	re_.clear();
}


inline 
bool AutLib::wordRe::match(const string& str, bool literalMatch) const
{
	if (literalMatch || !re_.exists())
	{
		// check as string
		return (*this == str);
	}
	else
	{
		// check as regex
		return re_.match(str);
	}
}


inline 
AutLib::string AutLib::wordRe::quotemeta() const
{
	return string::quotemeta<regExp>(*this);
}


inline 
void AutLib::wordRe::set(const std::string& str, const compOption opt)
{
	string::operator=(str);
	compile(opt);
}


inline 
void AutLib::wordRe::set(const char* str, const compOption opt)
{
	string::operator=(str);
	compile(opt);
}

inline 
const AutLib::wordRe& AutLib::wordRe::operator=(const wordRe& str)
{
	string::operator=(str);

	if (str.isPattern())
	{
		compile();
	}
	else
	{
		re_.clear();
	}
	return *this;
}


inline 
const AutLib::wordRe& AutLib::wordRe::operator=(const word& str)
{
	word::operator=(str);
	re_.clear();
	return *this;
}


inline 
const AutLib::wordRe& AutLib::wordRe::operator=(const string& str)
{
	string::operator=(str);
	compile(DETECT);  // auto-detect regex
	return *this;
}


inline 
const AutLib::wordRe& AutLib::wordRe::operator=(const std::string& str)
{
	string::operator=(str);
	compile(DETECT);  // auto-detect regex
	return *this;
}


inline 
const AutLib::wordRe& AutLib::wordRe::operator=(const char* str)
{
	string::operator=(str);
	compile(DETECT);  // auto-detect regex
	return *this;
}