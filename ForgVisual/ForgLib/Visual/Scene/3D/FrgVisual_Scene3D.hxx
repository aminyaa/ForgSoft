#pragma once
#ifndef _FrgVisual_Scene3D_Header
#define _FrgVisual_Scene3D_Header

#include <FrgVisual_Global.hxx>
#include <FrgVisual_Scene.hxx>

#include <FrgVisual_Serialization_Global.hxx>

namespace ForgBaseLib
{
	class FrgBase_MainWindow;
	class FrgBase_Pnt3d;
}

BeginForgVisualLib

class FrgVisual_3DPointActor;
class FrgVisual_3DLineActor;
class FrgVisual_3DPolylineActor;
class FrgVisual_3DBoxActor;

class FORGVISUAL_EXPORT FrgVisual_Scene3D
	: public FrgVisual_Scene
{

public:

	FrgVisual_Scene3D(ForgBaseLib::FrgBase_MainWindow* parentMainWindow);
	void Init() override;

	void RenderScene(bool resetCamera = true) override;

	template <typename Triangulation>
	void AddTriangulations(std::vector<Triangulation> triangulations, bool render);

	FrgVisual_3DPointActor* AddPoint(std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> pt, bool render = true);
	FrgVisual_3DPointActor* AddPoint(double x = 0.0, double y = 0.0, double z = 0.0, bool render = true);

	FrgVisual_3DLineActor* AddLine(std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> P0, std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> P1, bool render = true);
	FrgVisual_3DLineActor* AddLine(double P0_X, double P0_Y, double P0_Z, double P1_X, double P1_Y, double P1_Z, bool render = true);

	FrgVisual_3DPolylineActor* AddPolyline(std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d>> pts, bool render = true);

	FrgVisual_3DBoxActor* AddBox(std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> P0, std::shared_ptr<ForgBaseLib::FrgBase_Pnt3d> P1, bool render = true);
	FrgVisual_3DBoxActor* AddBox(double P0_X, double P0_Y, double P0_Z, double P1_X, double P1_Y, double P1_Z, bool render = true);

	template <typename T>
	void ClearAllDataType();

	void ClearAllPoints();
	void ClearAllLines();
	void ClearAllPolylines();

private:

	DECLARE_SAVE_LOAD_HEADER
};

EndForgVisualLib

DECLARE_SAVE_LOAD_HEADER_CONSTRUCT(ForgVisualLib::FrgVisual_Scene3D)

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Scene3D)

#include <FrgVisual_Scene3DI.hxx>

#endif // !_FrgVisual_Scene3D_Header

