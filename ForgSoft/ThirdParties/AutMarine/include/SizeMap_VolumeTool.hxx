#pragma once
#ifndef _SizeMap_VolumeTool_Header
#define _SizeMap_VolumeTool_Header

#include <SizeMap_Tool.hxx>

#include <map>
#include <list>
#include <memory>

namespace AutLib
{

	template<class SizeMapTraits>
	class SizeMap_VolumeTool
		: public SizeMap_Tool<SizeMapTraits>
	{

		typedef typename SizeMapTraits::primShapeType primShapeType;

		/*Private Data*/

		std::map<Standard_Integer, std::shared_ptr<primShapeType>> theShapes_;

		Standard_Integer theBucketSize_;

	public:

		SizeMap_VolumeTool
		(
			const std::shared_ptr<Mesh_ReferenceValues>& theReference,
			const std::shared_ptr<objectType>& theObject
		)
			: SizeMap_Tool<SizeMapTraits>(theReference, theObject)
		{}

		Standard_Boolean ImportSource(const std::shared_ptr<primShapeType>& theShape);

		Standard_Boolean RemoveSource(const std::shared_ptr<primShapeType>& theShape);

		void SetBucketSize(const Standard_Integer theSize)
		{
			theBucketSize_ = theSize;
		}

		void CreateSizeMap();

	protected:


	};
}

#endif // !_SizeMap_VolumeTool_Header
