#pragma once
#ifndef _SingularZone_Line_TwoSide_Header
#define _SingularZone_Line_TwoSide_Header

#include <SingularZone_Line.hxx>

namespace AutLib
{

	struct SingularZone_Line_TwoSide_Base
	{
		static const word typeName;
	};

	template<class SurfPln>
	class SingularZone_Line_TwoSide
		: public SingularZone_Line<SurfPln>
		, public SingularZone_Line_TwoSide_Base
	{

		typedef typename SurfPln::parCurveType plnCurve;

		/*Private Data*/

		std::shared_ptr<plnCurve> theHorizon0_;
		std::shared_ptr<plnCurve> theHorizon1_;

	public:

		SingularZone_Line_TwoSide()
		{}

		SingularZone_Line_TwoSide
		(
			const std::shared_ptr<plnCurve>& theHorizon0,
			const std::shared_ptr<plnCurve>& theHorizon1
		)
			: theHorizon0_(theHorizon0)
			, theHorizon1_(theHorizon1)
		{}

		SingularZone_Line_TwoSide
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<plnCurve>& theHorizon0,
			const std::shared_ptr<plnCurve>& theHorizon1
		)
			: SingularZone_Line<SurfPln>(theIndex)
			, theHorizon0_(theHorizon0)
			, theHorizon1_(theHorizon1)
		{}

		Cad_SingularType Type() const override
		{
			return Cad_SingularType::Line_TwoSide;
		}

		const word& TypeName() const override
		{
			return typeName;
		}

		Standard_Boolean IsLoaded() const
		{
			if (!theHorizon0_) return Standard_False;
			if (!theHorizon1_) return Standard_False;
			return Standard_True;
		}

		Standard_Integer NbHorizons() const override
		{
			return 2;
		}

		const std::shared_ptr<plnCurve>&
			Horizon
			(
				const Standard_Integer theIndex
			) const override
		{
			return (&theHorizon0_)[theIndex];
		}

		const std::shared_ptr<plnCurve>& Horizon0() const
		{
			return theHorizon0_;
		}

		const std::shared_ptr<plnCurve>& Horizon1() const
		{
			return theHorizon1_;
		}

		void LoadHorizons
		(
			const std::shared_ptr<plnCurve>& theHorizon0,
			const std::shared_ptr<plnCurve>& theHorizon1
		)
		{
			theHorizon0_ = theHorizon0;
			theHorizon1_ = theHorizon1;
		}
	};
}

#endif // !_SingularZone_Line_TwoSide_Header
