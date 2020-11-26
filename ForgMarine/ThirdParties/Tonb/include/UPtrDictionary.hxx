#pragma once
#ifndef _UPtrDictionary_Header
#define _UPtrDictionary_Header

#include <DictionaryBase.hxx>
#include <DLList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class UPtrDictionary Declaration
	\*---------------------------------------------------------------------------*/

	template<class T>
	class UPtrDictionary
		: public DictionaryBase<DLList<T*>, T>
	{

	public:

		// Constructors

			//- Null constructor
		UPtrDictionary();

		//- Copy construct
		UPtrDictionary(const UPtrDictionary&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <UPtrDictionary.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_UPtrDictionary_Header
