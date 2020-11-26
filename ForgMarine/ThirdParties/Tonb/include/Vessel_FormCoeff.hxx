#pragma once
#ifndef _Vessel_FormCoeff_Header
#define _Vessel_FormCoeff_Header

#include <Marine_VesselParams.hxx>

namespace tnbLib
{

	class Vessel_FormCoeff_Parameters
	{

		/*Private Data*/

		//- Block coefficient
		marineLib::CB theCb_;

		//- Displacement
		marineLib::DISPV theDispv_;

		//- Displacement mass
		marineLib::DISPM theDispm_;

		//- Midship coefficient
		marineLib::CM theCm_;

		//- Midship-section area
		marineLib::AM theAm_;

		//- Prismatic coefficient
		marineLib::CP theCp_;

		//- Vertical Prismatic coefficient
		marineLib::CVP theCvp_;

		//- Waterplane area
		marineLib::AW theAw_;

		//- Wetted Area
		marineLib::WETA theWeta_;

		//- Waterplane-area coefficient
		marineLib::CWL theCwl_;

		marineLib::LCB theLcb_;

		marineLib::VCB theVcb_;

		marineLib::KB theKb_;

	protected:

		Vessel_FormCoeff_Parameters();

		marineLib::CB& ChangeCB()
		{
			return theCb_;
		}

		marineLib::DISPV& ChangeDISPV()
		{
			return theDispv_;
		}

		marineLib::DISPM& ChangeDISPM()
		{
			return theDispm_;
		}

		marineLib::CM& ChangeCM()
		{
			return theCm_;
		}

		marineLib::AM& ChangeAM()
		{
			return theAm_;
		}

		marineLib::CP& ChangeCP()
		{
			return theCp_;
		}

		marineLib::CVP& ChangeCVP()
		{
			return theCvp_;
		}

		marineLib::AW& ChangeAW()
		{
			return theAw_;
		}

		marineLib::WETA& ChangeWETA()
		{
			return theWeta_;
		}

		marineLib::CWL& ChangeCWL()
		{
			return theCwl_;
		}

		marineLib::LCB& ChangeLCB()
		{
			return theLcb_;
		}

		marineLib::VCB& ChangeVCB()
		{
			return theVcb_;
		}

		marineLib::KB& ChangeKB()
		{
			return theKb_;
		}

	public:

		const marineLib::CB& CB() const
		{
			return theCb_;
		}

		const marineLib::DISPV& DISPV() const
		{
			return theDispv_;
		}

		const marineLib::DISPM& DISPM() const
		{
			return theDispm_;
		}

		const marineLib::CM& CM() const
		{
			return theCm_;
		}

		const marineLib::AM& AM() const
		{
			return theAm_;
		}

		const marineLib::CP& CP() const
		{
			return theCp_;
		}

		const marineLib::CVP& CVP() const
		{
			return theCvp_;
		}

		const marineLib::AW& AW() const
		{
			return theAw_;
		}

		const marineLib::WETA& WETA() const
		{
			return theWeta_;
		}

		const marineLib::CWL& CWL() const
		{
			return theCwl_;
		}

		const marineLib::LCB& LCB() const
		{
			return theLcb_;
		}

		const marineLib::VCB& VCB() const
		{
			return theVcb_;
		}

		const marineLib::KB& KB() const
		{
			return theKb_;
		}
	};


	class Vessel_FormCoeff
		: public Vessel_FormCoeff_Parameters
	{

		/*Private Data*/



		// Calculate Auxiliaries

		void CalcFUW();

		void CalcAUW();

		void CalcAWL();

		void CalcFWL();


		// Calculate Dimensions

		void CalcB();

		void CalcBWL();

		void CalcD();

		void CalcFPP();

		void CalcAPP();

		void CalcLPP();

		void CalcMPP();

		void CalcLWL();

		void CalcLOS();

		void CalcLOA();

		// Calculate Area of stations

		void CalcArea();

	public:


	};
}

#endif // !_Vessel_FormCoeff_Header
