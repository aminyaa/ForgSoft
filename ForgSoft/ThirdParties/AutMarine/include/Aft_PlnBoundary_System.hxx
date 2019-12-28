#pragma once
#ifndef _Aft_PlnBoundary_System_Header
#define _Aft_PlnBoundary_System_Header

#include <Aft2d_PlnBoundary_InfoFwd.hxx>
#include <Aft2d_PlnBoundaryAnIso_Info.hxx>

#include <memory>

namespace AutLib
{

	// Forward Declarations
	class Mesh_CurveInfo;
	class Numeric_AdaptIntegrationInfo;
	class Numeric_NewtonSolverInfo;
	class Mesh_CurveOptmPoint_CorrectionInfo;

	namespace plnBoundarySys
	{

		extern std::shared_ptr<Numeric_AdaptIntegrationInfo> gl_plane_boundary_intg_overall_info;
		extern std::shared_ptr<Numeric_AdaptIntegrationInfo> gl_plane_boundary_intg_newton_info;
		extern std::shared_ptr<Numeric_NewtonSolverInfo> gl_plane_boundary_newton_solver_info;
		extern std::shared_ptr<Mesh_CurveOptmPoint_CorrectionInfo> gl_plane_boundary_opt_node_info;

		extern std::shared_ptr<Mesh_CurveInfo> gl_plane_boundary_curve_mesh_info;

		extern std::shared_ptr<Aft2d_PlnBoundary_Info> gl_plane_boundary_info;
		extern std::shared_ptr<Aft2d_PlnBoundaryAnIso_Info> gl_plane_boundary_aniso_info;

		void init_plane_boundary_mesh_info();
	}
}

#endif // !_Aft_PlnBoundary_System_Header
