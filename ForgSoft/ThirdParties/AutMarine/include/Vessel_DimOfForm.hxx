#pragma once
#ifndef _Vessel_DimOfForm_Header
#define _Vessel_DimOfForm_Header

#include <Marine_VesselParams.hxx>
#include <Global_AccessMethod.hxx>

namespace AutLib
{

	class Vessel_DimOfForm
	{

		/*Private Data*/

		//- After perpendicular
		marineLib::APP theApp_;

		//- Forward perpendicular
		marineLib::FPP theFpp_;

		//- Middle perpendicular
		marineLib::MPP theMpp_;

		//- Length between perpendiculars
		marineLib::LPP theLpp_;

		//- Breadth
		marineLib::B theB_;

		//- Breadth Waterline
		marineLib::BWL theBwl_;

		//- Depth
		marineLib::D theD_;

		//- Design waterline
		marineLib::DWL theDwl_;

		//- Waterline length
		marineLib::LWL theLwl_;

		//- Forward Waterline
		marineLib::FWL theFwl_;

		//- Aft Waterline
		marineLib::AWL theAwl_;

		//- Forward Underwater
		marineLib::FUW theFuw_;

		//- Aft Underwater
		marineLib::AUW theAuw_;

		//- Heel Angle
		marineLib::HEELANG theHeelang_;

		//- Freeboard
		//marineLib::FREP theFrep_;

		//- Length overall
		marineLib::LOA theLoa_;

		//- Length overall submerged
		marineLib::LOS theLos_;

		//- Waterline

	protected:

		Vessel_DimOfForm();

	public:

		//- Macros

		GLOBAL_ACCESS_SINGLE(marineLib::APP, App)
			GLOBAL_ACCESS_SINGLE(marineLib::FPP, Fpp)
			GLOBAL_ACCESS_SINGLE(marineLib::MPP, Mpp)
			GLOBAL_ACCESS_SINGLE(marineLib::LPP, Lpp)
			GLOBAL_ACCESS_SINGLE(marineLib::B, B)
			GLOBAL_ACCESS_SINGLE(marineLib::BWL, Bwl)
			GLOBAL_ACCESS_SINGLE(marineLib::D, D)
			GLOBAL_ACCESS_SINGLE(marineLib::DWL, Dwl)
			GLOBAL_ACCESS_SINGLE(marineLib::LWL, Lwl)
			GLOBAL_ACCESS_SINGLE(marineLib::FWL, Fwl)
			GLOBAL_ACCESS_SINGLE(marineLib::AWL, Awl)
			GLOBAL_ACCESS_SINGLE(marineLib::FUW, Fuw)
			GLOBAL_ACCESS_SINGLE(marineLib::AUW, Auw)
			GLOBAL_ACCESS_SINGLE(marineLib::HEELANG, Heelang)
			//GLOBAL_ACCESS_SINGLE(marineLib::FREP, Frep)
			GLOBAL_ACCESS_SINGLE(marineLib::LOA, Loa)
			GLOBAL_ACCESS_SINGLE(marineLib::LOS, Los)

	};
}

#endif // !_Vessel_DimOfForm_Header
