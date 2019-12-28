#pragma once
#ifndef _Mesh_Node_Header
#define _Mesh_Node_Header

#include <Mesh_Entity.hxx>
#include <Mesh_NodeAdaptor.hxx>

#include <memory>

namespace AutLib
{

	template<class NodeTraits>
	class Mesh_Node
		: public Mesh_Entity
		, public Mesh_NodeAdaptor
		<
		typename NodeTraits::edgeType,
		typename NodeTraits::elementType,
		typename NodeTraits::facetType
		>
	{

		typedef typename NodeTraits::ptType Point;

		/*Private Data*/

		Point theCoord_;

	public:

		typedef Point ptType;

		enum
		{
			rank = 0
		};

		static const std::shared_ptr<Mesh_Node> null_ptr;

		Mesh_Node()
		{}

		Mesh_Node
		(
			const Standard_Integer theIndex
		)
			: Mesh_Entity(theIndex)
		{}

		Mesh_Node
		(
			const Standard_Integer theIndex,
			const Point& theCoord
		)
			: Mesh_Entity(theIndex)
			, theCoord_(theCoord)
		{}

		const Point& Coord() const
		{
			return theCoord_;
		}

		Point& Coord()
		{
			return theCoord_;
		}

		void SetCoord(const Point& theCoord)
		{
			theCoord_ = theCoord;
		}


		//- Static functions and operators

		static Standard_Boolean IsLess
		(
			const std::shared_ptr<Mesh_Node>& theNode0,
			const std::shared_ptr<Mesh_Node>& theNode1
		)
		{
			Debug_Null_Pointer(theNode0);
			Debug_Null_Pointer(theNode1);

			return theNode0->Index() < theNode1->Index();
		}
	};
}

#endif // !_Mesh_Node_Header