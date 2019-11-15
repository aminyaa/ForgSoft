#pragma once
#ifndef _Leg_Prop_PropView_Header
#define _Leg_Prop_PropView_Header

#include <Global_AccessMethod.hxx>
#include <Standard_TypeDef.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	class Leg_Prop_ExpandedView;
	class Leg_Prop_WrappedSection;
	class Leg_Prop_UnWrappedSection;
	class Leg_Prop_BladeFace;

	class Leg_Prop_PropView
	{

		/*Private Data*/

		std::vector<std::shared_ptr<Leg_Prop_ExpandedView>> theExpanded_;

		std::vector<std::shared_ptr<Leg_Prop_WrappedSection>> theWrapped_;

		std::vector<std::shared_ptr<Leg_Prop_UnWrappedSection>> theUnWrapped_;

		std::shared_ptr<Leg_Prop_BladeFace> theSurface_;


		void AllocateMemory(const Standard_Integer theSize);

	public:

		Leg_Prop_PropView(const Standard_Integer theSize)
		{
			AllocateMemory(theSize);
		}

		//- Macros

		GLOBAL_ACCESS_SINGLE(std::shared_ptr<Leg_Prop_BladeFace>, Surface)
			GLOBAL_ACCESS_VECTOR_INDEX_1(std::shared_ptr<Leg_Prop_ExpandedView>, Expanded)
			GLOBAL_ACCESS_VECTOR_INDEX_1(std::shared_ptr<Leg_Prop_WrappedSection>, Wrapped)
			GLOBAL_ACCESS_VECTOR_INDEX_1(std::shared_ptr<Leg_Prop_UnWrappedSection>, UnWrapped)
	};
}

#endif // !_Leg_Prop_PropView_Header
