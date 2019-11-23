#pragma once
#ifndef _Leg_Model_SectionCtrlPts_Header
#define _Leg_Model_SectionCtrlPts_Header

#include <Leg_Model_PointList.hxx>

#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array2OfReal.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	class Leg_Model_SectionCtrlPts
	{

		/*Private Data*/

		Leg_Model::pointList thePoints_;

	public:

		Leg_Model_SectionCtrlPts()
		{}

		const Leg_Model::pointList& Points() const
		{
			return thePoints_;
		}

		Leg_Model::pointList& Points()
		{
			return thePoints_;
		}

		virtual Standard_Boolean HasCorner() const
		{
			return Standard_False;
		}
	};


	class Leg_Model_CorneredSectionCtrlPts
		: public Leg_Model_SectionCtrlPts
	{

		/*Private Data*/

		Standard_Integer theCorner_;

	public:

		Leg_Model_CorneredSectionCtrlPts()
			: theCorner_(0)
		{}


		Standard_Integer Corner() const
		{
			return theCorner_;
		}

		Standard_Integer& Corner() 
		{
			return theCorner_;
		}


		//- override functions and operators

		Standard_Boolean HasCorner() const override
		{
			return Standard_True;
		}
	};


	namespace Leg_Model
	{

		typedef std::shared_ptr<Leg_Model_SectionCtrlPts> sectionCPts_ptr;
		typedef std::vector<sectionCPts_ptr> sectionCPtsList;

		typedef TColgp_Array2OfPnt ctrlNet;
		typedef std::shared_ptr<TColgp_Array2OfPnt> ctrlNet_ptr;

		typedef TColStd_Array2OfReal weightNet;
		typedef std::shared_ptr<TColStd_Array2OfReal> weightNet_ptr;
	}
}

#endif // !_Leg_Model_SectionCtrlPts_Header
