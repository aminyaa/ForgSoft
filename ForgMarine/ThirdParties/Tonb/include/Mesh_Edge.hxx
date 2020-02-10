#pragma once
#ifndef _Mesh_Edge_Header
#define _Mesh_Edge_Header

#include <Mesh_Entity.hxx>
#include <Mesh_EdgeAdaptor.hxx>
#include <Traits.hxx>

#include <memory>

namespace tnbLib
{

	template<class EdgeTraits>
	class Mesh_Edge
		: public Mesh_Entity
		, public Mesh_EdgeAdaptor
		<
		typename EdgeTraits::elementType,
		typename EdgeTraits::facetType
		>
	{

	public:

		typedef typename EdgeTraits::nodeType nodeType;
		typedef typename EdgeTraits::facetType facetType;
		typedef typename EdgeTraits::elementType elementType;

		typedef typename nodeType::ptType Point;

		template< bool cond, typename U >
		using resolvedType = typename std::enable_if< cond, U >::type;


	private:

		/*Private Data*/

		std::shared_ptr<nodeType> theNodes_[2];

	public:

		enum
		{
			rank = 1,
			hierarchy = 0
		};

		Mesh_Edge()
		{}

		Mesh_Edge(const Standard_Integer theIndex)
			: Mesh_Entity(theIndex)
		{}

		Mesh_Edge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<nodeType>& theNode0,
			const std::shared_ptr<nodeType>& theNode1
		)
			: Mesh_Entity(theIndex)
		{
			theNodes_[0] = theNode0;
			theNodes_[1] = theNode1;
		}

		const std::shared_ptr<nodeType>& Node0() const
		{
			return theNodes_[0];
		}

		std::shared_ptr<nodeType>& Node0()
		{
			return theNodes_[0];
		}

		const std::shared_ptr<nodeType>& Node1() const
		{
			return theNodes_[1];
		}

		std::shared_ptr<nodeType>& Node1()
		{
			return theNodes_[1];
		}

		const std::shared_ptr<nodeType>& Node(const Standard_Integer theIndex) const
		{
			return theNodes_[theIndex];
		}

		std::shared_ptr<nodeType>& Node(const Standard_Integer theIndex)
		{
			return theNodes_[theIndex];
		}

		void SetNode(const Standard_Integer theIndex, const std::shared_ptr<nodeType>& theNode)
		{
			theNodes_[theIndex] = theNode;
		}

		void SetNode0(const std::shared_ptr<nodeType>& theNode)
		{
			theNodes_[0] = theNode;
		}

		void SetNode1(const std::shared_ptr<nodeType>& theNode)
		{
			theNodes_[1] = theNode;
		}

		template<class U = Standard_Boolean>
		resolvedType<is_two_dimension<(int)Point::dim>::value, U>
			IsRightSide
			(
				const Point& theCoord
			) const;

		template<class U = Standard_Boolean>
		resolvedType<is_two_dimension<(int)Point::dim>::value, U>
			IsLeftSide
			(
				const Point& theCoord
			) const;

		template<class U = Standard_Real>
		resolvedType<is_two_dimension<(int)Point::dim>::value, U> Oriented
		(
			const Point& theCoord
		) const;

		Standard_Real CalcDistance(const Point& theCoord) const;

		Standard_Real CalcSquareDistance(const Point& theCoord) const;


		//- Static functions and operators

		static Standard_Boolean IsLess
		(
			const std::shared_ptr<Mesh_Edge>& theEdge0,
			const std::shared_ptr<Mesh_Edge>& theEdge1
		)
		{
			Debug_Null_Pointer(theEdge0);
			Debug_Null_Pointer(theEdge1);
			return theEdge0->Index() < theEdge1->Index();
		}

		static Standard_Boolean IsLess
		(
			const std::weak_ptr<Mesh_Edge>& theEdge0,
			const std::weak_ptr<Mesh_Edge>& theEdge1
		)
		{
			Debug_Null_Pointer(theEdge0.lock());
			Debug_Null_Pointer(theEdge1.lock());
			return theEdge0.lock()->Index() < theEdge1.lock()->Index();
		}
	};
}

#include <Mesh_EdgeI.hxx>

#endif // !_Mesh_Edge_Header