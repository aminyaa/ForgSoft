#pragma once
#ifndef _SingularZone_Line_Loop_Header
#define _SingularZone_Line_Loop_Header

#include <SingularZone_Line.hxx>

namespace AutLib
{

	struct SingularZone_Line_Loop_Base
	{
		static const word typeName;
	};

	template<class SurfPln>
	class SingularZone_Line_Loop
		: public SingularZone_Line<SurfPln>
		, public SingularZone_Line_Loop_Base
	{
		typedef typename SurfPln::plnCurve plnCurve;

		/*Private Data*/

		std::shared_ptr<plnCurve> theHorizon0_;
		std::shared_ptr<plnCurve> theHorizon1_;
		std::shared_ptr<plnCurve> theHorizon2_;
		std::shared_ptr<plnCurve> theHorizon3_;

	public:

		SingularZone_Line_Loop()
		{}

		SingularZone_Line_Loop
		(
			const std::shared_ptr<plnCurve>& theHorizon0,
			const std::shared_ptr<plnCurve>& theHorizon1,
			const std::shared_ptr<plnCurve>& theHorizon2,
			const std::shared_ptr<plnCurve>& theHorizon3
		)
			: theHorizon0_(theHorizon0)
			, theHorizon1_(theHorizon1)
			, theHorizon2_(theHorizon2)
			, theHorizon3_(theHorizon3)
		{}

		SingularZone_Line_Loop
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<plnCurve>& theHorizon0,
			const std::shared_ptr<plnCurve>& theHorizon1,
			const std::shared_ptr<plnCurve>& theHorizon2,
			const std::shared_ptr<plnCurve>& theHorizon3
		)
			: SingularZone_Line<SurfPln>(theIndex)
			, theHorizon0_(theHorizon0)
			, theHorizon1_(theHorizon1)
			, theHorizon2_(theHorizon2)
			, theHorizon3_(theHorizon3)
		{}

		Mesh_SingularType Type() const override
		{
			return Mesh_SingularType::Line_Loop;
		}

		const word& TypeName() const override
		{
			return typeName;
		}

		Standard_Boolean IsLoaded() const
		{
			if (!theHorizon0_) return Standard_False;
			if (!theHorizon1_) return Standard_False;
			if (!theHorizon2_) return Standard_False;
			if (!theHorizon3_) return Standard_False;
			return Standard_True;
		}

		const std::shared_ptr<plnCurve>& Horizon0() const
		{
			return theHorizon0_;
		}

		const std::shared_ptr<plnCurve>& Horizon1() const
		{
			return theHorizon1_;
		}

		const std::shared_ptr<plnCurve>& Horizon2() const
		{
			return theHorizon2_;
		}

		const std::shared_ptr<plnCurve>& Horizon3() const
		{
			return theHorizon3_;
		}

		Standard_Integer NbHorizons() const override
		{
			return 4;
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
			const std::shared_ptr<plnCurve>& theHorizon1,
			const std::shared_ptr<plnCurve>& theHorizon2,
			const std::shared_ptr<plnCurve>& theHorizon3
		)
		{
			theHorizon0_ = theHorizon0;
			theHorizon1_ = theHorizon1;
			theHorizon2_ = theHorizon2;
			theHorizon3_ = theHorizon3;
		}
	};
}

#endif // !_SingularZone_Line_Loop_Header
