#pragma once
#ifndef _CadRepair_DefectPatch_OrderWire_Header
#define _CadRepair_DefectPatch_OrderWire_Header

#include <CadRepair_DefectPatch.hxx>

#include <vector>

//#include "TModel_Surface.hxx"
//#include "TModel_Wire.hxx"

namespace AutLib
{

	template<class SurfType>
	class CadRepair_DefectPatch_OrderWire
		: public CadRepair_DefectPatch<SurfType>
	{

		typedef typename SurfType::wireType wireType;

		/*Private Data*/

		std::vector<std::shared_ptr<wireType>> theWires_;

	public:

		typedef CadRepair_DefectPatch<SurfType>
			base;

		CadRepair_DefectPatch_OrderWire
		(
			const Standard_Integer theIndex, 
			const std::shared_ptr<SurfType>& theSurface,
			const std::vector<std::shared_ptr<wireType>>& theWires
		)
			: CadRepair_DefectPatch<SurfType>(theIndex, theSurface)
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
				std::vector<std::shared_ptr<wireType>>& theWires
			);

		static Standard_Boolean Check(const wireType& theWire);

	};
}

#include <CadRepair_DefectPatch_OrderWireI.hxx>

#endif // !_CadRepair_DefectPatch_OrderWire_Header
