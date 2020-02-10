#pragma once
#ifndef _UIDLList_Header
#define _UIDLList_Header

#include <UILList.hxx>
#include <DLListBase.hxx>

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class UIDLList Declaration
\*---------------------------------------------------------------------------*/

	template<class T>
	class UIDLList
		: public UILList<DLListBase, T>
	{

	public:

		// Constructors

			//- Null construct
		UIDLList()
		{}

		//- Construct given initial T
		UIDLList(T a)
			: UILList<DLListBase, T>(a)
		{}

		//- Construct from Istream
		UIDLList(Istream& is)
			: UILList<DLListBase, T>(is)
		{}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_UIDLList_Header
