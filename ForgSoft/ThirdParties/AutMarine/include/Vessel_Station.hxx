#pragma once
#ifndef _Vessel_Station_Header
#define _Vessel_Station_Header

#include <Global_Indexed.hxx>
#include <Global_Named.hxx>
#include <Entity2d_Box.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	// Forward Declarations
	class Vessel_SingleStation;

	class Vessel_Station
		: public Global_Indexed
		, public Global_Named
		, public std::enable_shared_from_this<Vessel_Station>
	{

		typedef std::pair<Standard_Real, Standard_Real> bounds;

		/*Private Data*/

		Entity2d_Box theBox_;

	protected:

		Vessel_Station()
		{}

		Vessel_Station(const Standard_Integer theIndex, const word& theName)
			: Global_Indexed(theIndex)
			, Global_Named(theName)
		{}

		Entity2d_Box& ChangeBoundingBox()
		{
			return theBox_;
		}

	public:

		virtual ~Vessel_Station()
		{}


		const Entity2d_Box& BoundingBox() const
		{
			return theBox_;
		}


		bounds CalcBreadth(const Standard_Real theZ) const;

		bounds CalcDepth(const Standard_Real theY) const;

		Standard_Real CalcArea(const Standard_Real theTol) const;

		Standard_Real Calc_zBar(const Standard_Real theDraft, const Standard_Real theTol) const;

		Standard_Real Z0() const;

		Standard_Real Z1() const;

		Standard_Real Y0() const;

		Standard_Real Y1() const;

		//- virtual functions and operators

		virtual Standard_Boolean IsSingle() const
		{
			return Standard_False;
		}

		virtual Standard_Boolean IsCompound() const
		{
			return Standard_False;
		}

		virtual Standard_Integer NbStations() const = 0;

		virtual std::shared_ptr<Vessel_SingleStation> Station(const Standard_Integer theIndex) const = 0;

		virtual Standard_Real CalcLength() const = 0;
	};

	namespace marineLib
	{
		typedef std::vector<std::shared_ptr<Vessel_Station>> stationList;
	}
}

#endif // !_Vessel_Station_Header
