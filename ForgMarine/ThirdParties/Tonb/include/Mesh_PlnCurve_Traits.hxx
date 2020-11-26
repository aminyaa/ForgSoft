#pragma once
#ifndef _Mesh_PlnCurve_Traits_Header
#define _Mesh_PlnCurve_Traits_Header

class Geom2d_Curve;

namespace tnbLib
{

	// Forward Declarations
	class Pln_Curve;
	class GModel_ParaCurve;
	class TModel_ParaCurve;

	template<class CurveType>
	struct Mesh_PlnCurve_Traits
	{};

	template<>
	struct Mesh_PlnCurve_Traits<Pln_Curve>{ typedef Geom2d_Curve geomType; };

	template<>
	struct Mesh_PlnCurve_Traits<GModel_ParaCurve> { typedef Geom2d_Curve geomType; };

	template<>
	struct Mesh_PlnCurve_Traits<TModel_ParaCurve> { typedef Geom2d_Curve geomType; };
}

#endif // !_Mesh_PlnCurve_Traits_Header