//#pragma once
//#ifndef _FrgVisual_Scene3D_Header
//#define _FrgVisual_Scene3D_Header
//
//#include <FrgVisual_Global.hxx>
//#include <QVTKOpenGLNativeWidget.h>
//
//class vtkRenderer;
//class vtkGenericOpenGLRenderWindow;
//class vtkRenderWindowInteractor;
//class FrgVisual_Scene_InterStyle3D;
//class vtkCamera;
//class vtkTextActor;
//class vtkActor;
//class vtkProp;
//class QPoint;
//
//template<class T>
//class vtkSmartPointer;
//
//BeginForgVisualLib
//
//class FrgBase_MainWindow;
////class FrgBase_Tree;
//class FrgBase_Menu;
//
//class FORGVISUAL_EXPORT FrgVisual_Scene3D
//	: public QVTKOpenGLNativeWidget
//{
//	Q_OBJECT
//
//public:
//
//	enum GridDrawPlane
//	{
//		XY = 0,
//		XZ = 1,
//		YZ = 2
//	};
//
//	struct GridActor
//	{
//		vtkSmartPointer<vtkActor> theMajorActor_ = FrgNullPtr;
//		vtkSmartPointer<vtkActor> theMinorActor_ = FrgNullPtr;
//		vtkSmartPointer<vtkActor> theMiddleLines_ = FrgNullPtr;
//
//		int theNbMajorDivision_;
//		int theNbMinorDivision_;
//
//		GridActor(int nbMajorDivision, int nbMinorDivision, double MajorColor[3], double MinorColor[3]);
//	};
//
//private:
//
//	FrgBase_Menu* theContextMenuInScene_ = FrgNullPtr;
//	QList<FrgBase_Menu*> theMenus_;
//
//	vtkSmartPointer<vtkRenderer> theRenderer_;
//	vtkSmartPointer<vtkGenericOpenGLRenderWindow> theRenderWindow_;
//	vtkSmartPointer<vtkRenderWindowInteractor> theRenderWindowInteractor_;
//	vtkSmartPointer<FrgVisual_Scene_InterStyle3D> theInteractorStyle_;
//	vtkSmartPointer<vtkCamera> theCamera_;
//	vtkSmartPointer<vtkTextActor> theLogoActor_;
//	QList<vtkSmartPointer<vtkActor>> theActors_;
//
//	GridActor* theGridActor_ = FrgNullPtr;
//
//	/* Parents */
//	FrgBase_MainWindow* theParentMainWindow_ = FrgNullPtr;
//	//FrgBase_Tree* theParentTree_;
//
//	void Init();
//	void DrawGrid(vtkSmartPointer<vtkActor> actor, int nbDivision, FrgBool isMajor, double* bounds, GridDrawPlane plane = XY);
//	void DrawGridMiddleLines(vtkSmartPointer<vtkActor> actor, double* bounds, GridDrawPlane plane = XY);
//	void CreateContextMenuInScene();
//	void CreateMenus();
//
//public:
//
//	FrgVisual_Scene3D(FrgBase_MainWindow* parentMainWindow);
//
//	void StartScene();
//
//	FrgGetMacro(vtkSmartPointer<vtkRenderer>, Renderer, theRenderer_);
//	FrgGetMacro(vtkSmartPointer<vtkRenderWindowInteractor>, RenderWindowInteractor, theRenderWindowInteractor_);
//	FrgGetMacro(vtkSmartPointer<FrgVisual_Scene_InterStyle3D>, InteractorStyle, theInteractorStyle_);
//	FrgGetMacro(vtkSmartPointer<vtkCamera>, FrgBaseCamera, theCamera_);
//	FrgGetMacro(vtkSmartPointer<vtkTextActor>, LogoActor, theLogoActor_);
//	FrgGetMacro(vtkSmartPointer<vtkGenericOpenGLRenderWindow>, FrgBaseRenderWindow, theRenderWindow_);
//	FrgGetMacro(QList<vtkSmartPointer<vtkActor>>, Actors, theActors_);
//	//FrgGetMacro(QMapActorToPartFeature, ActorToPartFeature, theActorToPartFeature_);
//	//FrgGetMacro(QMapPartFeatureToActor, PartFeatureToActor, thePartFeatureToActor_);
//	FrgGetMacro(FrgBase_Menu*, ContextMenuInScene, theContextMenuInScene_);
//	FrgGetMacro(QList<FrgBase_Menu*>, Menus, theMenus_);
//	//FrgGetMacro(FrgBase_CADScene_TreeItem*, ParentCADSceneTreeItem, theParentCADSceneTreeItem_);
//	//FrgGetMacro(FrgBase_Tree*, ParentTree, theParentTree_);
//	FrgGetMacro(FrgBase_MainWindow*, ParentMainWindow, theParentMainWindow_);
//
//	void Render(FrgBool resetCamera = FrgTrue);
//	QAction* GetActionItemInScene(FrgString actionName);
//	void DrawGrid(int nbDivision, int nbMinorDivision, GridDrawPlane plane = XY);
//	void ClearGrid();
//	void RemoveActor(vtkProp* prop);
//
//public slots:
//
//	void customContextMenuRequestedSlot(const QPoint& pos);
//	void SetViewToXYPlaneSlot(bool);
//	void SetViewToXZPlaneSlot(bool);
//	void SetViewToYZPlaneSlot(bool);
//	void SetViewToXYZSlot(bool);
//	void GridOpacityChangedSlot(int);
//	void DrawGridSlot(bool);
//	void ScreenshotSlot(bool);
//	void RandomColorsSlot(bool);
//	void ShowMeshSlot(bool condition);
//	void HideActorsSlot(bool);
//	void ShowHiddenPartsSlot(bool);
//	virtual void ExportSelectedPartClickedSlot(bool) {}
//
//	void SelectIconSelectedSlot(bool);
//	void MoveIconSelectedSlot(bool);
//	void RotateXIconSelectedSlot(bool);
//	void RotateYIconSelectedSlot(bool);
//	void RotateZIconSelectedSlot(bool);
//	void RotateXYZIconSelectedSlot(bool);
//
//signals:
//
//	void ActorSelectedSignal(bool);
//};
//
//EndForgVisualLib
//
//#endif // !_FrgVisual_Scene3D_Header
