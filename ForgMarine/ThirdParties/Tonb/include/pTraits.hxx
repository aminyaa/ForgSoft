#pragma once
#ifndef _pTraits_Header
#define _pTraits_Header

namespace tnbLib
{

	// Forward Declarations
	class Istream;

	template<class PrimitiveType>
	class pTraits
		: public PrimitiveType
	{

		// Constructors

	public:

		pTraits(const PrimitiveType& p)
			: PrimitiveType(p)
		{}

		pTraits(Istream& is)
			: PrimitiveType(is)
		{}
	};
}

#endif // !_pTraits_Header
