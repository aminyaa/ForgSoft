#pragma once
#ifndef _CadAnalys_Model_Traits_Header
#define _CadAnalys_Model_Traits_Header

namespace AutLib
{

	template<class SurfType>
	struct CadAnalys_Model_Traits
	{};

	// Forward Declarations
	class TModel_Surface;
	class GModel_Surface;

	class TModel_Wire;
	class GModel_Wire;

	template<> struct CadAnalys_Model_Traits<GModel_Surface>
	{
		typedef GModel_Wire wireType;
	};

	template<> struct CadAnalys_Model_Traits<TModel_Surface>
	{
		typedef TModel_Wire wireType;
	};
}

#endif // !_CadAnalys_Model_Traits_Header
