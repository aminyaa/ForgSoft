#pragma once
#ifndef _Leg_Prop_BladeFace_Header
#define _Leg_Prop_BladeFace_Header

#include <Leg_Model_Surface.hxx>
#include <Global_AccessMethod.hxx>
#include <OFstream.hxx>

namespace AutLib
{

	class Leg_Prop_BladeFace
	{

		/*Private Data*/

		Leg_Model::geomSurface theFace_;
		Leg_Model::geomSurface theBack_;

	public:

		Leg_Prop_BladeFace()
		{}

		void ExportToPlt(OFstream& File) const;

		//- Macros

		GLOBAL_ACCESS_SINGLE(Leg_Model::geomSurface, Face)
			GLOBAL_ACCESS_SINGLE(Leg_Model::geomSurface, Back)
	};
}

#endif // !_Leg_Prop_BladeFace_Header
