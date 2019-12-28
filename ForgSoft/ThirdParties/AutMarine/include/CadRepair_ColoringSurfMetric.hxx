#pragma once
#ifndef _CadRepair_ColoringSurfMetric_Header
#define _CadRepair_ColoringSurfMetric_Header

#include <Global_Done.hxx>
#include <Mesh2d_ElementFwd.hxx>
#include <OFstream.hxx>
#include <error.hxx>
#include <OSstream.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	class CadRepair_ApproxSurfMetric;
	class Pnt2d;

	struct CadRepair_ColoringSurfMetric_Base
	{

		typedef std::pair
			<
			std::shared_ptr<Mesh2d_Element>,
			Standard_Integer>
			elementColor;
	};

	class CadRepair_ColoringSurfMetric
		: public CadRepair_ColoringSurfMetric_Base
		, public Global_Done
	{

		/*Private Data*/

		std::vector<elementColor> theElements_;

		std::shared_ptr<CadRepair_ApproxSurfMetric> theApprox_;

	public:

		CadRepair_ColoringSurfMetric()
		{}

		CadRepair_ColoringSurfMetric
		(
			const std::shared_ptr<CadRepair_ApproxSurfMetric>& theApprox
		)
			: theApprox_(theApprox)
		{}

		Standard_Boolean IsLoaded() const
		{
			return (Standard_Boolean)theApprox_;
		}

		Standard_Integer Value(const Standard_Integer theIndex) const
		{
			Debug_If_Condition(NOT IsDone());
			return theElements_[theIndex].second;
		}

		Standard_Integer Value(const Pnt2d& theCoord) const;

		const std::shared_ptr<Mesh2d_Element>& Element
		(
			const Standard_Integer theIndex
		) const
		{
			Debug_If_Condition(NOT IsDone());
			return theElements_[theIndex].first;
		}

		const std::shared_ptr<CadRepair_ApproxSurfMetric>& Approx() const
		{
			return theApprox_;
		}

		void Perform();

		void LoadApproxMetric
		(
			const std::shared_ptr<CadRepair_ApproxSurfMetric>& theApprox
		)
		{
			theApprox_ = theApprox;
		}

		void ExportColorsToPlt(OFstream& File) const;
	};
}

#endif // !_CadRepair_ColoringSurfMetric_Header
