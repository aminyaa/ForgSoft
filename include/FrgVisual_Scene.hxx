#pragma once
#ifndef _FrgVisual_Scene_Header
#define _FrgVisual_Scene_Header

#include <FrgVisual_Global.hxx>
#include <FrgBase_Object.hxx>
#include <QtWidgets/QMainWindow>

#include <FrgVisual_Serialization_Global.hxx>
#include <FrgVisual_Global_Icons.hxx>

class vtkRenderer;
class vtkGenericOpenGLRenderWindow;
class vtkRenderWindowInteractor;
class vtkInteractorStyle;
class vtkCamera;
class vtkTextActor;
class vtkAxesActor;
class vtkCameraInterpolator;
class vtkLight;
class vtkLogoRepresentation;

class QPoint;
class QVTKOpenGLNativeWidget;

template<class T>
class vtkSmartPointer;

namespace ForgBaseLib
{
	class FrgBase_MainWindow;
	class FrgBase_Menu;

	template<int Dim>
	class FrgBase_Pnt;
}

BeginForgVisualLib

class FrgVisual_SceneRegistry;
class FrgVisual_BaseActor_Entity;
class FrgVisual_Scene_InterStyle_Base;
class FrgVisual_GridActor;
class FrgVisual_Scene_Ruler;

template<int Dim>
class FrgVisual_TextActor;

