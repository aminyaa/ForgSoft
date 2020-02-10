#pragma once
#ifndef _LegModel_SectionCtrlPts_Header
#define _LegModel_SectionCtrlPts_Header

#include <LegModel_PointList.hxx>

#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array2OfReal.hxx>

#include <memory>
#include <vector>

namespace tnbLib
{

	class LegModel_SectionCtrlPts
	{

		/*Private Data*/

		legModel::pointList thePoints_;

	public:

		LegModel_SectionCtrlPts()
		{}

		const auto& Points() const
		{
			return thePoints_;
		}

		auto& Points()
		{
			return thePoints_;
		}

		virtual Standard_Boolean HasCorner() const
		{
			return Standard_False;
		}
	};

	class LegModel_CorneredSectionCtrlPts
		: public LegModel_SectionCtrlPts
	{

		/*Private Data*/

		Standard_Integer theCorner_;

	public:

		LegModel_CorneredSectionCtrlPts()
			: theCorner_(0)
		{}

		auto Corner() const
		{
			return theCorner_;
		}

		auto& Corner()
		{
			return theCorner_;
		}

		//- override functions and operators

		Standard_Boolean HasCorner() const override
		{
			return Standard_True;
		}
	};

	namespace legModel
	{

		typedef std::vector<std::shared_ptr<LegModel_SectionCtrlPts>>
			sectionCPtsList;

		typedef TColgp_Array2OfPnt ctrlNet;
		typedef TColStd_Array2OfReal weightNet;
	}
}

#endif // !_LegModel_SectionCtrlPts_Header
