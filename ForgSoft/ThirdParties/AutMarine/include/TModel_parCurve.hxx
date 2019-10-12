#pragma once
#ifndef _TModel_parCurve_Header
#define _TModel_parCurve_Header

#include <TModel_Entity.hxx>
#include <Cad_Curve.hxx>
#include <Entity2d_BoxFwd.hxx>
#include <OFstream.hxx>

class Geom2d_Curve;
#include <Precision.hxx>

#include <memory>
#include <vector>
#include <list>

namespace AutLib
{

	// Forward Declarations
	class Cad_CurveInfo;

	class TModel_parCurve
		: public TModel_Entity
		, public Cad_Curve<Geom2d_Curve>
	{

		typedef std::shared_ptr<TModel_parCurve> pCurve_ptr;
		typedef std::vector<std::shared_ptr<TModel_parCurve>> curveList;

		/*Private Data*/

		std::shared_ptr<Cad_CurveInfo> theInfo_;

	public:

		TModel_parCurve
		(
			const Standard_Real theFirst,
			const Standard_Real theLast,
			const Handle(Geom2d_Curve)& theCurve,
			const std::shared_ptr<Cad_CurveInfo>& theInfo
		)
			: Cad_Curve<Geom2d_Curve>(theFirst, theLast, theCurve)
			, theInfo_(theInfo)
		{}

		const std::shared_ptr<Cad_CurveInfo>& Info() const
		{
			return theInfo_;
		}

		Standard_Boolean IsClosed
		(
			const Standard_Real theTol = Precision::Confusion()
		) const;

		Pnt2d Start() const;

		Pnt2d Last() const;

		Pnt2d Value(const Standard_Real x) const;

		Pnt2d NormalizedParameterValue
		(
			const Standard_Real x
		) const;

		Entity2d_Box BoundingBox
		(
			const Standard_Real theTol = 0.0
		) const;

		void ReverseGeometry();

		virtual void Split
		(
			const Standard_Real x,
			std::shared_ptr<TModel_parCurve>& theC1,
			std::shared_ptr<TModel_parCurve>& theC2
		) const;

		virtual void BSplineSplit
		(
			const Standard_Real x,
			std::shared_ptr<TModel_parCurve>& theC1,
			std::shared_ptr<TModel_parCurve>& theC2
		) const;

		virtual curveList Split
		(
			const std::list<Standard_Real>& theParams,
			const Standard_Real theTol
		) const;

		virtual curveList BSplineSplit
		(
			const std::list<Standard_Real>& theParams,
			const Standard_Real theTol
		) const;

		void OverrideInfo(const std::shared_ptr<Cad_CurveInfo>& theInfo)
		{
			theInfo_ = theInfo;
		}


		//- IO functions and operators

		void ExportToPlt(OFstream& File) const;
	};
}

#endif // !_TModel_parCurve_Header
