#pragma once
#ifndef _Marine_WaterCurve_Header
#define _Marine_WaterCurve_Header

#include <Pln_Curve.hxx>

namespace tnbLib
{

	class Marine_WaterCurve
		: public Pln_Curve
	{

		/*Private Data*/

	public:

		Marine_WaterCurve();

		Marine_WaterCurve
		(
			const Standard_Integer theIndex,
			const Handle(Geom2d_Curve)& theGeom
		);

		Marine_WaterCurve
		(
			const Handle(Geom2d_Curve)& theGeom
		);

		Marine_WaterCurve
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Handle(Geom2d_Curve)& theGeom
		);


		Standard_Boolean IsOnWater() const override
		{
			return Standard_True;
		}

		std::shared_ptr<Pln_Entity>
			Copy() const override;

		std::tuple<std::shared_ptr<Pln_Curve>, std::shared_ptr<Pln_Curve>>
			Split
			(
				const Standard_Real x
			) const override;

		void Split
		(
			const Standard_Real x,
			std::shared_ptr<Pln_Curve>& theLeft,
			std::shared_ptr<Pln_Curve>& theRight
		) const override;

		void Split
		(
			const Standard_Real x,
			Pnt2d& theCoord,
			std::shared_ptr<Pln_Curve>& theLeft,
			std::shared_ptr<Pln_Curve>& theRight
		) const override;

		std::tuple
			<
			std::shared_ptr<Pln_Curve>,
			std::shared_ptr<Pln_Curve>,
			std::shared_ptr<Pln_Curve>
			>
			Split
			(
				const Cad2d_IntsctEntity_TangSegment& x
			) const override;

	};
}

#endif // !_Marine_WaterCurve_Header
