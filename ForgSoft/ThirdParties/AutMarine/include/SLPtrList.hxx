#pragma once
#ifndef _SLPtrList_Header
#define _SLPtrList_Header

#include <LPtrList.hxx>
#include <SLListBase.hxx>

namespace AutLib
{

	template<class T>
	class SLPtrList
		: public LPtrList<SLListBase, T>
	{

	public:

		// Constructors

		//- Null construct
		SLPtrList()
		{}

		//- Construct given initial T*
		SLPtrList(T* a)
			: LPtrList<SLListBase, T>(a)
		{}

		//- Construct from Istream using given Istream constructor class
		template<class INew>
		SLPtrList(Istream& is, const INew& inewt)
			: LPtrList<SLListBase, T>(is, inewt)
		{}

		//- Construct from Istream
		SLPtrList(Istream& is)
			: LPtrList<SLListBase, T>(is)
		{}
	};
}

#endif // !_SLPtrList_Header
