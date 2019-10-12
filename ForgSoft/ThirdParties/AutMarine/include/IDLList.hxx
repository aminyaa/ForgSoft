#pragma once
#ifndef _IDLList_Header
#define _IDLList_Header

#include <ILList.hxx>
#include <DLListBase.hxx>

namespace AutLib
{

	template<class T>
	class IDLList
		: public ILList<DLListBase, T>
	{

	public:

		// Constructors

		//- Null construct
		IDLList()
		{}

		//- Construct given initial T
		IDLList(const T& a)
			: ILList<DLListBase, T>(a)
		{}

		//- Construct from Istream using given Istream constructor class
		template<class INew>
		IDLList(Istream& is, const INew& inewt)
			: ILList<DLListBase, T>(is, inewt)
		{}

		//- Construct from Istream
		IDLList(Istream& is)
			: ILList<DLListBase, T>(is)
		{}

		//- Copy constructor with additional argument for clone
		template<class CloneArg>
		IDLList(const IDLList<T>& idll, const CloneArg& cloneArg)
			: ILList<DLListBase, T>(idll, cloneArg)
		{}
	};
}

#endif // !_IDLList_Header
