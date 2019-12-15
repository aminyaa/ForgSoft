#pragma once
#ifndef _ViewPorts_Header
#define _ViewPorts_Header

#include <FrgBaseGlobals.hxx>

#include <QtWidgets/QMainWindow>

class QMdiArea;
class QToolBar;
class QToolButton;

BeginFrgBaseLib

class CADScene;
//class NihadVesselPartTreeItem;
class FrgBaseCADPart_Entity;
class FrgBaseMainWindow;
class FrgBase_CADScene_TreeItem;

class ViewPorts : public QMainWindow
{

private:

	QMdiArea* theMdiArea_ = FrgNullPtr;
	QToolBar* theToolBar_ = FrgNullPtr;
	QList<QToolButton*> theToolButtons_;

	QList<CADScene*> theScenes_;

	FrgBaseMainWindow* theParentMainWindow_ = FrgNullPtr;

public:

	ViewPorts(FrgBase_CADScene_TreeItem* parentCADSceneTreeItem, FrgBaseMainWindow* parent = FrgNullPtr);

	FrgGetMacro(QList<CADScene*>, Scenes, theScenes_);
	FrgGetMacro(QMdiArea*, MdiArea, theMdiArea_);
	FrgGetMacro(QToolBar*, ToolBar, theToolBar_);
	FrgGetMacro(QList<QToolButton*>, ToolButtons, theToolButtons_);

	void SetLogoText(FrgString text);

	void CreateActor(FrgBaseCADPart_Entity* part);

	void ClearScenes();

	void RenderScenes();

	void AddScene(CADScene* scene, Qt::WindowFlags flags = Qt::WindowFlags());

	void TileSubWindows();

	void SetToolBar();

};

EndFrgBaseLib

#endif // !_ViewPorts_Header
