#pragma once
#ifndef _Vessel_FormDim_Header
#define _Vessel_FormDim_Header

#include <Marine_VesselParams.hxx>

namespace tnbLib
{

	class Vessel_FormDim_Parameters
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

		Vessel_FormDim_Parameters();

		marineLib::APP& ChangeAPP()
		{
			return theApp_;
		}

		marineLib::FPP& ChangeFPP()
		{
			return theFpp_;
		}

		marineLib::MPP& ChangeMPP()
		{
			return theMpp_;
		}

		marineLib::LPP& ChangeLPP()
		{
			return theLpp_;
		}

		marineLib::B& ChangeB()
		{
			return theB_;
		}

		marineLib::BWL& ChangeBWL()
		{
			return theBwl_;
		}

		marineLib::D& ChangeD()
		{
			return theD_;
		}

		marineLib::DWL& ChangeDWL()
		{
			return theDwl_;
		}

		marineLib::LWL& ChangeLWL()
		{
			return theLwl_;
		}

		marineLib::FWL& ChangeFWL()
		{
			return theFwl_;
		}

		marineLib::AWL& ChangeAWL()
		{
			return theAwl_;
		}

		marineLib::FUW& ChangeFUW()
		{
			return theFuw_;
		}

		marineLib::AUW& ChangeAUW()
		{
			return theAuw_;
		}

		marineLib::LOA& ChangeLOA()
		{
			return theLoa_;
		}

		marineLib::LOS& ChangeLOS()
		{
			return theLos_;
		}

	public:

		const marineLib::APP APP() const
		{
			return theApp_;
		}

		const marineLib::FPP& FPP() const
		{
			return theFpp_;
		}

		const marineLib::MPP& MPP() const
		{
			return theMpp_;
		}

		const marineLib::LPP& LPP() const
		{
			return theLpp_;
		}

		const marineLib::B& B() const
		{
			return theB_;
		}

		const marineLib::BWL& BWL() const
		{
			return theBwl_;
		}

		const marineLib::D& D() const
		{
			return theD_;
		}

		const marineLib::DWL& DWL() const
		{
			return theDwl_;
		}

		const marineLib::LWL& LWL() const
		{
			return theLwl_;
		}

		const marineLib::FWL& FWL() const
		{
			return theFwl_;
		}

		const marineLib::AWL& AWL() const
		{
			return theAwl_;
		}

		const marineLib::FUW& FUW() const
		{
			return theFuw_;
		}

		const marineLib::AUW& AUW() const
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

		const marineLib::LOS& LOS() const
		{
			return theLos_;
		}

	};
}

#endif // !_Vessel_FormDim_Header
