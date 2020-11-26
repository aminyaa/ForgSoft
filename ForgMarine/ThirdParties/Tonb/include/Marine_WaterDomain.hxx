#pragma once
#ifndef _Marine_WaterDomain_Header
#define _Marine_WaterDomain_Header

#include <Global_Done.hxx>
#include <Marine_Entity.hxx>
#include <Entity3d_Box.hxx>
#include <OFstream.hxx>

#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class Marine_Section;
	class Marine_Domain;

	class Marine_WaterDomain
		: public Marine_Entity
		, public Global_Done
	{

		/*Private Data*/

		std::vector<std::shared_ptr<Marine_Section>> theWaters_;

		std::shared_ptr<Marine_Domain> theDomain_;

	protected:

		Marine_WaterDomain
		(
			const std::shared_ptr<Marine_Domain>& theDomain
		);

		Marine_WaterDomain
		(
			const Standard_Integer theIndex, 
			const std::shared_ptr<Marine_Domain>& theDomain
		);

		Marine_WaterDomain
		(
			const Standard_Integer theIndex, 
			const word& theName, 
			const std::shared_ptr<Marine_Domain>& theDomain
		);

		auto& ChangeWaters()
		{
			return theWaters_;
		}

	public:

		const auto& Domain() const
		{
			return theDomain_;
		}

		const auto& Waters() const
		{
			return theWaters_;
		}

		void ExportToPlt(OFstream& File) const;
	};
}

#endif // !_Marine_WaterDomain_Header
