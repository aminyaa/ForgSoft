#pragma once
#ifndef _regIOobject_Header
#define _regIOobject_Header

#include <IOobject.hxx>
#include <optimisationSwitch.hxx>

namespace AutLib
{

	class regIOobject
		: public IOobject
	{

		// Private data

		//- Is this object registered with the registry
		bool registered_;

		//- Is this object owned by the registry
		bool ownedByRegistry_;

		//- Time of last modification
		mutable time_t lastModified_;

		//- eventNo of last update
		label eventNo_;

		//- Istream for reading
		Istream* isPtr_;


		// Private member functions

		//- Return Istream
		Istream& readStream();

		//- Dissallow assignment
		void operator=(const regIOobject&) = delete;

	public:

		// Static data

		//- Runtime type information
		static const char* typeName_() { return "regIOobject"; }

		static const word typeName;
		static debug::debugSwitch debug;;

		virtual const word& type() const { return typeName; };

		//- File modification skew
		static const debug::optimisationSwitch fileModificationSkew;


		// Constructors

		//- Construct from IOobject. Optional flag for if IOobject is the
		//  top level regIOobject.
		regIOobject(const IOobject&, const bool isTime = false);

		//- Construct as copy
		regIOobject(const regIOobject&);

		//- Construct as copy, and transferring registry registration to copy
		//  if registerCopy is true
		regIOobject(const regIOobject&, bool registerCopy);


		// Destructor

		virtual ~regIOobject();


		// Member functions

		// Registration

		//- Add object to registry
		bool checkIn();

		//- Remove object from registry
		bool checkOut();

		//- Is this object owned by the registry?
		bool ownedByRegistry() const;

		//- Transfer ownership of this object to its registry
		void store();

		//- Transfer ownership of the given object pointer to its registry
		//  and return reference to object.
		template<class Type>
		static Type& store(Type*);

		//- Transfer ownership of the given object pointer to its registry
		//  and return reference to object.
		template<class Type>
		static Type& store(autoPtr<Type>&);

		//- Release ownership of this object from its registry
		void release();


		// Dependency checking

		//- Event number at last update.
		label eventNo() const;

		//- Event number at last update.
		label& eventNo();

		//- Am I uptodate with respect to other regIOobjects
		bool upToDate(const word&) const;
		bool upToDate(const word&, const word&) const;
		bool upToDate(const word&, const word&, const word&) const;
		bool upToDate
		(
			const word&,
			const word&,
			const word&,
			const word&
		) const;

		//- Flag me as up to date
		void setUpToDate();


		// Edit

		//- Rename
		virtual void rename(const word& newName);


		// Reading

		//- Return Istream and check object type against that given
		Istream& readStream(const word&);

		//- Close Istream
		void close();

		//- Virtual readData function.
		//  Must be defined in derived types for which
		//  re-reading is required
		virtual bool readData(Istream&);

		//- Read object
		virtual bool read();

		//- Return true if the object's file has been modified
		virtual bool modified() const;

		//- Read object if modified
		virtual bool readIfModified();


		// Writing

		//- Pure virtual writaData function.
		//  Must be defined in derived types
		virtual bool writeData(Ostream&) const = 0;

		//- Write using given format, version and compression
		virtual bool writeObject
		(
			IOstream::streamFormat,
			IOstream::versionNumber,
			IOstream::compressionType
		) const;

		//- Write using setting from DB
		virtual bool write() const;


		// Member operators

		void operator=(const IOobject&);
	};
}

#include <regIOobjectI.hxx>

#endif // !_regIOobject_Header
