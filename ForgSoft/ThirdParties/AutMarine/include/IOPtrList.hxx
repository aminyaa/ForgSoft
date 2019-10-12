#pragma once
#ifndef _IOPtrList_Header
#define _IOPtrList_Header

#include <PtrList.hxx>
#include <regIOobject.hxx>

namespace AutLib
{

	template<class T>
	class IOPtrList
		: public regIOobject
		, public PtrList<T>
	{

	public:

		//- Runtime type information
		static const char* typeName_() { return "PtrList"; }

		static const word typeName;
		static debug::debugSwitch debug;;

		virtual const word& type() const { return typeName; };


		// Constructors

		//- Construct from IOobject using given Istream constructor class
		template<class INew>
		IOPtrList(const IOobject&, const INew&);

		//- Construct from IOobject
		IOPtrList(const IOobject&);

		//- Construct from IOobject with given size
		IOPtrList(const IOobject&, const label);

		//- Construct from IOobject and a PtrList
		IOPtrList(const IOobject&, const PtrList<T>&);

		//- Construct by transferring the PtrList contents
		IOPtrList(const IOobject&, const Xfer<PtrList<T> >&);


		// Destructor

		virtual ~IOPtrList();


		// Member functions

		bool writeData(Ostream&) const;


		// Member operators

		void operator=(const IOPtrList<T>&);
	};
}

#include <IOPtrListI.hxx>

#endif // !_IOPtrList_Header
