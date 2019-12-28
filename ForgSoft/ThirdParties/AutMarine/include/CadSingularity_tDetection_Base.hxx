#pragma once
#ifndef _CadSingularity_tDetection_Base_Header
#define _CadSingularity_tDetection_Base_Header

#include <CadSingularity_Detection_Base.hxx>
#include <TModel_parCurve.hxx>

namespace AutLib
{

	typedef CadSingularity_Detection_Base<TModel_parCurve>
		CadSingularity_tDetection_Base;

	template<>
	static std::shared_ptr<TModel_parCurve> 
		CadSingularity_tDetection_Base::ParametricCurve_Pole
		(
			const Pnt2d& theP0,
			const Pnt2d& theP1
		);

	template<>
	static std::shared_ptr<TModel_parCurve> 
		CadSingularity_tDetection_Base::ParametricCurve_Line
		(
			const Pnt2d& theP0, 
			const Pnt2d& theP1
		);
}

#endif // !_CadSingularity_tDetection_Base_Header
