#pragma once
#ifndef _FrgVisual_Scene_Ruler_Header
#define _FrgVisual_Scene_Ruler_Header

#include <FrgVisual_Global.hxx>

#include <vtkLegendScaleActor.h>

BeginForgVisualLib

class FrgVisual_Scene_Entity;

class FORGVISUAL_EXPORT FrgVisual_Scene_Ruler
	: public vtkLegendScaleActor
{

public:

	static FrgVisual_Scene_Ruler* New();
	vtkTypeMacro(FrgVisual_Scene_Ruler, vtkLegendScaleActor);

	FrgVisual_Scene_Ruler();

	void BuildRepresentation(vtkViewport* viewport) override;

	FrgVisual_Scene_Entity* GetParentScene() const { return theParentScene_; }
	void SetParentScene(FrgVisual_Scene_Entity* ps) { theParentScene_ = ps; }

	void TurnOn(const bool render = true);
	void TurnOff(const bool render = true);

protected:

	FrgVisual_Scene_Entity* theParentScene_ = nullptr;
};

EndForgVisualLib

#endif // !_FrgVisual_Scene_Ruler_Header
