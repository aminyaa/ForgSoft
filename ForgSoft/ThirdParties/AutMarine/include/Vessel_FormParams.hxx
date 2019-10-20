#pragma once
#ifndef _Vessel_FormParams_Header
#define _Vessel_FormParams_Header

#include <Marine_VesselParams.hxx>

namespace AutLib
{

	class Vessel_FormParams
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

	public:

		Vessel_FormParams();


		const marineLib::APP APP() const
		{
			return theApp_;
		}

		marineLib::APP& APP()
		{
			return theApp_;
		}

		const marineLib::FPP& FPP() const
		{
			return theFpp_;
		}

		marineLib::FPP& FPP()
		{
			return theFpp_;
		}

		const marineLib::MPP& MPP() const
		{
			return theMpp_;
		}

		marineLib::MPP& MPP()
		{
			return theMpp_;
		}

		const marineLib::LPP& LPP() const
		{
			return theLpp_;
		}

		marineLib::LPP& LPP()
		{
			return theLpp_;
		}

		const marineLib::B& B() const
		{
			return theB_;
		}

		marineLib::B& B()
		{
			return theB_;
		}

		const marineLib::BWL& BWL() const
		{
			return theBwl_;
		}

		marineLib::BWL& BWL()
		{
			return theBwl_;
		}

		const marineLib::D& D() const
		{
			return theD_;
		}

		marineLib::D& D()
		{
			return theD_;
		}

		const marineLib::DWL& DWL() const
		{
			return theDwl_;
		}

		marineLib::DWL& DWL()
		{
			return theDwl_;
		}

		const marineLib::LWL& LWL() const
		{
			return theLwl_;
		}

		marineLib::LWL& LWL()
		{
			return theLwl_;
		}

		const marineLib::FWL& FWL() const
		{
			return theFwl_;
		}

		marineLib::FWL& FWL()
		{
			return theFwl_;
		}

		const marineLib::AWL& AWL() const
		{
			return theAwl_;
		}

		marineLib::AWL& AWL()
		{
			return theAwl_;
		}

		const marineLib::FUW& FUW() const
		{
			return theFuw_;
		}

		marineLib::FUW& FUW()
		{
			return theFuw_;
		}

		const marineLib::AUW& AUW() const
		{
			return theAuw_;
		}

		marineLib::AUW& AUW()
		{
			return theAuw_;
		}

		const marineLib::HEELANG& HEELANG() const
		{
			return theHeelang_;
		}

		marineLib::HEELANG& HEELANG()
		{
			return theHeelang_;
		}

		/*const marineLib::FREP& FREP() const
		{
			return theFrep_;
		}

		marineLib::FREP& FREP()
		{
			return theFrep_;
		}*/

		const marineLib::LOA& LOA() const
		{
			return theLoa_;
		}

		marineLib::LOA& LOA()
		{
			return theLoa_;
		}

		const marineLib::LOS& LOS() const
		{
			return theLos_;
		}

		marineLib::LOS& LOS()
		{
			return theLos_;
		}
	};
}

#endif // !_Vessel_FormParams_Header
