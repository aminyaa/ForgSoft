#pragma once
#ifndef _Cad2d_SubEntity_TangEdge_Header
#define _Cad2d_SubEntity_TangEdge_Header

#include <Cad2d_SubEntity_Edge.hxx>

namespace tnbLib
{

	class Cad2d_SubEntity_TangEdge
		: public Cad2d_SubEntity_Edge
	{

		/*private Data*/

		std::weak_ptr<Cad2d_SubEntity_TangEdge> thePair_;

	public:

		Cad2d_SubEntity_TangEdge();

		Cad2d_SubEntity_TangEdge(const Standard_Integer theIndex);

		Cad2d_SubEntity_TangEdge(const Standard_Integer theIndex, const word& theName);

		const auto& Pair() const
		{
			return thePair_;
		}

		void SetPair(const std::weak_ptr<Cad2d_SubEntity_TangEdge>& thePair)
		{
			thePair_ = thePair;
		}
	};
}

#endif // !_Cad2d_SubEntity_TangEdge_Header
