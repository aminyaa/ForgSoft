#pragma once
#ifndef _GModel_parCurve_Header
#define _GModel_parCurve_Header

#include <GModel_Entity.hxx>
#include <Cad_Curve.hxx>
#include <OFstream.hxx>
#include <Pnt2d.hxx>

#include <Precision.hxx>

class Geom2d_Curve;

#include <memory>
#include <vector>
#include <list>

namespace AutLib
{

	// Forward Declarations
	class Cad_CurveInfo;

	class GModel_parCurve
		: public GModel_Entity
		, public Cad_Curve<Geom2d_Curve>
	{

		typedef std::shared_ptr<GModel_parCurve> pCurve_ptr;
		typedef std::vector<std::shared_ptr<GModel_parCurve>> curveList;

		/*Private Data*/

		std::shared_ptr<Cad_CurveInfo> theInfo_;

	public:

		GModel_parCurve
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
			std::shared_ptr<GModel_parCurve>& theC1,
			std::shared_ptr<GModel_parCurve>& theC2
		) const;

		virtual void BSplineSplit
		(
			const Standard_Real x,
			std::shared_ptr<GModel_parCurve>& theC1,
			std::shared_ptr<GModel_parCurve>& theC2
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


		//- Io functions and operators

		void ExportToPlt(OFstream& File) const;


		//- Static functions and operators


	};
}

#endif // !_GModel_parCurve_Header
