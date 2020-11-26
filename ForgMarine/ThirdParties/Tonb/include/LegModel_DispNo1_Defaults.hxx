#pragma once
#ifndef _LegModel_DispNo1_Defaults_Header
#define _LegModel_DispNo1_Defaults_Header

#include <LegModel_ConstParameter.hxx>

namespace tnbLib
{

	class LegModel_DispNo1_Defaults
	{

		typedef LegModel_ConstParameter param;

		/*Private Data*/

	public:

		static const param LENGTH_ON_DECK;
		static const param BEAM_ON_DECK;
		static const param DEPTH_AT_BOW;
		static const param DEPTH_AT_TRANSOM;
		static const param TRANSOM_HEIGHT;


		static const param BOW_ROUNDING;
		static const param FORE_FOOT_SHAPE;
		static const param STEM_RAKE;

		static const param FWD_TIGHTNESS;
		static const param FWD_FLARE;
		static const param FWD_DEADRISE;
		static const param FWD_SIDE_SLOPE;

		static const param MID_TIGHTNESS;
		static const param MID_FLARE;
		static const param MID_DEADRISE;
		static const param MID_SIDE_SLOPE;

		static const param AFT_TIGHTNESS;
		static const param AFT_FLARE;
		static const param AFT_DEADRISE;
		static const param AFT_SIDE_SLOPE;

		static const param TRANSOM_RAKE;
		static const param TRANSOM_WIDTH;

		static const param KEEL_RISE_POINT;
		static const param KEEL_POSITION;
		static const param KEEL_RISE_SLOPE;
		static const param KEEL_TRANSOM_SLOPE;

		static const param MAX_AREA_LOCATION;
		static const param FWD_FULLNESS;
		static const param AFT_FULLNESS;

		static const Standard_Integer NB_OF_NET_COLUMNS;
		static const Standard_Integer NB_OF_NET_ROWS;
	};
}

#endif // !_LegModel_DispNo1_Defaults_Header
