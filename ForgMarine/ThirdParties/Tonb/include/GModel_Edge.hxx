#pragma once
#ifndef _GModel_Edge_Header
#define _GModel_Edge_Header

#include <GModel_Entity.hxx>

namespace tnbLib
{

	// Forward Declarations
	class GModel_ParaCurve;
	class GModel_Curve;

	class GModel_Edge
		: public GModel_Entity
	{

		/*Private Data*/

		std::shared_ptr<GModel_ParaCurve> thePar_;
		std::shared_ptr<GModel_Curve> theCurve_;

	public:

		GModel_Edge
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<GModel_ParaCurve>& thePar,
			const std::shared_ptr<GModel_Curve>& theCurve
		);

		GModel_Edge
		(
			const Standard_Integer theIndex, 
			const word& theName,
			const std::shared_ptr<GModel_ParaCurve>& thePar,
			const std::shared_ptr<GModel_Curve>& theCurve
		);

		const auto& Par() const
		{
			return thePar_;
		}

		const auto& Curve() const
		{
			return theCurve_;
		}
	};
}

#endif // !_GModel_Edge_Header
