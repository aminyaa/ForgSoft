#pragma once
#ifndef _CadPlnModel_Segment_Header
#define _CadPlnModel_Segment_Header

#include <CadPlnModel_Curve.hxx>

class gp_Ax2d;
class Geom2d_Curve;

namespace AutLib
{

	// Forward Declarations
	class Pnt2d;
	class Cad_CurveInfo;

	class CadPlnModel_Segment
		: public CadPlnModel_Curve
	{

		/*Private Data*/

		void Make
		(
			const Pnt2d& theP0, 
			const Pnt2d& theP1,
			const std::shared_ptr<Cad_CurveInfo>& theInfo
		);

	public:

		CadPlnModel_Segment()
		{}

		CadPlnModel_Segment
		(
			const Pnt2d& theP0, 
			const Pnt2d& theP1, 
			const std::shared_ptr<Cad_CurveInfo>& theInfo
		);

		CadPlnModel_Segment
		(
			const gp_Ax22d& theP0,
			const Standard_Real theLength,
			const std::shared_ptr<Cad_CurveInfo>& theInfo
		);

		std::shared_ptr<Pln_Curve> operator()
			(
				const Pnt2d& theP0,
				const Pnt2d& theP1, 
				const std::shared_ptr<Cad_CurveInfo>& theInfo
				);

		std::shared_ptr<Pln_Curve> operator()
			(
				const gp_Ax22d& theP0,
				const Standard_Real theLength,
				const std::shared_ptr<Cad_CurveInfo>& theInfo
				);

		
		void Discrete
		(
			const std::shared_ptr<Geo_ApprxCurveInfo>& theInfo
		) const override;
	};
}

#endif // !_CadPlnModel_Segment_Header
