#pragma once
#ifndef _CadRepair_DefectPatch_OpenWire_Header
#define _CadRepair_DefectPatch_OpenWire_Header

#include <CadRepair_DefectPatch_Wire.hxx>

#include <vector>

namespace AutLib
{

	template<class SurfType>
	class CadRepair_DefectPatch_OpenWire
		: public CadRepair_DefectPatch_Wire<SurfType>
	{

		typedef typename SurfType::wireType wireType;

		/*private Data*/

		std::vector<std::shared_ptr<wireType>> theWires_;

	public:

		typedef CadRepair_DefectPatch_Wire<SurfType>
			base;

		CadRepair_DefectPatch_OpenWire
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<SurfType>& theSurface, 
			const std::vector<std::shared_ptr<wireType>>& theWires
		)
			: base(theIndex, theSurface)
			, theWires_(theWires)
		{}

		const std::vector<std::shared_ptr<wireType>>& Wires() const
		{
			return theWires_;
		}

		//- Static functions and operators

		static Standard_Boolean
			Check
			(
				const SurfType& theSurface,
				std::vector<std::shared_ptr<wireType>>& theWires,
				const Standard_Real theTol
			);

		static Standard_Boolean
			Check
			(
				const wireType& theWire,
				const Standard_Real theTol
			);
	};
}

#include <CadRepair_DefectPatch_OpenWireI.hxx>

#endif // !_CadRepair_DefectPatch_OpenWire_Header
