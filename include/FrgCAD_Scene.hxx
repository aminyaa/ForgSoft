#pragma once
#ifndef _FrgCAD_Scene_Header
#define _FrgCAD_Scene_Header

#include <FrgCAD_Global.hxx>
#include <FrgVisual_Scene2D.hxx>

class QToolBar;

BeginForgCADLib

class FrgCAD_Scene_InteractorStyle;
class FrgCAD_CmdLineEdit;

class FORGCAD_EXPORT FrgCAD_Scene
	: public ForgVisualLib::FrgVisual_Scene2D
{

	Q_OBJECT

public:

	FrgCAD_Scene(ForgBaseLib::FrgBase_MainWindow* parentMainWindow = nullptr);

	FrgCAD_CmdLineEdit* GetCmdLineEdit() const { return theCmdLineEdit_; }

protected:

	void FormToolBar() override;
	void InitInteractorStyle() override;
	void keyPressEvent(QKeyEvent* event) override;

protected:

	QToolBar* theLeftToolBar_ = nullptr;
	FrgCAD_CmdLineEdit* theCmdLineEdit_ = nullptr;

	FrgCAD_Scene_InteractorStyle* theCastedInterStyle_ = nullptr;

Q_SIGNALS:

	void ActorAddedToCADSignal(ForgVisualLib::FrgVisual_BaseActor_Entity*);
	void ActorIsGoingToBeDeletedFromCADSignal(ForgVisualLib::FrgVisual_BaseActor_Entity*);

private:

	DECLARE_SAVE_LOAD_HEADER(FORGCAD_EXPORT)
};

EndForgCADLib

BOOST_CLASS_EXPORT_KEY(ForgCADLib::FrgCAD_Scene, FORGCAD_EXPORT)

#endif // !_FrgCAD_Scene_Header
