#pragma once
#ifndef _Marine_SingleStation_Header
#define _Marine_SingleStation_Header

#include <Marine_VesselStation.hxx>

namespace AutLib
{

	class Marine_SingleStation
		: public Marine_VesselStation
	{

		/*Private Data*/

		std::shared_ptr<marineLib::cmpSectCurve> theCurve_;


		//- private functions and operators

		void CalcBoundingBox();

	protected:

		Marine_SingleStation
		(
			const std::shared_ptr<marineLib::cmpSectCurve>& theCurve
		);

	public:


		const std::shared_ptr<marineLib::cmpSectCurve>& Curve() const
		{
			return theCurve_;
		}

		//- override functions and operators

		Standard_Real CalcLength() const override;
	};
}

#endif // !_Marine_SingleStation_Header
