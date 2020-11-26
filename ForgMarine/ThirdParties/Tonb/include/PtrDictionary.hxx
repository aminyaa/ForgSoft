#pragma once
#ifndef _PtrDictionary_Header
#define _PtrDictionary_Header

#include <DictionaryBase.hxx>
#include <DLPtrList.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class PtrDictionary Declaration
	\*---------------------------------------------------------------------------*/

	template<class T>
	class PtrDictionary
		: public DictionaryBase<DLPtrList<T>, T>
	{

	public:

		// Constructors

			//- Null constructor
		PtrDictionary();

		//- Copy construct
		PtrDictionary(const PtrDictionary&);

		//- Construct from Istream using given Istream constructor class
		template<class INew>
		PtrDictionary(Istream&, const INew&);

		//- Construct from Istream
		PtrDictionary(Istream&);
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#ifdef NoRepository
#   include <PtrDictionary.cxx>
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_PtrDictionary_Header
