#pragma once
#ifndef _char_Header
#define _char_Header

namespace AutLib
{

	class Istream;
	class Ostream;

	char readChar(Istream&);

	Istream& operator>>(Istream&, char&);

	Ostream& operator<<(Ostream&, const char);

	Ostream& operator<<(Ostream&, const char*);

	inline bool isspace(char c)
	{
		return
			(
				c == ' '
				|| c == '\n'
				|| c == '\r'
				|| c == '\t'
				);
	}
}

#endif // !_char_Header
