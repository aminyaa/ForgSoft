#pragma once
#ifndef _FrgVisual_Scene2D_Header
#define _FrgVisual_Scene2D_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Scene.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	class FrgBase_MainWindow;
	template<int Dim>
	class FrgBase_Pnt;
}

BeginForgVisualLib

template<int Dim>
class FrgVisual_BSPLineActor;

//class FrgVisual_2DPointActor;
//class FrgVisual_2DLineActor;
//class FrgVisual_2DPolylineActor;
//class FrgVisual_2DRectangleActor;
//class FrgVisual_2DMeshActor;
//class FrgVisual_2DBSPLineActor;
//class FrgVisual_2DGridActor;

class FORGVISUAL_EXPORT FrgVisual_Scene2D
	: public FrgVisual_Scene<2>
{

public:

	FrgVisual_Scene2D(ForgBaseLib::FrgBase_MainWindow* parentMainWindow = nullptr);

	//void Init() override;

	bool Is2D() const override { return true; }

	void RenderSceneSlot(bool resetCamera = true, bool resetView = false) override;

	std::vector<FrgVisual_BaseActor_Entity*> GetSelectedActors() const override;
	std::vector<FrgVisual_BaseActor_Entity*> GetHiddenActors() const override;

	void SelectActor(FrgVisual_BaseActor_Entity* actor, int isControlKeyPressed, bool render = true) override;
	void SelectActor(std::vector<FrgVisual_BaseActor_Entity*> actors, int isControlKeyPressed, bool render = true) override;
	void UnSelectActor(FrgVisual_BaseActor_Entity* actor, bool render = true) override;
	void SelectAllActors(bool render = true) override;
	void UnSelectAllActors(bool render = true) override;

protected:

	void InitInteractorStyle() override;

private:

	DECLARE_SAVE_LOAD_HEADER( )
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Scene2D)

#include <FrgVisual_Scene2DI.hxx>

#endif // !_FrgVisual_Scene2D_Header
