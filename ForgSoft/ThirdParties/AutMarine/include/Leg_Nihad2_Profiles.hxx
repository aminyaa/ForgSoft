#pragma once
#ifndef _Leg_Nihad2_Profiles_Header
#define _Leg_Nihad2_Profiles_Header

#include <Global_Macros.hxx>
#include <Leg_ParameterProfile.hxx>
#include <Leg_Nihad2_Dim.hxx>
#include <Leg_Model_PointList.hxx>
#include <Leg_Model_SectionCtrlPts.hxx>
#include <error.hxx>
#include <OSstream.hxx>

namespace AutLib
{

	struct Leg_Nihad2_Profile
	{

		Leg_ParameterProfile Deck;
		Leg_ParameterProfile Buttock;

		Leg_ParameterProfileList Flares;
		Leg_ParameterProfileList Sections;

	protected:

		void AllocateMemory
		(
			const Standard_Integer n
		)
		{
			if (NOT INSIDE(n, Leg_Nihad2::MIN_NB_SECTIONS, Leg_Nihad2::MAX_NB_SECTIONS))
			{
				FatalErrorIn("void AllocateMemory(const Standard_Integer n)")
					<< " Invalid Nb of Sections; nb. of Sections = " << n << endl
					<< " Min nb. of sections = " << Leg_Nihad2::MIN_NB_SECTIONS << endl
					<< " Max nb. of sections = " << Leg_Nihad2::MAX_NB_SECTIONS << endl
					<< abort(FatalError);
			}

			Flares.resize(n);
			Sections.resize(n);
		}
	};


	struct Leg_Nihad2_Xparams
	{

		Leg_Model::realList xXCoords;
		Leg_Model::realList xYCoords;
		Leg_Model::realList xZCoords;

		Leg_Model::realList xDepth;
		Leg_Model::realList xSheer;

		Leg_Model::realList xDeadRise;
		Leg_Model::realList xSideSlope;
		Leg_Model::realList xSideSlopeAngle;
		Leg_Model::realList xTightness0;
		Leg_Model::realList xTightness1;
		Leg_Model::realList xTrim;

		Leg_Model::realList xRake;

		Leg_Model::sectionCPtsList xSection;

	protected:

		void AllocateMemory
		(
			const Standard_Integer n
		)
		{
			if (NOT INSIDE(n, Leg_Nihad2::MIN_NB_SECTIONS, Leg_Nihad2::MAX_NB_SECTIONS))
			{
				FatalErrorIn("void AllocateMemory(const Standard_Integer n)")
					<< " Invalid Nb of Sections; nb. of Sections = " << n << endl
					<< " Min nb. of sections = " << Leg_Nihad2::MIN_NB_SECTIONS << endl
					<< " Max nb. of sections = " << Leg_Nihad2::MAX_NB_SECTIONS << endl
					<< abort(FatalError);
			}

			xXCoords.resize(n);
			xYCoords.resize(n);
			xZCoords.resize(n);

			xDepth.resize(n);
			xSheer.resize(n);

			xDeadRise.resize(n);
			xSideSlope.resize(n);
			xSideSlopeAngle.resize(n);
			xTightness0.resize(n);
			xTightness1.resize(n);
			xTrim.resize(n);

			xRake.resize(n);

			xSection.resize(n);
		}
	};
}

#endif // !_Leg_Nihad2_Profiles_Header
