#pragma once
#ifndef _SingularZone_Pole_WholeSide_Header
#define _SingularZone_Pole_WholeSide_Header

#include <SingularZone_Pole.hxx>

namespace AutLib
{

	struct SingularZone_Pole_WholeSide_Base
	{
		static const word typeName;
	};

	template<class SurfPln>
	class SingularZone_Pole_WholeSide
		: public SingularZone_Pole<SurfPln>
		, public SingularZone_Pole_WholeSide_Base
	{

		typedef typename SurfPln::plnCurve plnCurve;

		/*Private Data*/

		std::shared_ptr<plnCurve> theHorizon_;

	public:

		SingularZone_Pole_WholeSide()
		{}

		SingularZone_Pole_WholeSide
		(
			const std::shared_ptr<plnCurve>& theCurve
		)
			: theHorizon_(theCurve)
		{}

		SingularZone_Pole_WholeSide
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<plnCurve>& theCurve
		)
			: SingularZone_Pole<SurfPln>(theIndex)
			, theHorizon_(theCurve)
		{}

		Standard_Boolean IsLoaded() const
		{
			if (!theHorizon_) return Standard_False;
			return Standard_True;
		}

		const word& TypeName() const override
		{
			return typeName;
		}

		Mesh_SingularType Type() const override
		{
			return Mesh_SingularType::Pole_WholeSide;
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

#endif // !_SingularZone_Pole_WholeSide_Header
