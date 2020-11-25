#include <FrgVisual_Scene.hxx>
#include <FrgBase_MainWindow.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgVisual_Scene_InterStyle.hxx>

#include <FrgBase_SerialSpec_QString.hxx>
#include <FrgBase_SerialSpec_QColor.hxx>

#include <FrgVisual_PointActor.hxx>
#include <FrgVisual_LineActor.hxx>
#include <FrgVisual_PolylineActor.hxx>
#include <FrgVisual_MeshActor.hxx>
#include <FrgVisual_BSPLineActor.hxx>
#include <FrgVisual_RectangleActor.hxx>
#include <FrgVisual_GridActor.hxx>
#include <FrgVisual_BoxActor.hxx>
#include <FrgVisual_TextActor.hxx>
#include <FrgVisual_Scene_InterStyle2D.hxx>
#include <FrgVisual_Scene_InterStyle3D.hxx>
#include <FrgBase_Menu.hxx>
#include <FrgBase_Pnt.hxx>
#include <FrgBase_TabWidget.hxx>

#include <QVTKOpenGLNativeWidget.h>
#include <vtkActor.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkAxesActor.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>
#include <vtkCamera.h>
#include <vtkLineSource.h>
#include <vtkPolyLine.h>
#include <vtkCubeSource.h>
#include <vtkAssemblyPath.h>
#include <vtkCollection.h>
#include <vtkCameraInterpolator.h>

#include <vtkAutoInit.h>

#define IS_FRGVISUAL_ACTOR "IS_FRGVISUAL_ACTOR"
#define IS_NOT_FRGVISUAL_ACTOR "IS_NOT_FRGVISUAL_ACTOR"

VTK_MODULE_INIT(vtkRenderingContextOpenGL2)
VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingFreeType)
VTK_MODULE_INIT(vtkRenderingGL2PSOpenGL2)

ForgVisualLib::FrgVisual_Scene_Entity::FrgVisual_Scene_Entity
(
	ForgBaseLib::FrgBase_MainWindow* parentMainWindow
)
	: QMainWindow(parentMainWindow)
	, theParentMainWindow_(parentMainWindow)
{
	theOpenGLWidget_ = new QVTKOpenGLNativeWidget(parentMainWindow);
	
	theContextMenuInScene_ = new ForgBaseLib::FrgBase_Menu("Scene Settings", parentMainWindow, false);
	theContextMenuInScene_->SetToolBarHidden(true);

	auto hideAction = theContextMenuInScene_->AddItem("Hide", false);
	auto unHideAction = theContextMenuInScene_->AddItem("UnHide", false);

	connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(customContextMenuRequestedSlot(const QPoint&)));

	this->setCentralWidget(theOpenGLWidget_);

	if(theParentMainWindow_)
	{
		connect(theParentMainWindow_->GetTabWidget(), &ForgBaseLib::FrgBase_TabWidget::currentChanged, this, &FrgVisual_Scene_Entity::CurrentTabChangedSlot);
	}
}

ForgVisualLib::FrgVisual_Scene_Entity::~FrgVisual_Scene_Entity()
{
	RemoveAllActors();
}

void ForgVisualLib::FrgVisual_Scene_Entity::RemoveAllActors()
{
	if (theRenderer_)
	{
		vtkActorCollection* ac = theRenderer_->GetActors();
		vtkCollectionSimpleIterator ait;
		vtkActor* anActor, * aPart;
		vtkAssemblyPath* path;
		for (ac->InitTraversal(ait); (anActor = ac->GetNextActor(ait)); )
		{
			theRenderer_->RemoveActor(anActor);
		}
	}
}

void ForgVisualLib::FrgVisual_Scene_Entity::SetLogoText(const char* logoText)
{
	if (theLogoActor_)
	{
		theLogoActor_->SetInput(logoText);
		RenderScene(false);
	}
}

void ForgVisualLib::FrgVisual_Scene_Entity::SetParentMainWindow(ForgBaseLib::FrgBase_MainWindow* parentMainWindow)
{
	this->setParent(parentMainWindow);
	theParentMainWindow_ = parentMainWindow;

	connect(theParentMainWindow_->GetTabWidget(), &ForgBaseLib::FrgBase_TabWidget::currentChanged, this, &FrgVisual_Scene_Entity::CurrentTabChangedSlot);
}

