#pragma once
#ifndef _Mesh_Element_Header
#define _Mesh_Element_Header

#include <Global_AccessMethod.hxx>
#include <Mesh_Entity.hxx>
#include <Mesh_ElementAdaptor.hxx>
#include <Mesh_ElementType.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <memory>

namespace AutLib
{

	template<class ElementTraits, Mesh_ElementType ElmType = Mesh_ElementType_Tetrahedron>
	class Mesh_Element
		: public Mesh_Entity
		, public Mesh_ElementAdaptor<typename ElementTraits::elementType, ElmType>
	{

	public:

		typedef typename ElementTraits::nodeType nodeType;
		typedef typename ElementTraits::edgeType edgeType;
		typedef typename ElementTraits::facetType facetType;
		typedef typename ElementTraits::elementType elementType;

		typedef typename ElementTraits::connectType connectType;
		typedef typename nodeType::ptType Point;

		typedef Mesh_ElementAdaptor<typename ElementTraits::elementType, ElmType> adaptor;

	private:

		/*Private Data*/

		std::shared_ptr<nodeType> theNodes_[4];

		std::shared_ptr<edgeType> theEdges_[6];
		std::shared_ptr<facetType> theFacets_[4];

	public:

		enum
		{
			nbNodes = 4
		};

		Mesh_Element()
		{}

		Mesh_Element
		(
			const Standard_Integer theIndex
		)
			: Mesh_Entity(theIndex)
		{}

		Mesh_Element
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<nodeType>& theNode0,
			const std::shared_ptr<nodeType>& theNode1,
			const std::shared_ptr<nodeType>& theNode2,
			const std::shared_ptr<nodeType>& theNode3
		)
			: Mesh_Entity(theIndex)
		{
			Node0() = theNode0;
			Node1() = theNode1;
			Node2() = theNode2;
			Node3() = theNode3;
		}

		Point Centre() const
		{
			Point pt = 
				(Node0()->Coord() + Node1()->Coord() + Node2()->Coord() + Node3()->Coord())
				/ (Standard_Real)4.0;
			return std::move(pt);
		}

		Standard_Integer OppositeVertexIndex
		(
			const std::shared_ptr<facetType>& theFace
		) const
		{
			Debug_Null_Pointer(theFace);
			for (int i = 0; i < 4; i++)
			{
				if (Face(i) == theFace)
				{
					return i;
				}
			}

			FatalErrorIn("Standard_Integer OppositeVertexIndex(const std::shared_ptr<facetType>& theFace) const")
				<< "Found no opposite vertex"
				<< abort(FatalError);

			return 0;
		}

		Standard_Integer OppositeVertexIndex
		(
			const std::shared_ptr<Mesh_Element>& theElement
		) const
		{
			Debug_Null_Pointer(theElement);
			for (int i = 0; i < 4; i++)
			{
				if (adaptor::Neighbor(i).lock() == theElement)
				{
					return i;
				}
			}

			FatalErrorIn("Standard_Integer OppositeVertexIndex(const std::shared_ptr<Mesh_Element>& theElement) const")
				<< "Found no opposite vertex"
				<< abort(FatalError);

			return 0;
		}

		const std::shared_ptr<nodeType>& OppositeVertex
		(
			const std::shared_ptr<edgeType>& theEdge
		) const
		{
			for (int i = 0; i < 4; i++)
			{
				if (Edge(i) == theEdge)
				{
					return this->Node(i);
				}
			}
			return nodeType::null_ptr;
		}

		const std::shared_ptr<nodeType>& OppositeVertex
		(
			const std::shared_ptr<elementType>& theElement
		) const
		{
			for (int i = 0; i < 4; i++)
			{
				if (adaptor::Neighbor(i).lock() == theElement)
				{
					return this->Node(i);
				}
			}
			return nodeType::null_ptr;
		}

		//- Static function and operators

		static Standard_Boolean
			IsLess
			(
				const std::shared_ptr<Mesh_Element>& theElement0,
				const std::shared_ptr<Mesh_Element>& theElement1
			)
		{
			Debug_Null_Pointer(theElement0);
			Debug_Null_Pointer(theElement1);

			return theElement0->Index() < theElement1->Index();
		}

