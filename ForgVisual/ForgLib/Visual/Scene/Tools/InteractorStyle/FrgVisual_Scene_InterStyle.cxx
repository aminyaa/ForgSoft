#include <FrgVisual_Scene_InterStyle.hxx>

void ForgVisualLib::FrgVisual_Scene_InterStyle_Base::SetPickingToleranceToSurface()
{
	thePickingTolerance_ = RecommendPickingTolerance(FrgVisual_Scene_InterStyle_Base::PickingToleranceHelper::Surface);
}

void ForgVisualLib::FrgVisual_Scene_InterStyle_Base::SetPickingToleranceToCurve()
{
	thePickingTolerance_ = RecommendPickingTolerance(FrgVisual_Scene_InterStyle_Base::PickingToleranceHelper::Curve);
}

double ForgVisualLib::FrgVisual_Scene_InterStyle_Base::RecommendPickingTolerance(PickingToleranceHelper helper)
{
	if (helper == FrgVisual_Scene_InterStyle_Base::PickingToleranceHelper::Surface)
		return 0.00001;
	if (helper == FrgVisual_Scene_InterStyle_Base::PickingToleranceHelper::Curve)
		return 0.001;

	return 0.00001;
}