void ForgVisualLib::FrgVisual_Scene_Entity::ComputeVisiblePropBounds(double bounds[6]) const
{
	if (theRenderer_)
		theRenderer_->ComputeVisiblePropBounds(bounds);
}

void ForgVisualLib::FrgVisual_Scene_Entity::customContextMenuRequestedSlot(const QPoint& pos)
{
	theContextMenuInScene_->exec(this->mapToGlobal(pos));
}

void ForgVisualLib::FrgVisual_Scene_Entity::HideActionIsCalledSlot()
{

}

void ForgVisualLib::FrgVisual_Scene_Entity::UnHideActionIsCalledSlot()
{

}

void ForgVisualLib::FrgVisual_Scene_Entity::CurrentTabChangedSlot(int index)
{
	if (theParentMainWindow_->GetTabWidget()->widget(index) == this)
		RenderScene(false);
}

template<int Dim>
ForgVisualLib::FrgVisual_Scene<Dim>::FrgVisual_Scene(ForgBaseLib::FrgBase_MainWindow* parentMainWindow)
	: FrgVisual_Scene_Entity(parentMainWindow)
{

}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene<Dim>::Init()
{
	theRenderer_ = vtkSmartPointer<vtkRenderer>::New();

	if (theParentMainWindow_)
	{
		if (theParentMainWindow_->IsThemeDark())
		{
			theRenderer_->SetBackground(30.0 / 255.0, 94.0 / 255.0, 144.0 / 255.0);
			theRenderer_->SetBackground2(0.0, 0.0, 0.0);
			theRenderer_->SetGradientBackground(true);
		}
		else
		{
			theRenderer_->SetBackground(1.0, 1.0, 1.0);
			theRenderer_->SetGradientBackground(false);
		}
	}
	else
	{
		if constexpr (Dim == 2)
		{
			theRenderer_->SetBackground(1.0, 1.0, 1.0);
			theRenderer_->SetGradientBackground(false);
		}
		else if constexpr (Dim == 3)
		{
			theRenderer_->SetBackground(1.0, 1.0, 1.0);
			theRenderer_->SetBackground2(0.7, 0.7, 0.7);
			theRenderer_->SetGradientBackground(true);
		}
	}

	theRenderWindow_ = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();

	theRenderWindow_->AddRenderer(theRenderer_);

	theRenderWindowInteractor_ = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	theRenderWindowInteractor_->SetRenderWindow(theRenderWindow_);

	if constexpr (Dim == 2)
		theInteractorStyle_ = FrgVisual_Scene_InterStyle2D::New();
	else if constexpr (Dim == 3)
		theInteractorStyle_ = FrgVisual_Scene_InterStyle3D::New();

	if constexpr (Dim == 2)
	{
		auto castedInteractorStyle = FrgVisual_Scene_InterStyle2D::SafeDownCast((FrgVisual_Scene_InterStyle2D::SuperClass*)(theInteractorStyle_));
		castedInteractorStyle->SetParentScene(this);
		castedInteractorStyle->SetCurrentRenderer(theRenderer_);
		castedInteractorStyle->SetMouseWheelMotionFactor(0.5);
		theRenderWindowInteractor_->SetInteractorStyle(castedInteractorStyle);
	}
	else if constexpr (Dim == 3)
	{
		auto castedInteractorStyle = FrgVisual_Scene_InterStyle3D::SafeDownCast((FrgVisual_Scene_InterStyle3D::SuperClass*)(theInteractorStyle_));
		castedInteractorStyle->SetParentScene(this);
		castedInteractorStyle->SetCurrentRenderer(theRenderer_);
		castedInteractorStyle->SetMouseWheelMotionFactor(0.5);
		theRenderWindowInteractor_->SetInteractorStyle(castedInteractorStyle);
	}

	theAxesActor_ = vtkAxesActor::New();

	theAxesActor_->PickableOff();
	theAxesActor_->SetShaftTypeToLine();
	theAxesActor_->SetOrigin(0.0, 0.0, 0.0);
	theAxesActor_->SetScale(10.0);

	if constexpr (Dim == 2)
	{
		theAxesActor_->SetZAxisLabelText("");
		theAxesActor_->GetZAxisShaftProperty()->SetAmbient(0.0);
		theAxesActor_->GetZAxisTipProperty()->SetAmbient(0.0);
	}

	vtkOrientationMarkerWidget* widget = vtkOrientationMarkerWidget::New();

	widget->SetOutlineColor(0.9300, 0.5700, 0.1300);
	widget->SetOrientationMarker(theAxesActor_);
	widget->SetInteractor(theRenderWindowInteractor_);
	widget->SetViewport(0.0, 0.0, 0.4, 0.4);
	widget->SetEnabled(1);
	widget->InteractiveOff();

	// Create a TextActor
	theLogoActor_ = vtkSmartPointer<vtkTextActor>::New();
	theLogoActor_->SetInput("Forg Soft");
	vtkTextProperty* tprop = theLogoActor_->GetTextProperty();
	tprop->SetFontFamilyToArial();
	tprop->ShadowOff();

	tprop->SetLineSpacing(1.0);
	tprop->SetFontSize(24);
	//tprop->SetFontFamilyToArial();
	tprop->BoldOn();
	tprop->SetFontFile(":/Fonts/swissek.ttf");
	tprop->ShadowOn();
	tprop->SetColor(0.91, 0.91, 0.91); // (Black) Color

	theLogoActor_->SetDisplayPosition(20, 20);
	theRenderer_->AddActor2D(theLogoActor_);

	theCamera_ = vtkSmartPointer<vtkCamera>::New();
	theRenderer_->LightFollowCameraOn();
	theRenderer_->TwoSidedLightingOn();

	connect(theContextMenuInScene_->GetItem("Hide"), SIGNAL(triggered()), theInteractorStyle_, SLOT(HideActionIsCalledSlot()));
	connect(theContextMenuInScene_->GetItem("UnHide"), SIGNAL(triggered()), theInteractorStyle_, SLOT(UnHideActionIsCalledSlot()));

	theRenderWindowInteractor_->Initialize();
	theRenderer_->SetActiveCamera(theCamera_);

	theOpenGLWidget_->SetRenderWindow(theRenderWindow_);

	RenderScene(true);

	FormToolBar();

	theCameraInterpolator_ = vtkCameraInterpolator::New();
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene<Dim>::RenderScene(bool resetCamera)
{

}

template<int Dim>
ForgVisualLib::FrgVisual_PointActor<Dim>* ForgVisualLib::FrgVisual_Scene<Dim>::AddPoint(
	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> pt,
	bool render
)
{
	if (!pt)
	{
		std::exception myException("Pt cannot be null in order to add a point.");
		throw myException;
	}

	vtkSmartPointer<FrgVisual_PointActor<Dim>> actor =
		vtkSmartPointer<FrgVisual_PointActor<Dim>>::New();
	actor->SetRenderer(theRenderer_);

	actor->SetData(pt);
	actor->SetColor(1.0, 0.0, 0.0);
	actor->SetSize(5);

	theRenderer_->AddActor(actor);

	if (render)
		RenderScene(false);

	return actor;
}

template<int Dim>
template<typename>
ForgVisualLib::FrgVisual_PointActor<2>* ForgVisualLib::FrgVisual_Scene<Dim>::AddPoint
(
	double x,
	double y,
	bool render
)
{
	return AddPoint(std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(x, y), render);
}

template<int Dim>
template<typename>
ForgVisualLib::FrgVisual_PointActor<3>* ForgVisualLib::FrgVisual_Scene<Dim>::AddPoint
(
	double x,
	double y,
	double z,
	bool render
)
{
	return AddPoint(std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(x, y, z), render);
}

template<int Dim>
ForgVisualLib::FrgVisual_LineActor<Dim>* ForgVisualLib::FrgVisual_Scene<Dim>::AddLine
(
	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> P0,
	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>> P1,
	bool render
)
{
	if (!P0 || !P1)
	{
		std::exception myException("P0 or P1 is null in order to add line.");
		throw myException;
	}

	vtkSmartPointer<FrgVisual_LineActor<Dim>> actor =
		vtkSmartPointer<FrgVisual_LineActor<Dim>>::New();
	actor->SetRenderer(theRenderer_);

	actor->SetData(P0, P1);
	actor->SetLineWidth(1);
	actor->SetColor(1.0, 0.0, 0.0);

	theRenderer_->AddActor(actor);

	if (render)
		RenderScene(false);

	return actor;
}

template<int Dim>
template<typename>
ForgVisualLib::FrgVisual_LineActor<2>* ForgVisualLib::FrgVisual_Scene<Dim>::AddLine
(
	double P0_X,
	double P0_Y,
	double P1_X,
	double P1_Y,
	bool render
)
{
	return AddLine(std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(P0_X, P0_Y), std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(P1_X, P1_Y), render);
}

template<int Dim>
template<typename>
ForgVisualLib::FrgVisual_LineActor<3>* ForgVisualLib::FrgVisual_Scene<Dim>::AddLine
(
	double P0_X,
	double P0_Y,
	double P0_Z,
	double P1_X,
	double P1_Y,
	double P1_Z,
	bool render
)
{
	return AddLine(std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(P0_X, P0_Y, P0_Z), std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(P1_X, P1_Y, P1_Z), render);
}

template<int Dim>
ForgVisualLib::FrgVisual_PolylineActor<Dim>* ForgVisualLib::FrgVisual_Scene<Dim>::AddPolyline
(
	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> pts,
	bool render
)
{
	if (pts.size() == 0)
	{
		std::exception myException("Pts vector is empty in order to add polyline.");
		throw myException;
	}


	vtkSmartPointer<FrgVisual_PolylineActor<Dim>> actor =
		vtkSmartPointer<FrgVisual_PolylineActor<Dim>>::New();
	actor->SetRenderer(theRenderer_);

	actor->SetData(pts);
	actor->SetColor(1.0, 0.0, 0.0);

	theRenderer_->AddActor(actor);

	if (render)
		RenderScene(false);

	return actor;
}

template<int Dim>
template<typename>
ForgVisualLib::FrgVisual_RectangleActor* ForgVisualLib::FrgVisual_Scene<Dim>::AddRectangle
(
	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<2>> P0,
	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<2>> P1,
	bool render
)
{
	if (!P0 || !P1)
	{
		std::exception myException("P0 or P1 are null in order to add rectangle.");
		throw myException;
	}

	// Actor
	vtkNew<FrgVisual_RectangleActor> actor;
	actor->SetRenderer(theRenderer_);

	actor->SetData(P0, P1);
	actor->SetColor(1.0, 0.0, 0.0);

	theRenderer_->AddActor(actor);

	if (render)
		RenderScene(false);

	return actor;
}

template<int Dim>
template<typename>
ForgVisualLib::FrgVisual_RectangleActor* ForgVisualLib::FrgVisual_Scene<Dim>::AddRectangle
(
	double P0_X,
	double P0_Y,
	double P1_X,
	double P1_Y,
	bool render
)
{
	return AddRectangle(std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(P0_X, P0_Y), std::make_shared<ForgBaseLib::FrgBase_Pnt<Dim>>(P1_X, P1_Y), render);
}

template<int Dim>
template<typename Triangulation>
void ForgVisualLib::FrgVisual_Scene<Dim>::AddTriangulations
(
	std::vector<Triangulation> triangulations,
	bool render
)
{
}

template<int Dim>
ForgVisualLib::FrgVisual_MeshActor<Dim>* ForgVisualLib::FrgVisual_Scene<Dim>::AddTriangulation
(
	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> pts,
	std::vector<std::shared_ptr<std::tuple<int, int, int>>> connectivity,
	bool render
)
{
	if (pts.size() == 0 || connectivity.size() == 0)
	{
		std::exception myException("pts or connectivity vector is empty in order to add rectangle.");
		throw myException;
	}

	vtkSmartPointer<FrgVisual_MeshActor<Dim>> actor =
		vtkSmartPointer<FrgVisual_MeshActor<Dim>>::New();
	actor->SetRenderer(theRenderer_);

	actor->SetDataTriangulation(pts, connectivity);

	theRenderer_->AddActor(actor);

	if (render)
		RenderScene(false);
}

template<int Dim>
ForgVisualLib::FrgVisual_BSPLineActor<Dim>* ForgVisualLib::FrgVisual_Scene<Dim>::AddBSPLine
(
	std::vector<std::shared_ptr<ForgBaseLib::FrgBase_Pnt<Dim>>> ctrlPts,
	int degree,
	bool drawCtrlPts,
	bool render
)
{
	// Actor
	vtkSmartPointer<FrgVisual_BSPLineActor<Dim>> actor = nullptr;

	try
	{
		actor = vtkSmartPointer<FrgVisual_BSPLineActor<Dim>>::New();

		actor->SetRenderer(theRenderer_);

		actor->SetData(ctrlPts, degree, drawCtrlPts);
		actor->SetColor(1.0, 0.0, 0.0);

		theRenderer_->AddActor(actor);
		theRenderer_->AddActor(actor->GetCtrlPtsPolyLine());

		if (render)
			RenderScene(false);
	}
	catch (const std::exception& catchedException)
	{
		if (theParentMainWindow_)
			theParentMainWindow_->PrintErrorToConsole(QString(catchedException.what()));

		return nullptr;
	}

	return actor;
}

template<>
template<>
ForgVisualLib::FrgVisual_BoxActor* ForgVisualLib::FrgVisual_Scene<3>::AddBox
(
	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<3>> P0,
	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<3>> P1,
	bool render
)
{
	if (!P0 || !P1)
	{
		std::exception myException("P0 or P1 is null in order to add line.");
		throw myException;
	}

	// Actor
	vtkNew<FrgVisual_BoxActor> actor;
	actor->SetRenderer(theRenderer_);

	actor->SetData(P0, P1);
	actor->SetColor(1.0, 0.0, 0.0);

	theRenderer_->AddActor(actor);

	if (render)
		RenderScene(false);

	return actor;
}

template<>
template<>
ForgVisualLib::FrgVisual_BoxActor* ForgVisualLib::FrgVisual_Scene<3>::AddBox
(
	double P0_X,
	double P0_Y,
	double P0_Z,
	double P1_X,
	double P1_Y,
	double P1_Z,
	bool render
)
{
	return AddBox(std::make_shared<ForgBaseLib::FrgBase_Pnt<3>>(P0_X, P0_Y, P0_Z), std::make_shared<ForgBaseLib::FrgBase_Pnt<3>>(P1_X, P1_Y, P1_Z), render);
}

template<>
template<>
ForgVisualLib::FrgVisual_TextActor<2>* ForgVisualLib::FrgVisual_Scene<2>::AddText
(
	const QString& value,
	double posx,
	double posy,
	bool render
)
{
	// Actor
	vtkNew<FrgVisual_TextActor<2>> actor;
	actor->SetRenderer(theRenderer_);

	actor->SetData(value, posx, posy);

	theRenderer_->AddActor(actor);

	if (render)
		RenderScene(false);

	return actor;
}

template<>
template<>
ForgVisualLib::FrgVisual_TextActor<3>* ForgVisualLib::FrgVisual_Scene<3>::AddText
(
	const QString& value,
	double posx,
	double posy,
	double posz,
	bool render
)
{
	// Actor
	vtkNew<FrgVisual_TextActor<3>> actor;
	actor->SetRenderer(theRenderer_);

	actor->SetData(value, posx, posy, posz);

	theRenderer_->AddActor(actor);

	if (render)
		RenderScene(false);

	return actor;
}

template<int Dim>
std::vector<ForgVisualLib::FrgVisual_GridActor*> ForgVisualLib::FrgVisual_Scene<Dim>::DrawGrid
(
	std::shared_ptr<ForgBaseLib::FrgBase_Pnt<2>> center,
	double L1,
	double L2,
	int numberOfDivisions1,
	int numberOfDivisions2,
	bool render
)
{
	std::vector<ForgVisualLib::FrgVisual_GridActor*> myGrids;

	if (center == nullptr)
		return myGrids;

	if (theMajorGridActor_ || theMinorGridActor_)
		ClearGrid();

	theMajorGridActor_ = FrgVisual_GridActor::New();
	theMinorGridActor_ = FrgVisual_GridActor::New();
	theMajorGridActor_->SetRenderer(theRenderer_);
	theMinorGridActor_->SetRenderer(theRenderer_);

	theMajorGridActor_->SetData(center, L1, L2, numberOfDivisions1, numberOfDivisions2, true);
	theMajorGridActor_->SetColor(theMajorGridColor_.redF(), theMajorGridColor_.greenF(), theMajorGridColor_.blueF());
	theMajorGridActor_->SetLineWidth(2.0f);

	theMinorGridActor_->SetData(center, L1, L2, numberOfDivisions1 * 2, numberOfDivisions2 * 2);
	theMinorGridActor_->SetColor(theMinorGridColor_.redF(), theMinorGridColor_.greenF(), theMinorGridColor_.blueF());
	theMinorGridActor_->SetLineWidth(1.0f);

	auto myXLine = theMajorGridActor_->GetXLine();
	auto myYLine = theMajorGridActor_->GetYLine();

	theRenderer_->AddActor(theMajorGridActor_);
	theRenderer_->AddActor(theMinorGridActor_);
	theRenderer_->AddActor(myXLine);
	theRenderer_->AddActor(myYLine);

	if (render)
		RenderScene(false);

	myGrids.push_back(theMajorGridActor_);
	myGrids.push_back(theMinorGridActor_);

	return myGrids;
}

template<int Dim>
std::vector<ForgVisualLib::FrgVisual_GridActor*> ForgVisualLib::FrgVisual_Scene<Dim>::DrawGrid
(
	double xCenter,
	double yCenter,
	double L1,
	double L2,
	int numberOfDivisions1,
	int numberOfDivisions2,
	bool render
)
{
	return DrawGrid(std::make_shared<ForgBaseLib::FrgBase_Pnt<2>>(xCenter, yCenter), L1, L2, numberOfDivisions1, numberOfDivisions2);
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene<Dim>::ClearAllPoints()
{
	ClearAllDataType<FrgVisual_PointActor<Dim>>();
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene<Dim>::ClearAllLines()
{
	ClearAllDataType<FrgVisual_LineActor<Dim>>();
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene<Dim>::ClearAllPolylines()
{
	ClearAllDataType<FrgVisual_PolylineActor<Dim>>();
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene<Dim>::RemoveActor(FrgVisual_BaseActor_Entity* actor)
{
	if (!actor)
		return;

	if (theRenderer_)
	{
		actor->RemoveActors(theRenderer_);

		theRenderer_->RemoveActor(actor);
	}
}

template<int Dim>
void ForgVisualLib::FrgVisual_Scene<Dim>::ClearGrid()
{
	if (theMajorGridActor_)
	{
		theRenderer_->RemoveActor(theMajorGridActor_->GetXLine());
		theRenderer_->RemoveActor(theMajorGridActor_->GetYLine());
		theRenderer_->RemoveActor(theMajorGridActor_);

		FreePointer(theMajorGridActor_);
	}

	if (theMinorGridActor_)
	{
		theRenderer_->RemoveActor(theMinorGridActor_->GetXLine());
		theRenderer_->RemoveActor(theMinorGridActor_->GetYLine());
		theRenderer_->RemoveActor(theMinorGridActor_);

		FreePointer(theMinorGridActor_);
	}
}

DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Scene_Entity)
{
	double redBackground, greenBackground, blueBackground;
	double redBackground2, greenBackground2, blueBackground2;
	bool isGradientBackground;
	double xCameraPosition, yCameraPosition, zCameraPosition;
	double xFocalPoint, yFocalPoint, zFocalPoint;
	double xViewUp, yViewUp, zViewUp;

	theRenderer_->GetBackground(redBackground, greenBackground, blueBackground);
	theRenderer_->GetBackground2(redBackground2, greenBackground2, blueBackground2);
	isGradientBackground = theRenderer_->GetGradientBackground();
	theCamera_->GetPosition(xCameraPosition, yCameraPosition, zCameraPosition);
	theCamera_->GetFocalPoint(xFocalPoint, yFocalPoint, zFocalPoint);
	theCamera_->GetViewUp(xViewUp, yViewUp, zViewUp);

	ar& redBackground;
	ar& greenBackground;
	ar& blueBackground;

	ar& redBackground2;
	ar& greenBackground2;
	ar& blueBackground2;

	ar& isGradientBackground;

	ar& xCameraPosition;
	ar& yCameraPosition;
	ar& zCameraPosition;

	ar& xFocalPoint;
	ar& yFocalPoint;
	ar& zFocalPoint;

	ar& xViewUp;
	ar& yViewUp;
	ar& zViewUp;
}

DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Scene_Entity)
{
	double redBackground, greenBackground, blueBackground;
	double redBackground2, greenBackground2, blueBackground2;
	bool isGradientBackground;
	double xCameraPosition, yCameraPosition, zCameraPosition;
	double xFocalPoint, yFocalPoint, zFocalPoint;
	double xViewUp, yViewUp, zViewUp;

	ar& redBackground;
	ar& greenBackground;
	ar& blueBackground;

	ar& redBackground2;
	ar& greenBackground2;
	ar& blueBackground2;

	ar& isGradientBackground;

	ar& xCameraPosition;
	ar& yCameraPosition;
	ar& zCameraPosition;

	ar& xFocalPoint;
	ar& yFocalPoint;
	ar& zFocalPoint;

	ar& xViewUp;
	ar& yViewUp;
	ar& zViewUp;

	theRenderer_->SetBackground(redBackground, greenBackground, blueBackground);
	theRenderer_->SetBackground2(redBackground2, greenBackground2, blueBackground2);
	theRenderer_->SetGradientBackground(isGradientBackground);
	theCamera_->SetPosition(xCameraPosition, yCameraPosition, zCameraPosition);
	theCamera_->SetFocalPoint(xFocalPoint, yFocalPoint, zFocalPoint);
	theCamera_->SetViewUp(xViewUp, yViewUp, zViewUp);
}

template<int Dim>
DECLARE_SAVE_IMP(ForgVisualLib::FrgVisual_Scene<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_Scene_Entity>(*this);

	double mouseWheelMotionFactor;
	if constexpr (Dim == 2)
		mouseWheelMotionFactor = FrgVisual_Scene_InterStyle2D::SafeDownCast((FrgVisual_Scene_InterStyle2D::SuperClass*)(theInteractorStyle_))->GetMouseWheelMotionFactor();
	else if constexpr (Dim == 3)
		mouseWheelMotionFactor = FrgVisual_Scene_InterStyle3D::SafeDownCast((FrgVisual_Scene_InterStyle3D::SuperClass*)(theInteractorStyle_))->GetMouseWheelMotionFactor();

	ar& mouseWheelMotionFactor;

	vtkActorCollection* ac;
	vtkActor* anActor;
	FrgVisual_BaseActor_Entity* aPart;

	int numberOfItems = theRenderer_->GetActors()->GetNumberOfItems();
	ar& numberOfItems;

	ac = theRenderer_->GetActors();
	vtkCollectionSimpleIterator ait;
	for (ac->InitTraversal(ait); (anActor = ac->GetNextActor(ait)); )
	{
		aPart = dynamic_cast<FrgVisual_BaseActor_Entity*>(anActor);
		QString isFrgVisualActor;

		if (aPart)
		{
			isFrgVisualActor = IS_FRGVISUAL_ACTOR;

			ar& isFrgVisualActor;

			bool isIndependent = aPart->IsIndependent();
			ar& isIndependent;

			if (isIndependent)
				ar& aPart;
		}
		else
		{
			isFrgVisualActor = IS_NOT_FRGVISUAL_ACTOR;

			ar& isFrgVisualActor;
		}
	}

	ar& theMajorGridColor_;
	ar& theMinorGridColor_;
}

template<int Dim>
DECLARE_LOAD_IMP(ForgVisualLib::FrgVisual_Scene<Dim>)
{
	ar& boost::serialization::base_object<ForgVisualLib::FrgVisual_Scene_Entity>(*this);

	double mouseWheelMotionFactor;
	ar& mouseWheelMotionFactor;

	if constexpr (Dim == 2)
		FrgVisual_Scene_InterStyle2D::SafeDownCast((FrgVisual_Scene_InterStyle2D::SuperClass*)(theInteractorStyle_))->SetMouseWheelMotionFactor(mouseWheelMotionFactor);
	else if constexpr (Dim == 3)
		FrgVisual_Scene_InterStyle3D::SafeDownCast((FrgVisual_Scene_InterStyle3D::SuperClass*)(theInteractorStyle_))->SetMouseWheelMotionFactor(mouseWheelMotionFactor);

	int numberOfItems;
	ar& numberOfItems;

	for (int i = 0; i < numberOfItems; i++)
	{
		QString isFrgVisualActor;

		ar& isFrgVisualActor;

		if (isFrgVisualActor == IS_FRGVISUAL_ACTOR)
		{
			bool isIndependent;
			ar& isIndependent;

			if (isIndependent)
			{
				FrgVisual_BaseActor_Entity* aPart;
				ar& aPart;

				aPart->SetRenderer(theRenderer_);

				theRenderer_->AddActor(aPart);
			}

			/*auto myGrid = dynamic_cast<FrgVisual_GridActor*>(aPart);
			if (myGrid)
			{
				if (myGrid->GetXLine())
					theMajorGridActor_ = myGrid;
				else
					theMinorGridActor_ = myGrid;
			}*/
		}
		else if (isFrgVisualActor == IS_NOT_FRGVISUAL_ACTOR)
		{

		}
	}

	ar& theMajorGridColor_;
	ar& theMinorGridColor_;

	this->RenderScene(true);
}

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Scene_Entity)

BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Scene<2>)
BOOST_CLASS_EXPORT_CXX(ForgVisualLib::FrgVisual_Scene<3>)

template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_Scene<2>;
template FORGVISUAL_EXPORT class ForgVisualLib::FrgVisual_Scene<3>;

template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_PointActor<2>* ForgVisualLib::FrgVisual_Scene<2>::AddPoint(double x, double y, bool render);
template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_PointActor<3>* ForgVisualLib::FrgVisual_Scene<3>::AddPoint(double x, double y, double z, bool render);

template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_LineActor<2>* ForgVisualLib::FrgVisual_Scene<2>::AddLine(double P0_X, double P0_Y, double P1_X, double P1_Y, bool render);
template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_LineActor<3>* ForgVisualLib::FrgVisual_Scene<3>::AddLine(double P0_X, double P0_Y, double P0_Z, double P1_X, double P1_Y, double P1_Z, bool render);

template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_RectangleActor* ForgVisualLib::FrgVisual_Scene<2>::AddRectangle(std::shared_ptr<ForgBaseLib::FrgBase_Pnt<2>> P0, std::shared_ptr<ForgBaseLib::FrgBase_Pnt<2>> P1, bool render);
template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_RectangleActor* ForgVisualLib::FrgVisual_Scene<2>::AddRectangle(double P0_X, double P0_Y, double P1_X, double P1_Y, bool render);

template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_BoxActor* ForgVisualLib::FrgVisual_Scene<3>::AddBox(std::shared_ptr<ForgBaseLib::FrgBase_Pnt<3>> P0, std::shared_ptr<ForgBaseLib::FrgBase_Pnt<3>> P1, bool render);
template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_BoxActor* ForgVisualLib::FrgVisual_Scene<3>::AddBox(double P0_X, double P0_Y, double P0_Z, double P1_X, double P1_Y, double P1_Z, bool render);

template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_TextActor<2>* ForgVisualLib::FrgVisual_Scene<2>::AddText(const QString& value, double posx, double posy, bool render);
template FORGVISUAL_EXPORT ForgVisualLib::FrgVisual_TextActor<3>* ForgVisualLib::FrgVisual_Scene<3>::AddText(const QString& value, double posx, double posy, double posz, bool render);