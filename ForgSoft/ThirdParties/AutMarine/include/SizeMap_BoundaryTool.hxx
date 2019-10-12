#pragma once
#ifndef _SizeMap_BoundaryTool_Header
#define _SizeMap_BoundaryTool_Header

#include <word.hxx>
#include <SizeMap_Tool.hxx>

#include <list>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	class Mesh_ReferenceValues;

	template<class SizeMapTraits>
	class SizeMap_BoundaryTool
		: public SizeMap_Tool<SizeMapTraits>
	{

		typedef typename SizeMapTraits::objectType objectType;

		/*Private Data*/

		std::list<word> thePatches_;

	public:

		Standard_Integer NbPatches() const
		{
			return (Standard_Integer)thePatches_.size();
		}

		//- Return true if the patch is not found
		Standard_Boolean RemovePatch(const word& theName);

		const std::list<word>& Patches() const
		{
			return thePatches_;
		}

		void ImportPatch(const word& theName);

		virtual std::vector<typename objectType::entitytype> RetrieveEntities() const = 0;

	protected:

		SizeMap_BoundaryTool
		(
			const std::shared_ptr<Mesh_ReferenceValues>& theReference,
			const std::shared_ptr<objectType>& theObject
		)
			: SizeMap_Tool<SizeMapTraits>(theReference, theObject)
		{}
	};
}

#include <SizeMap_BoundaryToolI.hxx>

#endif // !_SizeMap_BoundaryTool_Header
