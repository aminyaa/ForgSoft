#pragma once
#ifndef _CadRepair_Patch_Header
#define _CadRepair_Patch_Header

#include <Global_Indexed.hxx>

#include <memory>

namespace AutLib
{

	template<class SurfType>
	class CadRepair_Patch
		: public Global_Indexed
		, public std::enable_shared_from_this<CadRepair_Patch<SurfType>>
	{

		/*Private Data*/

		std::shared_ptr<SurfType> theSurface_;

	protected:

		CadRepair_Patch
		(
			const Standard_Integer theIndex,
			const std::shared_ptr<SurfType>& theSurface
		)
			: Global_Indexed(theIndex)
			, theSurface_(theSurface)
		{}

	public:

		const std::shared_ptr<SurfType>& Surface() const
		{
			return theSurface_;
		}
	};
}

#endif // !_CadRepair_Patch_Header
