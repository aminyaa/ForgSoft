#pragma once
#ifndef _CadRepair_DefectPatch_IntersectWire_Header
#define _CadRepair_DefectPatch_IntersectWire_Header

#include <CadRepair_DefectPatch_Wire.hxx>

namespace AutLib
{

	template<class SurfType>
	class CadRepair_DefectPatch_IntersectWire
		: public CadRepair_DefectPatch_Wire<SurfType>
	{

		typedef typename SurfType::parWireType wireType;

		/*Private Data*/

		std::shared_ptr<wireType> theWire1_;
		std::shared_ptr<wireType> theWire2_;

	public:

		typedef CadRepair_DefectPatch_Wire<SurfType>
			base;

		CadRepair_DefectPatch_IntersectWire
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<SurfType>& theSurface,
			const std::shared_ptr<wireType>& theWire1,
			const std::shared_ptr<wireType>& theWire2
		)
			: base(theIndex, theSurface)
			, theWire1_(theWire1)
			, theWire2_(theWire2)
		{}

		//- Static functions and operators

		static Standard_Boolean
			Check
			(
				const SurfType& theSurface,
				std::shared_ptr<wireType>& theOuter,
				std::shared_ptr<wireType>& theInner,
				const Standard_Real theTol
			);
	};
}

#include <CadRepair_DefectPatch_IntersectWireI.hxx>

#endif // !_CadRepair_DefectPatch_IntersectWire_Header
