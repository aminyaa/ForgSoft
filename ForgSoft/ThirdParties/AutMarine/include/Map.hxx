#pragma once
#ifndef _Map_Header
#define _Map_Header

#include <HashTable.hxx>
#include <Hash.hxx>

namespace AutLib
{

	template<class T>
	class Map
		: public HashTable<T, label, Hash<label> >
	{

	public:

		typedef typename HashTable<T, label, Hash<label> >::iterator iterator;

		typedef typename HashTable<T, label, Hash<label> >::const_iterator
			const_iterator;

		// Constructors

		//- Construct given initial size
		Map(const label size = 128)
			: HashTable<T, label, Hash<label> >(size)
		{}

		//- Construct from Istream
		Map(Istream& is)
			: HashTable<T, label, Hash<label> >(is)
		{}

		//- Construct as copy
		Map(const Map<T>& map)
			: HashTable<T, label, Hash<label> >(map)
		{}

		//- Construct by transferring the parameter contents
		Map(const Xfer<Map<T> >& map)
			: HashTable<T, label, Hash<label> >(map)
		{}

		//- Construct by transferring the parameter contents
		Map(const Xfer<HashTable<T, label, Hash<label> > >& map)
			: HashTable<T, label, Hash<label> >(map)
		{}

	};
}

#endif // !_Map_Header
