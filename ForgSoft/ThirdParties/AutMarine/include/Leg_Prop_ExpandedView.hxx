#pragma once
#ifndef _Leg_Prop_ExpandedView_Header
#define _Leg_Prop_ExpandedView_Header

#include <Standard_TypeDef.hxx>
#include <Global_AccessMethod.hxx>

#include <vector>

namespace AutLib
{

	class Leg_Prop_ExpandedView
	{

		typedef std::vector<Standard_Real> realList;

		/*Private Data*/

		realList theXs_;
		realList theTf_;
		realList theTb_;
		realList theYf_;
		realList theYb_;

		realList theX_;


		void AllocateMemory(const Standard_Integer theSize);

	public:

		Leg_Prop_ExpandedView(const Standard_Integer theSize);

		Standard_Integer Size() const
		{
			return (Standard_Integer)theX_.size();
		}

		// Macros
		GLOBAL_ACCESS_VECTOR_INDEX_1(Standard_Real, Xs);
		GLOBAL_ACCESS_VECTOR_INDEX_1(Standard_Real, Tf);
		GLOBAL_ACCESS_VECTOR_INDEX_1(Standard_Real, Tb);
		GLOBAL_ACCESS_VECTOR_INDEX_1(Standard_Real, Yf);
		GLOBAL_ACCESS_VECTOR_INDEX_1(Standard_Real, Yb);

		GLOBAL_ACCESS_VECTOR_INDEX_1(Standard_Real, X);
	};
}

#endif // !_Leg_Prop_ExpandedView_Header
