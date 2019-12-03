#pragma once
#ifndef _SingularZone_Pole_Corner_Header
#define _SingularZone_Pole_Corner_Header

#include <SingularZone_Pole.hxx>

namespace AutLib
{

	struct SingularZone_Pole_Corner_Base
	{
		static const word typeName;
	};

	template<class SurfPln>
	class SingularZone_Pole_Corner
		: public SingularZone_Pole<SurfPln>
		, public SingularZone_Pole_Corner_Base
	{

		typedef typename SurfPln::plnCurve plnCurve;

		/*Private Data*/

		std::shared_ptr<plnCurve> theHorizon_;

	public:

		SingularZone_Pole_Corner()
		{}

		SingularZone_Pole_Corner
		(
			const std::shared_ptr<plnCurve>& theCurve
		)
			: theHorizon_(theCurve)
		{}

		SingularZone_Pole_Corner
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<plnCurve>& theCurve
		)
			: SingularZone_Pole<SurfPln>(theIndex)
			, theHorizon_(theCurve)
		{}

		Mesh_SingularType Type() const override
		{
			return Mesh_SingularType::Pole_Corner;
		}

		const word& TypeName() const override
		{
			return typeName;
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

		void LoadHorizon(const std::shared_ptr<plnCurve>& theHorizon)
		{
			theHorizon_ = theHorizon;
		}
	};
}

#endif // !_SingularZone_Pole_Corner_Header
