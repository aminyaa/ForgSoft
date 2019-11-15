#pragma once
#ifndef _Leg_Prop_WrappedSection_Header
#define _Leg_Prop_WrappedSection_Header

#include <Leg_Model_PointList.hxx>
#include <Global_AccessMethod.hxx>

namespace AutLib
{

	class Leg_Prop_WrappedSection
	{

		/*Private Data*/

		Leg_Model::pointList theFace_;
		Leg_Model::pointList theBack_;

	public:

		Leg_Prop_WrappedSection(const Standard_Integer theSize);


		//- Macros

		GLOBAL_ACCESS_VECTOR_INDEX_1(Pnt3d, Face)
			GLOBAL_ACCESS_VECTOR_INDEX_1(Pnt3d, Back)

			GLOBAL_ACCESS_SINGLE(Leg_Model::pointList, Face)
			GLOBAL_ACCESS_SINGLE(Leg_Model::pointList, Back)
	};
}

#endif // !_Leg_Prop_WrappedSection_Header
