#pragma once
#ifndef _EdgeMap_Header
#define _EdgeMap_Header

#include <HashTable.hxx>
#include <edge.hxx>

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
							   Class EdgeMap Declaration
	\*---------------------------------------------------------------------------*/

	template<class T>
	class EdgeMap
		: public HashTable<T, edge, Hash<edge> >
	{

	public:

		// Constructors

			//- Construct given initial map size
		EdgeMap(const label size = 128)
			:
			HashTable<T, edge, Hash<edge> >(size)
		{}

		//- Construct from Istream
		EdgeMap(Istream& is)
			:
			HashTable<T, edge, Hash<edge> >(is)
		{}

		//- Construct as copy
		EdgeMap(const EdgeMap<T>& map)
			:
			HashTable<T, edge, Hash<edge> >(map)
		{}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace tnbLib

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif // !_EdgeMap_Header
