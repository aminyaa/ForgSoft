#pragma once
#ifndef _Marine_VesselStation_Header
#define _Marine_VesselStation_Header

#include <Marine_CompoundSectionFwd.hxx>
#include <Entity2d_Box.hxx>
#include <Global_Indexed.hxx>
#include <Global_Named.hxx>

#include <memory>
#include <vector>

namespace AutLib
{

	class Marine_VesselStation
		: public Global_Indexed
		, public Global_Named
	{

		/*Private Data*/


		Entity2d_Box theBox_;


		//- private functions and operators


	protected:

		Marine_VesselStation()
		{}


		Entity2d_Box& ChangeBoundingBox()
		{
			return theBox_;
		}

	public:

		virtual ~Marine_VesselStation()
		{}


		const Entity2d_Box& BoundingBox() const
		{
			return theBox_;
		}

		//- virtual functions and operators

		virtual Standard_Real CalcLength() const = 0;
	};

	namespace numLib
	{
		typedef std::vector<std::shared_ptr<Marine_VesselStation>> stationList;
	}
}

#endif // !_Marine_VesselStation_Header
