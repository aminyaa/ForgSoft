#pragma once
#ifndef _Marine_ModelMaker_Shape_Header
#define _Marine_ModelMaker_Shape_Header

#include <Marine_ModelMaker.hxx>
#include <TopoDS_Shape.hxx>

namespace tnbLib
{

	// Forward Declarations
	class Marine_SectionDistribution;

	class Marine_ModelMaker_Shape
		: public Marine_ModelMaker
	{

		/*Private Data*/

		TopoDS_Shape theShape_;

		std::shared_ptr<Marine_SectionDistribution> theDistributor_;
		

	public:

		Marine_ModelMaker_Shape()
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

#endif // !_Marine_ModelMaker_Shape_Header
