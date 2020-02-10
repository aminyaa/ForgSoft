#pragma once
#ifndef _PlnOpert_SplitWire_Info_Header
#define _PlnOpert_SplitWire_Info_Header

#include <Standard_TypeDef.hxx>

#include <memory>

namespace tnbLib
{

	// Forward Declarations
	class PlnOpert_IntsctEdgeEdge_Info;

	class PlnOpert_SplitWire_Info
	{

		/*Private Data*/

		std::shared_ptr<PlnOpert_IntsctEdgeEdge_Info> theIntsctInfo_;

		Standard_Real theTolerance_;

	public:

		static const Standard_Real DEFAULT_TOLERANCE;

		PlnOpert_SplitWire_Info()
			: theTolerance_(DEFAULT_TOLERANCE)
		{}

		const auto& IntsctInfo() const
		{
			return theIntsctInfo_;
		}

		void LoadIntsctInfo(const std::shared_ptr<PlnOpert_IntsctEdgeEdge_Info>& theInfo)
		{
			theIntsctInfo_ = theInfo;
		}
	};
}

#endif // !_PlnOpert_SplitWire_Info_Header
