#pragma once
#ifndef _DLPtrList_Header
#define _DLPtrList_Header

#include <LPtrList.hxx>
#include <DLListBase.hxx>

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class DLPtrList Declaration
\*---------------------------------------------------------------------------*/

	template<class T>
	class DLPtrList
		: public LPtrList<DLListBase, T>
	{

	public:

		// Constructors

			//- Null construct
		DLPtrList()
		{}

		//- Construct given initial T
		DLPtrList(T a)
			: LPtrList<DLListBase, T>(a)
		{}

		//- Construct from Istream using given Istream constructor class
		template<class INew>
		DLPtrList(Istream& is, const INew& inewt)
			: LPtrList<DLListBase, T>(is, inewt)
		{}

		//- Construct from Istream
		DLPtrList(Istream& is)
			: LPtrList<DLListBase, T>(is)
		{}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_DLPtrList_Header
