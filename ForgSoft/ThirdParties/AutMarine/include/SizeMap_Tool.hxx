#pragma once
#ifndef _SizeMap_Tool_Header
#define _SizeMap_Tool_Header

#include <Mesh_Conditions.hxx>
#include <Mesh_Values.hxx>
#include <Global_AccessMethod.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Mesh_ReferenceValues;

	template<class SizeMapTraits>
	class SizeMap_Tool
	{

	public:

		typedef typename SizeMapTraits::backMeshType backMeshType;
		typedef typename SizeMapTraits::objectType objectType;

	private:

		/*Private Data*/

		Mesh_Conditions theConditions_;

		Mesh_Values theValues_;

		std::shared_ptr<Mesh_ReferenceValues> theReference_;

		std::shared_ptr<backMeshType> theBackMesh_;
		std::shared_ptr<objectType> theObject_;

	public:

		virtual ~SizeMap_Tool()
		{}

		const std::shared_ptr<objectType>& Object() const
		{
			return theObject_;
		}

		const std::shared_ptr<backMeshType>& BackMesh() const
		{
			return theBackMesh_;
		}

		const std::shared_ptr<Mesh_ReferenceValues>& Reference() const
		{
			return theReference_;
		}

		//- Macros

		GLOBAL_ACCESS_SINGLE(Mesh_Conditions, Conditions)
			GLOBAL_ACCESS_SINGLE(Mesh_Values, Values)


	protected:

		SizeMap_Tool
		(
			const std::shared_ptr<Mesh_ReferenceValues>& theReference,
			const std::shared_ptr<objectType>& theObject
		);

		void SpecifiedValues
		(
			Standard_Real& theElementSize,
			Standard_Real& theMinSize, 
			Standard_Real& theSpanAngle
		) const;

	};
}

#include <SizeMap_ToolI.hxx>

#endif // !_SizeMap_Tool_Header
