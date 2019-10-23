#pragma once
#ifndef _Vessel_Stations_Header
#define _Vessel_Stations_Header

#include <Vessel_Station.hxx>
#include <Global_AccessMethod.hxx>

namespace AutLib
{

	class Vessel_Stations
		: public Global_Indexed
		, public Global_Named
	{

		typedef std::shared_ptr<Vessel_Station> cmpStation;

		/*Private Data*/

		marineLib::stationList theStations_;

		cmpStation theMidShip_;
		//cmpStation theApp_;

	public:

		Vessel_Stations()
		{}

		Vessel_Stations(const Standard_Integer theIndex, const word& theName)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
		{}

		Standard_Integer NbStations() const
		{
			return (Standard_Integer)theStations_.size();
		}

		const cmpStation& Station(const Standard_Integer theIndex) const
		{
			return theStations_[theIndex];
		}

		void InsertStation(const cmpStation& theStation)
		{
			theStations_.push_back(theStation);
		}

		//- Macros
		
		GLOBAL_ACCESS_SINGLE(cmpStation, MidShip)
			//GLOBAL_ACCESS_SINGLE(cmpStation, App)

	};
}

#endif // !_Vessel_Stations_Header
