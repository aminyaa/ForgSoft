#pragma once
#ifndef _Cad2d_SubEntity_VertexAdaptor_Header
#define _Cad2d_SubEntity_VertexAdaptor_Header

#include <Standard_TypeDef.hxx>

#include <memory>
#include <map>

namespace tnbLib
{

	// Forward Declarations
	class Cad2d_SubEntity_Edge;
	class Cad2d_SubEntity_Vertex;

	class Cad2d_SubEntity_VertexAdaptor
	{

		/*Private Data*/

		std::map<Standard_Integer, std::weak_ptr<Cad2d_SubEntity_Edge>>
			theEdges_;

		std::weak_ptr<Cad2d_SubEntity_Vertex> thePair_;

	protected:

		Cad2d_SubEntity_VertexAdaptor()
		{}

	public:

		Standard_Integer NbEdges() const;

		const auto& Edges() const
		{
			return theEdges_;
		}

		const auto& Pair() const
		{
			return thePair_;
		}

		void InsertToEdges(const Standard_Integer theIndex, const std::weak_ptr<Cad2d_SubEntity_Edge>& theEdge);

		void RemoveFromEdges(const Standard_Integer theIndex);

		void SetPair(const std::weak_ptr<Cad2d_SubEntity_Vertex>& thePair)
		{
			thePair_ = thePair;
		}
	};
}

#endif // !_Cad2d_SubEntity_VertexAdaptor_Header

