#pragma once
#include <Mesh_ReferenceValues.hxx>
#include <Mesh_RelativeAbsoluteInfo.hxx>
#include <Mesh_SurfaceSizeValues.hxx>
#include <Standard_Real.hxx>
namespace AutLib
{

	//template<class SizeMapTraits>
	//void SizeMap_Tool<SizeMapTraits>::SpecifiedValues
	//(
	//	Standard_Real & theElementSize, 
	//	Standard_Real & theMinSize, 
	//	Standard_Real & theSpanAngle
	//) const
	//{

	//	const auto& Ref = *Reference();
	//	const auto& conditions = Conditions();
	//	const auto& values = Values();

	//	if (conditions.CustomSurfaceSize())
	//	{
	//		// Specify Relative or Absolute sizes
	//		if (values.SurfaceSize().RelativeAbsolute() IS_EQUAL Mesh_RelativeAbsoluteInfo_Absolute)
	//		{
	//			theElementSize = values.SurfaceSize().TargetSize();
	//			theMinSize = values.SurfaceSize().MinSize();
	//		}
	//		else
	//		{ // is Relative to Base
	//			theElementSize = values.SurfaceSize().TargetSize()*Ref.BaseSize() / 100.0;
	//			theMinSize = values.SurfaceSize().MinSize()*Ref.BaseSize() / 100.0;
	//		}
	//	}
	//	else
	//	{
	//		if (Ref.SurfaceSize().RelativeAbsolute() IS_EQUAL Mesh_RelativeAbsoluteInfo_Absolute)
	//		{
	//			theElementSize = Ref.SurfaceSize().TargetSize();
	//			theMinSize = Ref.SurfaceSize().MinSize();
	//		}
	//		else
	//		{
	//			theElementSize = Ref.SurfaceSize().TargetSize()*Ref.BaseSize() / 100.0;
	//			theMinSize = Ref.SurfaceSize().MinSize()*Ref.BaseSize() / 100.0;
	//		}
	//	}

	//	if (theElementSize <= 0 OR theMinSize <= 0)
	//	{
	//		FatalErrorIn("void SpecifiedValues()")
	//			<< "NULL Element size detected" << endl
	//			<< abort(FatalError);
	//	}

	//	// Specify Combination of min, target sizes
	//	if (theValues_.SurfaceSize().SizeMethod() IS_EQUAL Mesh_SizeMethodInfo_MinOnly) { theElementSize = theMinSize; }

	//	if (conditions.CustomSurfaceCurvature() EQUAL Mesh_SurfaceCurvatureInfo_Disable) { theSpanAngle = RealLast(); }
	//	else if (conditions.CustomSurfaceCurvature() EQUAL Mesh_SurfaceCurvatureInfo_Continuum_Values) { theSpanAngle = Ref.SurfaceCurvature().SpanAngle(); }
	//	else
	//	{ // Specify Surface curvature value 	
	//		theSpanAngle = values.SurfaceCurvature().SpanAngle();
	//	}

	//	if (theSpanAngle <= 0)
	//	{
	//		FatalErrorIn("void SpecifiedValues()")
	//			<< "NULL Span Angle detected" << endl
	//			<< abort(FatalError);
	//	}
	//}
}