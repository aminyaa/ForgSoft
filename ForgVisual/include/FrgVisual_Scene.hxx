#pragma once
#ifndef _FrgVisual_Scene_Header
#define _FrgVisual_Scene_Header

#include <FrgVisual_Global.hxx>
#include <QVTKOpenGLNativeWidget.h>

BeginForgVisualLib

class FrgVisual_Scene
	: public QVTKOpenGLNativeWidget
{

public:

	FrgVisual_Scene() {}

};

EndForgVisualLib

#endif // !_FrgVisual_Scene_Header
