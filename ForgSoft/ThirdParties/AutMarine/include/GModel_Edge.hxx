#pragma once
#ifndef _GModel_Edge_Header
#define _GModel_Edge_Header

#include <GModel_Entity.hxx>

#include <memory>

class gp_Trsf2d;

namespace AutLib
{

	// Forward Declarations
	class GModel_parCurve;
	class GModel_Curve;

	class GModel_Edge
		: public GModel_Entity
	{

		/*Private Data*/

		std::shared_ptr<GModel_parCurve> thePar_;
		std::shared_ptr<GModel_Curve> theCurve_;

	public:

		GModel_Edge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<GModel_parCurve>& thePar,
			const std::shared_ptr<GModel_Curve>& theCurve
		)
			: GModel_Entity(theIndex)
			, thePar_(thePar)
			, theCurve_(theCurve)
		{}

		GModel_Edge
		(
			const Standard_Integer theIndex,
			const word& theName,
			const std::shared_ptr<GModel_parCurve>& thePar,
			const std::shared_ptr<GModel_Curve>& theCurve
		)
			: GModel_Entity(theIndex, theName)
			, thePar_(thePar)
			, theCurve_(theCurve)
		{}

		const std::shared_ptr<GModel_parCurve>& Par() const
		{
			return thePar_;
		}

		const std::shared_ptr<GModel_Curve>& Curve() const
		{
			return theCurve_;
		}


	};
}

#endif // !_GModel_Edge_Header
