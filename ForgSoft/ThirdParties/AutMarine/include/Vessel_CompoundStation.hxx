#pragma once
#ifndef _Vessel_CompoundStation_Header
#define _Vessel_CompoundStation_Header

#include <Vessel_Station.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	class Vessel_SingleStation;

	class Vessel_CompoundStation
		: public Vessel_Station
	{

		typedef std::vector<std::shared_ptr<Vessel_SingleStation>> stationList;

		/*Private Data*/

		stationList theStations_;

	public:

		Vessel_CompoundStation()
		{}

		Vessel_CompoundStation
		(
			const Standard_Integer theIndex, 
			const word& theName
		)
			: Vessel_Station(theIndex, theName)
		{}

		const stationList& Stations() const
		{
			return theStations_;
		}

		//- override functions and operators

		Standard_Integer NbStations() const override
		{
			return (Standard_Integer)theStations_.size();
		}

		std::shared_ptr<Vessel_SingleStation> Station(const Standard_Integer theIndex) const override
		{
			return theStations_[theIndex];
		}

		Standard_Boolean IsCompound() const override
		{
			return Standard_True;
		}
	};
}

#endif // !_Vessel_CompoundStation_Header
