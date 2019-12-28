#pragma once
#ifndef _SingularZone_Line_WholeSide_Header
#define _SingularZone_Line_WholeSide_Header

#include <SingularZone_Line.hxx>

namespace AutLib
{

	struct SingularZone_Line_WholeSide_Base
	{
		static const word typeName;
	};

	template<class SurfPln>
	class SingularZone_Line_WholeSide
		: public SingularZone_Line<SurfPln>
		, public SingularZone_Line_WholeSide_Base
	{

		typedef typename SurfPln::parCurveType plnCurve;

		/*Private Data*/

		std::shared_ptr<plnCurve> theHorizon_;

	public:

		SingularZone_Line_WholeSide()
		{}

		SingularZone_Line_WholeSide
		(
			const std::shared_ptr<plnCurve>& theHorizon
		)
			: theHorizon_(theHorizon)
		{}

		SingularZone_Line_WholeSide
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<plnCurve>& theHorizon
		)
			: SingularZone_Line<SurfPln>(theIndex)
			, theHorizon_(theHorizon)
		{}

		Cad_SingularType Type() const override
		{
			return Cad_SingularType::Line_WholeSide;
		}

		const word& TypeName() const override
		{
			return typeName;
		}

		Standard_Boolean IsLoaded() const
		{
			if (!theHorizon_) return Standard_False;
			return Standard_True;
		}

		Standard_Integer NbHorizons() const override
		{
			return 1;
		}

		const std::shared_ptr<plnCurve>&
			Horizon
			(
				const Standard_Integer theIndex
			) const override
		{
			return theHorizon_;
		}

		const std::shared_ptr<plnCurve>& Horizon() const
		{
			return theHorizon_;
		}

		void LoadHorizon(const std::shared_ptr<plnCurve>& theHorizon)
		{
			theHorizon_ = theHorizon;
		}
	};
}

#endif // !_SingularZone_Line_WholeSide_Header
