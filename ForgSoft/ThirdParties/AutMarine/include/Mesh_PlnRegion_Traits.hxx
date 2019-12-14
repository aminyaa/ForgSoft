#pragma once
#ifndef _Mesh_PlnRegion_Traits_Header
#define _Mesh_PlnRegion_Traits_Header

namespace AutLib
{

	// Forward Declarations
	class Pln_Curve;
	class GModel_parCurve;
	class TModel_parCurve;

	class Cad2d_Plane;
	class GModel_Plane;
	class TModel_Plane;

	template<class CurveType>
	struct Mesh_PlnRegion_Traits
	{};

	template<> struct Mesh_PlnRegion_Traits<Pln_Curve> { typedef Cad2d_Plane plnType; };
	template<> struct Mesh_PlnRegion_Traits<GModel_parCurve> { typedef GModel_Plane plnType; };
	template<> struct Mesh_PlnRegion_Traits<TModel_parCurve> { typedef TModel_Plane plnType; };
}

#endif // !_Mesh_PlnRegion_Traits_Header
