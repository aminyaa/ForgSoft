#pragma once
#ifndef _Mesh_EdgeAdaptor_Header
#define _Mesh_EdgeAdaptor_Header

#include <Mesh_EntityAdaptorM.hxx>

namespace tnbLib
{

	Mesh_EntityToEntityAdaptor(Edge, Facet, FacetType);
	Mesh_EntityToEntityAdaptor(Edge, Element, ElementType);

	template<class ElementType, class FacetType = void>
	class Mesh_EdgeAdaptor
		: public Mesh_EdgeToFacetAdaptor<FacetType>
		, public Mesh_EdgeToElementAdaptor<ElementType>
	{

		/*Private Data*/

	public:

		Mesh_EdgeAdaptor()
		{}
	};

	//template<class FacetType>
	//class Mesh_EdgeAdaptor<void, FacetType>
	//	: public Mesh_EdgeToFacetAdaptor<FacetType>
	//{

	//	/*Private Data*/

	//public:

	//	Mesh_EdgeAdaptor()
	//	{}
	//};

	template<>
	class Mesh_EdgeAdaptor<void, void>
	{};

	template<class ElementType>
	class Mesh_EdgeAdaptor<ElementType, void>
	{

		/*Private Data*/

		std::weak_ptr<ElementType> theRight_;
		std::weak_ptr<ElementType> theLeft_;

	public:

		Mesh_EdgeAdaptor()
		{}

		const std::weak_ptr<ElementType>& RightElement() const
		{
			return theRight_;
		}

		std::weak_ptr<ElementType>& RightElement()
		{
			return theRight_;
		}

		const std::weak_ptr<ElementType>& LeftElement() const
		{
			return theLeft_;
		}

		std::weak_ptr<ElementType>& LeftElement()
		{
			return theLeft_;
		}

		Standard_Boolean IsOrphan() const
		{
			return theRight_.lock() == nullptr && theLeft_.lock() == nullptr;
		}

		void SetRightElement(const std::weak_ptr<ElementType>& theElement)
		{
			theRight_ = theElement;
		}

		void SetLeftElement(const std::weak_ptr<ElementType>& theElement)
		{
			theLeft_ = theElement;
		}
	};
}

#endif // !_Mesh_EdgeAdaptor_Header