#pragma once
#ifndef _DLList_Header
#define _DLList_Header

#include <LList.hxx>
#include <DLListBase.hxx>

namespace AutLib
{

	template<class T>
	class DLList
		: public LList<DLListBase, T>
	{

	public:

		// Constructors

		//- Null construct
		DLList()
		{}

		//- Construct given initial T
		DLList(T a)
			: LList<DLListBase, T>(a)
		{}

		//- Construct from Istream
		DLList(Istream& is)
			: LList<DLListBase, T>(is)
		{}
	};
}

#endif // !_DLList_Header
