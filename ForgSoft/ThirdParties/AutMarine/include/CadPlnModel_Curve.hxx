#pragma once
#ifndef _CadPlnModel_Curve_Header
#define _CadPlnModel_Curve_Header

#include <CadPlnModel_Entity.hxx>

namespace AutLib
{

	// Forward Declarations
	class Pln_Curve;

	class CadPlnModel_Curve
		: public CadPlnModel_Entity
	{

		/*Private Data*/

	protected:

		CadPlnModel_Curve()
		{}

		CadPlnModel_Curve
		(
			const Standard_Integer theIndex, 
			const word& theName
		)
			: CadPlnModel_Entity(theIndex, theName)
		{}

	public:

		std::shared_ptr<Pln_Curve> Curve() const;

		Pnt2d P0() const;

		Pnt2d P1() const;

		void Discrete
		(
			const std::shared_ptr<Geo_ApprxCurveInfo>& theInfo
		) const override;
	};
}

#endif // !_CadPlnModel_Curve_Header
