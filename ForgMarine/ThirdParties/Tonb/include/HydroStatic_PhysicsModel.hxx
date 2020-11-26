#pragma once
#ifndef _HydroStatic_PhysicsModel_Header
#define _HydroStatic_PhysicsModel_Header

#include <Marine_PhysicsModel.hxx>
#include <Marine_ThreeDimensional.hxx>
#include <Marine_Steady.hxx>

namespace tnbLib
{

	class HydroStatic_PhysicsModel
		: public Marine_PhysicsModel
		, public Marine_Steady
		, public Marine_ThreeDimensional
	{

		/*Private Data*/

	protected:

		HydroStatic_PhysicsModel();
	};
}

#endif // !_HydroStatic_PhysicsModel_Header
