#pragma once
#ifndef _Leg_PropNo1_Profiles_Header
#define _Leg_PropNo1_Profiles_Header

#include <Global_Macros.hxx>
#include <Leg_ParameterProfile.hxx>
#include <Leg_Model_PointList.hxx>
#include <Leg_PropNo1_Dim.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <vector>

namespace AutLib
{

	struct Leg_PropNo1_Profile
	{

		Leg_ParameterProfile Pitch;
		Leg_ParameterProfile Chord;
		Leg_ParameterProfile Camber;
		Leg_ParameterProfile Skew;
		Leg_ParameterProfile Rake;
		Leg_ParameterProfile Thickness;


	};

	struct Leg_PropNo1_Xparams
	{

		Leg_Model::realList xXCoords;

		Leg_Model::realList xPitchAngle;
		Leg_Model::realList xChord;
		Leg_Model::realList xMaxCamber;
		Leg_Model::realList xMaxCamberPosition;
		Leg_Model::realList xSkew;
		Leg_Model::realList xRake;
		Leg_Model::realList xThickness;


		void AllocateMemory
		(
			const Standard_Integer n
		)
		{
			if (NOT INSIDE(n, Leg_PropNo1::MIN_NB_SECTIONS, Leg_PropNo1::MAX_NB_SECTIONS))
			{
				FatalErrorIn("void AllocateMemory(const Standard_Integer n)")
					<< " Invalid Nb of Sections; nb. of Sections = " << n << endl
					<< " Min nb. of sections = " << Leg_PropNo1::MIN_NB_SECTIONS << endl
					<< " Max nb. of sections = " << Leg_PropNo1::MAX_NB_SECTIONS << endl
					<< abort(FatalError);
			}

			xXCoords.resize(n);

			xPitchAngle.resize(n);
			xChord.resize(n);
			xMaxCamber.resize(n);
			xMaxCamberPosition.resize(n);
			xSkew.resize(n);
			xRake.resize(n);
			xThickness.resize(n);
		}
	};
}

#endif // !_Leg_PropNo1_Profiles_Header
