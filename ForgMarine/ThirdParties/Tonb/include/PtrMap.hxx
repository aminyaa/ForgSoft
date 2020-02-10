#pragma once
#ifndef _PtrMap_Header
#define _PtrMap_Header

#include <HashPtrTable.hxx>

namespace tnbLib
{

	/*---------------------------------------------------------------------------*\
						   Class PtrMap Declaration
\*---------------------------------------------------------------------------*/

	template<class T>
	class PtrMap
		: public HashPtrTable<T, label, Hash<label>>
	{

	public:

		// Constructors

			//- Construct given initial map size
		PtrMap(const label size = 128)
			: HashPtrTable<T, label, Hash<label>>(size)
		{}

		//- Construct from Istream
		PtrMap(Istream& is)
			: HashPtrTable<T, label, Hash<label>>(is)
		{}

		//- Construct as copy
		PtrMap(const PtrMap<T>& map)
			: HashPtrTable<T, label, Hash<label>>(map)
		{}
	};


	// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
}

#endif // !_PtrMap_Header
