#pragma once
#ifndef _Pln_IntsctSegment_Header
#define _Pln_IntsctSegment_Header

#include <Pln_IntsctEntity.hxx>
#include <Standard_Handle.hxx>
#include <Pnt2d.hxx>

class Geom2d_Curve;

namespace AutLib
{

	// Forward Declarations

	class Pln_IntsctSegment
		: public Pln_IntsctEntity
	{

		/*Private Data*/

		Pnt2d theCoord0_;
		Pnt2d theCoord1_;

		Standard_Boolean HasFirstPoint_;
		Standard_Boolean HasLastPoint_;

		Standard_Real theParameter0_;
		Standard_Real theParameter1_;

		Handle(Geom2d_Curve) theSegment_;

	public:

		Pln_IntsctSegment()
		{}

		Pln_IntsctSegment
		(
			const std::shared_ptr<Pln_Edge>& theEdge,
			const Pnt2d& theCoord0, 
			const Pnt2d& theCoord1,
			const Standard_Real theParam0, 
			const Standard_Real theParam1,
			const Handle(Geom2d_Curve)& theSegment
		)
			: Pln_IntsctEntity(theEdge)
			, theCoord0_(theCoord0)
			, theCoord1_(theCoord1)
			, theParameter0_(theParam0)
			, theParameter1_(theParam1)
			, theSegment_(theSegment)
		{}

		Standard_Boolean IsSegment() const override
		{
			return Standard_True;
		}

		Standard_Boolean HasFirstPoint() const
		{
			return HasFirstPoint_;
		}

		Standard_Boolean HasLastPoint() const
		{
			return HasLastPoint_;
		}

		Standard_Real MidParameter() const override
		{
			Debug_If_Condition(NOT HasFirstPoint_);
			Debug_If_Condition(NOT HasLastPoint_);

			return MEAN(theParameter0_, theParameter1_);
		}

		void SetFirstPointCondition(const Standard_Boolean cond)
		{
			HasFirstPoint_ = cond;
		}

		void SetLastPointCondition(const Standard_Boolean cond)
		{
			HasLastPoint_ = cond;
		}

		//- Macros
		GLOBAL_ACCESS_SINGLE(Pnt2d, Coord0)
			GLOBAL_ACCESS_SINGLE(Pnt2d, Coord1)

			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Parameter0)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, Parameter1)

			GLOBAL_ACCESS_SINGLE(Handle(Geom2d_Curve), Segment)
	};
}

#endif // !_Pln_IntscSegment_Header
