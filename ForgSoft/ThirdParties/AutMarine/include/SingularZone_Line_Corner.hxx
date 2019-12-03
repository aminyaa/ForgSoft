#pragma once
#ifndef _SingularZone_Line_Corner_Header
#define _SingularZone_Line_Corner_Header

#include <SingularZone_Line.hxx>

namespace AutLib
{

	struct SingularZone_Line_Corner_Base
	{
		static const word typeName;
	};

	template<class SurfPln>
	class SingularZone_Line_Corner
		: public SingularZone_Line<SurfPln>
		, public SingularZone_Line_Corner_Base
	{

		typedef typename SurfPln::plnCurve plnCurve;

		/*private Data*/

		std::shared_ptr<plnCurve> theHorizon0_;
		std::shared_ptr<plnCurve> theHorizon1_;

	public:

		SingularZone_Line_Corner()
		{}

		SingularZone_Line_Corner
		(
			const std::shared_ptr<plnCurve>& theHorizon0,
			const std::shared_ptr<plnCurve>& theHorizon1
		)
			: theHorizon0_(theHorizon0)
			, theHorizon1_(theHorizon1)
		{}

		SingularZone_Line_Corner
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<plnCurve>& theHorizon0,
			const std::shared_ptr<plnCurve>& theHorizon1
		)
			: SingularZone_Line<SurfPln>(theIndex)
			, theHorizon0_(theHorizon0)
			, theHorizon1_(theHorizon1)
		{}

		Standard_Boolean IsLoaded() const
		{
			if (!theHorizon0_) return Standard_False;
			if (!theHorizon1_) return Standard_False;
			return Standard_True;
		}

		Mesh_SingularType Type() const override
		{
			return Mesh_SingularType::Line_Corner;
		}

		const word& TypeName() const override
		{
			return typeName;
		}

		const std::shared_ptr<plnCurve>& Horizon0() const
		{
			return theHorizon0_;
		}

		const std::shared_ptr<plnCurve>& Horizon1() const
		{
			return theHorizon1_;
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

#endif // !_SingularZone_Line_Corner_Header
