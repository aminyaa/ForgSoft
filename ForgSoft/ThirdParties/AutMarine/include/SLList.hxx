#pragma once
#ifndef _SLList_Header
#define _SLList_Header

#include <LList.hxx>
#include <SLListBase.hxx>

namespace AutLib
{

	template<class T>
	class SLList
		: public LList<SLListBase, T>
	{

	public:

		// Constructors

		//- Null construct
		SLList()
		{}

		//- Construct given initial T
		explicit SLList(T a)
			: LList<SLListBase, T>(a)
		{}

		//- Construct from Istream
		explicit SLList(Istream& is)
			: LList<SLListBase, T>(is)
		{}
	};
}

#endif // !_SLList_Header
