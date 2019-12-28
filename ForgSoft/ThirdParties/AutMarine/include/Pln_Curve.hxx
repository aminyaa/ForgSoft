#pragma once
#ifndef _Pln_Curve_Header
#define _Pln_Curve_Header

#include <Cad_Curve.hxx>
#include <Pln_Entity.hxx>
#include <Entity2d_Box.hxx>
#include <Entity2d_Polygon.hxx>

#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>

namespace AutLib
{

	// Forward Declarations
	class Cad_CurveInfo;

	class Pln_Curve
		: public Cad_Curve<Geom2d_Curve>
		, public Pln_Entity
	{

		typedef Cad_CurveInfo info;

		/*Private Data*/

		std::shared_ptr<info> theInfo_;

	public:

		typedef info infoType;
		typedef Geom2d_Curve geomType;
		typedef Cad_Curve<Geom2d_Curve> base;

		Pln_Curve(const std::shared_ptr<info>& theInfo)
			: theInfo_(theInfo)
		{}

		Pln_Curve
		(
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const Handle(Geom2d_Curve)& theCurve,
			const std::shared_ptr<info>& theInfo
		);

		Pln_Curve
		(
			const Standard_Integer theIndex,
			const word& theName,
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const Handle(Geom2d_Curve)& theCurve,
			const std::shared_ptr<info>& theInfo
		);

		void Init
		(
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const Handle(Geom2d_Curve)& theCurve
		);

		const std::shared_ptr<info>& Info() const
		{
			return theInfo_;
		}

		Standard_Boolean IsClosed
		(
			const Standard_Real theTolerance
		) const
		{
			return Distance(FirstCoord(), LastCoord())
				<= theTolerance;
		}

		Standard_Real CalcCurvature(const Standard_Real theParameter) const;

		Pnt2d Value(const Standard_Real theParam) const;

		Pnt2d FirstCoord() const
		{
			return Value(FirstParam());
		}

		Pnt2d LastCoord() const
		{
			return Value(LastParam());
		}

		Pnt2d NormalizedParameterValue
		(
			const Standard_Real theParam
		) const;

		Entity2d_Box BoundingBox() const;

		Standard_Boolean Interpolation
		(
			const std::vector<Pnt2d>& theQ,
			const Standard_Integer theDeg = 2,
			const Standard_Real theTolerance = 1.0E-6
		);

		void Split
		(
			const Standard_Real x,
			std::shared_ptr<Pln_Curve>& theLeft,
			std::shared_ptr<Pln_Curve>& theRight
		) const;

		void Split
		(
			const Standard_Real x,
			Pnt2d& theCoord,
			std::shared_ptr<Pln_Curve>& theLeft,
			std::shared_ptr<Pln_Curve>& theRight
		) const;

		template<bool Sorted = true>
		void Split
		(
			const std::vector<Standard_Real>& theParams,
			std::vector<Pnt2d>& theCoords,
			std::vector<std::shared_ptr<Pln_Curve>>& theCurves,
			const Standard_Real theTol = 1.0E-7
		) const;

		template<>
		void Split<false>
			(
				const std::vector<Standard_Real>& theParams,
				std::vector<Pnt2d>& theCoords,
				std::vector<std::shared_ptr<Pln_Curve>>& theCurves,
				const Standard_Real theTol
				) const;

		void ExportToPlt(fstream& File) const;

		void Mirror(const gp_Pnt2d& P);

		void Mirror(const gp_Ax2d& A);

		void Rotate(const gp_Pnt2d& P, const Standard_Real Ang);

		void Scale(const gp_Pnt2d& P, const Standard_Real S);

		void Translate(const gp_Vec2d& V);

		void Translate(const gp_Pnt2d& P1, const gp_Pnt2d& P2);

		void Transform(const gp_Trsf2d& T);

		// Static functions and operators

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
				const Pnt2d& theP1,
				const std::shared_ptr<info>& theInfo
			);

		static std::shared_ptr<Pln_Curve>
			MakeCircularArc
			(
				const gp_Ax22d& A,
				const Standard_Real Radius,
				const Standard_Real theDeg0,
				const Standard_Real theDeg1,
				const std::shared_ptr<info>& theInfo
			);

		static std::shared_ptr<Pln_Curve>
			MakeCircularArc
			(
				const gp_Ax2d& A,
				const Standard_Real Radius,
				const Standard_Real theDeg0,
				const Standard_Real theDeg1,
				const std::shared_ptr<info>& theInfo,
				const Standard_Boolean Sense = Standard_True
			);

		static std::shared_ptr<Pln_Curve> MakeEllipse(const gp_Ax2d& MajorAxis, const Standard_Real MajorRadius, const Standard_Real MinorRadius, const std::shared_ptr<info>& theInfo, const Standard_Boolean Sense = Standard_True);

		static std::shared_ptr<Pln_Curve> MakeEllipse(const gp_Ax22d& Axis, const Standard_Real MajorRadius, const Standard_Real MinorRadius, const std::shared_ptr<info>& theInfo);
	};
}

#endif // !_Pln_Curve_Header