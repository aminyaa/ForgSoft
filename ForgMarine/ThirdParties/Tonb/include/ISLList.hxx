#pragma once
#ifndef _ISLList_Header
#define _ISLList_Header

#include <ILList.hxx>
#include <SLListBase.hxx>

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class ISLList Declaration
\*---------------------------------------------------------------------------*/

	template<class T>
	class ISLList
		: public ILList<SLListBase, T>
	{

	public:

		// Constructors

			//- Null construct
		ISLList()
		{}

		//- Construct given initial T
		ISLList(const T& a)
			: ILList<SLListBase, T>(a)
		{}

		//- Construct from Istream using given Istream constructor class
		template<class INew>
		ISLList(Istream& is, const INew& inewt)
			: ILList<SLListBase, T>(is, inewt)
		{}

		//- Construct from Istream
		ISLList(Istream& is)
			: ILList<SLListBase, T>(is)
		{}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_ISLList_Header
