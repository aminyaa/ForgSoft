#pragma once
#ifndef _Mesh_PatchTemplate_Traits_Header
#define _Mesh_PatchTemplate_Traits_Header

namespace tnbLib
{

	// Forward Declarations
	class GModel_Surface;
	class TModel_Surface;
	class GModel_ParaCurve;
	class TModel_ParaCurve;

	template<class SurfType>
	struct Mesh_PatchTemplate_Traits{};

	template<>
	struct Mesh_PatchTemplate_Traits<GModel_Surface> { typedef GModel_ParaCurve parCurveType; };

	template<>
	struct Mesh_PatchTemplate_Traits<TModel_Surface> { typedef TModel_ParaCurve parCurveType; };
}

#endif // !_Mesh_PatchTemplate_Traits_Header
