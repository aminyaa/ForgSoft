#pragma once
#ifndef _DictionaryTemplate_Header
#define _DictionaryTemplate_Header

#include <DictionaryBase.hxx>
#include <IDLList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							 Class Dictionary Declaration
	\*---------------------------------------------------------------------------*/

	template<class T>
	class Dictionary
		: public DictionaryBase<IDLList<T>, T>
	{

	public:

		// Constructors

		//- Null constructor
		Dictionary();

		//- Copy construct
		Dictionary(const Dictionary&);


		// Member functions

		//- Remove an entry specified by keyword and delete the pointer.
		//  Returns true if the keyword was found
		bool erase(const word& keyword);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <DictionaryTemplate.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_DictionaryTemplate_Header
