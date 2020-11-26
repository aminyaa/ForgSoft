#pragma once
#ifndef _Pln_Curve_Header
#define _Pln_Curve_Header

#include <Standard_Handle.hxx>
#include <Global_AccessMethod.hxx>
#include <Pln_Entity.hxx>
#include <Pnt2d.hxx>
#include <Entity2d_BoxFwd.hxx>
#include <Entity2d_PolygonFwd.hxx>

class Geom2d_Curve;
class gp_Ax2d;
class gp_Ax22d;
class gp_Trsf2d;

#include <memory>
#include <vector>
#include <tuple>

namespace tnbLib
{

	// Forward Declarations
	class Cad2d_IntsctEntity_TangSegment;

	class Pln_Curve
		: public Pln_Entity
	{

		/*Private Data*/

		//- must be bounded
		Handle(Geom2d_Curve) theGeometry_;


		auto& ChangeGeometry()
		{
			return theGeometry_;
		}

		void CheckBoundary(const Standard_Real x, const char* theName) const;

	public:

		typedef Pnt2d ptType;

		Pln_Curve()
		{}

		Pln_Curve
		(
			const Standard_Integer theIndex,
			const Handle(Geom2d_Curve)& theGeom
		);

		Pln_Curve
		(
			const Handle(Geom2d_Curve)& theGeom
		);

		Pln_Curve
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Handle(Geom2d_Curve)& theGeom
		);

		const auto& Geometry() const
		{
			return theGeometry_;
		}

		Standard_Real FirstParameter() const;

		Standard_Real LastParameter() const;

		Pnt2d Value(const Standard_Real x) const;

		Pnt2d Value_normParam(const Standard_Real x) const;

		Pnt2d FirstCoord() const;

		Pnt2d LastCoord() const;

		Entity2d_Box CalcBoundingBox() const;

		std::shared_ptr<Pln_Entity>
			Copy() const override;

		void Transform(const gp_Trsf2d& t);

		void Interpolation
		(
			const std::vector<Pnt2d>& theQ,
			const Standard_Integer theDeg = 2, 
			const Standard_Real theTol = 1.0E-6
		);

		virtual std::tuple<std::shared_ptr<Pln_Curve>, std::shared_ptr<Pln_Curve>>
			Split(const Standard_Real x) const;

		virtual void Split
		(
			const Standard_Real x,
			std::shared_ptr<Pln_Curve>& theLeft,
			std::shared_ptr<Pln_Curve>& theRight
		) const;

		virtual void Split
		(
			const Standard_Real x,
			Pnt2d& theCoord,
			std::shared_ptr<Pln_Curve>& theLeft,
			std::shared_ptr<Pln_Curve>& theRight
		) const;

		std::vector<std::shared_ptr<Pln_Curve>> Split
		(
			const std::vector<Standard_Real>& theParameters
		) const;

		void Split
		(
			const std::vector<Standard_Real>& theParameters,
			std::vector<Pnt2d>& theCoords,
			std::vector<std::shared_ptr<Pln_Curve>>& theCurves
		) const;

		virtual std::tuple
			<
			std::shared_ptr<Pln_Curve>,
			std::shared_ptr<Pln_Curve>,
			std::shared_ptr<Pln_Curve>
			>
			Split
			(
				const Cad2d_IntsctEntity_TangSegment& x
			) const;

		virtual Standard_Boolean IsTangential() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsOnWater() const
		{
			return Standard_False;
		}

		// Static functions and operators

		static std::shared_ptr<Pln_Curve> 
			Clip
			(
				const Pln_Curve& theCurve,
				const Standard_Real theP0,
				const Standard_Real theP1
			);

		static std::shared_ptr<Entity2d_Polygon>
			Discretize
			(
				const Pln_Curve& theCurve,
				const Standard_Integer theNbSegments
			);

		static std::shared_ptr<Pln_Curve>
			MakeLineSegment
			(
				const Pnt2d& theP0,
				const Pnt2d& theP1
			);

		static std::shared_ptr<Pln_Curve>
			MakeCircularArc
			(
				const gp_Ax22d& A,
				const Standard_Real Radius,
				const Standard_Real theDeg0,
				const Standard_Real theDeg1
			);

		static std::shared_ptr<Pln_Curve>
			MakeCircularArc
			(
				const gp_Ax2d& A,
				const Standard_Real Radius,
				const Standard_Real theDeg0,
				const Standard_Real theDeg1,
				const Standard_Boolean Sense = Standard_True
			);

		static std::shared_ptr<Pln_Curve> 
			MakeEllipse
			(
				const gp_Ax2d& MajorAxis,
				const Standard_Real MajorRadius,
				const Standard_Real MinorRadius,
				const Standard_Boolean Sense = Standard_True
			);

		static std::shared_ptr<Pln_Curve> 
			MakeEllipse
			(
				const gp_Ax22d& Axis,
				const Standard_Real MajorRadius,
				const Standard_Real MinorRadius
			);

		//- Macros


	};
}

#include <Pln_CurveI.hxx>

#endif // !_Pln_Curve_Header