class FORGVISUAL_EXPORT FrgVisual_Scene_Entity
	: public QMainWindow
	, public ForgBaseLib::FrgBase_Object
{

	Q_OBJECT

public:

	FrgVisual_Scene_Entity
	(
		ForgBaseLib::FrgBase_MainWindow* parentMainWindow = nullptr
	);

	~FrgVisual_Scene_Entity();

	virtual bool Is2D() const { return false; }
	virtual bool Is3D() const { return false; }

	virtual bool IsThemeDark() const;
	virtual void SetThemeDark(const bool isDark = false);

	vtkSmartPointer<vtkRenderer> GetRenderer() { return theRenderer_; }
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> GetRenderWindow() { return theRenderWindow_; }
	vtkSmartPointer<vtkRenderWindowInteractor> GetRenderWindowInteractor() { return theRenderWindowInteractor_; }
	FrgVisual_Scene_InterStyle_Base* GetInteractorStyle() { return theInteractorStyle_; }
	vtkSmartPointer<vtkCamera> GetCamera() const { return theCamera_; }
	std::vector<vtkSmartPointer<vtkLight>> GetLights() const { return theLights_; }
	std::vector<vtkSmartPointer<vtkLight>>& GetLightsRef() { return theLights_; }
	vtkSmartPointer<vtkTextActor> GetLogoTextActor() const { return theLogoActor_; }
	vtkSmartPointer<FrgVisual_Scene_Ruler> GetLegendScaleActor() const { return theRuler_; }
	vtkAxesActor* GetAxesActor() const { return theAxesActor_; }
	vtkAxesActor* GetAxesCenterWorldActor() const { return theAxesCenterWorldActor_; }
	vtkCameraInterpolator* GetCameraInterpolator() const { return theCameraInterpolator_; }

	ForgBaseLib::FrgBase_MainWindow* GetParentMainWindow() const { return theParentMainWindow_; }
	ForgBaseLib::FrgBase_Menu* GetContextMenuInScene() const { return theCopyContextMenuInScene_ ? theCopyContextMenuInScene_ : theContextMenuInScene_; }
	ForgBaseLib::FrgBase_Menu*& GetContextMenuInSceneRef() { return theCopyContextMenuInScene_; }
	void SetContextMenuInScene(ForgBaseLib::FrgBase_Menu* menu);
	void RestoreContextMenuInScene() { theCopyContextMenuInScene_ = nullptr; }
	const auto& GetContextMenuPosition() const { return theContextMenuPosition_; }
	void SetContextMenuPosition(const QPoint& pos) { theContextMenuPosition_ = pos; }

	bool IsInitiated() const { return theInitiated_; }
	void SetInitiated(bool condition) { theInitiated_ = condition; }

	FrgVisual_GridActor* GetMajorGridActor() const { return theMajorGridActor_; }
	FrgVisual_GridActor* GetMinorGridActor() const { return theMinorGridActor_; }

	const QColor& GetMajorGridColor() const { return theMajorGridColor_; }
	const QColor& GetMinorGridColor() const { return theMinorGridColor_; }

	bool IsContextMenuExecutable() const { return theIsContextMenuExecutable_; }
	void SetContextMenuExecutable(bool condition) { theIsContextMenuExecutable_ = condition; }

	void RemoveAllActors();
	virtual void SetLogoText(const char* logoText);

	virtual void SetParentMainWindow(ForgBaseLib::FrgBase_MainWindow* parentMainWindow);

	void SetMajorGridColor(const QColor& color);
	void SetMinorGridColor(const QColor& color);

	const vtkSmartPointer<vtkLogoRepresentation>& GetLogoImage() const { return theLogoImage_; }
	void SetLogoImage(const vtkSmartPointer<vtkLogoRepresentation>& logoImage);

	virtual std::vector<FrgVisual_BaseActor_Entity*> GetAllActors(const bool everything = false) const;
	virtual std::vector<FrgVisual_BaseActor_Entity*> GetSelectedActors() const { return std::vector<FrgVisual_BaseActor_Entity*>(); }
	virtual std::vector<FrgVisual_BaseActor_Entity*> GetHiddenActors() const { return std::vector<FrgVisual_BaseActor_Entity*>(); }

	virtual void SelectActor(FrgVisual_BaseActor_Entity* actor, int isControlKeyPressed, bool render = true) {}
	virtual void SelectActor(std::vector<FrgVisual_BaseActor_Entity*> actors, int isControlKeyPressed, bool render = true) {}
	virtual void UnSelectActor(FrgVisual_BaseActor_Entity* actor, bool render = true) {}
	virtual void SelectAllActors(bool render = true) {}
	virtual void UnSelectAllActors(bool render = true) {}

	// return actor index in registry, return -2 if actor is PickingPoint, return -1 if registration of actor was not successful
	int AddActorToScene(FrgVisual_BaseActor_Entity* actor);
	Q_SIGNAL void RemoveActor(FrgVisual_BaseActor_Entity* actor);

	std::vector<FrgVisual_GridActor*> DrawGrid
	(
		std::shared_ptr<ForgBaseLib::FrgBase_Pnt<2>> center,
		double L1,
		double L2,
		int numberOfDivisions1,
		int numberOfDivisions2,
		bool render = true
	);

	std::vector<FrgVisual_GridActor*> DrawGrid
	(
		double xCenter,
		double yCenter,
		double L1,
		double L2,
		int numberOfDivisions1,
		int numberOfDivisions2,
		bool render = true
	);

	void ClearGrid();

	// ==================================================================================
	// Add Text
	// ==================================================================================

	FrgVisual_TextActor<2>* AddText
	(
		const QString& value,
		double posx,
		double posy,
		bool render = true
	);

	FrgVisual_TextActor<3>* AddText
	(
		const QString& value,
		double posx,
		double posy,
		double posz,
		bool render = true
	);

	FrgVisual_SceneRegistry* GetRegistry() const { return theRegistry_; }

	void SetLogoImageFileAddress(const std::string& fileName);
	void SetLogoImageHidden(bool condition);

	// first: min point, second: max point
	virtual std::pair<ForgBaseLib::FrgBase_Pnt<3>, ForgBaseLib::FrgBase_Pnt<3>>
		ComputeVisibleBoundingBox() const;

	virtual void ComputeVisiblePropBounds(double bounds[6]) const;

protected:

	void InitLogoImage(const std::string& fileName = ICON_FRGVISUAL_SCENE_LOGO);

	void RemoveActorSlot(FrgVisual_BaseActor_Entity* actor);

Q_SIGNALS:

	void RenderScene(bool resetCamera = true, bool resetView = false);
	void ActorAddedSignal(FrgVisual_BaseActor_Entity*);
	void ActorIsGoingToBeDeletedSignal(FrgVisual_BaseActor_Entity*);
	void ActorSelectedSignal(FrgVisual_BaseActor_Entity*);
	void ActorUnSelectedSignal(FrgVisual_BaseActor_Entity*);
	void ActorHideSignal(FrgVisual_BaseActor_Entity*);
	void ActorUnHideSignal(FrgVisual_BaseActor_Entity*);

	void ContextMenuAboutToShow(ForgBaseLib::FrgBase_Menu*);
	void ContextMenuAboutToHide(ForgBaseLib::FrgBase_Menu*);

	void OnMouseMove(FrgVisual_Scene_Entity*);
	void OnLeftButtonDown(FrgVisual_Scene_Entity*);
	void OnLeftButtonUp(FrgVisual_Scene_Entity*);
	void OnMiddleButtonDown(FrgVisual_Scene_Entity*);
	void OnMiddleButtonUp(FrgVisual_Scene_Entity*);
	void OnRightButtonDown(FrgVisual_Scene_Entity*);
	void OnRightButtonUp(FrgVisual_Scene_Entity*);
	void OnMouseWheelBackward(FrgVisual_Scene_Entity*);
	void OnMouseWheelForward(FrgVisual_Scene_Entity*);

protected:

	QVTKOpenGLNativeWidget* theOpenGLWidget_ = nullptr;
	QToolBar* theToolBar_ = nullptr;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)

