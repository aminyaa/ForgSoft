#pragma once
#ifndef _Leg_Model_CtrlNet_Header
#define _Leg_Model_CtrlNet_Header

#include <Leg_Model_SectionCtrlPts.hxx>

namespace AutLib
{

	struct Leg_Model_CtrlNet
	{

		Leg_Model::ctrlNet_ptr CtrlNet;
	};

	struct Leg_Model_WeightNet
	{
		Leg_Model::weightNet_ptr WeightNet;
	};
}

#endif // !_Leg_Model_CtrlNet_Header
