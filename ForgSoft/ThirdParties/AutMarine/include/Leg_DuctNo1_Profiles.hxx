#pragma once
#ifndef _Leg_DuctNo1_Profiles_Header
#define _Leg_DuctNo1_Profiles_Header

#include <Global_Macros.hxx>
#include <Leg_ParameterProfile.hxx>
#include <Leg_Model_PointList.hxx>
#include <Leg_DuctNo1_Dim.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <vector>

namespace AutLib
{

	struct Leg_DuctNo1_Profile
	{

		Leg_ParameterProfile Breadth;
		Leg_ParameterProfile Depth;

		//Leg_ParameterProfileList Section;
	};

	struct Leg_DuctNo1_Xparams
	{
		Leg_Model::realList xXCoords;
		Leg_Model::realList xYCoords;
		Leg_Model::realList xZCoords;

		Leg_Model::realList xUpperTightness;
		Leg_Model::realList xLowerTightness;
		Leg_Model::realList xSideSlope;
		Leg_Model::realList xDepth;
		Leg_Model::realList xWidth;

		void AllocateMemory
		(
			const Standard_Integer n
		)
		{
			if (NOT INSIDE(n, Leg_DuctNo1::MIN_NB_SECTIONS, Leg_DuctNo1::MAX_NB_SECTIONS))
			{
				FatalErrorIn("void AllocateMemory(const Standard_Integer n)")
					<< " Invalid Nb of Sections; nb. of Sections = " << n << endl
					<< " Min nb. of sections = " << Leg_DuctNo1::MIN_NB_SECTIONS << endl
					<< " Max nb. of sections = " << Leg_DuctNo1::MAX_NB_SECTIONS << endl
					<< abort(FatalError);
			}

			xXCoords.resize(n);
			xYCoords.resize(n);
			xZCoords.resize(n);

			xUpperTightness.resize(n);
			xLowerTightness.resize(n);
			xSideSlope.resize(n);
			xDepth.resize(n);
			xWidth.resize(n);
		}
	};
}

#endif // !_Leg_DuctNo1_Profiles_Header