protected:

	FrgVisual_SceneRegistry* theRegistry_ = nullptr;

	vtkSmartPointer<vtkRenderer> theRenderer_;
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> theRenderWindow_;
	vtkSmartPointer<vtkRenderWindowInteractor> theRenderWindowInteractor_;
	FrgVisual_Scene_InterStyle_Base* theInteractorStyle_;
	vtkSmartPointer<vtkCamera> theCamera_;
	mutable std::vector<vtkSmartPointer<vtkLight>> theLights_;
	mutable vtkSmartPointer<vtkTextActor> theLogoActor_;
	vtkAxesActor* theAxesActor_ = nullptr;
	vtkAxesActor* theAxesCenterWorldActor_ = nullptr;
	vtkCameraInterpolator* theCameraInterpolator_ = nullptr;

	vtkSmartPointer<FrgVisual_Scene_Ruler> theRuler_;

	ForgBaseLib::FrgBase_MainWindow* theParentMainWindow_ = nullptr;
	ForgBaseLib::FrgBase_Menu* theContextMenuInScene_ = nullptr;
	ForgBaseLib::FrgBase_Menu* theCopyContextMenuInScene_ = nullptr;

	QPoint theContextMenuPosition_;

	bool theInitiated_;

	FrgVisual_GridActor* theMajorGridActor_ = nullptr;
	FrgVisual_GridActor* theMinorGridActor_ = nullptr;

	QColor theMajorGridColor_;
	QColor theMinorGridColor_;

	bool theIsContextMenuExecutable_ = true;

	vtkSmartPointer<vtkLogoRepresentation> theLogoImage_;

protected:

	virtual void Init() {}

	virtual void FormToolBar();

	virtual void InitInteractorStyle() {}

public slots:

	void customContextMenuRequestedSlot(const QPoint& pos);

	void HideActionIsCalledSlot();
	void UnHideActionIsCalledSlot();

	void CurrentTabChangedSlot(int index);

protected slots:
	
	virtual void RenderSceneSlot(bool resetCamera = true, bool resetView = false);

};

