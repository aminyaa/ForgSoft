#pragma once
#ifndef _Marine_VesselModel_Header
#define _Marine_VesselModel_Header

#include <Marine_Model.hxx>

#include <vector>
#include <map>

namespace tnbLib
{

	// Forward Declarations
	class Marine_CmpSection;

	class Marine_VesselModel
		: public Marine_Model
	{

		/*Private Data*/

		std::map<Standard_Integer, std::shared_ptr<Marine_CmpSection>>
			theSections_;

	public:

		Marine_VesselModel()
		{}

		Standard_Integer NbSections() const;

		const auto& Sections() const
		{
			return theSections_;
		}

		std::vector<std::shared_ptr<Marine_CmpSection>>
			SortedSections() const;

		void ImportSection(const Standard_Integer theIndex, const std::shared_ptr<Marine_CmpSection>& theSection);

		void RemoveSection(const Standard_Integer theIndex);

		Standard_Boolean IsVessel() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_Marine_VesselModel_Header