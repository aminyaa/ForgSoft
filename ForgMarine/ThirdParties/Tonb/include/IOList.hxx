#pragma once
#ifndef _IOList_Header
#define _IOList_Header

#include <List.hxx>
#include <regIOobject.hxx>

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class IOList Declaration
\*---------------------------------------------------------------------------*/

	template<class T>
	class IOList
		: public regIOobject
		, public List<T>
	{

	public:

		//- Runtime type information
		TypeName("List");


		// Constructors

			//- Construct from IOobject
		IOList(const IOobject&);

		//- Construct from IOobject and size of IOList
		IOList(const IOobject&, const label);

		//- Construct from IOobject and a List
		IOList(const IOobject&, const List<T>&);

		//- Construct by transferring the List contents
		IOList(const IOobject&, const Xfer<List<T>>&);


		// Destructor

		virtual ~IOList();


		// Member functions

		bool writeData(Ostream&) const;


		// Member operators

		void operator=(const IOList<T>&);

		void operator=(const List<T>&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#include <IOListI.hxx>

#ifdef NoRepository
#   include <IOList.cxx>
#endif

#endif // !_IOList_Header
