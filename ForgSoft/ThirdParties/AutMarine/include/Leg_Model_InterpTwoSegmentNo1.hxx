#pragma once
#ifndef _Leg_Model_InterpTwoSegmentNo1_Header
#define _Leg_Model_InterpTwoSegmentNo1_Header

#include <Global_AccessMethod.hxx>
#include <Leg_PropNo1_Form.hxx>
#include <Leg_Model_Parameter.hxx>

#include <memory>

namespace AutLib
{

	class Leg_Model_InterpTwoSegmentNo1
	{

		typedef Leg_Model_Parameter parameter;

		/*Private Data*/

		std::shared_ptr<parameter> theMidWidth_;

		std::shared_ptr<parameter> theMidOffset_;
		std::shared_ptr<parameter> theInletOffset_;
		std::shared_ptr<parameter> theOutletOffset_;

		std::shared_ptr<parameter> theLeftTurningPosition_;
		std::shared_ptr<parameter> theLeftTurningWidth_;

		std::shared_ptr<parameter> theRightTurningPosition_;
		std::shared_ptr<parameter> theRightTurningWidth_;

		std::shared_ptr<parameter> theInletRiseWeight_;
		std::shared_ptr<parameter> theOutletRiseWeight_;

		std::shared_ptr<parameter> theInletWeight_;
		std::shared_ptr<parameter> theOutletWeight_;

	public:

		Leg_Model_InterpTwoSegmentNo1()
		{}

		//- Macros
		GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, MidWidth)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, MidOffset)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, InletOffset)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, OutletOffset)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, LeftTurningPosition)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, LeftTurningWidth)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, RightTurningPosition)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, RightTurningWidth)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, InletRiseWeight)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, OutletRiseWeight)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, InletWeight)
			GLOBAL_ACCESS_SINGLE(std::shared_ptr<parameter>, OutletWeight)
	};
}

#endif // !_Leg_Model_InterpTwoSegmentNo1_Header
