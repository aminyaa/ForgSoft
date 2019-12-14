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

	class TModel_parWire;
	class GModel_parWire;

	template<> struct CadAnalys_Model_Traits<GModel_Surface>
	{
		typedef GModel_parWire parWireType;
	};

	template<> struct CadAnalys_Model_Traits<TModel_Surface>
	{
		typedef TModel_parWire parWireType;
	};
}

#endif // !_CadAnalys_Model_Traits_Header
