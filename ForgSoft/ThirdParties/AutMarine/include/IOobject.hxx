#pragma once
#ifndef _IOobject_Header
#define _IOobject_Header

#include <fileName.hxx>
#include <autoPtr.hxx>

namespace AutLib
{

	class objectRegistry;
	class Time;

	class IOobject
	{

	public:

		// Public data types

		//- Enumeration defining the valid states of an IOobject
		enum objectState
		{
			GOOD,
			BAD
		};

		//- Enumeration defining the read options
		enum readOption
		{
			MUST_READ,
			READ_IF_PRESENT,
			NO_READ
		};

		//- Enumeration defining the write options
		enum writeOption
		{
			AUTO_WRITE = 0,
			NO_WRITE = 1
		};

	private:

		// Private data

		//- Name
		word name_;

		//- Class name read from header
		word headerClassName_;

		//- Optional note
		string note_;

		//- Instance path component
		fileName instance_;

		//- Local path component
		fileName local_;

		//- objectRegistry reference
		const objectRegistry& db_;

		//- Read option
		readOption rOpt_;

		//- Write option
		writeOption wOpt_;

		//- Register object created from this IOobject with registry if true
		bool registerObject_;

		//- IOobject state
		objectState objState_;

	protected:

		// Protected member functions

		//- Construct and return an IFstream for the object.
		//  The results is NULL if the stream construction failed
		Istream* objectStream();

		//- Set the object state to bad
		void setBad(const string&);

	public:

		//- Runtime type information
		static const char* typeName_() { return "IOobject"; }
		static const word typeName;
		static debug::debugSwitch debug;;
		virtual const word& type() const { return typeName; };


		// Static Member Functions

		//- Split path into instance, local, name components
		static bool fileNameComponents
		(
			const fileName& path,
			fileName& instance,
			fileName& local,
			word& name
		);


		// Constructors

		//- Construct from name, instance, registry, io options
		IOobject
		(
			const word& name,
			const Time& registry,
			readOption r = NO_READ,
			writeOption w = NO_WRITE
		);

		//- Construct from name, instance, registry, io options
		IOobject
		(
			const word& name,
			const fileName& instance,
			const objectRegistry& registry,
			readOption r = NO_READ,
			writeOption w = NO_WRITE,
			bool registerObject = true
		);

		//- Construct from name, instance, local, registry, io options
		IOobject
		(
			const word& name,
			const fileName& instance,
			const fileName& local,
			const objectRegistry& registry,
			readOption r = NO_READ,
			writeOption w = NO_WRITE,
			bool registerObject = true
		);

		//- Construct from path, registry, io options
		//  Uses fileNameComponents() to split path into components.
		IOobject
		(
			const fileName& path,
			const objectRegistry& registry,
			readOption r = NO_READ,
			writeOption w = NO_WRITE,
			bool registerObject = true
		);

		//- Clone
		autoPtr<IOobject> clone() const
		{
			return autoPtr<IOobject>(new IOobject(*this));
		}


		// Destructor

		virtual ~IOobject();


		// Member Functions

		// General access

		//- Return time
		const Time& time() const;

		//- Return the local objectRegistry
		const objectRegistry& db() const;

		//- Return name
		const word& name() const
		{
			return name_;
		}

		//- Return name of the class name read from header
		const word& headerClassName() const
		{
			return headerClassName_;
		}

		//- Return non-constant access to the optional note
		string& note()
		{
			return note_;
		}

		//- Return the optional note
		const string& note() const
		{
			return note_;
		}

		//- Rename
		virtual void rename(const word& newName)
		{
			name_ = newName;
		}

		//- Register object created from this IOobject with registry
		//  if true
		bool registerObject() const
		{
			return registerObject_;
		}


		// Read/write options

		readOption readOpt() const
		{
			return rOpt_;
		}

		readOption& readOpt()
		{
			return rOpt_;
		}

		writeOption writeOpt() const
		{
			return wOpt_;
		}

		writeOption& writeOpt()
		{
			return wOpt_;
		}


		// Path components

		const fileName& rootPath() const;

		const fileName& caseName() const;

		const fileName& instance() const
		{
			return instance_;
		}

		fileName& instance()
		{
			return instance_;
		}

		const fileName& local() const
		{
			return local_;
		}

		//- Return complete path
		fileName path() const;

		//- Return complete path with alternative instance and local
		fileName path
		(
			const word& instance,
			const fileName& local = ""
		) const;

		//- Return complete path + object name
		fileName objectPath() const
		{
			return path() / name();
		}

		//- Return complete path + object name if the file exists
		//  either in the case/processor or case otherwise null
		fileName filePath() const;


		// Reading

		//- Read header
		bool readHeader(Istream&);

		//- Read and check header info
		bool headerOk();


		// Writing

		//- Write the standard FOAM file/dictionary banner
		//  Optionally without -*- C++ -*- editor hint (eg, for logs)
		template<class Stream>
		static inline Stream& writeBanner
		(
			Stream& os,
			bool noHint = false,
			bool noCopyRight = false
		);

		//- Write the standard file section divider
		template<class Stream>
		static inline Stream& writeDivider(Stream& os);

		//- Write the standard end file divider
		template<class Stream>
		static inline Stream& writeEndDivider(Stream& os);

		//- Write header
		bool writeHeader(Ostream&) const;


		// Error Handling

		bool good() const
		{
			return objState_ == GOOD;
		}

		bool bad() const
		{
			return objState_ == BAD;
		}


		// Info

		//- Return info proxy.
		//  Used to print token information to a stream
		InfoProxy<IOobject> info() const
		{
			return *this;
		}


		// Member operators

		void operator=(const IOobject&);
	};

	Ostream& operator<<(Ostream& os, const InfoProxy<IOobject>& ip);
}

#include <IOobjectI.hxx>

#endif // !_IOobject_Header
