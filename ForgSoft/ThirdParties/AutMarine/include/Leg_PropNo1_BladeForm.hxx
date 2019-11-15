#pragma once
#ifndef _Leg_PropNo1_BladeForm_Header
#define _Leg_PropNo1_BladeForm_Header

#include <Leg_PropNo1_PitchForm.hxx>
#include <Leg_PropNo1_SkewForm.hxx>
#include <Leg_PropNo1_ChordForm.hxx>
#include <Leg_PropNo1_CamberForm.hxx>
#include <Leg_PropNo1_RakeForm.hxx>
#include <Leg_PropNo1_ThicknessForm.hxx>

namespace AutLib
{

	class Leg_PropNo1_BladeForm
		: public Leg_PropNo1_Form
	{

		/*Private Data*/

		Leg_PropNo1_PitchForm thePitch_;

		Leg_PropNo1_ChordForm theChord_;

		Leg_PropNo1_CamberForm theCamber_;

		Leg_PropNo1_SkewForm theSkew_;

		Leg_PropNo1_ThicknessForm theThickness_;

		Leg_PropNo1_RakeForm theRake_;


	public:

		Leg_PropNo1_BladeForm()
		{}

		GLOBAL_ACCESS_SINGLE(Leg_PropNo1_PitchForm, Pitch)
			GLOBAL_ACCESS_SINGLE(Leg_PropNo1_ChordForm, Chord)
			GLOBAL_ACCESS_SINGLE(Leg_PropNo1_CamberForm, Camber)
			GLOBAL_ACCESS_SINGLE(Leg_PropNo1_SkewForm, Skew)
			GLOBAL_ACCESS_SINGLE(Leg_PropNo1_ThicknessForm, Thickness)
			GLOBAL_ACCESS_SINGLE(Leg_PropNo1_RakeForm, Rake)
	};
}

#endif // !_Leg_PropNo1_BladeForm_Header
