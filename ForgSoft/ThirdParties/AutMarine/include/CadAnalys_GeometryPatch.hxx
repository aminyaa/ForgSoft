#pragma once
#ifndef _CadAnalys_GeometryPatch_Header
#define _CadAnalys_GeometryPatch_Header

#include <Global_Indexed.hxx>
#include <Global_Done.hxx>

#include <memory>

namespace AutLib
{

	template<class SurfType>
	class CadAnalys_GeometryPatch
		: public Global_Indexed
		, public Global_Done
		, public std::enable_shared_from_this<CadAnalys_GeometryPatch<SurfType>>
	{

		/*Private Data*/

		std::shared_ptr<SurfType> theSurface_;

	protected:

		CadAnalys_GeometryPatch
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

#endif // !_CadAnalys_GeometryPatch_Header
