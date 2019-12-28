#pragma once
#ifndef _Aft_PlnBoundary_Traits_Header
#define _Aft_PlnBoundary_Traits_Header

#include <Aft2d_PlnRegionFwd.hxx>
#include <Aft2d_PlnRegionAnIsoFwd.hxx>
#include <Aft2d_gPlnRegionSurfaceFwd.hxx>
#include <Aft2d_tPlnRegionSurfaceFwd.hxx>
#include <Aft2d_PlnBoundary_InfoFwd.hxx>
#include <Aft2d_PlnBoundaryAnIso_InfoFwd.hxx>

#include <Aft2d_SegmentEdgeFwd.hxx>
#include <Aft2d_SegmentEdgeAnIsoFwd.hxx>
#include <Aft2d_gSegmentEdgeFwd.hxx>
#include <Aft2d_tSegmentEdge.hxx>

namespace AutLib
{

	template<class RegionType> struct aft_pln_boundary_info_type{};

	template<> struct aft_pln_boundary_info_type<Aft2d_PlnRegion> { typedef Aft2d_PlnBoundary_Info type; };
	template<> struct aft_pln_boundary_info_type<Aft2d_PlnRegionAnIso> { typedef Aft2d_PlnBoundaryAnIso_Info type; };
	template<> struct aft_pln_boundary_info_type<Aft2d_gPlnRegionSurface> { typedef Aft2d_PlnBoundaryAnIso_Info type; };
	template<> struct aft_pln_boundary_info_type<Aft2d_tPlnRegionSurface> { typedef Aft2d_PlnBoundaryAnIso_Info type; };

	template<class RegionType> struct aft_pln_boundary_entity_type {};

	template<> struct aft_pln_boundary_entity_type<Aft2d_PlnRegion> { typedef Aft2d_SegmentEdge type; };
	template<> struct aft_pln_boundary_entity_type<Aft2d_PlnRegionAnIso> { typedef Aft2d_SegmentEdgeAnIso type; };
	template<> struct aft_pln_boundary_entity_type<Aft2d_gPlnRegionSurface> { typedef Aft2d_gSegmentEdge type; };
	template<> struct aft_pln_boundary_entity_type<Aft2d_tPlnRegionSurface> { typedef Aft2d_tSegmentEdge type; };

}

#endif // !_Aft_PlnBoundary_Traits_Header
