#pragma once
#ifndef _Mesh_BndNode_Header
#define _Mesh_BndNode_Header

#include <Standard_TypeDef.hxx>

namespace AutLib
{

	template<class NodeType, class GeomAdaptor>
	class Mesh_BndNode
		: public NodeType
		, public GeomAdaptor
	{

		typedef typename NodeType::ptType Point;

		/*Private Data*/

	public:

		Mesh_BndNode()
		{}

		Mesh_BndNode
		(
			const Standard_Integer theIndex,
			const Point& theCoord
		)
			: NodeType(theIndex, theCoord)
		{}
	};
}

#endif // !_Mesh_BndNode_Header