		//- Marcos

		GLOBAL_ACCESS_VECTOR(std::shared_ptr<nodeType>, Node, 0)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<nodeType>, Node, 1)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<nodeType>, Node, 2)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<nodeType>, Node, 3)		

			GLOBAL_ACCESS_VECTOR(std::shared_ptr<edgeType>, Edge, 0)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<edgeType>, Edge, 1)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<edgeType>, Edge, 2)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<edgeType>, Edge, 3)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<edgeType>, Edge, 4)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<edgeType>, Edge, 5)		

			GLOBAL_ACCESS_VECTOR(std::shared_ptr<facetType>, Facet, 0)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<facetType>, Facet, 1)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<facetType>, Facet, 2)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<facetType>, Facet, 3)

			GLOBAL_ACCESS_VECTOR_INDEX(std::shared_ptr<nodeType>, Node)
			GLOBAL_ACCESS_VECTOR_INDEX(std::shared_ptr<edgeType>, Edge)
			GLOBAL_ACCESS_VECTOR_INDEX(std::shared_ptr<facetType>, Facet)
	};

	template<class ElementTraits>
	class Mesh_Element<ElementTraits, Mesh_ElementType_Triangle3D>
		: public Mesh_Entity
		, public Mesh_ElementAdaptor<typename ElementTraits::elementType, Mesh_ElementType_Triangle3D>
	{

	public:

		typedef typename ElementTraits::nodeType nodeType;
		typedef typename ElementTraits::edgeType edgeType;
		typedef typename ElementTraits::facetType facetType;
		typedef typename ElementTraits::elementType elementType;

		typedef typename ElementTraits::connectType connectType;

		typedef typename nodeType::ptType Point;

	private:

		/*Private Data*/

		std::shared_ptr<nodeType> theNodes_[3];

		std::shared_ptr<edgeType> theEdges_[3];

	public:

		enum
		{
			nbNodes = 3
		};

		Mesh_Element()
		{}

		Mesh_Element
		(
			const Standard_Integer theIndex
		)
			: Mesh_Entity(theIndex)
		{}

		Mesh_Element
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<nodeType>& theNode0,
			const std::shared_ptr<nodeType>& theNode1,
			const std::shared_ptr<nodeType>& theNode2
		)
			: Mesh_Entity(theIndex)
		{
			Node0() = theNode0;
			Node1() = theNode1;
			Node2() = theNode2;
		}

		Point Centre() const
		{
			Point pt = 
				(Node0()->Coord() + Node1()->Coord() + Node2()->Coord()) 
				/ (Standard_Real)3.0;
			return std::move(pt);
		}


		//- Static function and operators


		static Standard_Boolean
			IsLess
			(
				const std::shared_ptr<Mesh_Element>& theElement0,
				const std::shared_ptr<Mesh_Element>& theElement1
			)
		{
			Debug_Null_Pointer(theElement0);
			Debug_Null_Pointer(theElement1);

			return theElement0->Index() < theElement1->Index();
		}

		//- Marcos

		GLOBAL_ACCESS_VECTOR(std::shared_ptr<nodeType>, Node, 0)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<nodeType>, Node, 1)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<nodeType>, Node, 2)

			GLOBAL_ACCESS_VECTOR(std::shared_ptr<edgeType>, Edge, 0)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<edgeType>, Edge, 1)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<edgeType>, Edge, 2)

			GLOBAL_ACCESS_VECTOR_INDEX(std::shared_ptr<nodeType>, Node)
			GLOBAL_ACCESS_VECTOR_INDEX(std::shared_ptr<edgeType>, Edge)
	};


	template<class ElementTraits>
	class Mesh_Element<ElementTraits, Mesh_ElementType_Triangle2D>
		: public Mesh_Entity
		, public Mesh_ElementAdaptor<typename ElementTraits::elementType, Mesh_ElementType_Triangle2D>
	{

	public:

		typedef typename ElementTraits::nodeType nodeType;
		typedef typename ElementTraits::edgeType edgeType;
		typedef typename ElementTraits::facetType facetType;
		typedef typename ElementTraits::elementType elementType;

		typedef typename ElementTraits::connectType connectType;

		typedef typename nodeType::ptType Point;
		typedef Mesh_Element<ElementTraits, Mesh_ElementType_Triangle3D> base;

	private:

		/*Private Data*/

		std::shared_ptr<nodeType> theNodes_[3];

		std::shared_ptr<edgeType> theEdges_[3];

	public:

		enum
		{
			nbNodes = 3
		};

		Mesh_Element()
		{}

		Mesh_Element
		(
			const Standard_Integer theIndex
		)
			: Mesh_Entity(theIndex)
		{}

		Mesh_Element
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<nodeType>& theNode0,
			const std::shared_ptr<nodeType>& theNode1,
			const std::shared_ptr<nodeType>& theNode2
		)
			: Mesh_Entity(theIndex)
		{
			Node0() = theNode0;
			Node1() = theNode1;
			Node2() = theNode2;
		}


		Point Centre() const
		{
			Point pt =
				(Node0()->Coord() + Node1()->Coord() + Node2()->Coord())
				/ (Standard_Real)3.0;
			return std::move(pt);
		}


		Standard_Integer OppositeVertexIndex(const std::shared_ptr<edgeType>& theEdge) const
		{
			Debug_Null_Pointer(theEdge);
			for (int i = 0; i < 3; i++)
			{
				if (base::Edge(i) == theEdge)
				{
					return i;
				}
			}

			FatalErrorIn("Standard_Integer OppositeVertexIndex(const std::shared_ptr<edgeType>& theEdge) const")
				<< "Found no opposite vertex"
				<< abort(FatalError);

			return 0;
		}

		Standard_Integer OppositeVertexIndex(const std::shared_ptr<elementType>& theElement) const
		{
			Debug_Null_Pointer(theElement);
			for (int i = 0; i < 3; i++)
			{
				if (base::Neighbor(i).lock() == theElement)
				{
					return i;
				}
			}

			FatalErrorIn("Standard_Integer OppositeVertexIndex(const std::shared_ptr<elementType>& theElement) const")
				<< "Found no opposite vertex"
				<< abort(FatalError);

			return 0;
		}

		const std::shared_ptr<nodeType>& OppositeVertex
		(
			const std::shared_ptr<edgeType>& theEdge
		) const
		{
			for (int i = 0; i < 3; i++)
			{
				if (Edge(i) == theEdge)
				{
					return this->Node(i);
				}
			}
			return nodeType::null_ptr;
		}

		const std::shared_ptr<nodeType>& OppositeVertex
		(
			const std::shared_ptr<elementType>& theElement
		) const
		{
			for (int i = 0; i < 3; i++)
			{
				if (adaptor::Neighbor(i).lock() == theElement)
				{
					return this->Node(i);
				}
			}
			return nodeType::null_ptr;
		}


		//- Static function and operators


		static Standard_Boolean
			IsLess
			(
				const std::shared_ptr<Mesh_Element>& theElement0,
				const std::shared_ptr<Mesh_Element>& theElement1
			)
		{
			Debug_Null_Pointer(theElement0);
			Debug_Null_Pointer(theElement1);

			return theElement0->Index() < theElement1->Index();
		}

		//- Marcos

		GLOBAL_ACCESS_VECTOR(std::shared_ptr<nodeType>, Node, 0)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<nodeType>, Node, 1)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<nodeType>, Node, 2)

			GLOBAL_ACCESS_VECTOR(std::shared_ptr<edgeType>, Edge, 0)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<edgeType>, Edge, 1)
			GLOBAL_ACCESS_VECTOR(std::shared_ptr<edgeType>, Edge, 2)

			GLOBAL_ACCESS_VECTOR_INDEX(std::shared_ptr<nodeType>, Node)
			GLOBAL_ACCESS_VECTOR_INDEX(std::shared_ptr<edgeType>, Edge)
	};


	
}

#endif // !_Mesh_Element_Header
