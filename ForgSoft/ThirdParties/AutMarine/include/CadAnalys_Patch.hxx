#pragma once
#ifndef _CadAnalys_Patch_Header
#define _CadAnalys_Patch_Header

#include <Global_Indexed.hxx>
#include <Global_Done.hxx>

namespace AutLib
{

	// Forward Declarations
	template<class SurfType>
	class CadRepair_RegularPatch;

	template<class SurfType>
	class CadRepair_SingularPatch;



	template<class SurfType>
	class CadAnalys_Patch
		: public Global_Indexed
		, public Global_Done
	{

		/*Private Data*/

		Standard_Boolean GeometryConfirmed_;
		Standard_Boolean TopologyConfirmed_;
		Standard_Boolean SingularityConfirmed_;

	public:

		CadAnalys_Patch()
		{}



	};
}

#endif // !_CadAnalys_Patch_Header
