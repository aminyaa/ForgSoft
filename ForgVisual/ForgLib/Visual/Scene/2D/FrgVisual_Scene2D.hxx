#pragma once
#ifndef _FrgVisual_Scene2D_Header
#define _FrgVisual_Scene2D_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Scene.hxx>

namespace ForgBaseLib
{
	class FrgBase_MainWindow;
}

BeginForgVisualLib

class FORGVISUAL_EXPORT FrgVisual_Scene2D
	: public FrgVisual_Scene
{

public:

	FrgVisual_Scene2D(ForgBaseLib::FrgBase_MainWindow* parentMainWindow);

	void Init() override {}
};

EndForgVisualLib

#endif // !_FrgVisual_Scene2D_Header
