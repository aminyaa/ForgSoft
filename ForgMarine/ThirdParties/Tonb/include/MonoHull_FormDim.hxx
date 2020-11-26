#pragma once
#ifndef _MonoHull_FormDim_Header
#define _MonoHull_FormDim_Header

#include <Vessel_FormDim.hxx>
#include <HsPhysModel_MonoHull.hxx>

namespace tnbLib
{

	// Forward Declarations
	class HsEntity_MonoHull;

	class MonoHull_FormDim
		: public Vessel_FormDim_Parameters
		, public HsPhysModel_MonoHull
	{

		/*Private Data*/

		std::shared_ptr<HsEntity_MonoHull> theModel_;


		//- private functions

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

		const auto& Model() const
		{
			return theModel_;
		}

		void Perform();
	};
}

#endif // !_MonoHull_FormDim_Header
