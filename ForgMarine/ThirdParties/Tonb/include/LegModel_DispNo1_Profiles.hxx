#pragma once
#ifndef _LegModel_DispNo1_Profiles_Header
#define _LegModel_DispNo1_Profiles_Header

#include <Global_Macros.hxx>
#include <LegModel_ParameterProfile.hxx>
#include <LegModel_DispNo1_System.hxx>
#include <LegModel_PointList.hxx>
#include <LegModel_SectionCtrlPts.hxx>
#include <error.hxx>
#include <OSstream.hxx>

namespace tnbLib
{

	struct LegModel_DispNo1_Profile
	{


		LegModel_ParameterProfile Deck;
		LegModel_ParameterProfile Buttock;

		Leg_ParameterProfileList Flares;
		Leg_ParameterProfileList Sections;

	protected:

		void AllocateMemory
		(
			const Standard_Integer n
		)
		{
			if (NOT INSIDE(n, leg_DispNo1::MIN_NB_SECTIONS, leg_DispNo1::MAX_NB_SECTIONS))
			{
				FatalErrorIn("void AllocateMemory(const Standard_Integer n)")
					<< " Invalid Nb of Sections; nb. of Sections = " << n << endl
					<< " Min nb. of sections = " << leg_DispNo1::MIN_NB_SECTIONS << endl
					<< " Max nb. of sections = " << leg_DispNo1::MAX_NB_SECTIONS << endl
					<< abort(FatalError);
			}

			Flares.resize(n);
			Sections.resize(n);
		}
	};


	struct LegModel_DispNo1_Xparams
	{

		legModel::realList xXCoords;
		legModel::realList xYCoords;
		legModel::realList xZCoords;

		legModel::realList xDepth;
		legModel::realList xSheer;

		legModel::realList xTightness;
		legModel::realList xFlare;
		legModel::realList xDeadRise;
		legModel::realList xSideSlope;
		legModel::realList xSideSlopeAngle;

		legModel::realList xRake;

		legModel::sectionCPtsList xSection;

	protected:

		void AllocateMemory
		(
			const Standard_Integer n
		)
		{
			if (NOT INSIDE(n, leg_DispNo1::MIN_NB_SECTIONS, leg_DispNo1::MAX_NB_SECTIONS))
			{
				FatalErrorIn("void AllocateMemory(const Standard_Integer n)")
					<< " Invalid Nb of Sections; nb. of Sections = " << n << endl
					<< " Min nb. of sections = " << leg_DispNo1::MIN_NB_SECTIONS << endl
					<< " Max nb. of sections = " << leg_DispNo1::MAX_NB_SECTIONS << endl
					<< abort(FatalError);
			}

			xXCoords.resize(n);
			xYCoords.resize(n);
			xZCoords.resize(n);

			xDepth.resize(n);
			xSheer.resize(n);

			xTightness.resize(n);
			xFlare.resize(n);
			xDeadRise.resize(n);
			xSideSlope.resize(n);
			xSideSlopeAngle.resize(n);

			xRake.resize(n);

			xSection.resize(n);
		}
	};
}

#endif // !_LegModel_DispNo1_Profiles_Header
