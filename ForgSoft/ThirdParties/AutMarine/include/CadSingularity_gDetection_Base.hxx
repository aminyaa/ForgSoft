#pragma once
#ifndef _CadSingularity_gDetection_Base_Header
#define _CadSingularity_gDetection_Base_Header

#include <CadSingularity_Detection_Base.hxx>
#include <GModel_parCurve.hxx>

namespace AutLib
{

	typedef CadSingularity_Detection_Base<GModel_parCurve>
		CadSingularity_gDetection_Base;

	template<>
	static std::shared_ptr<GModel_parCurve> 
		CadSingularity_gDetection_Base::ParametricCurve_Pole
		(
			const Pnt2d& theP0, 
			const Pnt2d& theP1
		);

	template<>
	static std::shared_ptr<GModel_parCurve> 
		CadSingularity_gDetection_Base::ParametricCurve_Line
		(
			const Pnt2d& theP0,
			const Pnt2d& theP1
		);
}

#endif // !_CadSingularity_gDetection_Base_Header
