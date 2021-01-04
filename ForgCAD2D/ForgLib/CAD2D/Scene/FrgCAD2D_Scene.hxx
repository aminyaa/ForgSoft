#pragma once
#ifndef _FrgCAD2D_Scene_Header
#define _FrgCAD2D_Scene_Header

#include <FrgCAD2D_Global.hxx>
#include <FrgVisual_Scene2D.hxx>

class QToolBar;

BeginForgCAD2DLib

class FrgCAD2D_Scene_InteractorStyle;

class FORGCAD2D_EXPORT FrgCAD2D_Scene
	: public ForgVisualLib::FrgVisual_Scene2D
{

public:

	FrgCAD2D_Scene(ForgBaseLib::FrgBase_MainWindow* parentMainWindow = nullptr);

protected:

	void FormToolBar() override;

	void InitInteractorStyle() override;

	void keyPressEvent(QKeyEvent* event) override;

protected:

	QToolBar* theLeftToolBar_ = nullptr;

private:

	DECLARE_SAVE_LOAD_HEADER()
};

EndForgCAD2DLib

BOOST_CLASS_EXPORT_KEY(ForgCAD2DLib::FrgCAD2D_Scene, FORGCAD2D_EXPORT)

#endif // !_FrgCAD2D_Scene_Header
