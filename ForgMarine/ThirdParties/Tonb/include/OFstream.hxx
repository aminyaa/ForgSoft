#pragma once
#ifndef _OFstream_Header
#define _OFstream_Header

#include <OSstream.hxx>
#include <fileName.hxx>
#include <className.hxx>

#include <fstream>
using std::ofstream;

namespace tnbLib
{

	class OFstream;

	/*---------------------------------------------------------------------------*\
						   Class OFstreamAllocator Declaration
	\*---------------------------------------------------------------------------*/

	//- A std::ostream with ability to handle compressed files
	class OFstreamAllocator
	{
		friend class OFstream;

		ostream* ofPtr_;

		// Constructors

			//- Construct from pathname
		OFstreamAllocator
		(
			const fileName& pathname,
			ios_base::openmode mode,
			IOstream::compressionType compression = IOstream::UNCOMPRESSED

		);

		// Destructor

		~OFstreamAllocator();


	public:

		// Member functions

			//- Access to underlying std::ostream
		ostream& stdStream();
	};


	/*---------------------------------------------------------------------------*\
							   Class OFstream Declaration
	\*---------------------------------------------------------------------------*/

	class OFstream
		: private OFstreamAllocator
		, public OSstream
	{
		// Private data

		fileName pathname_;


	public:

		// Declare name of the class and its debug switch
		ClassName("OFstream");


		// Constructors

			//- Construct from pathname
		OFstream
		(
			const fileName& pathname,
			ios_base::openmode mode = ios_base::out | ios_base::trunc,
			streamFormat format = ASCII,
			versionNumber version = currentVersion,
			compressionType compression = UNCOMPRESSED
		);


		// Destructor

		~OFstream();


		// Member functions

			// Access

				//- Return the name of the stream
		const fileName& name() const
		{
			return pathname_;
		}

		//- Return non-const access to the name of the stream
		fileName& name()
		{
			return pathname_;
		}


		// Print

			//- Print description of IOstream to Ostream
		void print(Ostream&) const;
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
	// Global predefined null output stream

	extern OFstream Snull;

	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_OFstream_Header