template<int Dim>
class FrgVisual_PointActor;
template<int Dim>
class FrgVisual_PickingPointActor;
template<int Dim>
class FrgVisual_LineActor;
template<int Dim>
class FrgVisual_PolylineActor;
template<int Dim>
class FrgVisual_MeshActor;
template<int Dim>
class FrgVisual_MeshPolyhedralActor;
template<int Dim>
class FrgVisual_BSPLineActor;
template<int Dim>
class FrgVisual_PlaneActor;

class FrgVisual_RectangleActor;
class FrgVisual_CircleActor;
class FrgVisual_BoxActor;
class FrgVisual_CylinderActor;

template<int Dim>
class FORGVISUAL_EXPORT FrgVisual_Scene
	: public FrgVisual_Scene_Entity
{

public:

	FrgVisual_Scene(ForgBaseLib::FrgBase_MainWindow* parentMainWindow = nullptr);

	~FrgVisual_Scene();

	void Init() override;

	void RenderSceneSlot(bool resetCamera = true, bool resetView = false) override;

	// ==================================================================================
	// Add Point
	// ==================================================================================

	FrgVisual_PointActor<Dim>* AddPoint
	(
		const ForgBaseLib::FrgBase_Pnt<Dim>& pt,
		bool render = true
	);

	template <typename = typename std::enable_if_t<Dim == 2>>
	FrgVisual_PointActor<2>* AddPoint
	(
		double x = 0.0,
		double y = 0.0,
		bool render = true
	);

	template <typename = typename std::enable_if_t<Dim == 3>>
	FrgVisual_PointActor<3>* AddPoint
	(
		double x = 0.0,
		double y = 0.0,
		double z = 0.0,
		bool render = true
	);

	FrgVisual_PickingPointActor<Dim>* AddPickingPoint
	(
		const ForgBaseLib::FrgBase_Pnt<Dim>& pt,
		bool render = true
	);

	// ==================================================================================
	// Add Line
	// ==================================================================================

	FrgVisual_LineActor<Dim>* AddLine
	(
		const ForgBaseLib::FrgBase_Pnt<Dim>& P0,
		const ForgBaseLib::FrgBase_Pnt<Dim>& P1,
		bool render = true
	);

	template <typename = typename std::enable_if_t<Dim == 2>>
	FrgVisual_LineActor<2>* AddLine
	(
		double P0_X,
		double P0_Y,
		double P1_X,
		double P1_Y,
		bool render = true
	);

	template <typename = typename std::enable_if_t<Dim == 3>>
	FrgVisual_LineActor<3>* AddLine
	(
		double P0_X,
		double P0_Y,
		double P0_Z,
		double P1_X,
		double P1_Y,
		double P1_Z,
		bool render = true
	);

	// ==================================================================================
	// Add Polyline
	// ==================================================================================

	FrgVisual_PolylineActor<Dim>* AddPolyline
	(
		const std::vector<ForgBaseLib::FrgBase_Pnt<Dim>>& pts,
		bool render = true
	);

	// ==================================================================================
	// Add Rectangle
	// ==================================================================================

	template <typename = typename std::enable_if_t<Dim == 2>>
	FrgVisual_RectangleActor* AddRectangle
	(
		const ForgBaseLib::FrgBase_Pnt<2>& P0,
		const ForgBaseLib::FrgBase_Pnt<2>& P1,
		bool render = true
	);

	template <typename = typename std::enable_if_t<Dim == 2>>
	FrgVisual_RectangleActor* AddRectangle
	(
		double P0_X,
		double P0_Y,
		double P1_X,
		double P1_Y,
		bool render = true
	);

	// ==================================================================================
	// Add Circle
	// ==================================================================================

	template <typename = typename std::enable_if_t<Dim == 2>>
	FrgVisual_CircleActor* AddCircle
	(
		const ForgBaseLib::FrgBase_Pnt<2>& center,
		double radius,
		bool render = true
	);

	template <typename = typename std::enable_if_t<Dim == 2>>
	FrgVisual_CircleActor* AddCircleUsingCenterAndPointOnCurve
	(
		const ForgBaseLib::FrgBase_Pnt<2>& center,
		const ForgBaseLib::FrgBase_Pnt<2>& pointOnCurve,
		bool render = true
	);

	// ==================================================================================
	// Add Triangulation
	// ==================================================================================

	template <typename Triangulation>
	void AddTriangulations
	(
		const std::vector<Triangulation>& triangulations,
		bool render
	);

	FrgVisual_MeshActor<Dim>* AddTriangulation
	(
		const std::vector<ForgBaseLib::FrgBase_Pnt<Dim>>& pts,
		const std::vector<std::tuple<int, int, int>>& connectivity,
		bool render = true
	);

	// ==================================================================================
	// Add Polyhedral
	// ==================================================================================
	FrgVisual_MeshPolyhedralActor<Dim>* AddPolyhedral
	(
		const std::vector<ForgBaseLib::FrgBase_Pnt<Dim>>& pts,
		const std::vector<std::vector<int>>& connectivity,
		bool render = true
	);

	// ==================================================================================
	// Add BSPLine
	// ==================================================================================

	FrgVisual_BSPLineActor<Dim>* AddBSPLine
	(
		const std::vector<ForgBaseLib::FrgBase_Pnt<Dim>>& ctrlPts,
		int degree,
		bool render = true
	);

	// Interpolating BSPLine Curve
	FrgVisual_BSPLineActor<Dim>* AddBSPLineThroughPoints
	(
		const std::vector<ForgBaseLib::FrgBase_Pnt<Dim>>& pts,
		int degree,
		bool render = true
	);

	// ==================================================================================
	// Add Box
	// ==================================================================================

	template <typename = typename std::enable_if_t<Dim == 3>>
	FrgVisual_BoxActor* AddBox
	(
		const ForgBaseLib::FrgBase_Pnt<3>& P0,
		const ForgBaseLib::FrgBase_Pnt<3>& P1,
		bool render = true
	);

	template <typename = typename std::enable_if_t<Dim == 3>>
	FrgVisual_BoxActor* AddBox
	(
		double P0_X,
		double P0_Y,
		double P0_Z,
		double P1_X,
		double P1_Y,
		double P1_Z,
		bool render = true
	);

	// ==================================================================================
	// Add Cylinder
	// ==================================================================================

	template <typename = typename std::enable_if_t<Dim == 3>>
	FrgVisual_CylinderActor* AddCylinder
	(
		const ForgBaseLib::FrgBase_Pnt<3>& Start,
		const ForgBaseLib::FrgBase_Pnt<3>& End,
		double radius,
		bool render = true
	);

	template <typename = typename std::enable_if_t<Dim == 3>>
	FrgVisual_CylinderActor* AddCylinder
	(
		double Start_X,
		double Start_Y,
		double Start_Z,
		double End_X,
		double End_Y,
		double End_Z,
		double radius,
		bool render = true
	);

	// ==================================================================================
	// Add Plane
	// ==================================================================================

	FrgVisual_PlaneActor<Dim>* AddPlane
	(
		const ForgBaseLib::FrgBase_Pnt<Dim>& center,
		const ForgBaseLib::FrgBase_Pnt<Dim>& normal,
		bool render = true
	);

	FrgVisual_PlaneActor<Dim>* AddPlane
	(
		const ForgBaseLib::FrgBase_Pnt<Dim>& origin,
		const ForgBaseLib::FrgBase_Pnt<Dim>& P1,
		const ForgBaseLib::FrgBase_Pnt<Dim>& P2,
		bool render = true
	);

	template <typename T>
	void ClearAllDataType();

	void ClearAllPoints();
	void ClearAllLines();
	void ClearAllPolylines();

private:

	DECLARE_SAVE_LOAD_HEADER( )
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Scene_Entity)

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Scene<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Scene<3>)

#include <FrgVisual_SceneI.hxx>

#endif // !_FrgVisual_Scene_Header
