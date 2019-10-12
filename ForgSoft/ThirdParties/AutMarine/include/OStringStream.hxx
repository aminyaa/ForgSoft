#pragma once
#ifndef _OStringStream_Header
#define _OStringStream_Header

#include <OSstream.hxx>
#include <sstream>

namespace AutLib
{

	class OStringStream
		: public OSstream
	{

	public:

		// Constructors

		//- Construct and set stream status
		OStringStream
		(
			streamFormat format = ASCII,
			versionNumber version = currentVersion
		)
			: OSstream
			(
				*(new std::ostringstream()),
				"OStringStream.sinkFile",
				format,
				version
			)
		{}

		//- Construct as copy
		OStringStream(const OStringStream& oss)
			: OSstream
			(
				*(new std::ostringstream(dynamic_cast<const std::ostringstream&>(oss.stream()).str())),
				oss.name(),
				oss.format(),
				oss.version()
			)
		{}


		// Destructor

		~OStringStream()
		{
			delete &dynamic_cast<std::ostringstream&>(stream());
		}


		// Member functions

		// Access

		//- Return the string
		string str() const
		{
			return dynamic_cast<const std::ostringstream&>(stream()).str();
		}


		// Edit

		//- Clear the OStringStream
		void rewind()
		{
#               if __GNUC__ < 4 && __GNUC_MINOR__ < 4
			stream().rdbuf()->pubsetbuf((char*)" ", 1);
#               else
			stream().rdbuf()->pubseekpos(0);
#               endif
		}


		// Print

		//- Print description to Ostream
		void print(Ostream&) const;
	};
}

#endif // !_OStringStream_Header
