#pragma once
#ifndef _CrossSection_ShapeStation_Header
#define _CrossSection_ShapeStation_Header

#include <Marine_CrossSection.hxx>
#include <TopoDS_Shape.hxx>

namespace tnbLib
{

	// Forward Declarations
	class Marine_SectionDistribution;

	class CrossSection_xShapeStation
		: public Marine_CrossSection
	{

		/*Private Data*/

		TopoDS_Shape theShape_;

		std::shared_ptr<Marine_SectionDistribution> theDistributor_;

	public:

		CrossSection_xShapeStation(const gp_Ax2& theSystem)
			: Marine_CrossSection(theSystem)
		{}

		const auto& Shape() const
		{
			return theShape_;
		}

		const auto& Distributor() const
		{
			return theDistributor_;
		}

		void LoadShape
		(
			const TopoDS_Shape& theShape
		)
		{
			theShape_ = theShape;
		}

		void LoadDistributor
		(
			const std::shared_ptr<Marine_SectionDistribution>& theDistributor
		)
		{
			theDistributor_ = theDistributor;
		}

		void Perform();


	};
}

#endif // !_CrossSection_ShapeStation_Header
