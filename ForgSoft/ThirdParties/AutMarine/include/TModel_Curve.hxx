#pragma once
#ifndef _TModel_Curve_Header
#define _TModel_Curve_Header

#include <Standard_TypeDef.hxx>
#include <TModel_Entity.hxx>
#include <Cad_Curve.hxx>
#include <Pnt3d.hxx>
#include <Entity3d_BoxFwd.hxx>
#include <OFstream.hxx>

#include <Standard_Handle.hxx>
#include <Precision.hxx>

class Geom_Curve;

namespace AutLib
{

	// Forward Declarations
	class Cad_CurveInfo;

	class TModel_Curve
		: public TModel_Entity
		, public Cad_Curve<Geom_Curve>
	{

		/*Private Data*/

		std::shared_ptr<Cad_CurveInfo> theInfo_;

	public:

		TModel_Curve
		(
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const Handle(Geom_Curve)& theCurve,
			const std::shared_ptr<Cad_CurveInfo>& theInfo
		)
			: Cad_Curve<Geom_Curve>(theFirst, theLast, theCurve)
			, theInfo_(theInfo)
		{}

		Standard_Boolean IsClosed
		(
			const Standard_Real theTol = Precision::Confusion()
		) const;

		Standard_Boolean IsDegenerated
		(
			const Standard_Real theTol = Precision::PConfusion()
		) const
		{
			return ABS(FirstParam() - LastParam()) <= theTol;
		}

		Standard_Real IsValid() const
		{
			return FirstParam() <= LastParam();
		}

		const std::shared_ptr<Cad_CurveInfo>& Info() const
		{
			return theInfo_;
		}

		Pnt3d Start() const;

		Pnt3d Last() const;

		Pnt3d Value(const Standard_Real x) const;

		Pnt3d NormalizedParameterValue(const Standard_Real x) const;

		Entity3d_Box BoundingBox(const Standard_Real theTol = 0.0) const;

		void Split
		(
			const Standard_Real x,
			std::shared_ptr<TModel_Curve>& theC1,
			std::shared_ptr<TModel_Curve>& theC2
		) const;

		void OverrideInfo(const std::shared_ptr<Cad_CurveInfo>& theInfo)
		{
			theInfo_ = theInfo;
		}

		//- IO functions and operators

		void ExportToPlt(OFstream& File) const;
	};
}

#endif // !_TModel_Curve_Header
