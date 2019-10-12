#pragma once
#ifndef _pTraits_Header
#define _pTraits_Header

namespace AutLib
{
	class Istream;

	template<class PrimitiveType>
	class pTraits
		: public PrimitiveType
	{

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
