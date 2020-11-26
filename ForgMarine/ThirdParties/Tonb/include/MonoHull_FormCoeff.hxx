#pragma once
#ifndef _MonoHull_FormCoeff_Header
#define _MonoHull_FormCoeff_Header

#include <Vessel_FormCoeff.hxx>
#include <HsPhysModel_MonoHull.hxx>

namespace tnbLib
{

	// Forward Declarations
	class MonoHull_FormDim;
	class HsEntity_MonoHull;

	class MonoHull_FormCoeff
		: public Vessel_FormCoeff_Parameters
		, public HsPhysModel_MonoHull
	{

		/*Private Data*/

		std::shared_ptr<MonoHull_FormDim> theFormDim_;

		std::shared_ptr<HsEntity_MonoHull> theModel_;

		//- private functions

		void CalcVolume();

		void CalcCB();

		void CalcAM();

		void CalcCP();

		void CalcCM();

		void CalcAW();

		void CalcCWL();

		void CalcCVP();

		void CalcWettedArea();

		void CalcLCB();

		void CalcVCB();

		void CalcKB();

	public:

		const auto& FormDim() const
		{
			return theFormDim_;
		}

		const auto& Model() const
		{
			return theModel_;
		}
	};
}

#endif // !_MonoHull_FormCoeff_Header
