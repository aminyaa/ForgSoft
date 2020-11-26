#pragma once
#ifndef _HydroStatic_Region_Header
#define _HydroStatic_Region_Header

#include <Marine_Region.hxx>

#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class HydroStatic_Boundary;
	class TModel_Shell;

	class HydroStatic_Region
		: public Marine_Region
	{

		/*Private Data*/

		std::shared_ptr<TModel_Shell> theFar_;
		std::shared_ptr<TModel_Shell> theHull_;

		std::vector<std::shared_ptr<TModel_Shell>> theTanks_;
		std::vector<std::shared_ptr<TModel_Shell>> theSails_;


		std::vector<std::shared_ptr<HydroStatic_Boundary>>
			RetrieveFarBoundaries() const;

		std::vector<std::shared_ptr<HydroStatic_Boundary>>
			RetrieveHullBoundaries() const;

		std::vector<std::shared_ptr<HydroStatic_Boundary>>
			RetrieveSailBoundaries() const;

		std::vector<std::shared_ptr<HydroStatic_Boundary>>
			RetrieveTankBoundaries() const;

		void SetBoundaries();

		void CkeckBoundaries();

	public:

		HydroStatic_Region();

		HydroStatic_Region
		(
			const Standard_Integer theIndex
		);

		HydroStatic_Region
		(
			const Standard_Integer theIndex, 
			const word& theName
		);


		const auto& Far() const
		{
			return theFar_;
		}

		const auto& Hull() const
		{
			return theHull_;
		}

		const auto& Sails() const
		{
			return theSails_;
		}

		const auto& Tanks() const
		{
			return theTanks_;
		}

		void Perform();
	};
}

#endif // !_HydroStatic_Region_Header
