#pragma once
#ifndef _Marine_WaveProfile_Header
#define _Marine_WaveProfile_Header

#include <Global_Bound.hxx>
#include <Global_Indexed.hxx>
#include <Marine_VesselParam_TA.hxx>
#include <Marine_VesselParam_TF.hxx>
#include <Marine_VesselParam_TM.hxx>

namespace AutLib
{

	class Marine_WaveProfile
		: public Global_Indexed
		, public Global_Named
		, public Global_Bound<Standard_Real>
	{

		/*Private Data*/

		marineLib::TA theTa_;
		marineLib::TF theTf_;

		marineLib::TM theTm_;

	protected:

		Marine_WaveProfile
		(
			const Standard_Real theTa,
			const Standard_Real theTf
		);

		Marine_WaveProfile
		(
			const Standard_Real theTa,
			const Standard_Real theTf,
			const Standard_Real theTm
		);

		Standard_Real& ChangeTA()
		{
			return theTa_();
		}

		Standard_Real& ChangeTF()
		{
			return theTf_();
		}

		Standard_Real& ChangeTM()
		{
			return theTm_();
		}

	public:

		virtual Standard_Real Value(const Standard_Real x) const = 0;

		Standard_Real operator()(const Standard_Real x) const
		{
			return Value(x);
		}

		const marineLib::TA& TA() const
		{
			return theTa_;
		}

		const marineLib::TF& TF() const
		{
			return theTf_;
		}

		const marineLib::TM& TM() const
		{
			return theTm_;
		}
	};
}

#endif // !_Marine_WaveProfile_Header
