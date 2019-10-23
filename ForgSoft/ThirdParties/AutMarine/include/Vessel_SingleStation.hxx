#pragma once
#ifndef _Vessel_SingleStation_Header
#define _Vessel_SingleStation_Header

#include <Vessel_Station.hxx>
#include <Marine_CompoundSectionFwd.hxx>

namespace AutLib
{

	class Vessel_SingleStation
		: public Vessel_Station
	{

		/*Private Data*/

		std::shared_ptr<marineLib::cmpSectCurve> theCurve_;


		//- private functions and operators

		void CalcBoundingBox();

	protected:

		Vessel_SingleStation
		(
			const std::shared_ptr<marineLib::cmpSectCurve>& theCurve
		);

		Vessel_SingleStation
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<marineLib::cmpSectCurve>& theCurve
		);

	public:

		enum 
		{
			nbStations = 1
		};

		const std::shared_ptr<marineLib::cmpSectCurve>& Curve() const
		{
			return theCurve_;
		}

		//- override functions and operators

		Standard_Integer NbStations() const override
		{
			return (Standard_Integer)nbStations;
		}

		std::shared_ptr<Vessel_SingleStation> 
			Station
			(
				const Standard_Integer theIndex
			) const override
		{
			auto ptr = 
				std::dynamic_pointer_cast<Vessel_SingleStation>(std::const_pointer_cast<Vessel_Station>(shared_from_this()));
			return std::move(ptr);
		}

		Standard_Boolean IsSingle() const override
		{
			return Standard_True;
		}

		Standard_Real CalcLength() const override;
	};
}

#endif // !_Vessel_SingleStation_Header
