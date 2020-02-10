#pragma once
#ifndef _UDictionary_Header
#define _UDictionary_Header

#include <DictionaryBase.hxx>
#include <UIDLList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class UDictionary Declaration
	\*---------------------------------------------------------------------------*/

	template<class T>
	class UDictionary
		: public DictionaryBase<UIDLList<T>, T>
	{

	public:

		// Constructors

			//- Null constructor
		UDictionary();

		//- Copy construct
		UDictionary(const UDictionary&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <UDictionary.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_UDictionary_Header
