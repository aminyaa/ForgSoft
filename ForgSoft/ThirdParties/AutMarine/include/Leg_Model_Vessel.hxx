#pragma once
#ifndef _Leg_Model_Vessel_Header
#define _Leg_Model_Vessel_Header

#include <Leg_Model_Entity.hxx>

namespace AutLib
{

	class Leg_Model_Vessel
		: public Leg_Model_Entity
	{

		/*Private Data*/

	protected:

		Leg_Model_Vessel()
		{}

		Leg_Model_Vessel(const Standard_Integer theIndex)
			: Leg_Model_Entity(theIndex, "Vessel Entity")
		{}

		Leg_Model_Vessel(const Standard_Integer theIndex, const word& theName)
			: Leg_Model_Entity(theIndex, theName)
		{}

	public:

		TopoDS_Shape GetStation(const Standard_Real theX) const;

		TopoDS_Shape GetButtock(const Standard_Real theY) const;

		TopoDS_Shape GetWater(const Standard_Real theZ) const;

	};
}

#endif // !_Leg_Model_Vessel_Header
