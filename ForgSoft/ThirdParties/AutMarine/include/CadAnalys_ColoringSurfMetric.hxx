#pragma once
#ifndef _CadAnalys_ColoringSurfMetric_Header
#define _CadAnalys_ColoringSurfMetric_Header

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
	class CadAnalys_ApprxSurfMetric;
	class Pnt2d;

	struct CadAnalys_ColoringSurfMetric_Base
	{

		typedef std::pair<std::shared_ptr<Mesh2d_Element>, Standard_Integer> elementColor;
	};

	class CadAnalys_ColoringSurfMetric
		: public Global_Done
		, public CadAnalys_ColoringSurfMetric_Base
	{

		/*Private Data*/

		std::vector<elementColor> theElements_;

		std::shared_ptr<CadAnalys_ApprxSurfMetric> theApprox_;

	public:

		CadAnalys_ColoringSurfMetric()
		{}

		CadAnalys_ColoringSurfMetric
		(
			const std::shared_ptr<CadAnalys_ApprxSurfMetric>& theApprox
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

		const std::shared_ptr<CadAnalys_ApprxSurfMetric>& Approx() const
		{
			return theApprox_;
		}

		void Perform();

		void LoadApproxMetric
		(
			const std::shared_ptr<CadAnalys_ApprxSurfMetric>& theApprox
		)
		{
			theApprox_ = theApprox;
		}

		void ExportColorsToPlt(OFstream& File) const;
	};
}

#endif // !_CadAnalys_ColoringSurfMetric_Header
