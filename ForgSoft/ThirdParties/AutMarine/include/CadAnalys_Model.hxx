#pragma once
#ifndef _CadAnalys_Model_Header
#define _CadAnalys_Model_Header

#include <Global_Done.hxx>
#include <CadAnalys_Model_Base.hxx>
#include <CadAnalys_Model_Traits.hxx>
#include <CadRepair_Patch.hxx>

#include "GModel_Surface.hxx"
#include "Geo3d_SizeFunction.hxx"

namespace AutLib
{

	// Forward Declarations
	class CadAnalys_Model_Info;

	template<class EntityType>
	class CadSingularity_Detection;

	template<class SurfType, class SizeFun>
	class CadAnalys_Model
		: public CadAnalys_Model_Base<CadRepair_Patch<SurfType>>
		, public Global_Done
	{

		typedef typename CadAnalys_Model_Traits<SurfType>::parWireType wireType;
		typedef CadAnalys_Model_Info info;
		typedef CadAnalys_Model_Base<CadRepair_Patch<SurfType>>
			base;

		/*Private Data*/

		const std::shared_ptr<SizeFun>& theSizeFunction_;

		const std::shared_ptr<info>& theInfo_;
		const std::vector<std::shared_ptr<SurfType>>& theSurfaces_;

		//- static functions and operators

		template<class EntityType>
		static Standard_Boolean CheckRegulars
		(
			const CadSingularity_Detection<EntityType>& detection
		);


	public:

		CadAnalys_Model
		(
			const std::vector<std::shared_ptr<SurfType>>& theSurfaces, 
			const std::shared_ptr<SizeFun>& theSizeFun, 
			const std::shared_ptr<info>& theInfo
		)
			: theSurfaces_(theSurfaces)
			, theSizeFunction_(theSizeFun)
			, theInfo_(theInfo)
		{}

		const std::shared_ptr<SizeFun>& SizeFunction() const
		{
			return theSizeFunction_;
		}

		const std::shared_ptr<info>& Info() const
		{
			return theInfo_;
		}

		const std::vector<std::shared_ptr<SurfType>>& Surfaces()
		{
			return theSurfaces_;
		}

		void Perform();
	};
}

#include <CadAnalys_ModelI.hxx>

#endif // !_CadAnalys_Model_Header
