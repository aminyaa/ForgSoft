#pragma once
#ifndef _Leg_DuctNo1_Defaults_Header
#define _Leg_DuctNo1_Defaults_Header

#include <Leg_Model_ConstParam.hxx>
#include <Standard_TypeDef.hxx>

namespace AutLib
{

	class Leg_DuctNo1_Defaults
	{

		typedef Leg_Model_ConstParam param;

	public:

		static const Standard_Integer NB_SECTIONS;

		static const param OVERAL_LENGTH;
		static const param BREADTH_AT_INLET;
		static const param BREADTH_AT_OUTLET;
		static const param DEPTH_AT_INLET;
		static const param DEPTH_AT_OUTLET;
		static const param HEIGHT_AT_OUTLET;

		static const param MID_LOCATION;

		static const param INLET_WIDTH;
		static const param INLET_SIDE_SLOPE;
		static const param INLET_UPPER_TIGHTNESS;
		static const param INLET_LOWER_TIGHTNESS;

		static const param MID_WIDTH;
		static const param MID_SIDE_SLOPE;
		static const param MID_UPPER_TIGHTNESS;
		static const param MID_LOWER_TIGHTNESS;

		static const param OUTLET_WIDTH;
		static const param OUTLET_SIDE_SLOPE;
		static const param OUTLET_UPPER_TIGHTNESS;
		static const param OUTLET_LOWER_TIGHTNESS;

		static const param BREADTH_INLET_OFFSET;
		static const param BREADTH_INLET_RISE_WEIGHT;
		static const param BREADTH_INLET_WEIGHT;
		static const param BREADTH_LEFT_TURNING_POSITION;
		static const param BREADTH_LEFT_TURNING_WIDTH;
		static const param BREADTH_MID_OFFSET;
		static const param BREADTH_MID_WIDTH;
		static const param BREADTH_OUTLET_OFFSET;
		static const param BREADTH_OUTLET_RISE_WEIGTH;
		static const param BREADTH_OUTLET_WEIGHT;
		static const param BREADTH_RIGHT_TURNING_POSITION;
		static const param BREADTH_RIGHT_TURNING_WIDTH;

		static const param DEPTH_INLET_OFFSET;
		static const param DEPTH_INLET_RISE_WEIGHT;
		static const param DEPTH_INLET_WEIGHT;
		static const param DEPTH_LEFT_TURNING_POSITION;
		static const param DEPTH_LEFT_TURNING_WIDTH;
		static const param DEPTH_MID_OFFSET;
		static const param DEPTH_MID_WIDTH;
		static const param DEPTH_OUTLET_OFFSET;
		static const param DEPTH_OUTLET_RISE_WEIGTH;
		static const param DEPTH_OUTLET_WEIGHT;
		static const param DEPTH_RIGHT_TURNING_POSITION;
		static const param DEPTH_RIGHT_TURNING_WIDTH;

		static const param GEN_RISE_POINT;
		static const param GEN_POSITION;
		static const param GEN_RISE_TANGENT;
		static const param GEN_OUTLET_TANGENT;
	};
}

#endif // !_Leg_DuctNo1_Defaults_Header
