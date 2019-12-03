#pragma once
#ifndef _Pln_IntsctPoint_Header
#define _Pln_IntsctPoint_Header

#include <Pln_IntsctEntity.hxx>
#include <Pnt2d.hxx>

class Geom2dInt_GInter;

namespace AutLib
{

	

	class Pln_IntsctPoint
		: public Pln_IntsctEntity
	{

		/*Private Data*/

		Pnt2d theCoord_;

		Standard_Real theParameter_;
		

	public:

		Pln_IntsctPoint()
		{}

		Pln_IntsctPoint
		(
			const std::shared_ptr<Pln_Edge>& theEdge, 
			const Pnt2d& theCoord,
			const Standard_Real theParameter
		)
			: Pln_IntsctEntity(theEdge)
			, theCoord_(theCoord)
			, theParameter_(theParameter)
		{}

		Standard_Boolean IsPoint() const override
		{
			return Standard_True;
		}

		Standard_Real MidParameter() const override
		{
			return theParameter_;
		}

		// macros

		GLOBAL_ACCESS_SINGLE(Pnt2d, Coord)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Parameter)

	};
}

#endif // !_Pln_IntsctPoint_Header
