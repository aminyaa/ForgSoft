#pragma once
#ifndef _SingularZone_Pole_PartialSide_Header
#define _SingularZone_Pole_PartialSide_Header

#include <SingularZone_Pole.hxx>

namespace AutLib
{

	struct SingularZone_Pole_PartialSide_Base
	{
		static const word typeName;
	};

	template<class SurfPln>
	class SingularZone_Pole_PartialSide
		: public SingularZone_Pole<SurfPln>
		, public SingularZone_Pole_PartialSide_Base
	{

		typedef typename SurfPln::plnCurve plnCurve;

		/*Private Data*/

		std::shared_ptr<plnCurve> theHorizon_;

	public:

		SingularZone_Pole_PartialSide()
		{}

		SingularZone_Pole_PartialSide
		(
			const std::shared_ptr<plnCurve>& theHorizon
		)
			: theHorizon_(theHorizon)
		{}

		SingularZone_Pole_PartialSide
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<plnCurve>& theHorizon
		)
			: SingularZone_Pole<SurfPln>(theIndex)
			, theHorizon_(theHorizon)
		{}

		Mesh_SingularType Type() const override
		{
			return Mesh_SingularType::Pole_PartialSide;
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

#endif // !_SingularZone_Pole_PartialSide_Header
