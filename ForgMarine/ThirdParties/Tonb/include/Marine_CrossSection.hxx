#pragma once
#ifndef _Marine_CrossSection_Header
#define _Marine_CrossSection_Header

#include <Global_Done.hxx>
#include <Global_AccessMethod.hxx>

#include <TopoDS_Shape.hxx>

class gp_Ax2;

#include <memory>
#include <vector>

namespace tnbLib
{

	// Forward Declarations
	class Marine_CmpSection;
	class Marine_SectionDistribution;

	class Marine_CrossSection
		: public Global_Done
	{

		/*Private Data*/

		Standard_Real theMinTolerance_;
		Standard_Real theMaxTolerance_;

		std::vector<std::shared_ptr<Marine_CmpSection>> theSections_;

		const gp_Ax2& theSystem_;

	protected:

		Marine_CrossSection(const gp_Ax2& theSystem);

		auto& ChangeSections()
		{
			return theSections_;
		}

	public:

		const auto& Sections() const
		{
			return theSections_;
		}

		const auto& System() const
		{
			return theSystem_;
		}

		//- Macros

		GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, MinTolerance)
			GLOBAL_ACCESS_PRIM_SINGLE(Standard_Real, MaxTolerance)

	};
}

#endif // !_Marine_CrossSection_Header
