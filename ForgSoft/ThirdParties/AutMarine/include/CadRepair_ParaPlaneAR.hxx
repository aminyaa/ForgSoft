#pragma once
#ifndef _CadRepair_ParaPlaneAR_Header
#define _CadRepair_ParaPlaneAR_Header

#include <Global_Done.hxx>
#include <Entity2d_Box.hxx>
#include <CadRepair_ParaPlaneAR_Info.hxx>

#include <memory>

namespace AutLib
{

	template<class SurfType>
	class CadRepair_ParaPlaneAR
		: public Global_Done
	{

		typedef CadRepair_ParaPlaneAR_Info info;

		/*Private Data*/

		std::shared_ptr<SurfType> theSurface_;
		std::shared_ptr<info> theInfo_;

		std::shared_ptr<SurfType> theModified_;

		Standard_Boolean Applied_;

		std::shared_ptr<SurfType>& ChangeModified()
		{
			return theModified_;
		}

		Standard_Boolean& ChangeApplied()
		{
			return Applied_;
		}

		static std::pair<Standard_Integer, Standard_Real> 
			CalcMaxAR(const SurfType& theSurface);

	public:

		CadRepair_ParaPlaneAR
		(
			const std::shared_ptr<info>& theInfo
		)
			: theInfo_(theInfo)
			, Applied_(Standard_False)
		{}

		CadRepair_ParaPlaneAR
		(
			const std::shared_ptr<SurfType>& theSurface,
			const std::shared_ptr<info>& theInfo
		)
			: theInfo_(theInfo)
			, theSurface_(theSurface)
			, Applied_(Standard_False)
		{}

		Standard_Boolean Applied() const
		{
			return Applied_;
		}

		const std::shared_ptr<info>& Info() const
		{
			return theInfo_;
		}

		const std::shared_ptr<SurfType>& Surface() const
		{
			return theSurface_;
		}

		const std::shared_ptr<SurfType>& Modified() const
		{
			return theModified_;
		}

		void Perform();

		void LoadSurface
		(
			const std::shared_ptr<SurfType>& theSurface
		)
		{
			theSurface_ = theSurface;
		}
	};
}

#include <CadRepair_ParaPlaneARI.hxx>

#endif // !_CadRepair_ParaPlaneAR_Header
