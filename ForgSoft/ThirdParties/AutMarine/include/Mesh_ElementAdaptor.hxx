#pragma once
#ifndef _Mesh_ElementAdaptor_Header
#define _Mesh_ElementAdaptor_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>
#include <Mesh_ElementType.hxx>

#include <memory>

namespace AutLib
{

	template<class ElementType, Mesh_ElementType ElmType = Mesh_ElementType_Tetrahedron>
	class Mesh_ElementAdaptor
	{

		/*Private Data*/

		std::weak_ptr<ElementType> theNeighbors_[4];

	public:

		Mesh_ElementAdaptor()
		{}

		const std::weak_ptr<ElementType>&
			Neighbor
			(
				const Standard_Integer theIndex
			) const
		{
			return theNeighbors_[theIndex];
		}

		std::weak_ptr<ElementType>&
			Neighbor
			(
				const Standard_Integer theIndex
			)
		{
			return theNeighbors_[theIndex];
		}

		//- Macros

		GLOBAL_ACCESS_VECTOR(std::weak_ptr<ElementType>, Neighbor, 0)
			GLOBAL_ACCESS_VECTOR(std::weak_ptr<ElementType>, Neighbor, 1)
			GLOBAL_ACCESS_VECTOR(std::weak_ptr<ElementType>, Neighbor, 2)
			GLOBAL_ACCESS_VECTOR(std::weak_ptr<ElementType>, Neighbor, 3)
	};

	template<class ElementType>
	class Mesh_ElementAdaptor<ElementType, Mesh_ElementType_Triangle2D>
	{

		/*Private Data*/

		std::weak_ptr<ElementType> theNeighbors_[3];

	public:

		Mesh_ElementAdaptor()
		{}

		const std::weak_ptr<ElementType>& 
			Neighbor
			(
				const Standard_Integer theIndex
			) const
		{
			return theNeighbors_[theIndex];
		}

		std::weak_ptr<ElementType>&
			Neighbor
			(
				const Standard_Integer theIndex
			)
		{
			return theNeighbors_[theIndex];
		}

		//- Macros

		GLOBAL_ACCESS_VECTOR(std::weak_ptr<ElementType>, Neighbor, 0)
			GLOBAL_ACCESS_VECTOR(std::weak_ptr<ElementType>, Neighbor, 1)
			GLOBAL_ACCESS_VECTOR(std::weak_ptr<ElementType>, Neighbor, 2)
	};

	template<class ElementType>
	class Mesh_ElementAdaptor<ElementType, Mesh_ElementType_Triangle3D>
	{

		/*Private Data*/

		std::weak_ptr<ElementType> theLeftElement_;
		std::weak_ptr<ElementType> theRightElement_;

	public:

		Mesh_ElementAdaptor()
		{}

		//- Macros

		GLOBAL_ACCESS_SINGLE(std::weak_ptr<ElementType>, LeftElement)
			GLOBAL_ACCESS_SINGLE(std::weak_ptr<ElementType>, RightElement)
	};
}

#endif // !_Mesh_ElementAdaptor_Header