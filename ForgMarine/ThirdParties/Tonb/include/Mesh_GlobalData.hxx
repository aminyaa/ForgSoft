#pragma once
#ifndef _Mesh_GlobalData_Header
#define _Mesh_GlobalData_Header

#include <Mesh_RegisterEntityM.hxx>
#include <Mesh_NamedEntity.hxx>
#include <Mesh_QualityMap.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <memory>

namespace tnbLib
{

	Mesh_RegisterEntity(Element, ElementType);

	template<class ElementType>
	class Mesh_GlobalData
		: public Mesh_NamedEntity
		, public Mesh_RegisterElement<ElementType>
	{

		/*Private Data*/

		//- Quality of the mesh	
		std::shared_ptr<Mesh_QualityMap> theQuality_;

	public:

		Mesh_GlobalData()
			: Mesh_NamedEntity(0, "Unknown")
		{}

		Standard_Boolean HasQuality() const
		{
			return (Standard_Boolean)theQuality_;
		}

		const std::shared_ptr<Mesh_QualityMap>& QualityMap() const
		{
			return theQuality_;
		}

		std::shared_ptr<Mesh_QualityMap>& QualityMap()
		{
			return theQuality_;
		}

		Standard_Real Quality(const Standard_Integer theIndex) const
		{
			if (IsNULL(theQuality_))
			{
				FatalErrorIn(FunctionSIG)
					<< "No allocated QualityMap has been found"
					<< abort(FatalError);
			}
			return theQuality_[theIndex];
		}

		void SetQuality
		(
			const Standard_Integer theElement,
			const Standard_Real theQuality
		)
		{
			if (IsNULL(theQuality_))
			{
				FatalErrorIn(FunctionSIG)
					<< "No allocated QualityMap has been found"
					<< abort(FatalError);
			}
			theQuality_[theElement] = theQuality;
		}
	};
}

#endif // !_Mesh_GlobalData_Header