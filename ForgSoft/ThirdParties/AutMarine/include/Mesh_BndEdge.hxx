#pragma once
#ifndef _Mesh_BndEdge_Header
#define _Mesh_BndEdge_Header

#include <Standard_TypeDef.hxx>

#include <memory>

namespace AutLib
{

	template<class EdgeType, class GeomAdaptor>
	class Mesh_BndEdge
		: public EdgeType
		, public GeomAdaptor
	{

		/*Private Data*/

	public:

		typedef typename EdgeType::nodeType nodeType;

		Mesh_BndEdge()
		{}

		Mesh_BndEdge
		(
			const Standard_Integer theIndex
		)
			: EdgeType(theIndex)
		{}

		Mesh_BndEdge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<nodeType>& theNode0,
			const std::shared_ptr<nodeType>& theNode1
		)
			: EdgeType(theIndex, theNode0, theNode1)
		{}
	};
}

#endif // !_Mesh_BndEdge_Header