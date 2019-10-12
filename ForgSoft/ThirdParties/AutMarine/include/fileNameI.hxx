#pragma once
inline 
void AutLib::fileName::stripInvalid()
{
	if (debug && string::stripInvalid<fileName>(*this))
	{
		std::cerr
			<< "fileName::stripInvalid() called for invalid fileName "
			<< this->c_str() << std::endl;

		if (debug > 1)
		{
			std::cerr
				<< "    For debug level (= " << debug
				<< ") > 1 this is considered fatal" << std::endl;
			std::abort();
		}

		removeRepeated('/');
		removeTrailing('/');
	}
}

inline
AutLib::fileName::fileName()
	: string()
{}

inline 
AutLib::fileName::fileName(const fileName& fn)
	: string(fn)
{}

inline 
AutLib::fileName::fileName(const word& w)
	: string(w)
{}


inline 
AutLib::fileName::fileName(const string& str)
	: string(str)
{
	stripInvalid();
}


inline 
AutLib::fileName::fileName(const std::string& str)
	: string(str)
{
	stripInvalid();
}


inline 
AutLib::fileName::fileName(const char* str)
	: string(str)
{
	stripInvalid();
}

inline 
bool AutLib::fileName::valid(char c)
{
	return
		(
			!isspace(c)
			&& c != '"'   // string quote
			&& c != '\''  // string quote
			);
}