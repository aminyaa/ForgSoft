#pragma once
#ifndef _CadRepair_ImpPatch_Header
#define _CadRepair_ImpPatch_Header

#include <CadRepair_Patch.hxx>

namespace AutLib
{

	template<class SurfType>
	class CadRepair_ImpPatch
		: public CadRepair_Patch<SurfType>
	{

		/*Private Data*/

		std::shared_ptr<SurfType> theRepaired_;


	protected:


		CadRepair_ImpPatch
		(
			const Standard_Integer theIndex, 
			const std::shared_ptr<SurfType>& theSurface
		)
			: CadRepair_Patch<SurfType>(theIndex, theSurface)
		{}


		std::shared_ptr<SurfType>& ChangeRepaired()
		{
			return theRepaired_;
		}

	public:

		typedef CadRepair_Patch<SurfType>
			base;

		//virtual void Repair() = 0;
	};
}

#endif // !_CadRepair_ImpPatch_Header
