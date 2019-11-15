#pragma once
#ifndef _Leg_Prop_UnWrappedSection_Header
#define _Leg_Prop_UnWrappedSection_Header

#include <Leg_Prop_WrappedSection.hxx>

namespace AutLib
{

	class Leg_Prop_UnWrappedSection
		: public Leg_Prop_WrappedSection
	{

		/*Private Data*/

	public:

		Leg_Prop_UnWrappedSection(const Standard_Integer theSize)
			: Leg_Prop_WrappedSection(theSize)
		{}
	};
}

#endif // !_Leg_Prop_UnWrappedSection_Header
