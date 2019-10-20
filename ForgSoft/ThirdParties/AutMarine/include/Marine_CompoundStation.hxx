#pragma once
#ifndef _Marine_CompoundStation_Header
#define _Marine_CompoundStation_Header

#include <Marine_VesselStation.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	class Marine_SingleStation;

	class Marine_CompoundStation
	{

		typedef std::vector<std::shared_ptr<Marine_SingleStation>> stationList;

		/*Private Data*/

		stationList theStations_;

	public:

		Marine_CompoundStation()
		{}

		const stationList& Stations() const
		{
			return theStations_;
		}

		const std::shared_ptr<Marine_SingleStation>&
			Station
			(
				const Standard_Integer theIndex
			) const
		{
			return theStations_[theIndex];
		}

		void InsertStation
		(
			const std::shared_ptr<Marine_SingleStation>& theStation
		)
		{
			theStations_.push_back(theStation);
		}

	};
}

#endif // !_Marine_CompoundStation_Header
