#pragma once
#ifndef _FrgVisual_Scene_Header
#define _FrgVisual_Scene_Header

#include <FrgVisual_Global.hxx>
#include <QtWidgets/QMainWindow>

#include <FrgVisual_Serialization_Global.hxx>

class vtkRenderer;
class vtkGenericOpenGLRenderWindow;
class vtkRenderWindowInteractor;
class vtkInteractorStyle;
class vtkCamera;
class vtkTextActor;
class vtkAxesActor;
class vtkCameraInterpolator;

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

class FrgVisual_Scene_InterStyle_Base;

class FORGVISUAL_EXPORT FrgVisual_Scene_Entity
	: public QMainWindow
{

	Q_OBJECT

public:

	FrgVisual_Scene_Entity
	(
		ForgBaseLib::FrgBase_MainWindow* parentMainWindow = nullptr
	);

	~FrgVisual_Scene_Entity();

	vtkSmartPointer<vtkRenderer> GetRenderer() { return theRenderer_; }
	vtkSmartPointer<vtkRenderWindowInteractor> GetRenderWindowInteractor() { return theRenderWindowInteractor_; }

	vtkAxesActor* GetAxesActor() const { return theAxesActor_; }

	void RemoveAllActors();
	virtual void SetLogoText(const char* logoText);

	virtual void SetParentMainWindow(ForgBaseLib::FrgBase_MainWindow* parentMainWindow);

	virtual void ComputeVisiblePropBounds(double bounds[6]) const;

	ForgBaseLib::FrgBase_MainWindow* GetParentMainWindow() const { return theParentMainWindow_; }

Q_SIGNALS:

	void RenderScene(bool resetCamera = true, bool resetView = false);

protected:

	QVTKOpenGLNativeWidget* theOpenGLWidget_ = nullptr;
	QToolBar* theToolBar_ = nullptr;

private:

	DECLARE_SAVE_LOAD_HEADER(FORGVISUAL_EXPORT)

protected:

	vtkSmartPointer<vtkRenderer> theRenderer_;
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> theRenderWindow_;
	vtkSmartPointer<vtkRenderWindowInteractor> theRenderWindowInteractor_;
	FrgVisual_Scene_InterStyle_Base* theInteractorStyle_;
	vtkSmartPointer<vtkCamera> theCamera_;
	vtkSmartPointer<vtkTextActor> theLogoActor_;
	vtkAxesActor* theAxesActor_ = nullptr;
	vtkCameraInterpolator* theCameraInterpolator_ = nullptr;

	ForgBaseLib::FrgBase_MainWindow* theParentMainWindow_ = nullptr;
	ForgBaseLib::FrgBase_Menu* theContextMenuInScene_ = nullptr;

	bool theInitiated_;

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

	virtual void RenderSceneSlot(bool resetCamera = true, bool resetView = false) {}

};

class FrgVisual_BaseActor_Entity;

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
class FrgVisual_BSPLineActor;
template<int Dim>
class FrgVisual_TextActor;

class FrgVisual_RectangleActor;
class FrgVisual_CircleActor;
class FrgVisual_GridActor;
class FrgVisual_BoxActor;

template <int Dim>
class FrgVisual_SceneRegistry;

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
		ForgBaseLib::FrgBase_Pnt<Dim> pt,
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
		ForgBaseLib::FrgBase_Pnt<Dim> pt,
		bool render = true
	);

	// ==================================================================================
	// Add Line
	// ==================================================================================

	FrgVisual_LineActor<Dim>* AddLine
	(
		ForgBaseLib::FrgBase_Pnt<Dim> P0,
		ForgBaseLib::FrgBase_Pnt<Dim> P1,
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
		std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> pts,
		bool render = true
	);

	// ==================================================================================
	// Add Rectangle
	// ==================================================================================

	template <typename = typename std::enable_if_t<Dim == 2>>
	FrgVisual_RectangleActor* AddRectangle
	(
		ForgBaseLib::FrgBase_Pnt<2> P0,
		ForgBaseLib::FrgBase_Pnt<2> P1,
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
		ForgBaseLib::FrgBase_Pnt<2> center,
		double radius,
		bool render = true
	);

	template <typename = typename std::enable_if_t<Dim == 2>>
	FrgVisual_CircleActor* AddCircleUsingCenterAndPointOnCurve
	(
		ForgBaseLib::FrgBase_Pnt<2> center,
		ForgBaseLib::FrgBase_Pnt<2> pointOnCurve,
		bool render = true
	);

	// ==================================================================================
	// Add Triangulation
	// ==================================================================================

	template <typename Triangulation>
	void AddTriangulations
	(
		std::vector<Triangulation> triangulations,
		bool render
	);

	FrgVisual_MeshActor<Dim>* AddTriangulation
	(
		std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> pts,
		std::vector<std::tuple<int, int, int>> connectivity,
		bool render = true
	);

	// ==================================================================================
	// Add BSPLine
	// ==================================================================================

	FrgVisual_BSPLineActor<Dim>* AddBSPLine
	(
		std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> ctrlPts,
		int degree,
		bool render = true
	);

	// Interpolating BSPLine Curve
	FrgVisual_BSPLineActor<Dim>* AddBSPLineThroughPoints
	(
		std::vector<ForgBaseLib::FrgBase_Pnt<Dim>> pts,
		int degree,
		bool render = true
	);

	// ==================================================================================
	// Add Box
	// ==================================================================================

	template <typename = typename std::enable_if_t<Dim == 3>>
	FrgVisual_BoxActor* AddBox
	(
		ForgBaseLib::FrgBase_Pnt<3> P0,
		ForgBaseLib::FrgBase_Pnt<3> P1,
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
	// Add Text
	// ==================================================================================

	template <typename = typename std::enable_if_t<Dim == 2>>
	FrgVisual_TextActor<2>* AddText
	(
		const QString& value,
		double posx,
		double posy,
		bool render = true
	);

	template <typename = typename std::enable_if_t<Dim == 3>>
	FrgVisual_TextActor<3>* AddText
	(
		const QString& value,
		double posx,
		double posy,
		double posz,
		bool render = true
	);

	template <typename T>
	void ClearAllDataType();

	void ClearAllPoints();
	void ClearAllLines();
	void ClearAllPolylines();

	// return actor index in registry, return -2 if actor is PickingPoint, return -1 if registration of actor was not successful
	int AddActorToScene(FrgVisual_BaseActor_Entity* actor);
	void RemoveActor(FrgVisual_BaseActor_Entity* actor);

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

	public:

		FrgVisual_GridActor* GetMajorGridActor() const { return theMajorGridActor_; }
		FrgVisual_GridActor* GetMinorGridActor() const { return theMinorGridActor_; }

private:

	DECLARE_SAVE_LOAD_HEADER()

protected:

	FrgVisual_GridActor* theMajorGridActor_ = nullptr;
	FrgVisual_GridActor* theMinorGridActor_ = nullptr;

	QColor theMajorGridColor_;
	QColor theMinorGridColor_;

	FrgVisual_SceneRegistry<Dim>* theRegistry_ = nullptr;
};

EndForgVisualLib

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Scene_Entity)

BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Scene<2>)
BOOST_CLASS_EXPORT_KEY(ForgVisualLib::FrgVisual_Scene<3>)

#include <FrgVisual_SceneI.hxx>

#endif // !_FrgVisual_Scene_Header
