#pragma once
#ifndef _HydroStatic_Boundary_Header
#define _HydroStatic_Boundary_Header

#include <Marine_Boundary.hxx>
#include <HsBnd_Type.hxx>

namespace tnbLib
{

	class HydroStatic_Boundary
		: public Marine_Boundary
	{

		/*Private Data*/

		HsBnd_Type theType_;


	public:

		HydroStatic_Boundary();

		HydroStatic_Boundary(const Standard_Integer theIndex);

		HydroStatic_Boundary(const Standard_Integer theIndex, const word& theName);

		
		//- Macros
		GLOBAL_ACCESS_PRIM_SINGLE(HsBnd_Type, Type)
	};
}

#endif // !_HydroStatic_Boundary_Header
