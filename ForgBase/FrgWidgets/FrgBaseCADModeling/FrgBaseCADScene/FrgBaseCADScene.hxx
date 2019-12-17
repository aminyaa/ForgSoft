#pragma once
#ifndef _FrgBaseCADScene_Header
#define _FrgBaseCADScene_Header

#include <FrgBaseGlobals.hxx>
#include <FrgBaseTreeItem.hxx>

#include <QVTKOpenGLNativeWidget.h>

class vtkCamera;
class vtkActor;
class vtkGenericOpenGLRenderWindow;
class vtkTextActor;
class vtkProp;
class QPoint;

BeginFrgBaseLib

enum GridDrawPlane
{
	XY = 0,
	XZ = 1,
	YZ = 2
};

struct GridActor
{
	vtkSmartPointer<vtkActor> theMajorActor_ = FrgNullPtr;
	vtkSmartPointer<vtkActor> theMinorActor_ = FrgNullPtr;
	vtkSmartPointer<vtkActor> theMiddleLines_ = FrgNullPtr;

	int theNbMajorDivision_;
	int theNbMinorDivision_;

	GridActor(int nbMajorDivision, int nbMinorDivision, double MajorColor[3], double MinorColor[3]);
};

class FrgBaseMainWindow;
class FrgBaseInteractorStyle;
class FrgBaseCADPartFeatureBase;
class FrgBase_CADScene_TreeItem;

typedef QMap<vtkSmartPointer<vtkActor>, FrgBaseCADPartFeatureBase*> QMapActorToPartFeature;
typedef QMap<FrgBaseCADPartFeatureBase*, vtkSmartPointer<vtkActor>> QMapPartFeatureToActor;

class FORGBASE_EXPORT FrgBaseCADScene : public QVTKOpenGLNativeWidget
{

	Q_OBJECT

private:

	FrgBaseMenu* theContextMenuInScene_ = FrgNullPtr;
	QList<FrgBaseMenu*> theMenus_;

	vtkSmartPointer<vtkRenderer> theRenderer_;

	vtkSmartPointer<vtkGenericOpenGLRenderWindow> theRenderWindow_;

	vtkSmartPointer<vtkRenderWindowInteractor> theRenderWindowInteractor_;

	vtkSmartPointer<FrgBaseInteractorStyle> theInteractorStyle_;

	vtkSmartPointer<vtkCamera> theCamera_;

	vtkSmartPointer<vtkTextActor> theLogoActor_;

	QList<vtkSmartPointer<vtkActor>> theActors_;

	GridActor* theGridActor_ = FrgNullPtr;

	QMapActorToPartFeature theActorToPartFeature_;
	QMapPartFeatureToActor thePartFeatureToActor_;

	FrgBaseTree* theParentTree_;
	FrgBase_CADScene_TreeItem* theParentCADSceneTreeItem_ = FrgNullPtr;

	void Init();

	void DrawGrid(vtkSmartPointer<vtkActor> actor, int nbDivision, FrgBool isMajor, double* bounds, GridDrawPlane plane = XY);

	void DrawGridMiddleLines(vtkSmartPointer<vtkActor> actor, double* bounds, GridDrawPlane plane = XY);

	void CreateContextMenuInScene();

	void CreateMenus();

public:

	FrgBaseCADScene(FrgBase_CADScene_TreeItem* parentCADSceneTreeItem, FrgBaseTree* parentTree);

	void StartScene();

	FrgGetMacro(vtkSmartPointer<vtkRenderer>, Renderer, theRenderer_);
	FrgGetMacro(vtkSmartPointer<vtkRenderWindowInteractor>, RenderWindowInteractor, theRenderWindowInteractor_);
	FrgGetMacro(vtkSmartPointer<FrgBaseInteractorStyle>, InteractorStyle, theInteractorStyle_);
	FrgGetMacro(vtkSmartPointer<vtkCamera>, FrgBaseCamera, theCamera_);
	FrgGetMacro(vtkSmartPointer<vtkTextActor>, LogoActor, theLogoActor_);
	FrgGetMacro(vtkSmartPointer<vtkGenericOpenGLRenderWindow>, FrgBaseRenderWindow, theRenderWindow_);
	FrgGetMacro(QList<vtkSmartPointer<vtkActor>>, Actors, theActors_);
	FrgGetMacro(QMapActorToPartFeature, ActorToPartFeature, theActorToPartFeature_);
	FrgGetMacro(QMapPartFeatureToActor, PartFeatureToActor, thePartFeatureToActor_);
	FrgGetMacro(FrgBaseMenu*, ContextMenuInScene, theContextMenuInScene_);
	FrgGetMacro(QList<FrgBaseMenu*>, Menus, theMenus_);
	FrgGetMacro(FrgBase_CADScene_TreeItem*, ParentCADSceneTreeItem, theParentCADSceneTreeItem_);

	QAction* GetActionItemInScene(FrgString actionName);

	void Render();

	FrgGetMacro(FrgBaseTree*, ParentTree, theParentTree_);

	void DrawGrid(int nbDivision, int nbMinorDivision, GridDrawPlane plane = XY);

	void ClearGrid();

	void RemoveActor(vtkProp* prop);

public slots:

	void customContextMenuRequestedSlot(const QPoint& pos);
	void SetViewToXYPlaneSlot(bool);
	void SetViewToXZPlaneSlot(bool);
	void SetViewToYZPlaneSlot(bool);
	void SetViewToXYZSlot(bool);
	void GridOpacityChangedSlot(int);
	void DrawGridSlot(bool);
	void ScreenshotSlot(bool);
	void RandomColorsSlot(bool);
	void ShowMeshSlot(bool condition);
	void HideActorsSlot(bool);
	void ShowHiddenPartsSlot(bool);
	virtual void ExportSelectedPartClickedSlot(bool) {}

	void SelectIconSelectedSlot(bool);
	void MoveIconSelectedSlot(bool);
	void RotateXIconSelectedSlot(bool);
	void RotateYIconSelectedSlot(bool);
	void RotateZIconSelectedSlot(bool);
	void RotateXYZIconSelectedSlot(bool);

signals:

	void ActorSelectedSignal(bool);
};

EndFrgBaseLib

#endif // !_FrgBaseCADScene_Header
